#pragma once

#include <QDialog>
#include "ui_DialogGetName.h"

class DialogGetName : public QDialog//继承自QDialog可使用阻塞窗口
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
