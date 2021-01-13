#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <Qdir>
#include <QtNetwork/QFtp>
#include <QHash>
#include "ui_FTPClient.h"
#include "DialogConnect.h"
#include "DialogGetName.h"

class FTPClient : public QMainWindow
{
    Q_OBJECT

public:
    FTPClient(QWidget *parent = Q_NULLPTR);

private:
	void initListWidgetFileLocal();//初始化本地文件浏览列表
	void initMenuBar();//初始化菜单栏
	void initPushButtons();//初始化所有按钮
	void initFtp();//连接FTP信号和槽函数
	void refreshFileInfoListLocal();//刷新本地文件浏览列表
	void refreshFileInfoListRemote();//刷新服务端文件浏览列表
	void clearFileInfoListsRemote();//清空服务端文件浏览列表
	void addFileInfoListRemote(const QUrlInfo & url);//添加至服务端文件浏览列表
	void connectFtp();//建立FTP连接
	void disconnectFtp();//断开FTP连接
private slots:
	void slotActionConnectTriggered();
	void slotActionDisconnectTriggered();
	void slotActionQuitTriggered();

	void slotPushButtonConnectClicked();
	void slotPushButtonDisconnectClicked();
	void slotPushButtonUploadClicked();
	void slotPushButtonDownloadClicked();
	void slotPushButtonParentDirLocalClicked();
	void slotPushButtonParentDirRemoteClicked();
	void slotPushButtonRenameLocalClicked();
	void slotPushButtonDeleteLocalClicked();
	void slotPushButtonRenameRemoteClicked();
	void slotPushButtonDeleteRemoteClicked();
	void slotListWidgetFileLocalItemClicked(QListWidgetItem *item);
	void slotListWidgetFileLocalItemDoubleClicked(QListWidgetItem *item);
	void slotLineEditPathLocalReturnPressed();
	void slotListWidgetFileRemoteItemClicked(QListWidgetItem *item);
	void slotListWidgetFileRemoteItemDoubleClicked(QListWidgetItem *item);
	void slotLineEditPathRemoteReturnPressed();

	void slotFtpCommandFinished(int id, bool error);
	void slotFtpCommandStarted(int id);
	void slotFtpDataTransferProgress(qint64 done, qint64 total);
	void slotFtpDone(bool error);
	void slotFtpListInfo(const QUrlInfo & i);
	void slotFtpRawCommandReply(int replyCode, const QString & detail);
	void slotFtpReadyRead();
	void slotFtpStateChanged(int state);

	void slotFtpLoggedIn(int id, bool error);
	void slotFtpUploadFinished(int id, bool error);
	void slotFtpDownloadFinished(int id, bool error);
	void slotFtpRenameFinished(int id, bool error);
	void slotFtpDeleteFinished(int id, bool error);
private:
	QLabel * mLabelFtpUser;//状态栏"User"
	QLabel * mLabelFtpState;//状态栏"Status"
	QLabel * mLabelFtpOpState;//状态栏"Operation"
	QProgressBar * mFtpProgressBar;//状态栏进度条
    Ui::FTPClientClass ui;
	DialogConnect mDialogConnect;//"连接"窗口
	DialogGetName mDialogGetName;//"重命名"窗口

	QDir mLocalDir;
	QString mRemoteCurrentDir;
	QHash<QString, bool> mIsRemoteItemDir;
	QHash<QString, bool> mIsLocalItemDir;
	QFtp * mFtp;
	QString mAddress;
	int mPort;
	QString mUser;
	QString mPass;
	QFile mFile;
};
