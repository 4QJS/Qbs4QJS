#ifndef SCRIPTPROPERTYLIST_H
#define SCRIPTPROPERTYLIST_H

#include <QObject>

class ScriptPropertyList : public QObject
{
    Q_OBJECT
public:
    explicit ScriptPropertyList(QObject *parent = nullptr);

signals:

};

#endif // SCRIPTPROPERTYLIST_H
