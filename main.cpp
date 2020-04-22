#include<iostream>

#include <QCoreApplication>
#include <QQmlEngine>
#include <QFile>
#include <QTextCodec>
#include <QByteArray>
#include <QString>

#include "scriptbinaryfile.h"
#include "scriptenvironment.h"
#include "scriptfile.h"
#include "scriptfileinfo.h"
#include "scriptgeneral.h"
#include "scriptprocess.h"
#include "scriptpropertylist.h"
#include "scripttemporarydir.h"
#include "scripttextfile.h"
#include "scriptutilities.h"
#include "scriptxml.h"

bool fromUtf8(const QByteArray &bytes, QString &unicode)
{
	QTextCodec::ConverterState state;
	const QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	unicode = codec->toUnicode(bytes.constData(), bytes.size(), &state);
	return state.invalidChars == 0;
}

using namespace std;
int main(int argc, char *argv[])
{
	if (argc < 2) {
		cerr << "Usage: Qbs4QJS <script.js>\n";
		return 1;
	}
	
	QCoreApplication app(argc, argv);
	QQmlEngine *mEngine = new QQmlEngine();
	QJSValue globalObject = mEngine->globalObject();

	ScriptBinaryFile *mBinaryFile = new ScriptBinaryFile();
	ScriptEnvironment *mEnvironment = new ScriptEnvironment();
	ScriptFile *mFile = new ScriptFile();
	ScriptFileInfo *mFileInfo = new ScriptFileInfo();
	ScriptGeneral *mGeneral = new ScriptGeneral();
	ScriptProcess *mProcess = new ScriptProcess();
	ScriptPropertyList *mPropertyList = new ScriptPropertyList();
	ScriptTemporaryDir *mTemporaryDir = new ScriptTemporaryDir();
	ScriptTextFile *mTextFile = new ScriptTextFile();
	ScriptUtilities *mUtilities = new ScriptUtilities();
	ScriptXml *mXml = new ScriptXml();

	globalObject.setProperty(QStringLiteral("BinaryFile"), mEngine->newQObject(mBinaryFile));
	globalObject.setProperty(QStringLiteral("Environment"), mEngine->newQObject(mEnvironment));
	globalObject.setProperty(QStringLiteral("File"), mEngine->newQObject(mFile));
	globalObject.setProperty(QStringLiteral("FileInfo"), mEngine->newQObject(mFileInfo));
	globalObject.setProperty(QStringLiteral("General"), mEngine->newQObject(mGeneral));
	globalObject.setProperty(QStringLiteral("Process"), mEngine->newQObject(mProcess));
	globalObject.setProperty(QStringLiteral("PropertyList"), mEngine->newQObject(mPropertyList));
	globalObject.setProperty(QStringLiteral("TemporaryDir"), mEngine->newQObject(mTemporaryDir));
	globalObject.setProperty(QStringLiteral("TextFile"), mEngine->newQObject(mTextFile));
	globalObject.setProperty(QStringLiteral("Utilities"), mEngine->newQObject(mUtilities));
	globalObject.setProperty(QStringLiteral("Xml"), mEngine->newQObject(mXml));


	QFile file(argv[1]);

	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		cerr << "Could not open file!\n";
		return 1;
	}

	const QByteArray bytes = file.readAll();
	QString script;
	
	if (!fromUtf8(bytes, script)) {
		script = QTextCodec::codecForUtfText(bytes)->toUnicode(bytes);
	}

	QJSValue result = mEngine->evaluate(script, argv[1]);

	if (result.isError()) {
		QString errorString = result.toString();
		QString stack = result.property(QStringLiteral("stack")).toString();
		const auto stackEntries = stack.splitRef(QLatin1Char('\n'));
		    if (stackEntries.size() > 0 && !stackEntries.first().startsWith(QLatin1String("%entry@"))) {
        // Add stack if there were more than one entries
        errorString.append(QLatin1Char('\n'));
        errorString.append("Stack traceback:");
        errorString.append(QLatin1Char('\n'));

        for (const auto &entry : stackEntries) {
            errorString.append(QLatin1String("  "));
            errorString.append(entry);
            errorString.append(QLatin1Char('\n'));
        }

        errorString.chop(1);
    }
    cerr << errorString.toUtf8().constData() << "\n";
    return 1;
	}

	return 0;
}
