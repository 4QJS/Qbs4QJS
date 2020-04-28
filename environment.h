#include <QObject>
#include <QString>
#include <QJSEngine>

namespace Qbs4QJS {

class Environment : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE Environment() {}

	Q_INVOKABLE QJSValue currentEnv() {
		 QJSValue env = qjsEngine(this)->newObject();

		 return env;
	}

	Q_INVOKABLE QString getEnv(QString key) {
		return "";
	}

	Q_INVOKABLE void putEnv(QString key, QString value) {}

	Q_INVOKABLE void unsetEnv(QString key) {}
	
private:
};

} // end namespace Qbs4QJS