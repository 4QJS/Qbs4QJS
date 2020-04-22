#ifndef SCRIPTTEMPORARYDIR_H
#define SCRIPTTEMPORARYDIR_H

#include <QObject>

class ScriptTemporaryDir : public QObject
{
    Q_OBJECT
public:
    explicit ScriptTemporaryDir(QObject *parent = nullptr);

signals:

};

#endif // SCRIPTTEMPORARYDIR_H
