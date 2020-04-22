#ifndef SCRIPTENVIRONMENT_H
#define SCRIPTENVIRONMENT_H

#include <QObject>

class ScriptEnvironment : public QObject
{
    Q_OBJECT
public:
    explicit ScriptEnvironment(QObject *parent = nullptr);

signals:

};

#endif // SCRIPTENVIRONMENT_H
