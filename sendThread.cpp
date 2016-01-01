#include "sendThread.h"


sendThread::sendThread(){

	sendMessage = "Hello World!";
	portName = "com1";

}


sendThread::~sendThread(){


}

void sendThread::readyRun(QString &portName, QString &sendMessage, int waitTime, int type){
	
	this->sendMessage = sendMessage;
	this->portName = portName;
	this->waitTime = waitTime;
	this->type = type;
	start();
}
int sendThread::hexMap(char c){

	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;

	return 0;
}
QByteArray sendThread::toHex(QString &str){
	
	QByteArray byteArray;

	string sstr = str.toStdString();

	qDebug() << sstr.size() << endl;

	int value = -1;

	for (int i = 0; i < sstr.size(); i++){
		
		if (sstr[i] == ' ' && value != -1){
			byteArray.append(value);
			value = -1;
		}
		if (sstr[i] != ' '){
			if (value == -1)
				value = hexMap(sstr[i]);
			else
				value = value * 16 + hexMap(sstr[i]);
		}
	}
	if (value != -1)
		byteArray.append(value);

	qDebug() << byteArray.size();

	return byteArray;

}
void sendThread::run(){
	
	QSerialPort serial;
	serial.setPortName(portName);
	
	if (!serial.open(QIODevice::ReadWrite)){

		qDebug() << "NO";
	}
	else {
		qDebug() << "YES";
	}

	QByteArray byteArray;


	if (type == 0)
		byteArray = toHex(sendMessage);

	if (type == 1)
		byteArray = sendMessage.toLocal8Bit();

	serial.write(byteArray);

	if (serial.waitForBytesWritten(waitTime)){
		
		emit this->response(sendMessage);

	}

	emit this->setSendButton();
}