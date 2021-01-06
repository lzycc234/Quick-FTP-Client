#include "DialogGetName.h"

DialogGetName::DialogGetName(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonConfirm, &QPushButton::clicked, this, &DialogGetName::slotPushButtonConfirmClicked);
	connect(ui.pushButtonCancel, &QPushButton::clicked, this, &DialogGetName::slotPushButtonCancelClicked);
}

DialogGetName::~DialogGetName()
{
}

QString DialogGetName::getName() const
{
	return ui.lineEditNewName->text();
}

void DialogGetName::slotPushButtonConfirmClicked()
{
	accept();
}

void DialogGetName::slotPushButtonCancelClicked()
{
	reject();
}
