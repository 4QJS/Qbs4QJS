#ifndef SCRIPTFILE_H
#define SCRIPTFILE_H

#include <QObject>

class ScriptFile : public QObject
{
    Q_OBJECT
public:
    explicit ScriptFile(QObject *parent = nullptr);

signals:

};

#endif // SCRIPTFILE_H
