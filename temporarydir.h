#include <QObject>
#include <QString>
#include <QTemporaryDir>

namespace Qbs4QJS {

class TemporaryDir : public QObject
{
	Q_OBJECT

	static bool tempDirIsCanonical() {
#if QT_VERSION >= 0x050c00
		return true;
#endif
		return false;
	}

public:

	Q_INVOKABLE TemporaryDir() {
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

} // end namespace Qbs4QJS