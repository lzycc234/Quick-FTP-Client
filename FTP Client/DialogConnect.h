#pragma once

#include <QDialog>
#include "ui_DialogConnect.h"

class DialogConnect : public QDialog//继承自QDialog可使用阻塞窗口
{
	Q_OBJECT
public:
	DialogConnect(QWidget *parent = Q_NULLPTR);
	~DialogConnect();
	int exec();//执行阻塞窗口
	QString getAddress()const;//获取地址
	int getPort()const;//获取端口
	QString getUser()const;//获取用户名
	QString getPass()const;//获取密码
	bool isAnonymous()const;//是否为匿名模式
private slots:
	void slotPushButtonLoginClicked();
	void slotCheckBoxShowPassStateChanged(int state);
	void slotCheckBoxAnonymousChanged(int state);
private:
	Ui::DialogConnect ui;
	bool mIsAccecpted;
};
