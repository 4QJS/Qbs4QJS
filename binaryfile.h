#include <QObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QFileInfo>
#include <QJSEngine>

namespace Qbs4QJS {

class BinaryFile : public QObject
{
	Q_OBJECT

public:
	Q_ENUM(QIODevice::OpenModeFlag)

	Q_INVOKABLE BinaryFile(const QString &filePath) {
		m_file = new QFile(filePath);	
	}
	
	~BinaryFile() override {
		close();
	}

	Q_INVOKABLE void open (QIODevice::OpenModeFlag mode = QIODevice::ReadOnly) {
		if (!m_file->open(mode)){
			qjsEngine(this)->throwError(m_file->errorString());
			m_file = nullptr;
		}
	}

	Q_INVOKABLE QString filePath() const {
		return QFileInfo(*m_file).absoluteFilePath();
	}

	Q_INVOKABLE bool atEof() const {
		if (!openCheck()){
			return false;
		}
		return m_file->atEnd();
	}

	Q_INVOKABLE qint64 size() const {
		if (!openCheck()) {
			return 0;
		}
		return m_file->size();
	}

	Q_INVOKABLE qint64 pos() const {
		if (!openCheck()) {
			return 0;
		}
		return m_file->pos();
	}

	Q_INVOKABLE void resize(qint64 size) {
		if (openCheck()) {
			m_file->resize(size);
		}
	}

	Q_INVOKABLE void seek(qint64 pos) {
		if (openCheck()) {
			m_file->seek(pos);
		}
	}

	Q_INVOKABLE QByteArray read(qint64 size) {
		if (!openCheck()) {
			return QByteArray();
		}
		return m_file->read(size);
	}

	Q_INVOKABLE void write(const QByteArray &data) {
		if (openCheck()) {
			m_file->write(data);
		}
	}

	Q_INVOKABLE void close() {
		delete m_file;
		m_file = nullptr;
	}

	// useful extras

	Q_INVOKABLE QByteArray readAll() {
		if (!openCheck()) {
			return QByteArray();
		}
		return m_file->readAll();
	}

private:
	QFile *m_file = nullptr;

	bool openCheck() const {
		if (!m_file){
			qjsEngine(this)->throwError("File is not open.");
			return false;
		}
		return true;
	}
};

} // end namespace Qbs4QJS