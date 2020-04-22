#include "scriptfileinfo.h"
#include <QFileInfo>
#include <QDir>

ScriptFileInfo::ScriptFileInfo(QObject *parent) : QObject(parent)
{}

QString ScriptFileInfo::baseName(const QString &filePath) const
{
	return QFileInfo(filePath).baseName();
}

QString ScriptFileInfo::canonicalPath(const QString &filePath) const
{
	return QFileInfo(filePath).canonicalPath();
}

QString ScriptFileInfo::cleanPath(const QString &filePath) const
{
	return QDir().cleanPath(filePath);
}

QString ScriptFileInfo::completeBaseName(const QString &filePath) const
{
	return QFileInfo(filePath).completeBaseName();
}

QString ScriptFileInfo::completeSuffix(const QString &filePath) const
{
	return QFileInfo(filePath).completeSuffix();
}

QString ScriptFileInfo::fileName(const QString &filePath) const
{
	return QFileInfo(filePath).fileName();
}

// QString ScriptFileInfo::fromNativeSeparators(const QString &filePath) const
// {
// 	return QFileInfo(filePath).fromNativeSeparators();
// }

// QString ScriptFileInfo::fromWindowsSeparators(const QString &filePath) const
// {
// 	return QFileInfo(filePath).fromWindowsSeparators();
// }

bool ScriptFileInfo::isAbsolutePath(const QString &filePath) const
{
	return QDir(filePath).isAbsolute();
}

// QString ScriptFileInfo::joinPaths(const QStringList &paths) const
// {
// 	return QFileInfo(filePath).joinPaths();
// }

QString ScriptFileInfo::path(const QString &filePath) const
{
	return QFileInfo(filePath).path();
}

// QString ScriptFileInfo::relativePath(const QString &dirPath, const QString &filePath) const
// {
// 	return QFileInfo(filePath).relativePath();
// }

QString ScriptFileInfo::suffix(const QString &filePath) const
{
	return QFileInfo(filePath).suffix();
}

// QString ScriptFileInfo::toNativeSeparators(const QString &filePath) const
// {
// 	return QFileInfo(filePath).toNativeSeparators();
// }

// QString ScriptFileInfo::toWindowsSeparators(const QString &filePath) const
// {
// 	return QFileInfo(filePath).toWindowsSeparators();
// }

