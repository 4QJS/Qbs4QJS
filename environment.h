#include <QObject>
#include <QString>
#include <QJSEngine>
#include <QProcessEnvironment>

namespace Qbs4QJS {

class Environment : public QObject
{
	Q_OBJECT

public:
	Environment() {
		m_procenv = QProcessEnvironment::systemEnvironment();
	}

	Q_INVOKABLE QJSValue currentEnv() {
		QJSValue envObject = qjsEngine(this)->newObject();
		const auto keys = m_procenv.keys();
		for (const QString &key : keys) {
			envObject.setProperty(key, QString(m_procenv.value(key)));
		}
		return envObject;
	}

	Q_INVOKABLE QString getEnv(QString key) const {
		return m_procenv.value(key);
	}

	Q_INVOKABLE void putEnv(QString key, QString value) {
		m_procenv.insert(key, value);
	}

	Q_INVOKABLE void unsetEnv(QString key) {
		m_procenv.remove(key);
	}
	
private:
	QProcessEnvironment m_procenv;
};

} // end namespace Qbs4QJS