#include "FTPClient.h"
#include <QtDebug>
#include <QMessageBox>
#include <QEventLoop>

FTPClient::FTPClient(QWidget *parent)
	: QMainWindow(parent), 
	mLabelFtpUser(new QLabel(QString("User:%1").arg("NULL"), this)),
	mLabelFtpState(new QLabel(QString("Status:%1").arg("Unconnected"), this)),
	mLabelFtpOpState(new QLabel(QString("Operation:%1").arg("NULL"), this)),
	mFtpProgressBar(new QProgressBar(this)), 
	mFtp(nullptr), 
	mRemoteCurrentDir(QDir::separator())
{
    ui.setupUi(this);
	ui.statusBar->addWidget(mLabelFtpUser);
	ui.statusBar->addWidget(mLabelFtpState);
	ui.statusBar->addWidget(mLabelFtpOpState);
	ui.statusBar->addPermanentWidget(mFtpProgressBar);
	mDialogConnect.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
	mDialogGetName.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
	initListWidgetFileLocal();
	initMenuBar();
	initPushButtons();

	connect(ui.listWidgetFileLocal, &QListWidget::itemClicked, this, &FTPClient::slotListWidgetFileLocalItemClicked);
	connect(ui.listWidgetFileLocal, &QListWidget::itemDoubleClicked, this, &FTPClient::slotListWidgetFileLocalItemDoubleClicked);
	connect(ui.lineEditPathLocal, &QLineEdit::returnPressed, this, &FTPClient::slotLineEditPathLocalReturnPressed);
	connect(ui.listWidgetFileRemote, &QListWidget::itemClicked, this, &FTPClient::slotListWidgetFileRemoteItemClicked);
	connect(ui.listWidgetFileRemote, &QListWidget::itemDoubleClicked, this, &FTPClient::slotListWidgetFileRemoteItemDoubleClicked);
	connect(ui.lineEditPathRemote, &QLineEdit::returnPressed, this, &FTPClient::slotLineEditPathRemoteReturnPressed);
}

void FTPClient::initListWidgetFileLocal()
{

	refreshFileInfoListLocal();
}

void FTPClient::initMenuBar()
{
	QAction * actionConnect = new QAction(QString::fromLocal8Bit("����"));
	actionConnect->setIcon(style()->standardIcon(QStyle::QStyle::SP_MediaPlay));
	ui.menuSession->addAction(actionConnect);
	connect(actionConnect, &QAction::triggered, this, &FTPClient::slotActionConnectTriggered);

	QAction * actionDisconnect = new QAction(QString::fromLocal8Bit("�Ͽ�"));
	actionDisconnect->setIcon(style()->standardIcon(QStyle::QStyle::SP_MediaStop));
	ui.menuSession->addAction(actionDisconnect);
	connect(actionDisconnect, &QAction::triggered, this, &FTPClient::slotActionDisconnectTriggered);

	QAction * actionQuit = new QAction(QString::fromLocal8Bit("�˳�"));
	actionQuit->setIcon(style()->standardIcon(QStyle::QStyle::SP_BrowserStop));
	ui.menuSession->addAction(actionQuit);
	connect(actionQuit, &QAction::triggered, this, &FTPClient::slotActionQuitTriggered);

}

