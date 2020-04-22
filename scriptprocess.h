#ifndef SCRIPTPROCESS_H
#define SCRIPTPROCESS_H

#include <QObject>

class ScriptProcess : public QObject
{
    Q_OBJECT
public:
    explicit ScriptProcess(QObject *parent = nullptr);

signals:

};

#endif // SCRIPTPROCESS_H
