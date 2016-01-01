#ifndef COMPORT_H
#define COMPORT_H

#include <QtWidgets/QMainWindow>

#include "ui_comport.h"
#include "sendThread.h"
#include "receThread.h"
#include "zigbeeid.h"


class comPort : public QMainWindow
{
    Q_OBJECT

public:
	comPort(QWidget *parent = 0);
	~comPort();

protected:
	void mousePressEvent(QMouseEvent *event);		
	void mouseMoveEvent(QMouseEvent *event);

public slots:

	//-------------------------------------------------
	void slotSend();
	void slotSendTextArea(const QString &s);
	void slotSetManacher(const QString &s);
	void slotSetSendButton();
	void soltReceStartButton();
	void soltReceStopButton();
	void slotReceTextArea(const QString &s);

	//-------------------------------------------------

	void slotSetTemperature(const int &temper);
	void slotSetHumidity(const int &temper);
	void slotSetLight(const int &temper);
	void slotSetVibration();
	void slotExit();

	//-------------------------------------------------

	void slotChangeToType0();
	void slotChangeToType1();
	void slotChangeToType2();

private:

	Ui::comPortClass ui;

	sendThread sThread;
	receThread rThread;

	QPoint  mousePrepos;

};

#endif // COMPORT_H
