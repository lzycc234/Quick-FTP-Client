/********************************************************************************
** Form generated from reading UI file 'FTPClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPCLIENT_H
#define UI_FTPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTPClientClass
{
public:
    QAction *actionxinjian;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionQuit;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionLog;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonUpload;
    QPushButton *pushButtonRenameLocal;
    QPushButton *pushButtonDeleteLocal;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonParentDirLocal;
    QLineEdit *lineEditPathLocal;
    QListWidget *listWidgetFileLocal;
    QLabel *labelSelectedFileLocal;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonDownload;
    QPushButton *pushButtonRenameRemote;
    QPushButton *pushButtonDeleteRemote;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonParentDirRemote;
    QLineEdit *lineEditPathRemote;
    QListWidget *listWidgetFileRemote;
    QLabel *labelSelectedFileRemote;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSession;
    QMenu *menuTools;
    QMenu *menuHelp;

    void setupUi(QMainWindow *FTPClientClass)
    {
        if (FTPClientClass->objectName().isEmpty())
            FTPClientClass->setObjectName(QStringLiteral("FTPClientClass"));
        FTPClientClass->resize(1032, 652);
        actionxinjian = new QAction(FTPClientClass);
        actionxinjian->setObjectName(QStringLiteral("actionxinjian"));
        actionConnect = new QAction(FTPClientClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setMenuRole(QAction::TextHeuristicRole);
        actionDisconnect = new QAction(FTPClientClass);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionQuit = new QAction(FTPClientClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSettings = new QAction(FTPClientClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(FTPClientClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLog = new QAction(FTPClientClass);
        actionLog->setObjectName(QStringLiteral("actionLog"));
        centralWidget = new QWidget(FTPClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonUpload = new QPushButton(centralWidget);
        pushButtonUpload->setObjectName(QStringLiteral("pushButtonUpload"));
        pushButtonUpload->setEnabled(false);

        horizontalLayout->addWidget(pushButtonUpload);

        pushButtonRenameLocal = new QPushButton(centralWidget);
        pushButtonRenameLocal->setObjectName(QStringLiteral("pushButtonRenameLocal"));
        pushButtonRenameLocal->setEnabled(true);

        horizontalLayout->addWidget(pushButtonRenameLocal);

        pushButtonDeleteLocal = new QPushButton(centralWidget);
        pushButtonDeleteLocal->setObjectName(QStringLiteral("pushButtonDeleteLocal"));
        pushButtonDeleteLocal->setEnabled(true);

        horizontalLayout->addWidget(pushButtonDeleteLocal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonParentDirLocal = new QPushButton(centralWidget);
        pushButtonParentDirLocal->setObjectName(QStringLiteral("pushButtonParentDirLocal"));

        horizontalLayout_2->addWidget(pushButtonParentDirLocal);

        lineEditPathLocal = new QLineEdit(centralWidget);
        lineEditPathLocal->setObjectName(QStringLiteral("lineEditPathLocal"));

        horizontalLayout_2->addWidget(lineEditPathLocal);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidgetFileLocal = new QListWidget(centralWidget);
        listWidgetFileLocal->setObjectName(QStringLiteral("listWidgetFileLocal"));

        verticalLayout->addWidget(listWidgetFileLocal);

        labelSelectedFileLocal = new QLabel(centralWidget);
        labelSelectedFileLocal->setObjectName(QStringLiteral("labelSelectedFileLocal"));

        verticalLayout->addWidget(labelSelectedFileLocal);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonDownload = new QPushButton(centralWidget);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));
        pushButtonDownload->setEnabled(false);

        horizontalLayout_4->addWidget(pushButtonDownload);

        pushButtonRenameRemote = new QPushButton(centralWidget);
        pushButtonRenameRemote->setObjectName(QStringLiteral("pushButtonRenameRemote"));
        pushButtonRenameRemote->setEnabled(false);

        horizontalLayout_4->addWidget(pushButtonRenameRemote);

        pushButtonDeleteRemote = new QPushButton(centralWidget);
        pushButtonDeleteRemote->setObjectName(QStringLiteral("pushButtonDeleteRemote"));
        pushButtonDeleteRemote->setEnabled(false);

        horizontalLayout_4->addWidget(pushButtonDeleteRemote);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonParentDirRemote = new QPushButton(centralWidget);
        pushButtonParentDirRemote->setObjectName(QStringLiteral("pushButtonParentDirRemote"));

        horizontalLayout_3->addWidget(pushButtonParentDirRemote);

        lineEditPathRemote = new QLineEdit(centralWidget);
        lineEditPathRemote->setObjectName(QStringLiteral("lineEditPathRemote"));
        lineEditPathRemote->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditPathRemote);


        verticalLayout_2->addLayout(horizontalLayout_3);

        listWidgetFileRemote = new QListWidget(centralWidget);
        listWidgetFileRemote->setObjectName(QStringLiteral("listWidgetFileRemote"));

        verticalLayout_2->addWidget(listWidgetFileRemote);

        labelSelectedFileRemote = new QLabel(centralWidget);
        labelSelectedFileRemote->setObjectName(QStringLiteral("labelSelectedFileRemote"));

        verticalLayout_2->addWidget(labelSelectedFileRemote);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        FTPClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FTPClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FTPClientClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(FTPClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1032, 26));
        menuSession = new QMenu(menuBar);
        menuSession->setObjectName(QStringLiteral("menuSession"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        FTPClientClass->setMenuBar(menuBar);

        menuBar->addAction(menuSession->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(FTPClientClass);

        QMetaObject::connectSlotsByName(FTPClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *FTPClientClass)
    {
        FTPClientClass->setWindowTitle(QApplication::translate("FTPClientClass", "Quick FTP", Q_NULLPTR));
        actionxinjian->setText(QApplication::translate("FTPClientClass", "xinjian", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("FTPClientClass", "\350\277\236\346\216\245", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("FTPClientClass", "\346\226\255\345\274\200", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("FTPClientClass", "\351\200\200\345\207\272", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("FTPClientClass", "\350\256\276\347\275\256", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("FTPClientClass", "\345\205\263\344\272\216", Q_NULLPTR));
        actionLog->setText(QApplication::translate("FTPClientClass", "\346\227\245\345\277\227", Q_NULLPTR));
        pushButtonUpload->setText(QApplication::translate("FTPClientClass", "\344\270\212\344\274\240", Q_NULLPTR));
        pushButtonRenameLocal->setText(QApplication::translate("FTPClientClass", "\351\207\215\345\221\275\345\220\215", Q_NULLPTR));
        pushButtonDeleteLocal->setText(QApplication::translate("FTPClientClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButtonParentDirLocal->setText(QString());
        labelSelectedFileLocal->setText(QApplication::translate("FTPClientClass", "\345\267\262\351\200\211:", Q_NULLPTR));
        pushButtonDownload->setText(QApplication::translate("FTPClientClass", "\344\270\213\350\275\275", Q_NULLPTR));
        pushButtonRenameRemote->setText(QApplication::translate("FTPClientClass", "\351\207\215\345\221\275\345\220\215", Q_NULLPTR));
        pushButtonDeleteRemote->setText(QApplication::translate("FTPClientClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButtonParentDirRemote->setText(QString());
        labelSelectedFileRemote->setText(QApplication::translate("FTPClientClass", "\345\267\262\351\200\211:", Q_NULLPTR));
        menuSession->setTitle(QApplication::translate("FTPClientClass", "\344\274\232\350\257\235(&E)", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("FTPClientClass", "\345\267\245\345\205\267(&T)", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("FTPClientClass", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FTPClientClass: public Ui_FTPClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPCLIENT_H
