#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>

namespace Qbs4QJS {

class FileInfo : public QObject
{
	Q_OBJECT

public:
	FileInfo() {}

	Q_INVOKABLE QString baseName(QString &filePath) const {
		return QFileInfo(filePath).baseName();
	}
	
	Q_INVOKABLE QString canonicalPath(QString &filePath) const {
		return QFileInfo(filePath).canonicalPath();
	}
	
	Q_INVOKABLE QString cleanPath(QString &filePath) const {
		return QDir::cleanPath(filePath);
	}
	
	Q_INVOKABLE QString completeBaseName(QString &filePath) const {
		return QFileInfo(filePath).completeBaseName();
	}
	
	Q_INVOKABLE QString completeSuffix(QString &filePath) const {
		return QFileInfo(filePath).completeSuffix();
	}
	
	Q_INVOKABLE QString fileName(QString &filePath) const {
		return QFileInfo(filePath).fileName();
	}
	
	Q_INVOKABLE QString fromNativeSeparators(QString &filePath) const {
		return QDir::fromNativeSeparators(filePath);
	}
	
	Q_INVOKABLE QString fromWindowsSeparators(QString &filePath) const {
		return QDir::fromNativeSeparators(filePath);
	}
	
	Q_INVOKABLE bool isAbsolutePath(QString &filePath) const {
		// TODO: need to do something with hostOS param
		return QFileInfo(filePath).isAbsolute();
	}
	
	Q_INVOKABLE QString joinPaths(QStringList paths) const {
		return QDir::cleanPath(paths.join(QDir::separator()));
	}

	Q_INVOKABLE QString path(QString &filePath) const {
		// TODO: need to do something with hostOS param
		return QFileInfo(filePath).path();
	}
	
	Q_INVOKABLE QString relativePath(QString &dirPath, QString &filePath) const {
		return QDir(dirPath).relativeFilePath(filePath);
	}
	
	Q_INVOKABLE QString suffix(QString &filePath) const {
		return QFileInfo(filePath).suffix();
	}
	
	Q_INVOKABLE QString toNativeSeparators(QString &filePath) const {
		return QDir::toNativeSeparators(filePath);
	}
	
	Q_INVOKABLE QString toWindowsSeparators(QString &filePath) const {
		return QDir::toNativeSeparators(filePath);
	}
};

} // end namespace Qbs4QJS
