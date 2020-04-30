#include <QObject>
#include <QString>
#include <QTemporaryDir>
#include <QJSEngine>

namespace Qbs4QJS {

class _TemporaryDir : public QObject
{
	Q_OBJECT

	static bool tempDirIsCanonical() {
#if QT_VERSION >= 0x050c00
		return true;
#endif
		return false;
	}

public:
	Q_INVOKABLE _TemporaryDir() {
		dir.setAutoRemove(false);
	}

	Q_INVOKABLE bool isValid() const {
		return dir.isValid();
	}

	Q_INVOKABLE QString path() const {
		return tempDirIsCanonical() ? dir.path() : QFileInfo(dir.path()).canonicalFilePath();
	}

	Q_INVOKABLE bool remove() {
		return dir.remove();
	}

private:
	QTemporaryDir dir;
};

class TemporaryDir
{
public:
	TemporaryDir(QJSEngine *jsEngine, QString jsName = "TemporaryDir") {
		jsEngine->globalObject().setProperty(jsName, jsEngine->newQMetaObject(&_TemporaryDir::staticMetaObject));
	}
};

} // end namespace Qbs4QJS