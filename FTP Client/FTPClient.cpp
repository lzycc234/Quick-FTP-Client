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
	QAction * actionConnect = new QAction(QString::fromLocal8Bit("连接"));
	actionConnect->setIcon(style()->standardIcon(QStyle::QStyle::SP_MediaPlay));
	ui.menuSession->addAction(actionConnect);
	connect(actionConnect, &QAction::triggered, this, &FTPClient::slotActionConnectTriggered);

	QAction * actionDisconnect = new QAction(QString::fromLocal8Bit("断开"));
	actionDisconnect->setIcon(style()->standardIcon(QStyle::QStyle::SP_MediaStop));
	ui.menuSession->addAction(actionDisconnect);
	connect(actionDisconnect, &QAction::triggered, this, &FTPClient::slotActionDisconnectTriggered);

	QAction * actionQuit = new QAction(QString::fromLocal8Bit("退出"));
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
	if (!mDialogConnect.exec())//若连接窗口被直接关闭则取消连接
	{
		return;
	}
	mAddress = mDialogConnect.getAddress();//获取地址
	mPort = mDialogConnect.getPort();//获取端口
	disconnectFtp();//先断开之前的连接
	mFtp = new QFtp(this);
	initFtp();
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpLoggedIn);
	mFtp->connectToHost(mAddress, mPort);//建立连接
	if (mDialogConnect.isAnonymous())//匿名连接
	{
		mFtp->login();
	}
	else
	{
		mUser = mDialogConnect.getUser();//获取用户名
		mPass = mDialogConnect.getPass();//获取密码
		mFtp->login(mUser, mPass);
	}
}

void FTPClient::disconnectFtp()
{
	QPalette palette;
	if (mFtp)//若已有连接则直接断开连接
	{
		mFtp->close();
		mFtp->deleteLater();
		mFtp = nullptr;
	}
	clearFileInfoListsRemote();//清空服务端文件浏览列表
	mRemoteCurrentDir = QDir::separator();//重置服务端当前路径
	ui.lineEditPathRemote->clear();//清空服务端当前路径
	//将服务端相关操作按钮重新禁用
	ui.pushButtonUpload->setEnabled(false);
	ui.pushButtonDownload->setEnabled(false);
	ui.pushButtonRenameRemote->setEnabled(false);
	ui.pushButtonDeleteRemote->setEnabled(false);
	//
	ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选："));
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
	if (!currentItem)//判断是否选中文件
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中文件！"));
		return;
	}
	QString fileName = currentItem->text();//获取所选文件名
	QString filePath = mLocalDir.absolutePath() + QDir::separator() + fileName;//获取所选文件路径
	if (QFileInfo(filePath).isDir())//判断所选是否为文件夹，若是文件夹则取消上传
	{
		return;
	}
	mFile.setFileName(filePath);
	if (mIsRemoteItemDir.contains(fileName))//判断服务端当前路径是否存在同名文件
	{
		//弹出是否继续上传窗口
		if (QMessageBox::question(this,
			QString::fromLocal8Bit("询问"),
			QString("%1:%2\n%3").arg(QString::fromLocal8Bit("已存在同名文件")).arg(fileName).arg(QString::fromLocal8Bit("是否继续？"))) != QMessageBox::Yes)
		{
			return;
		}
	}
	if (!mFile.open(QIODevice::ReadOnly))//打开本地文件
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法上传所选文件！"));
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
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpUploadFinished);//将上传结果建立连接
	mFtp->put(&mFile, QString::fromLatin1(uploadPath.toLocal8Bit()));//发出上传命令
}

void FTPClient::slotPushButtonDownloadClicked()
{
	QListWidgetItem * currentItem = ui.listWidgetFileRemote->currentItem();
	if (!currentItem)//判断是否选中文件
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中文件！"));
		return;
	}
	QString fileName = currentItem->text();//获取所选文件名
	QString filePath;//获取所选文件路径
	if (mRemoteCurrentDir.length() == 1)
	{
		filePath = QString("%1%2").arg(mRemoteCurrentDir).arg(fileName);
	}
	else
	{
		filePath = QString("%1%2%3").arg(mRemoteCurrentDir).arg(QDir::separator()).arg(fileName);
	}
	if (mIsRemoteItemDir[fileName])//判断所选是否为文件夹，若是文件夹则取消下载
	{
		return;
	}

	QString downloadPath= mLocalDir.absolutePath() + QDir::separator() + fileName;//下载至本地的文件路径
	mFile.setFileName(downloadPath);
	if (mFile.exists())//若本地当前路径已有同名文件
	{
		//弹出是否继续下载窗口
		if (QMessageBox::question(this,
			QString::fromLocal8Bit("询问"),
			QString("%1:%2\n%3").arg(QString::fromLocal8Bit("已存在同名文件")).arg(fileName).arg(QString::fromLocal8Bit("是否继续下载？"))) != QMessageBox::Yes)
		{
			return;
		}
	}
	if (!mFile.open(QIODevice::WriteOnly))//打开本地文件准备下载
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法下载所选文件！"));
		mFile.close();
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDownloadFinished);//将下载结果建立连接
	mFtp->get(QString::fromLatin1(filePath.toLocal8Bit()), &mFile);//发送下载命令
}