void FTPClient::initPushButtons()
{
	//connect(ui.pushButtonConnect, &QPushButton::clicked, this, &FTPClient::slotPushButtonConnectClicked);
	//connect(ui.pushButtonDisconnect, &QPushButton::clicked, this, &FTPClient::slotPushButtonDisconnectClicked);
	ui.pushButtonUpload->setIcon(style()->standardIcon(QStyle::QStyle::SP_ArrowUp));
	connect(ui.pushButtonUpload, &QPushButton::clicked, this, &FTPClient::slotPushButtonUploadClicked);

	ui.pushButtonDownload->setIcon(style()->standardIcon(QStyle::QStyle::SP_ArrowDown));
	connect(ui.pushButtonDownload, &QPushButton::clicked, this, &FTPClient::slotPushButtonDownloadClicked);

	ui.pushButtonParentDirLocal->setIcon(style()->standardIcon(QStyle::QStyle::SP_ArrowLeft));
	connect(ui.pushButtonParentDirLocal, &QPushButton::clicked, this, &FTPClient::slotPushButtonParentDirLocalClicked);

	ui.pushButtonParentDirRemote->setIcon(style()->standardIcon(QStyle::QStyle::SP_ArrowLeft));
	connect(ui.pushButtonParentDirRemote, &QPushButton::clicked, this, &FTPClient::slotPushButtonParentDirRemoteClicked);

	ui.pushButtonRenameLocal->setIcon(style()->standardIcon(QStyle::QStyle::SP_DialogResetButton));
	connect(ui.pushButtonRenameLocal, &QPushButton::clicked, this, &FTPClient::slotPushButtonRenameLocalClicked);

	ui.pushButtonDeleteLocal->setIcon(style()->standardIcon(QStyle::QStyle::SP_TrashIcon));
	connect(ui.pushButtonDeleteLocal, &QPushButton::clicked, this, &FTPClient::slotPushButtonDeleteLocalClicked);

	ui.pushButtonRenameRemote->setIcon(style()->standardIcon(QStyle::QStyle::SP_DialogResetButton));
	connect(ui.pushButtonRenameRemote, &QPushButton::clicked, this, &FTPClient::slotPushButtonRenameRemoteClicked);

	ui.pushButtonDeleteRemote->setIcon(style()->standardIcon(QStyle::QStyle::SP_TrashIcon));
	connect(ui.pushButtonDeleteRemote, &QPushButton::clicked, this, &FTPClient::slotPushButtonDeleteRemoteClicked);
}

void FTPClient::initFtp()
{
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpCommandFinished);
	connect(mFtp, &QFtp::commandStarted, this, &FTPClient::slotFtpCommandStarted);
	connect(mFtp, &QFtp::dataTransferProgress, this, &FTPClient::slotFtpDataTransferProgress);
	connect(mFtp, &QFtp::done, this, &FTPClient::slotFtpDone);
	connect(mFtp, &QFtp::listInfo, this, &FTPClient::slotFtpListInfo);
	connect(mFtp, &QFtp::rawCommandReply, this, &FTPClient::slotFtpRawCommandReply);
	connect(mFtp, &QFtp::readyRead, this, &FTPClient::slotFtpReadyRead);
	connect(mFtp, &QFtp::stateChanged, this, &FTPClient::slotFtpStateChanged);
}

void FTPClient::refreshFileInfoListLocal()
{
	mLocalDir.setFilter(QDir::NoDot | QDir::AllEntries);
	QFileInfoList fileInfoList = mLocalDir.entryInfoList();
	ui.listWidgetFileLocal->clear();

	for (int i = 0; i < fileInfoList.count(); i++)
	{
		QFileInfo curFileInfo = fileInfoList.at(i);
		if (curFileInfo.isDir())
		{
			QListWidgetItem * newDirItem = new QListWidgetItem(curFileInfo.fileName());
			newDirItem->setIcon(style()->standardIcon(QStyle::QStyle::SP_DirIcon));
			ui.listWidgetFileLocal->addItem(newDirItem);
		}
		else
		{
			QListWidgetItem * newFileItem = new QListWidgetItem(curFileInfo.fileName());
			newFileItem->setIcon(style()->standardIcon(QStyle::QStyle::SP_FileIcon));
			ui.listWidgetFileLocal->addItem(newFileItem);
		}
	}
	ui.lineEditPathLocal->setText(mLocalDir.absolutePath());
	ui.lineEditPathLocal->setCursorPosition(0);
}

void FTPClient::refreshFileInfoListRemote()
{
	clearFileInfoListsRemote();
	mFtp->list();
}

