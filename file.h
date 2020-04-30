#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QJSEngine>

namespace Qbs4QJS {

class _File : public QObject
{
	Q_OBJECT

public:
	enum Filter {
		Dirs = QDir::Filter::Dirs,
		Files = QDir::Filter::Files,
		Drives = QDir::Filter::Drives,
		NoSymLinks = QDir::Filter::NoSymLinks,
		AllEntries = QDir::Filter::AllEntries,
		TypeMask = QDir::Filter::TypeMask,
		Readable = QDir::Filter::Readable,
		Writable = QDir::Filter::Writable,
		Executable = QDir::Filter::Executable,
		PermissionMask = QDir::Filter::PermissionMask,
		Modified = QDir::Filter::Modified,
		Hidden = QDir::Filter::Hidden,
		System = QDir::Filter::System,
		AccessMask  = QDir::Filter::AccessMask ,
		AllDirs = QDir::Filter::AllDirs,
		CaseSensitive = QDir::Filter::CaseSensitive,
		NoDot = QDir::Filter::NoDot,
		NoDotDot = QDir::Filter::NoDotDot,
		NoDotAndDotDot = QDir::Filter::NoDotAndDotDot,
		NoFilter = QDir::Filter::NoFilter
	};
	Q_ENUMS(Filter)

	enum SortFlag {
		Name = QDir::SortFlag::Name,
		Time = QDir::SortFlag::Time,
		Size = QDir::SortFlag::Size,
		Type = QDir::SortFlag::Type,
		Unsorted = QDir::SortFlag::Unsorted,
		DirsFirst = QDir::SortFlag::DirsFirst,
		DirsLast = QDir::SortFlag::DirsLast,
		Reversed = QDir::SortFlag::Reversed,
		IgnoreCase = QDir::SortFlag::IgnoreCase,
		LocaleAware = QDir::SortFlag::LocaleAware,
		NoSort = QDir::SortFlag::NoSort
	};
	Q_ENUM(SortFlag)

	_File() {}

	Q_INVOKABLE bool copy(QString sourceFilePath, QString targetFilePath) const {
		return QFile(sourceFilePath).copy(targetFilePath);
	}

	Q_INVOKABLE bool exists(QString filePath) const {
		return QFile(filePath).exists();
	}

	Q_INVOKABLE QStringList directoryEntries(QString path, Filter filter = NoFilter, SortFlag sort = NoSort) const {
		return QDir(path).entryList((QDir::Filter)filter, (QDir::SortFlag)sort);
	}

	Q_INVOKABLE QDateTime lastModified(QString filePath) const {
		return QFileInfo(filePath).lastModified();
	}

	Q_INVOKABLE bool makePath(QString path) const {
		return QDir::root().mkpath(path);
	}

	Q_INVOKABLE bool move(QString oldPath, QString newPath, bool overwrite = true) const {
		QFileInfo o(newPath);
		QFileInfo n(newPath);
		if (overwrite || !n.exists()) {
			if (o.isDir()) {
				qjsEngine(this)->throwError("Source is a directory.");
				return false;
			} else if (n.isDir()) {
				qjsEngine(this)->throwError("Destination is a directory.");
				return false;
			} else {
				return QFile(oldPath).rename(newPath);
			}
		} else {
			qjsEngine(this)->throwError("Destination exists.");
			return false;
		}
	}

	Q_INVOKABLE bool remove(QString filePath) const {
		return QFile(filePath).remove();
	}
};

class File {
public:
	File (QJSEngine *jsEngine, QString jsName = "File"){
		jsEngine->globalObject().setProperty(jsName, jsEngine->newQObject(new Qbs4QJS::_File()));
	}
};

} // end namespace Qbs4QJS