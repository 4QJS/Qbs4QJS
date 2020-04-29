#include <QObject>
#include <QString>

namespace Qbs4QJS {

class PropertyList : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE PropertyList() {
	}
	
	~PropertyList() override {
	}

	Q_INVOKABLE bool isEmpty() const {}

	Q_INVOKABLE void clear() {}

	Q_INVOKABLE void readFromObject(const QScriptValue &value) {}

	Q_INVOKABLE void readFromString(const QString &input){}

	Q_INVOKABLE void readFromFile(const QString &filePath) {}

	Q_INVOKABLE void readFromData(const QByteArray &data) {}

	Q_INVOKABLE void writeToFile(const QString &filePath, const QString &plistFormat) {}

	Q_INVOKABLE QScriptValue format() const {}

	Q_INVOKABLE QScriptValue toObject() const {}

	Q_INVOKABLE QString toString(const QString &plistFormat) const {}

	Q_INVOKABLE QString toXMLString() const {}

	Q_INVOKABLE QString toJSON(const QString &style = QString()) const {}

};

} // end namespace Qbs4QJS