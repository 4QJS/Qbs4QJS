#include<iostream>

#include <QCoreApplication>
#include <QJSEngine>
#include <QFile>
#include <QString>
#include <QDebug>

#include "binaryfile.h"
#include "environment.h"
#include "file.h"
#include "fileinfo.h"
#include "process.h"
#include "temporarydir.h"
#include "textfile.h"

using namespace std;
int main(int argc, char *argv[])
{
	if (argc < 2) {
		cerr << "Usage: Qbs4QJS <script.js>\n";
		return 1;
	}
	
	QCoreApplication app(argc, argv);
	QJSEngine jsEngine;
	jsEngine.installExtensions(QJSEngine::AllExtensions);

	QString fileName = argv[1];
	QFile scriptFile(fileName);
	if (!scriptFile.open(QIODevice::ReadOnly)){
		qDebug() << "Could not open file " << fileName;
		return 1;
	}
	QTextStream stream(&scriptFile);
	QString contents = stream.readAll();
	scriptFile.close();

	Qbs4QJS::BinaryFile sfbin(&jsEngine);
	Qbs4QJS::Environment senv(&jsEngine);
	Qbs4QJS::File sfs(&jsEngine);
	Qbs4QJS::FileInfo sfi(&jsEngine);
	Qbs4QJS::Process sps(&jsEngine);
	Qbs4QJS::TemporaryDir stmp(&jsEngine);
	Qbs4QJS::TextFile sftxt(&jsEngine);

	QJSValue result = jsEngine.evaluate(contents, fileName);

	if (result.isError()) {
		qDebug()
			<< "Uncaught exception at line"
			<< result.property("lineNumber").toInt()
			<< ":" << result.toString();
		return 1;
	}

	return 0;
}
