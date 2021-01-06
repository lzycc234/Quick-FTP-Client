#pragma once

#include <QDialog>
#include "ui_DialogConnect.h"

class DialogConnect : public QDialog
{
	Q_OBJECT
	//friend class FTPClient;
public:
	DialogConnect(QWidget *parent = Q_NULLPTR);
	~DialogConnect();
	int exec();
	QString getAddress()const;
	int getPort()const;
	QString getUser()const;
	QString getPass()const;
	bool isAnonymous()const;
private slots:
	void slotPushButtonLoginClicked();
	void slotCheckBoxShowPassStateChanged(int state);
	void slotCheckBoxAnonymousChanged(int state);
private:
	Ui::DialogConnect ui;
	bool mIsAccecpted;
};
