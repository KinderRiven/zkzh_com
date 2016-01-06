#include "logFile.h"


LOG_TEXT::LOG_TEXT(QString path){

	loadFile(path);

}
LOG_TEXT::~LOG_TEXT(){

	if (file.isOpen())
		file.close();

}
void LOG_TEXT::loadFile(QString path){

	file.setFileName(path);

	file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

}

bool LOG_TEXT::writeInFile(QString data){

	if (!file.isOpen()){
		return false;
	}

	QTextStream qts(&file);
	qts << data << endl;

	return true;
}