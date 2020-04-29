#include <QObject>
#include <QString>
#include <QProcess>
#include <QTextStream>
#include <QProcessEnvironment>
#include <QJSEngine>

namespace Qbs4QJS {

class Process : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE Process () {
		m_qProcess = new QProcess;
    m_textStream = new QTextStream(m_qProcess);
    m_environment = QProcessEnvironment::systemEnvironment();
	}

	~Process () override {
		close();
	}

	Q_INVOKABLE QString getEnv(const QString &name) {
		return m_environment.value(name);
	}
	
	Q_INVOKABLE void setEnv(const QString &name, const QString &value) {
		m_environment.insert(name, value);
	}
	
	Q_INVOKABLE void setCodec(const QString &codec) {
		m_textStream->setCodec(qPrintable(codec));
	}
	
	Q_INVOKABLE QString workingDirectory() {
		return m_workingDirectory;
	}
	
	Q_INVOKABLE void setWorkingDirectory(const QString &dir) {
		m_workingDirectory = dir;
	}
	
	Q_INVOKABLE bool start(const QString &program, const QStringList &arguments) {
		if (!m_workingDirectory.isEmpty()) {
			m_qProcess->setWorkingDirectory(m_workingDirectory);
    }
		m_qProcess->setProcessEnvironment(m_environment);
    m_qProcess->start(program, arguments);
    return m_qProcess->waitForStarted();
	}
	
	Q_INVOKABLE int exec(const QString &program, const QStringList &arguments, bool throwOnError = false) {
		if (!start(program, arguments)) {
			if (throwOnError) {
				qjsEngine(this)->throwError("Error running " + program + m_qProcess->errorString());
			}
			return -1;
    }
    m_qProcess->closeWriteChannel();
    m_qProcess->waitForFinished(-1);
    // TODO: handle m_qProcess->error()
    return m_qProcess->exitCode();
	}
	
	Q_INVOKABLE void close() {
		delete m_textStream;
    m_textStream = nullptr;
    delete m_qProcess;
    m_qProcess = nullptr;
	}
	
	Q_INVOKABLE bool waitForFinished(int msecs = 30000) {
		return m_qProcess->waitForFinished(msecs);
	}
	
	Q_INVOKABLE void terminate() {
		m_qProcess->terminate();
	}
	
	Q_INVOKABLE void kill() {
		m_qProcess->kill();
	}
	
	Q_INVOKABLE QString readLine() {
		return m_textStream->readLine();
	}
	
	Q_INVOKABLE bool atEnd() const {
		return m_textStream->atEnd();
	}
	
	Q_INVOKABLE QString readStdOut() {
		return m_textStream->readAll();
	}
	
	Q_INVOKABLE QString readStdErr() {
		return m_qProcess->readAllStandardError();
	}
	
	Q_INVOKABLE void closeWriteChannel() {
		m_textStream->flush();
    m_qProcess->closeWriteChannel();
	}
	
	Q_INVOKABLE void write(const QString &str) {
		(*m_textStream) << str;
	}
	
	Q_INVOKABLE void writeLine(const QString &str){
		(*m_textStream) << str << '\n';
	}
	
	Q_INVOKABLE int exitCode() const {
		return m_qProcess->exitCode();
	}

private:
	QProcess *m_qProcess;
  QProcessEnvironment m_environment;
  QString m_workingDirectory;
  QTextStream *m_textStream;
};

} // end namespace Qbs4QJS