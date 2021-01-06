/********************************************************************************
** Form generated from reading UI file 'DialogGetName.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGETNAME_H
#define UI_DIALOGGETNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogGetName
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditNewName;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonConfirm;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DialogGetName)
    {
        if (DialogGetName->objectName().isEmpty())
            DialogGetName->setObjectName(QStringLiteral("DialogGetName"));
        DialogGetName->resize(334, 104);
        verticalLayout = new QVBoxLayout(DialogGetName);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEditNewName = new QLineEdit(DialogGetName);
        lineEditNewName->setObjectName(QStringLiteral("lineEditNewName"));
        lineEditNewName->setFrame(true);
        lineEditNewName->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEditNewName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonConfirm = new QPushButton(DialogGetName);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));

        horizontalLayout->addWidget(pushButtonConfirm);

        pushButtonCancel = new QPushButton(DialogGetName);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogGetName);

        QMetaObject::connectSlotsByName(DialogGetName);
    } // setupUi

    void retranslateUi(QDialog *DialogGetName)
    {
        DialogGetName->setWindowTitle(QApplication::translate("DialogGetName", "\350\257\267\350\276\223\345\205\245\346\226\260\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        pushButtonConfirm->setText(QApplication::translate("DialogGetName", "\347\241\256 \350\256\244", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("DialogGetName", "\345\217\226 \346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogGetName: public Ui_DialogGetName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGETNAME_H