void FTPClient::slotPushButtonParentDirLocalClicked()
{	
	if (mLocalDir.cd(".."))
	{
		refreshFileInfoListLocal();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("已经达到根目录！"));
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
	if (!ui.listWidgetFileLocal->currentItem())//判断是否已选中文件/文件夹
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中任何文件！"));
		return;
	}
	if (mDialogGetName.exec() != QDialog::Accepted)//若重命名窗口被直接关闭则取消重命名
	{
		return;
	}
	QString selectedFileName = ui.listWidgetFileLocal->currentItem()->text();//获取选中文件的文件名
	QString newName = mDialogGetName.getName();//获取新文件名
	if (newName.isEmpty())//判断输入的新文件名是否为空
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("已输入文件名为空！"));
		return;
	}
	if (mLocalDir.rename(selectedFileName, newName))//判断是否重命名成功
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Rename Finished!"));
		refreshFileInfoListLocal();
		if (ui.listWidgetFileLocal->currentItem())
		{
			ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("已选：") + ui.listWidgetFileLocal->currentItem()->text());
		}
		else
		{
			ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("已选："));
		}
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("重命名失败！"));
	}
}

void FTPClient::slotPushButtonDeleteLocalClicked()
{
	QPalette palette;
	if (!ui.listWidgetFileLocal->currentItem())//判断是否已选中文件/文件夹
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中任何文件！"));
		return;
	}
	QString selectedFileName = ui.listWidgetFileLocal->currentItem()->text();//获取选中文件的文件名
	//弹出确认删除窗口
	if (QMessageBox::question(this, QString::fromLocal8Bit("删除确认"), QString("%1:%2?").arg(QString::fromLocal8Bit("确认删除")).arg(selectedFileName)) != QMessageBox::Yes)
	{
		return;
	}
	if (mLocalDir.remove(selectedFileName) | mLocalDir.rmdir(selectedFileName))//判断所选的是文件或文件夹以及判断是否删除成功
	{
		palette.setColor(QPalette::WindowText, Qt::darkGreen);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Deletion Finished!"));
		ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("已选："));
		refreshFileInfoListLocal();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("删除失败！"));
	}
}

void FTPClient::slotPushButtonRenameRemoteClicked()
{
	if (!ui.listWidgetFileRemote->currentItem())//判断是否已选中文件/文件夹
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中任何文件！"));
		return;
	}
	if (mDialogGetName.exec() != QDialog::Accepted)//若重命名窗口被直接关闭则取消重命名
	{
		return;
	}
	QString selectedFileName = ui.listWidgetFileRemote->currentItem()->text();//获取选中文件的文件名
	QString newName = mDialogGetName.getName();//获取新文件名
	if (newName.isEmpty())//判断输入的新文件名是否为空
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("已输入文件名为空！"));
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpRenameFinished);//将重命名的结果建立连接
	mFtp->rename(QString::fromLatin1(selectedFileName.toLocal8Bit()), QString::fromLatin1(newName.toLocal8Bit()));//发出重命名命令
}

void FTPClient::slotPushButtonDeleteRemoteClicked()
{
	if (!ui.listWidgetFileRemote->currentItem())//判断是否已选中文件/文件夹
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未选中任何文件！"));
		return;
	}
	QString selectedFileName = ui.listWidgetFileRemote->currentItem()->text();//获取选中文件的文件名
	//弹出确认删除窗口
	if (QMessageBox::question(this, QString::fromLocal8Bit("删除确认"), QString("%1:%2?").arg(QString::fromLocal8Bit("确认删除")).arg(selectedFileName)) != QMessageBox::Yes)
	{
		return;
	}
	connect(mFtp, &QFtp::commandFinished, this, &FTPClient::slotFtpDeleteFinished);//将删除结果建立连接
	if (mIsRemoteItemDir[selectedFileName])//判断所选是否为文件夹
	{
		mFtp->rmdir(QString::fromLatin1(selectedFileName.toLocal8Bit()));//发出删除文件夹命令
	}
	else
	{
		mFtp->remove(QString::fromLatin1(selectedFileName.toLocal8Bit()));//发出删除文件命令
	}
}

void FTPClient::slotListWidgetFileLocalItemClicked(QListWidgetItem * item)
{
	ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("已选：") + item->text());
}

void FTPClient::slotListWidgetFileLocalItemDoubleClicked(QListWidgetItem * item)
{
	if (mLocalDir.cd(item->text()))
	{
		ui.labelSelectedFileLocal->setText(QString::fromLocal8Bit("已选："));
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
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("这不是一个有效路径！"));
	}
}

void FTPClient::slotListWidgetFileRemoteItemClicked(QListWidgetItem * item)
{
	ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选：") + item->text());
}

void FTPClient::slotListWidgetFileRemoteItemDoubleClicked(QListWidgetItem * item)
{
	if (mFtp->state() == QFtp::LoggedIn)
	{
		if (mIsRemoteItemDir[item->text()])
		{	
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选："));
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
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("上传失败！"));
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
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("下载失败！"));
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
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选：") + ui.listWidgetFileRemote->currentItem()->text());
		}
		else
		{
			ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选："));
		}
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("重命名失败！"));
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
		ui.labelSelectedFileRemote->setText(QString::fromLocal8Bit("已选："));
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("删除失败！"));
		palette.setColor(QPalette::WindowText, Qt::darkRed);
		mLabelFtpOpState->setPalette(palette);
		mLabelFtpOpState->setText(QString("Operation:%1").arg("Deletion Failed!"));
	}
}
