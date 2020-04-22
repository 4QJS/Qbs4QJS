#include <QQmlEngine>

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

int main(int argc, char *argv[])
{
    QQmlEngine mEngine = new QQmlEngine(this);
    QJSValue globalObject = mEngine->globalObject();

    ScriptBinaryFile mBinaryFile = new ScriptBinaryFile(this);
    ScriptEnvironment mEnvironment = new ScriptEnvironment(this);
    ScriptFile mFile = new ScriptFile(this);
    ScriptFileInfo mFileInfo = new ScriptFileInfo(this);
    ScriptGeneral mGeneral = new ScriptGeneral(this);
    ScriptProcess mProcess = new ScriptProcess(this);
    ScriptPropertyList mPropertyList = new ScriptPropertyList(this);
    ScriptTemporaryDir mTemporaryDir = new ScriptTemporaryDir(this);
    ScriptTextFile mTextFile = new ScriptTextFile(this);
    ScriptUtilities mUtilities = new ScriptUtilities(this);
    ScriptXml mXml = new ScriptXml(this);

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

    return 0;
}
