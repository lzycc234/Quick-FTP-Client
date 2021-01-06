/********************************************************************************
** Form generated from reading UI file 'DialogConnect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNECT_H
#define UI_DIALOGCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogConnect
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelUser;
    QLineEdit *lineEditAddress;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelPass;
    QLineEdit *lineEditPass;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxShowPass;
    QCheckBox *checkBoxAnonymous;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButtonActiveMode;
    QRadioButton *radioButtonPassiveMode;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonLogin;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelMessage;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *DialogConnect)
    {
        if (DialogConnect->objectName().isEmpty())
            DialogConnect->setObjectName(QStringLiteral("DialogConnect"));
        DialogConnect->resize(370, 229);
        DialogConnect->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout = new QVBoxLayout(DialogConnect);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelUser = new QLabel(DialogConnect);
        labelUser->setObjectName(QStringLiteral("labelUser"));

        horizontalLayout_4->addWidget(labelUser);

        lineEditAddress = new QLineEdit(DialogConnect);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditAddress->sizePolicy().hasHeightForWidth());
        lineEditAddress->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEditAddress);

        labelPort = new QLabel(DialogConnect);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        horizontalLayout_4->addWidget(labelPort);

        lineEditPort = new QLineEdit(DialogConnect);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPort->sizePolicy().hasHeightForWidth());
        lineEditPort->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEditPort);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(DialogConnect);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        lineEditUser = new QLineEdit(DialogConnect);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));

        horizontalLayout_6->addWidget(lineEditUser);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelPass = new QLabel(DialogConnect);
        labelPass->setObjectName(QStringLiteral("labelPass"));

        horizontalLayout_5->addWidget(labelPass);

        lineEditPass = new QLineEdit(DialogConnect);
        lineEditPass->setObjectName(QStringLiteral("lineEditPass"));
        lineEditPass->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(lineEditPass);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBoxShowPass = new QCheckBox(DialogConnect);
        checkBoxShowPass->setObjectName(QStringLiteral("checkBoxShowPass"));

        horizontalLayout->addWidget(checkBoxShowPass);

        checkBoxAnonymous = new QCheckBox(DialogConnect);
        checkBoxAnonymous->setObjectName(QStringLiteral("checkBoxAnonymous"));
        checkBoxAnonymous->setCheckable(true);

        horizontalLayout->addWidget(checkBoxAnonymous);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        radioButtonActiveMode = new QRadioButton(DialogConnect);
        radioButtonActiveMode->setObjectName(QStringLiteral("radioButtonActiveMode"));
        radioButtonActiveMode->setEnabled(false);
        radioButtonActiveMode->setCheckable(true);

        horizontalLayout_2->addWidget(radioButtonActiveMode);

        radioButtonPassiveMode = new QRadioButton(DialogConnect);
        radioButtonPassiveMode->setObjectName(QStringLiteral("radioButtonPassiveMode"));
        radioButtonPassiveMode->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonPassiveMode);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButtonLogin = new QPushButton(DialogConnect);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));

        horizontalLayout_3->addWidget(pushButtonLogin);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        labelMessage = new QLabel(DialogConnect);
        labelMessage->setObjectName(QStringLiteral("labelMessage"));

        horizontalLayout_7->addWidget(labelMessage);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(DialogConnect);

        QMetaObject::connectSlotsByName(DialogConnect);
    } // setupUi

    void retranslateUi(QDialog *DialogConnect)
    {
        DialogConnect->setWindowTitle(QApplication::translate("DialogConnect", "\350\277\236\346\216\245", Q_NULLPTR));
        labelUser->setText(QApplication::translate("DialogConnect", "\345\234\260  \345\235\200:", Q_NULLPTR));
        lineEditAddress->setText(QApplication::translate("DialogConnect", "127.0.0.1", Q_NULLPTR));
        labelPort->setText(QApplication::translate("DialogConnect", "\347\253\257  \345\217\243:", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("DialogConnect", "21", Q_NULLPTR));
        label->setText(QApplication::translate("DialogConnect", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        labelPass->setText(QApplication::translate("DialogConnect", "\345\257\206  \347\240\201:", Q_NULLPTR));
        lineEditPass->setInputMask(QString());
        lineEditPass->setText(QString());
        checkBoxShowPass->setText(QApplication::translate("DialogConnect", "\346\230\276\347\244\272\345\257\206\347\240\201", Q_NULLPTR));
        checkBoxAnonymous->setText(QApplication::translate("DialogConnect", "\345\214\277\345\220\215\347\231\273\345\275\225", Q_NULLPTR));
        radioButtonActiveMode->setText(QApplication::translate("DialogConnect", "\344\270\273\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        radioButtonPassiveMode->setText(QApplication::translate("DialogConnect", "\350\242\253\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
        pushButtonLogin->setText(QApplication::translate("DialogConnect", "\347\231\273 \345\275\225", Q_NULLPTR));
        labelMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogConnect: public Ui_DialogConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNECT_H
