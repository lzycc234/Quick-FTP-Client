#pragma once

#include <QDialog>
#include "ui_DialogConnect.h"

class DialogConnect : public QDialog//�̳���QDialog��ʹ����������
{
	Q_OBJECT
public:
	DialogConnect(QWidget *parent = Q_NULLPTR);
	~DialogConnect();
	int exec();//ִ����������
	QString getAddress()const;//��ȡ��ַ
	int getPort()const;//��ȡ�˿�
	QString getUser()const;//��ȡ�û���
	QString getPass()const;//��ȡ����
	bool isAnonymous()const;//�Ƿ�Ϊ����ģʽ
private slots:
	void slotPushButtonLoginClicked();
	void slotCheckBoxShowPassStateChanged(int state);
	void slotCheckBoxAnonymousChanged(int state);
private:
	Ui::DialogConnect ui;
	bool mIsAccecpted;
};