void FTPClient::clearFileInfoListsRemote()
{
	mIsRemoteItemDir.clear();
	ui.listWidgetFileRemote->clear();
}

void FTPClient::addFileInfoListRemote(const QUrlInfo & url)
{
	QString name = QString::fromLocal8Bit(url.name().toLatin1());
	
	if (url.isDir())
	{
		QListWidgetItem * newDirItem = new QListWidgetItem(name);
		newDirItem->setIcon(style()->standardIcon(QStyle::QStyle::SP_DirIcon));
		ui.listWidgetFileRemote->addItem(newDirItem);
		mIsRemoteItemDir[name] = true;
	}
	else
	{
		QListWidgetItem * newFileItem = new QListWidgetItem(name);
		newFileItem->setIcon(style()->standardIcon(QStyle::QStyle::SP_FileIcon));
		ui.listWidgetFileRemote->addItem(newFileItem);
		mIsRemoteItemDir[name] = false;
	}
}

void FTPClient::connectFtp()
{
	if (!mDialogConnect.exec())
	{
		return;
	}
	mAddress = mDialogConnect.getAddress();
	mPort = mDialogConnect.getPort();
	disconnectFtp();
	mFtp = new QFtp(this);
	initFtp();
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpLoggedIn);
	mFtp->connectToHost(mAddress, mPort);
	if (mDialogConnect.isAnonymous())
	{
		mFtp->login();
	}
	else
	{
		mUser = mDialogConnect.getUser();
		mPass = mDialogConnect.getPass();
		mFtp->login(mUser, mPass);
	}
}

void FTPClient::disconnectFtp()
{
	QPalette palette;
	if (mFtp)
	{
		mFtp->close();
		mFtp->deleteLater();
		mFtp = nullptr;
	}
	clearFileInfoListsRemote();
	mRemoteCurrentDir = QDir::separator();
	ui.lineEditPathRemote->clear();
	//ui.pushButtonDisconnect->setEnabled(false);
	ui.pushButtonUpload->setEnabled(false);
	ui.pushButtonDownload->setEnabled(false);
	//ui.pushButtonRenameLocal->setEnabled(false);
	//ui.pushButtonDeleteLocal->setEnabled(false);
	ui.pushButtonRenameRemote->setEnabled(false);
	ui.pushButtonDeleteRemote->setEnabled(false);
	ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��"));
	mLabelFtpUser->setText(QString("User:%1").arg("NULL"));
	palette.setColor(QPalette::WindowText, Qt::black);
	mLabelFtpState->setPalette(palette);
	mLabelFtpState->setText(QString("Status:%1").arg("Unconnected"));
}

void FTPClient::slotActionConnectTriggered()
{
	connectFtp();
}

void FTPClient::slotActionDisconnectTriggered()
{
	disconnectFtp();
}

void FTPClient::slotActionQuitTriggered()
{
	exit(0);
}

void FTPClient::slotPushButtonConnectClicked()
{
	connectFtp();
}

void FTPClient::slotPushButtonDisconnectClicked()
{
	disconnectFtp();
}

void FTPClient::slotPushButtonUploadClicked()
{
	QListWidgetItem * currentItem = ui.listWidgetFileLocal->currentItem();
	if (!currentItem)
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���ļ���"));
		return;
	}
	QString fileName = currentItem->text();
	QString filePath = mLocalDir.absolutePath() + QDir::separator() + fileName;
	if (QFileInfo(filePath).isDir())
	{
		return;
	}
	mFile.setFileName(filePath);
	if (mIsRemoteItemDir.contains(fileName))
	{
		if (QMessageBox::question(this,
			QString::fromLocal8Bit("ѯ��"),
			QString("%1:%2\n%3").arg(QString::fromLocal8Bit("�Ѵ���ͬ���ļ�")).arg(fileName).arg(QString::fromLocal8Bit("�Ƿ������"))) != QMessageBox::Yes)
		{
			return;
		}
	}
	if (!mFile.open(QIODevice::ReadOnly))
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޷��ϴ���ѡ�ļ���"));
		mFile.close();
		return;
	}
	QString uploadPath;
	if (mRemoteCurrentDir.length() == 1)
	{
		uploadPath = QString("%1%2").arg(mRemoteCurrentDir).arg(fileName);
	}
	else
	{
		uploadPath = QString("%1%2%3").arg(mRemoteCurrentDir).arg(QDir::separator()).arg(fileName);
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpUploadFinished);
	mFtp->put(&mFile, QString::fromLatin1(uploadPath.toLocal8Bit()));
}

