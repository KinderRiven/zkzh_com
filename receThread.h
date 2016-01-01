#pragma once
#include "headFile.h"
class receThread :
	public QThread
{
	Q_OBJECT
public:
	receThread();
	~receThread();
	void run();
    void readyRun(QString &portName, int waitTime, int type, int rate);
	void readyStop();
	QString toHex(QByteArray byteArray);
	void Manager(QByteArray &byteArray, QSerialPort &serial);

	void getTemperature(QByteArray &byteArray, QSerialPort &serial);
	void getHumidity(QByteArray &byteArray, QSerialPort &serial);
	void getLight(QByteArray &byteArray, QSerialPort &serial);
	void getInfrared(QByteArray &byteArray, QSerialPort &serial);
	void responseMessage();

	//控制电机
	QByteArray postMachine(char c);
	void startMachine(char c, QSerialPort &serial);

	//控制照明
	QByteArray postLight(char c);
	void startLight(char c, QSerialPort &serial);

	int runType;

signals:
	void setVibration();
	void response(const QString &s);
	void setTemper(const int &temper);
	void setHumidity(const int &temper);
	void setLight(const int &temper);
	void setManacher(const QString &s);

private:
	QString portName;
	bool quit;
	int waitTime;
	int type;
	int rate;
};

