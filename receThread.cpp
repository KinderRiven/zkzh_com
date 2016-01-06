#include "receThread.h"


receThread::receThread(){

    waitTime = 1000;

	runType = 0;

	runManache = 20;

}


receThread::~receThread(){

}

void receThread::readyRun(QString &portName, int waitTime, int type, int rate){

	this->portName = portName;

    this->waitTime = waitTime;

	this->type = type;

	this->rate = rate;

	quit = false;

	start();
}

void receThread::readyStop(){

	quit = true;

}
QString receThread::toHex(QByteArray byteArray){

    QString receMessage = "";

    for(int i = 0; i < byteArray.size(); i++){

        unsigned char iTemp = byteArray.at(i);

        receMessage += QString::number(iTemp & 0xff, 16).toUpper();
		
		receMessage += " ";

    }

    return receMessage;
}

//电机
QByteArray receThread::postMachine(char c){


	QByteArray byteArray;

	//head
	byteArray.append(0x40);
	byteArray.append(0x06);
	byteArray.append(0x01);
	byteArray.append(0x06);
	
	char all = 0x40 + 0x06 + 0x01 + 0x06 + c;

	byteArray.append(c);

	byteArray.append(all);

	return byteArray;
}

void receThread::startMachine(char c, QSerialPort &serial){

	QByteArray byteArray = postMachine(c);

	serial.write(byteArray);
	if (serial.waitForBytesWritten(1000)){

	}

	if (c == 0x0c){
		emit this->setManacher(QString("STOP"));
	}
	if (c == 0x0a){

		emit this->setManacher(QString("Running"));
	}
	qDebug() << "Manache ...";

}

//照明
QByteArray receThread::postLight(char c){

	QByteArray byteArray;

	//head
	byteArray.append(0x40);
	byteArray.append(0x06);
	byteArray.append(0x01);
	byteArray.append(0x09);

	char all = 0x40 + 0x06 + 0x01 + 0x09 + c;

	byteArray.append(c);

	byteArray.append(all);

	return byteArray;

}

void receThread::startLight(char c, QSerialPort &serial){

	QByteArray byteArray = postLight(c);

	serial.write(byteArray);

	if (serial.waitForBytesWritten(1000)){



	}
	qDebug() << "Light ...";

}
//温度
void receThread::getTemperature(QByteArray &byteArray, QSerialPort &serial){

	int temper = 256 * byteArray[5] + byteArray[6];

	qDebug() << "Temperature " << temper;

	QDateTime date = QDateTime::currentDateTime();

	QString data = date.toString() + " The temperature:" + QString::number(temper);

	log.writeInFile(data);

	if (temper >= runManache){
		
		if (runType & (1 << 1)){
			startMachine(0x0a, serial);
		}
	}

	else if (temper < runManache){

		if (runType & (1 << 1)){

			startMachine(0x0c, serial);
		}

	}

	emit this->setTemper(temper);
}
//湿度
void receThread::getHumidity(QByteArray &byteArray, QSerialPort &serial){

	int temper = 256 * byteArray[7] + byteArray[8];

	QDateTime date = QDateTime::currentDateTime();

	QString data = date.toString() + " The Humidity:" + QString::number(temper);

	log.writeInFile(data);

	qDebug() << "Humidity" << temper;

	emit this->setHumidity(temper);
}
//光照
void receThread::getLight(QByteArray &byteArray, QSerialPort &serial){

	int temper = (256 * byteArray[9] + byteArray[10]) * 3012.9 / (32768 * 4);

	qDebug() << temper;

	QDateTime date = QDateTime::currentDateTime();

	QString data = date.toString() + " The light:" + QString::number(temper);

	log.writeInFile(data);

	qDebug() << "Light " << temper;

	emit this->setLight(temper);
}
//红外线
void receThread::getInfrared(QByteArray &byteArray, QSerialPort &serial){

	if (runType & (1 << 2)){
		
		if ((int)byteArray[5] == 0x00){

			startLight(0x00, serial);

		}
		else if ((int)byteArray[5] == 0x01){

			startLight(0x09, serial);
		}

	}
}
//管理

//40 C 1 2 1 0 14 0 20 1E 26 C8
void receThread::Manager(QByteArray &byteArray, QSerialPort &serial){

	int Size = byteArray.size();

	qDebug() << Size;

	//
	if (runType == 0){

		startMachine(0x0c, serial);

	}
	switch (byteArray[3]){

	case zigBee::THL:

		if ((int)byteArray[1] == 0x0C){
			getTemperature(byteArray, serial);
			getLight(byteArray, serial);
			getHumidity(byteArray, serial);
		}

		break;

	case zigBee::Vibration:

		qDebug() << "Vibration";
		if ((int)byteArray[5] == 0x01)
			emit this->setVibration();
		break;

	case zigBee::Smoke:

		qDebug() << "Smoke";
		break;

	//红外线
	case zigBee::Infrared:

		if ((int)byteArray[1] == 0x07){

			getInfrared(byteArray, serial);
			qDebug() << "Infrared";

		}
		break;

	case zigBee::Motor:

		
		qDebug() << "Motor";
		break;

	case zigBee::Touch:

		qDebug() << "Touch";
		break;

	case zigBee::Wave:

		qDebug() << "Wave";
		break;

	case zigBee::PWM:

		qDebug() << "PWM";
		break;

	case zigBee::Relay:

		qDebug() << "Relay";
		break;

	case zigBee::Elect:

		qDebug() << "Elec";
		break;

	case zigBee::Voltage:

		qDebug() << "Voltage";
		break;

	case zigBee::VoltageSend:

		qDebug() << "VoltageSend";
		break;

	default:
		break;
	}

}

void receThread::run(){
	
	QSerialPort serial;

	serial.setPortName(portName);

	if (rate == 9600)
		serial.setBaudRate(QSerialPort::Baud9600);
	if (rate == 19200)
		serial.setBaudRate(QSerialPort::Baud19200);
	if (rate == 38400)
		serial.setBaudRate(QSerialPort::Baud38400);
	if (rate == 57600)
		serial.setBaudRate(QSerialPort::Baud57600);
	if (rate == 115200)
		serial.setBaudRate(QSerialPort::Baud115200);

	qDebug() << rate;

	if (!serial.open(QIODevice::ReadWrite)){

		qDebug() << "NO";
	}
	else {
		qDebug() << "YES";
	}
	
	while (!quit){

        if(serial.waitForReadyRead(waitTime)){

			QByteArray byteArray = serial.readAll();

			QByteArray allByte;

			allByte.append(byteArray);

			QString receMessage = "[Receive]:";

			if (type == 0)
				receMessage += toHex(byteArray);
			if (type == 1)
				receMessage += QString(byteArray);

            while(serial.waitForReadyRead(10)){

                byteArray = serial.readAll();

				allByte.append(byteArray);

				if (type == 0)
					receMessage += toHex(byteArray);
				if (type == 1)
					receMessage += QString(byteArray);
            }

			Manager(allByte, serial);

            emit this->response(receMessage);
        }
	}
}
