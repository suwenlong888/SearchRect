/********************************************************************************
** Form generated from reading UI file 'muitemdelegate.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUITEMDELEGATE_H
#define UI_MUITEMDELEGATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MuItemDelegate
{
public:

    void setupUi(QWidget *MuItemDelegate)
    {
        if (MuItemDelegate->objectName().isEmpty())
            MuItemDelegate->setObjectName(QStringLiteral("MuItemDelegate"));
        MuItemDelegate->resize(400, 300);

        retranslateUi(MuItemDelegate);

        QMetaObject::connectSlotsByName(MuItemDelegate);
    } // setupUi

    void retranslateUi(QWidget *MuItemDelegate)
    {
        MuItemDelegate->setWindowTitle(QApplication::translate("MuItemDelegate", "MuItemDelegate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MuItemDelegate: public Ui_MuItemDelegate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUITEMDELEGATE_H
