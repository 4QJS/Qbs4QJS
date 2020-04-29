#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QJSEngine>

namespace Qbs4QJS {

class File : public QObject
{
	Q_OBJECT

public:
	// for some reason, I couldn't use the QDir enums here, directly
	enum Filter {
		Dirs = 0x001,
		Files = 0x002,
		Drives = 0x004,
		NoSymLinks = 0x008,
		AllEntries = Dirs | Files | Drives,
		TypeMask = 0x00f,
		Readable = 0x010,
		Writable = 0x020,
		Executable = 0x040,
		PermissionMask = 0x070,
		Modified = 0x080,
		Hidden = 0x100,
		System = 0x200,
		AccessMask  = 0x3F0,
		AllDirs = 0x400,
		CaseSensitive = 0x800,
		NoDot = 0x2000,
		NoDotDot = 0x4000,
		NoDotAndDotDot = NoDot | NoDotDot,
		NoFilter = -1
	};
	Q_ENUMS(Filter)

	enum SortFlag {
		Name = 0x00,
		Time = 0x01,
		Size = 0x02,
		Type = 0x80,
		Unsorted = 0x03,
		DirsFirst = 0x04,
		DirsLast = 0x20,
		Reversed = 0x08,
		IgnoreCase = 0x10,
		LocaleAware = 0x40,
		NoSort = -1
	};
	Q_ENUM(SortFlag)

	File() {}

	Q_INVOKABLE bool copy(QString &sourceFilePath, QString &targetFilePath) const {
		return QFile(sourceFilePath).copy(targetFilePath);
	}

	Q_INVOKABLE bool exists(QString &filePath) const {
		return QFile(filePath).exists();
	}

	Q_INVOKABLE QStringList directoryEntries(QString &path, Filter filter = NoFilter,  SortFlag sort = NoSort) const {
		return QDir(path).entryList((QDir::Filters)filter, (QDir::SortFlag)sort);
	}

	Q_INVOKABLE QDateTime lastModified(QString &filePath) const {
		return QFileInfo(filePath).lastModified();
	}

	Q_INVOKABLE bool makePath(QString &path) const {
		return QDir::root().mkpath(path);
	}

	Q_INVOKABLE bool move(QString &oldPath, QString &newPath, bool overwrite = true) const {
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

	Q_INVOKABLE bool remove(QString &filePath) const {
		return QFile(filePath).remove();
	}
};

} // end namespace Qbs4QJS