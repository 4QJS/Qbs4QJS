#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QJSEngine>

namespace Qbs4QJS {

class _FileInfo : public QObject
{
	Q_OBJECT

public:
	_FileInfo() {}

	Q_INVOKABLE QString baseName(QString filePath) const {
		return QFileInfo(filePath).baseName();
	}
	
	Q_INVOKABLE QString canonicalPath(QString filePath) const {
		return QFileInfo(filePath).canonicalPath();
	}
	
	Q_INVOKABLE QString cleanPath(QString filePath) const {
		return QDir::cleanPath(filePath);
	}
	
	Q_INVOKABLE QString completeBaseName(QString filePath) const {
		return QFileInfo(filePath).completeBaseName();
	}
	
	Q_INVOKABLE QString completeSuffix(QString filePath) const {
		return QFileInfo(filePath).completeSuffix();
	}
	
	Q_INVOKABLE QString fileName(QString filePath) const {
		return QFileInfo(filePath).fileName();
	}
	
	Q_INVOKABLE QString fromNativeSeparators(QString filePath) const {
		return QDir::fromNativeSeparators(filePath);
	}
	
	Q_INVOKABLE QString fromWindowsSeparators(QString filePath) const {
		return QDir::fromNativeSeparators(filePath);
	}
	
	Q_INVOKABLE bool isAbsolutePath(QString filePath) const {
		// TODO: need to do something with hostOS param
		return QFileInfo(filePath).isAbsolute();
	}
	
	Q_INVOKABLE QString _joinPaths(QStringList paths) const {
		return QDir::cleanPath(paths.join(QDir::separator()));
	}

	Q_INVOKABLE QString path(QString filePath) const {
		// TODO: need to do something with hostOS param
		return QFileInfo(filePath).path();
	}
	
	Q_INVOKABLE QString relativePath(QString dirPath, QString filePath) const {
		return QDir(dirPath).relativeFilePath(filePath);
	}
	
	Q_INVOKABLE QString suffix(QString filePath) const {
		return QFileInfo(filePath).suffix();
	}
	
	Q_INVOKABLE QString toNativeSeparators(QString filePath) const {
		return QDir::toNativeSeparators(filePath);
	}
	
	Q_INVOKABLE QString toWindowsSeparators(QString filePath) const {
		return QDir::toNativeSeparators(filePath);
	}
};

class FileInfo
{
public:
	FileInfo(QJSEngine *jsEngine, QString jsName = "FileInfo") {
		jsEngine->globalObject().setProperty(jsName, jsEngine->newQObject(new Qbs4QJS::_FileInfo()));
		// allow dynamic arg-length
		jsEngine->evaluate(jsName + ".joinPaths = function (...args) { return this._joinPaths(args) }");
	}
};


} // end namespace Qbs4QJS
