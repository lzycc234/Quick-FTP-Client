#include "DialogConnect.h"

DialogConnect::DialogConnect(QWidget *parent)
	: QDialog(parent), mIsAccecpted(nullptr)
{
	ui.setupUi(this);
	connect(ui.pushButtonLogin, &QPushButton::clicked, this, &DialogConnect::slotPushButtonLoginClicked);
	connect(ui.checkBoxShowPass, &QCheckBox::stateChanged, this, &DialogConnect::slotCheckBoxShowPassStateChanged);
	connect(ui.checkBoxAnonymous, &QCheckBox::stateChanged, this, &DialogConnect::slotCheckBoxAnonymousChanged);
}

DialogConnect::~DialogConnect()
{
}

int DialogConnect::exec()
{
	return mIsAccecpted = QDialog::exec();
}

QString DialogConnect::getAddress() const
{
	return ui.lineEditAddress->text();;
}

int DialogConnect::getPort() const
{
	return ui.lineEditPort->text().toInt();
}

QString DialogConnect::getUser() const
{
	return ui.lineEditUser->text();
}

QString DialogConnect::getPass() const
{
	return ui.lineEditPass->text();
}

bool DialogConnect::isAnonymous() const
{
	return ui.checkBoxAnonymous->isChecked();
}

void DialogConnect::slotCheckBoxShowPassStateChanged(int state)
{
	if (state == Qt::CheckState::Checked)
	{
		ui.lineEditPass->setEchoMode(QLineEdit::EchoMode::Normal);
	}
	else if (state == Qt::CheckState::Unchecked)
	{
		ui.lineEditPass->setEchoMode(QLineEdit::EchoMode::Password);
	}
}

void DialogConnect::slotCheckBoxAnonymousChanged(int state)
{
	if (state == Qt::CheckState::Checked)
	{
		ui.lineEditUser->setEnabled(false);
		ui.lineEditPass->setEnabled(false);
		ui.checkBoxShowPass->setEnabled(false);
	}
	else if (state == Qt::CheckState::Unchecked)
	{
		ui.lineEditUser->setEnabled(true);
		ui.lineEditPass->setEnabled(true);
		ui.checkBoxShowPass->setEnabled(true);
	}
}

void DialogConnect::slotPushButtonLoginClicked()
{
	accept();
}
