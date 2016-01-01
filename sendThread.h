#pragma once

#include "headFile.h"

class sendThread : public QThread
{
	Q_OBJECT
public:
	sendThread();
	~sendThread();
	void run();
	void readyRun(QString &portName, QString &sendMessage, int timeOut, int type);
	QByteArray toHex(QString &str);

	int hexMap(char c);

signals:
	void response(const QString &s);
	void setSendButton();

private:
	QString sendMessage;
	QString portName;

	int waitTime;
	int type;
	int rate;
};

