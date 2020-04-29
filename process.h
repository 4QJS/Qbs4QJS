#include <QObject>
#include <QString>
#include <QProcess>
#include <QTextStream>

namespace Qbs4QJS {

class Process : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE Process () {
		m_qProcess = new QProcess;
    m_textStream = new QTextStream(m_qProcess);
	}

	~Process () override {
		delete m_textStream;
    delete m_qProcess;
	}

	Q_INVOKABLE QString getEnv(const QString &name) {
		return m_environment.value(name);
	}
	
	Q_INVOKABLE void setEnv(const QString &name, const QString &value) {}
	
	Q_INVOKABLE void setCodec(const QString &codec) {}
	
	Q_INVOKABLE QString workingDirectory() {}
	
	Q_INVOKABLE void setWorkingDirectory(const QString &dir) {}
	
	Q_INVOKABLE bool start(const QString &program, const QStringList &arguments) {}
	
	Q_INVOKABLE int exec(const QString &program, const QStringList &arguments, bool throwOnError = false) {}
	
	Q_INVOKABLE void close() {}
	
	Q_INVOKABLE bool waitForFinished(int msecs = 30000) {}
	
	Q_INVOKABLE void terminate() {}
	
	Q_INVOKABLE void kill() {}
	
	Q_INVOKABLE QString readLine() {}
	
	Q_INVOKABLE bool atEnd() const {}
	
	Q_INVOKABLE QString readStdOut() {}
	
	Q_INVOKABLE QString readStdErr() {}
	
	Q_INVOKABLE void closeWriteChannel() {}
	
	Q_INVOKABLE void write(const QString &str) {}
	
	Q_INVOKABLE void writeLine(const QString &str){}
	
	Q_INVOKABLE int exitCode() const {}

private:
	QProcess *m_qProcess;
  QProcessEnvironment m_environment;
  QString m_workingDirectory;
  QTextStream *m_textStream;
};

} // end namespace Qbs4QJS