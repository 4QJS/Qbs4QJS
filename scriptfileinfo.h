#pragma once

#include <QObject>
#include <QString>
#include <QStringList>

class ScriptFileInfo : public QObject
{
    Q_OBJECT
public:
    ScriptFileInfo(QObject *parent = nullptr);

    // original Qbs:
    Q_INVOKABLE QString baseName(const QString &filePath) const;
    Q_INVOKABLE QString canonicalPath(const QString &filePath) const;
    Q_INVOKABLE QString cleanPath(const QString &filePath) const;
    Q_INVOKABLE QString completeBaseName(const QString &filePath) const;
    Q_INVOKABLE QString completeSuffix(const QString &filePath) const;
    Q_INVOKABLE QString fileName(const QString &filePath) const;
    // Q_INVOKABLE QString fromNativeSeparators(const QString &filePath) const;
    // Q_INVOKABLE QString fromWindowsSeparators(const QString &filePath) const;
    Q_INVOKABLE bool isAbsolutePath(const QString &filePath) const;
    // Q_INVOKABLE QString joinPaths(const QStringList &paths) const;
    Q_INVOKABLE QString path(const QString &filePath) const;
    // Q_INVOKABLE QString relativePath(const QString &dirPath, const QString &filePath) const;
    Q_INVOKABLE QString suffix(const QString &filePath) const;
    // Q_INVOKABLE QString toNativeSeparators(const QString &filePath) const;
    // Q_INVOKABLE QString toWindowsSeparators(const QString &filePath) const;

    // extra useful utils
};