void FTPClient::slotPushButtonDownloadClicked()
{
	QListWidgetItem * currentItem = ui.listWidgetFileRemote->currentItem();
	if (!currentItem)
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���ļ���"));
		return;
	}
	QString fileName = currentItem->text();
	QString filePath;
	if (mRemoteCurrentDir.length() == 1)
	{
		filePath = QString("%1%2").arg(mRemoteCurrentDir).arg(fileName);
	}
	else
	{
		filePath = QString("%1%2%3").arg(mRemoteCurrentDir).arg(QDir::separator()).arg(fileName);
	}
	if (mIsRemoteItemDir[fileName])
	{
		return;
	}

	QString downloadPath= mLocalDir.absolutePath() + QDir::separator() + fileName;
	mFile.setFileName(downloadPath);
	if (mFile.exists())
	{
		if (QMessageBox::question(this,
			QString::fromLocal8Bit("ѯ��"),
			QString("%1:%2\n%3").arg(QString::fromLocal8Bit("�Ѵ���ͬ���ļ�")).arg(fileName).arg(QString::fromLocal8Bit("�Ƿ�������أ�"))) != QMessageBox::Yes)
		{
			return;
		}
	}
	if (!mFile.open(QIODevice::WriteOnly))
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޷�������ѡ�ļ���"));
		mFile.close();
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDownloadFinished);
	mFtp->get(QString::fromLatin1(filePath.toLocal8Bit()), &mFile);
}

void FTPClient::slotPushButtonParentDirLocalClicked()
{	
	if (mLocalDir.cd(".."))
	{
		refreshFileInfoListLocal();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�Ѿ��ﵽ��Ŀ¼��"));
	}
}

void FTPClient::slotPushButtonParentDirRemoteClicked()
{
	if (mFtp->state() == QFtp::LoggedIn)
	{
		mFtp->cd("..");
		refreshFileInfoListRemote();

		int sepatatorPos = mRemoteCurrentDir.lastIndexOf(QDir::separator(), mRemoteCurrentDir.length() - 2);
		if (sepatatorPos != -1)
		{
			mRemoteCurrentDir.truncate(sepatatorPos);
			if (mRemoteCurrentDir.length() <= 1)
			{
				mRemoteCurrentDir = QDir::separator();
			}
		}
		ui.lineEditPathRemote->setText(mRemoteCurrentDir);
	}
}

void FTPClient::slotPushButtonRenameLocalClicked()
{
	QPalette palette;
	if (!ui.listWidgetFileLocal->currentItem())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���κ��ļ���"));
		return;
	}
	if (mDialogGetName.exec() != QDialog::Accepted)
	{
		return;
	}
	QString selectedFileName = ui.listWidgetFileLocal->currentItem()->text();
	QString newName = mDialogGetName.getName();
	if (newName.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������ļ���Ϊ�գ�"));
		return;
	}
	if (mLocalDir.rename(selectedFileName, newName))
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Rename Finished!"));
		refreshFileInfoListLocal();
		if (ui.listWidgetFileLocal->currentItem())
		{
			ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("��ѡ��") + ui.listWidgetFileLocal->currentItem()->text());
		}
		else
		{
			ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("��ѡ��"));
		}
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("������ʧ�ܣ�"));
	}
}

