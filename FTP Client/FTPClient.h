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
	void initListWidgetFileLocal();
	void initMenuBar();
	void initPushButtons();
	void initFtp();
	void refreshFileInfoListLocal();
	void refreshFileInfoListRemote();
	void clearFileInfoListsRemote();
	void addFileInfoListRemote(const QUrlInfo & url);
	void connectFtp();
	void disconnectFtp();
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
	QLabel * mLabelFtpUser;
	QLabel * mLabelFtpState;
	QLabel * mLabelFtpOpState;
	QProgressBar * mFtpProgressBar;
    Ui::FTPClientClass ui;
	DialogConnect mDialogConnect;
	DialogGetName mDialogGetName;

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
