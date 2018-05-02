/********************************************************************************
** Form generated from reading UI file 'formlayers.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLAYERS_H
#define UI_FORMLAYERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLayers
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTextBox;
    QTableWidget *tableWidgetLayers;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonUp;
    QPushButton *buttonDown;
    QPushButton *buttonCopy;
    QPushButton *buttonDelete;

    void setupUi(QWidget *FormLayers)
    {
        if (FormLayers->objectName().isEmpty())
            FormLayers->setObjectName(QStringLiteral("FormLayers"));
        FormLayers->resize(350, 438);
        verticalLayout = new QVBoxLayout(FormLayers);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTextBox = new QLabel(FormLayers);
        labelTextBox->setObjectName(QStringLiteral("labelTextBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTextBox->sizePolicy().hasHeightForWidth());
        labelTextBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        labelTextBox->setFont(font);
        labelTextBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTextBox);

        tableWidgetLayers = new QTableWidget(FormLayers);
        tableWidgetLayers->setObjectName(QStringLiteral("tableWidgetLayers"));
        tableWidgetLayers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetLayers->setShowGrid(true);
        tableWidgetLayers->setGridStyle(Qt::NoPen);
        tableWidgetLayers->horizontalHeader()->setVisible(true);
        tableWidgetLayers->horizontalHeader()->setDefaultSectionSize(32);
        tableWidgetLayers->horizontalHeader()->setHighlightSections(true);
        tableWidgetLayers->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidgetLayers);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonUp = new QPushButton(FormLayers);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/up-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonUp->setIcon(icon);
        buttonUp->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(buttonUp);

        buttonDown = new QPushButton(FormLayers);
        buttonDown->setObjectName(QStringLiteral("buttonDown"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/down-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDown->setIcon(icon1);
        buttonDown->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(buttonDown);

        buttonCopy = new QPushButton(FormLayers);
        buttonCopy->setObjectName(QStringLiteral("buttonCopy"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/copy-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCopy->setIcon(icon2);
        buttonCopy->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(buttonCopy);

        buttonDelete = new QPushButton(FormLayers);
        buttonDelete->setObjectName(QStringLiteral("buttonDelete"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDelete->setIcon(icon3);
        buttonDelete->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(buttonDelete);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormLayers);

        QMetaObject::connectSlotsByName(FormLayers);
    } // setupUi

    void retranslateUi(QWidget *FormLayers)
    {
        FormLayers->setWindowTitle(QApplication::translate("FormLayers", "Form", nullptr));
        labelTextBox->setText(QApplication::translate("FormLayers", "Layers", nullptr));
        buttonUp->setText(QString());
        buttonDown->setText(QString());
        buttonCopy->setText(QString());
        buttonDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormLayers: public Ui_FormLayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLAYERS_H