void FTPClient::slotPushButtonDeleteLocalClicked()
{
	QPalette palette;
	if (!ui.listWidgetFileLocal->currentItem())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���κ��ļ���"));
		return;
	}
	QString selectedFileName = ui.listWidgetFileLocal->currentItem()->text();
	if (QMessageBox::question(this, QString::fromLocal8Bit("ɾ��ȷ��"), QString("%1:%2?").arg(QString::fromLocal8Bit("ȷ��ɾ��")).arg(selectedFileName)) != QMessageBox::Yes)
	{
		return;
	}
	if (mLocalDir.remove(selectedFileName) | mLocalDir.rmdir(selectedFileName))
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Deletion Finished!"));
		ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("��ѡ��"));
		refreshFileInfoListLocal();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ɾ��ʧ�ܣ�"));
	}
}

void FTPClient::slotPushButtonRenameRemoteClicked()
{
	if (!ui.listWidgetFileRemote->currentItem())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���κ��ļ���"));
		return;
	}
	if (mDialogGetName.exec() != QDialog::Accepted)
	{
		return;
	}
	QString selectedFileName = ui.listWidgetFileRemote->currentItem()->text();
	QString newName = mDialogGetName.getName();
	if (newName.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������ļ���Ϊ�գ�"));
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpRenameFinished);
	mFtp->rename(QString::fromLatin1(selectedFileName.toLocal8Bit()), QString::fromLatin1(newName.toLocal8Bit()));
}

void FTPClient::slotPushButtonDeleteRemoteClicked()
{
	if (!ui.listWidgetFileRemote->currentItem())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δѡ���κ��ļ���"));
		return;
	}
	QString selectedFileName = ui.listWidgetFileRemote->currentItem()->text();
	if (QMessageBox::question(this, QString::fromLocal8Bit("ɾ��ȷ��"), QString("%1:%2?").arg(QString::fromLocal8Bit("ȷ��ɾ��")).arg(selectedFileName)) != QMessageBox::Yes)
	{
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDeleteFinished);
	if (mIsRemoteItemDir[selectedFileName])
	{
		mFtp->rmdir(QString::fromLatin1(selectedFileName.toLocal8Bit()));
	}
	else
	{
		mFtp->remove(QString::fromLatin1(selectedFileName.toLocal8Bit()));
	}
}

void FTPClient::slotListWidgetFileLocalItemClicked(QListWidgetItem * item)
{
	ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("��ѡ��") + item->text());
}

void FTPClient::slotListWidgetFileLocalItemDoubleClicked(QListWidgetItem * item)
{
	if (mLocalDir.cd(item->text()))
	{
		ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("��ѡ��"));
		refreshFileInfoListLocal();
	}
	else
	{
		
	}
}

void FTPClient::slotLineEditPathLocalReturnPressed()
{
	if (mLocalDir.cd(ui.lineEditPathLocal->text()))
	{
		refreshFileInfoListLocal();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ⲻ��һ����Ч·����"));
	}
}

void FTPClient::slotListWidgetFileRemoteItemClicked(QListWidgetItem * item)
{
	ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��") + item->text());
}

void FTPClient::slotListWidgetFileRemoteItemDoubleClicked(QListWidgetItem * item)
{
	if (mFtp->state() == QFtp::LoggedIn)
	{
		if (mIsRemoteItemDir[item->text()])
		{	
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��"));
			mIsRemoteItemDir.clear();
			mFtp->cd(QString::fromLatin1(item->text().toLocal8Bit()));
			mFtp->list();
			mRemoteCurrentDir.append(item->text() + QDir::separator());
			ui.listWidgetFileRemote->clear();
			ui.lineEditPathRemote->setText(mRemoteCurrentDir);
		}
	}
}

void FTPClient::slotLineEditPathRemoteReturnPressed()
{
}

void FTPClient::slotFtpCommandFinished(int id, bool error)
{

}

void FTPClient::slotFtpCommandStarted(int id)
{

}

