#pragma once

#include <QDialog>
#include "ui_DialogGetName.h"

class DialogGetName : public QDialog//�̳���QDialog��ʹ����������
{
	Q_OBJECT

public:
	DialogGetName(QWidget *parent = Q_NULLPTR);
	~DialogGetName();
	QString getName()const;
private slots:
	void slotPushButtonConfirmClicked();
	void slotPushButtonCancelClicked();
private:
	Ui::DialogGetName ui;
};
