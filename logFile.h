#ifndef _LOG_TEXT_H
#define _LOG_TEXT_H

#include <qfile.h>
#include <QTextStream>


class LOG_TEXT{

public:
	void loadFile(QString path);
	bool writeInFile(QString data);
	LOG_TEXT(QString path = "log.txt");
	~LOG_TEXT();

private:
	QFile file;

};
#endif