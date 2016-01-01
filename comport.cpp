#include "comport.h"

comPort::comPort(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowOpacity(0.9f);

	ui.checkHeat->setEnabled(false);
	ui.checkLight->setEnabled(false);
	ui.checkSmoke->setEnabled(false);

	ui.comPort1->addItem("COM1");
	ui.comPort1->addItem("COM2");
	ui.comPort1->addItem("COM3");
	ui.comPort1->addItem("COM4");

	ui.comPort2->addItem("COM1");
	ui.comPort2->addItem("COM2");
	ui.comPort2->addItem("COM3");
	ui.comPort2->addItem("COM4");

	ui.comRate->addItem("9600");
	ui.comRate->addItem("19200");
	ui.comRate->addItem("38400");
	ui.comRate->addItem("57600");
	ui.comRate->addItem("115200");

	ui.comDataBits->addItem("1");
	ui.comDataBits->addItem("2");
	ui.comDataBits->addItem("4");
	ui.comDataBits->addItem("8");

	ui.comType1->addItem("HEX");
	ui.comType1->addItem("ASCII");


	ui.comType2->addItem("HEX");
	ui.comType2->addItem("ASCII");


	QObject::connect(ui.btnSend, SIGNAL(clicked()), this, SLOT(slotSend()));

	QObject::connect(&sThread, SIGNAL(response(QString)), this, SLOT(slotSendTextArea(QString)));

	QObject::connect(&rThread, SIGNAL(response(QString)), this, SLOT(slotReceTextArea(QString)));

	QObject::connect(&rThread, SIGNAL(setManacher(QString)), this, SLOT(slotSetManacher(QString)));


	QObject::connect(&sThread, SIGNAL(setSendButton()), this, SLOT(slotSetSendButton()));

	QObject::connect(ui.btnRStart, SIGNAL(clicked()), this, SLOT(soltReceStartButton()));

	QObject::connect(ui.btnRStop, SIGNAL(clicked()), this, SLOT(soltReceStopButton()));

	QObject::connect(&rThread, SIGNAL(setTemper(int)), this, SLOT(slotSetTemperature(int)));
	QObject::connect(&rThread, SIGNAL(setHumidity(int)), this, SLOT(slotSetHumidity(int)));
	QObject::connect(&rThread, SIGNAL(setLight(int)), this, SLOT(slotSetLight(int)));
	QObject::connect(&rThread, SIGNAL(setVibration()), this, SLOT(slotSetVibration()));

	QObject::connect(ui.btnRunType1, SIGNAL(clicked()), this, SLOT(slotChangeToType1()));
	QObject::connect(ui.btnRunType0, SIGNAL(clicked()), this, SLOT(slotChangeToType0()));
	QObject::connect(ui.btnRunType2, SIGNAL(clicked()), this, SLOT(slotChangeToType2()));


	QObject::connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(slotExit()));

	setWindowFlags(Qt::FramelessWindowHint);

	ui.btnRStart->setEnabled(true);
	ui.btnRStop->setEnabled(false);

	//LCD
}

void comPort::slotChangeToType0(){

	rThread.runType = 0;

	ui.checkLight->setCheckState(Qt::Unchecked);
	ui.checkHeat->setCheckState(Qt::Unchecked);

	qDebug() << rThread.runType;

}
void comPort::slotChangeToType1(){

	if (rThread.runType & (1 << 1)){
		
		rThread.runType &= ~(unsigned int)(1 << 1);

		ui.checkHeat->setCheckState(Qt::Unchecked);

	}
	else{
		rThread.runType |= (1 << 1);
		ui.checkHeat->setCheckState(Qt::Checked);
	}

	qDebug() << rThread.runType;

}
void comPort::slotChangeToType2(){

	if (rThread.runType & (1 << 2)){

		rThread.runType &= ~(unsigned int)(1 << 2);

		ui.checkLight->setCheckState(Qt::Unchecked);
	}
	else{

		ui.checkLight->setCheckState(Qt::Checked);
		rThread.runType |= (1 << 2);
	}

	qDebug() << rThread.runType;

}

void comPort::slotSendTextArea(const QString &s){

	ui.areaSend->append(s);

}

void comPort::slotReceTextArea(const QString &s){

	ui.areaRece->append(s);

}


comPort::~comPort()
{

}

void comPort::slotSend(){

	QString port = ui.comPort1->currentText();
	QString sendMessage = ui.txtSend->text();

	ui.txtSend->clear();

	ui.btnSend->setEnabled(false);

	QString sType = ui.comType1->currentText();

	if (sType == "HEX")
		sThread.readyRun(port, sendMessage, 100, 0);

	else if (sType == "ASCII")
		sThread.readyRun(port, sendMessage, 100, 1);
}


void comPort::mousePressEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void comPort::mouseMoveEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		if (posX < 0) posX = 0;
		if (posY < 0) posY = 0;

		move(QPoint(posX, posY));
		mousePrepos = mousePos;
	}
}

void comPort::slotSetSendButton(){

	ui.btnSend->setEnabled(true);
}

void comPort::soltReceStartButton(){

	QString portName = ui.comPort2->currentText();

    bool ok;
    int waitTime = ui.txtTime2->text().toInt(&ok, 10);

	QString sType = ui.comType2->currentText();

	qDebug() << sType;

	int rate = ui.comRate->currentText().toInt();

	if (sType == "HEX")
		rThread.readyRun(portName, waitTime, 0, rate);

	else if (sType == "ASCII")
		rThread.readyRun(portName, waitTime, 1, rate);

	ui.btnRStart->setEnabled(false);
	ui.btnRStop->setEnabled(true);

	ui.comPort2->setEnabled(false);
	ui.txtTime2->setEnabled(false);
	ui.comType2->setEnabled(false);

}

void comPort::soltReceStopButton(){

	rThread.readyStop();

	ui.btnRStart->setEnabled(true);
	ui.btnRStop->setEnabled(false);

	ui.txtTime2->setEnabled(true);
	ui.comPort2->setEnabled(true);
	ui.comType2->setEnabled(true);

}

//400C010201001A000B001C01
void comPort::slotSetTemperature(const int &temper){

	ui.ledTemper->display(temper);

}

void comPort::slotSetHumidity(const int &temper){

	ui.ledHumid->display(temper);
}

void comPort::slotSetLight(const int &temper){

	ui.ledLight->display(temper);

}

void comPort::slotExit(){

	exit(0);

}

void comPort::slotSetVibration(){

	int number = ui.ledVibration->intValue();

	++number;

	ui.ledVibration->display(number);
}
void comPort::slotSetManacher(const QString &s){

	ui.labManStatus->setText(s);

}