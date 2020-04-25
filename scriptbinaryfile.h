#include <QObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QFileInfo>

class ScriptBinaryFile : public QObject
{
    Q_OBJECT

public:
    Q_ENUM(QIODevice::OpenModeFlag)

    Q_INVOKABLE ScriptBinaryFile(const QString &filePath, QIODevice::OpenModeFlag mode = QIODevice::ReadOnly) {
       m_file = new QFile(filePath);
       m_file->open(mode);
    }
    
    ~ScriptBinaryFile() override {
        close();
    }

    Q_INVOKABLE QString filePath() const {
        return QFileInfo(*m_file).absoluteFilePath();
    }

    Q_INVOKABLE bool atEof() const {
        return m_file->atEnd();
    }

    Q_INVOKABLE qint64 size() const {
        return m_file->size();
    }

    Q_INVOKABLE qint64 pos() const {
        return m_file->pos();
    }

    Q_INVOKABLE void resize(qint64 size) {
        m_file->resize(size);
    }

    Q_INVOKABLE void seek(qint64 pos) {
        m_file->seek(pos);
    }

    Q_INVOKABLE QByteArray read(qint64 size) {
        return m_file->read(size);
    }

    Q_INVOKABLE void write(const QByteArray &data) {
        m_file->write(data);
    }

    Q_INVOKABLE void close() {
        m_file->close();
        delete m_file;
        m_file = nullptr;
    }

private:
    QFile *m_file = nullptr;
};