void FTPClient::slotFtpDataTransferProgress(qint64 done, qint64 total)
{
	if (!done && !total)
	{
		mFtpProgressBar->setRange(0, 100);
		mFtpProgressBar->setValue(100);
		mFtpProgressBar->update();
	}
	else
	{
		mFtpProgressBar->setRange(0, total);
		mFtpProgressBar->setValue(done);
		mFtpProgressBar->update();
	}
}

void FTPClient::slotFtpDone(bool error)
{

}

void FTPClient::slotFtpListInfo(const QUrlInfo & url)
{

	addFileInfoListRemote(url);
}

void FTPClient::slotFtpRawCommandReply(int replyCode, const QString & detail)
{

}

void FTPClient::slotFtpReadyRead()
{

}

void FTPClient::slotFtpStateChanged(int state)
{
	QPalette palette;
	if (state == QFtp::Unconnected)
	{
		palette.setColor(QPalette::WindowText, Qt::black);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("Unconnected"));

	}
	else if (state == QFtp::HostLookup)
	{
		palette.setColor(QPalette::WindowText, Qt::darkYellow);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("HostLookup"));

	}
	else if (state == QFtp::Connecting)
	{
		palette.setColor(QPalette::WindowText, Qt::darkYellow);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("Connecting"));

	}
	else if (state == QFtp::Connected)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("Connected"));

	}
	else if (state == QFtp::LoggedIn)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("LoggedIn"));
	}
	else if (state == QFtp::Closing)
	{
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpState->setPalette(palette);
		mLabelFtpState->setText(QString("Status:%1").arg("Closing"));
	}
}

void FTPClient::slotFtpLoggedIn(int id, bool error)
{
	if (mFtp->state() == QFtp::LoggedIn)
	{
		refreshFileInfoListRemote();
		if (mDialogConnect.isAnonymous())
		{
			mLabelFtpUser->setText(QString("User:%1").arg("\"ANONYMOUS\""));
		}
		else
		{
			mLabelFtpUser->setText(QString("User:%1").arg(mDialogConnect.getUser()));
		}
		ui.lineEditPathRemote->setText(mRemoteCurrentDir);
		//ui.pushButtonDisconnect->setEnabled(true);
		ui.pushButtonUpload->setEnabled(true);
		ui.pushButtonDownload->setEnabled(true);
		//ui.pushButtonRenameLocal->setEnabled(true);
		//ui.pushButtonDeleteLocal->setEnabled(true);
		ui.pushButtonRenameRemote->setEnabled(true);
		ui.pushButtonDeleteRemote->setEnabled(true);
		disconnect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpLoggedIn);
	}
	
}

void FTPClient::slotFtpUploadFinished(int id, bool error)
{
	QPalette palette;
	mFile.close();
	disconnect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpUploadFinished);
	if (!error)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Upload Finished!"));
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ϴ�ʧ�ܣ�"));
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Upload Failed!"));
	}
	refreshFileInfoListRemote();
}

void FTPClient::slotFtpDownloadFinished(int id, bool error)
{
	QPalette palette;
	mFile.close();
	disconnect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDownloadFinished);
	if (!error)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Download Finished!"));
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ʧ�ܣ�"));
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Download Failed!"));
	}
	refreshFileInfoListLocal();
}

void FTPClient::slotFtpRenameFinished(int id, bool error)
{
	QPalette palette;
	disconnect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpRenameFinished);
	refreshFileInfoListRemote();
	if (!error)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Rename Finished!"));
		if (ui.listWidgetFileRemote->currentItem())
		{
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��") + ui.listWidgetFileRemote->currentItem()->text());
		}
		else
		{
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��"));
		}
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("������ʧ�ܣ�"));
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Rename Failed!"));
	}
}

void FTPClient::slotFtpDeleteFinished(int id, bool error)
{
	QPalette palette;
	disconnect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDeleteFinished);
	refreshFileInfoListRemote();
	if (!error)
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Deletion Finished!"));
		ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("��ѡ��"));
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ɾ��ʧ�ܣ�"));
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Deletion Failed!"));
	}
}
