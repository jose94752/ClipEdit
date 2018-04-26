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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLayers
{
public:
    QSplitter *splitter_2;
    QLabel *labelTextBox;
    QTableWidget *tableWidgetLayers;
    QSplitter *splitter;
    QPushButton *buttonUp;
    QPushButton *pushDown;
    QPushButton *pushAdd;
    QPushButton *pushSupp;

    void setupUi(QWidget *FormLayers)
    {
        if (FormLayers->objectName().isEmpty())
            FormLayers->setObjectName(QStringLiteral("FormLayers"));
        FormLayers->resize(341, 269);
        splitter_2 = new QSplitter(FormLayers);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 10, 320, 247));
        splitter_2->setOrientation(Qt::Vertical);
        labelTextBox = new QLabel(splitter_2);
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
        splitter_2->addWidget(labelTextBox);
        tableWidgetLayers = new QTableWidget(splitter_2);
        tableWidgetLayers->setObjectName(QStringLiteral("tableWidgetLayers"));
        tableWidgetLayers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetLayers->setShowGrid(false);
        tableWidgetLayers->setGridStyle(Qt::NoPen);
        splitter_2->addWidget(tableWidgetLayers);
        tableWidgetLayers->horizontalHeader()->setVisible(false);
        tableWidgetLayers->horizontalHeader()->setDefaultSectionSize(32);
        tableWidgetLayers->horizontalHeader()->setHighlightSections(false);
        tableWidgetLayers->verticalHeader()->setVisible(false);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        buttonUp = new QPushButton(splitter);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        splitter->addWidget(buttonUp);
        pushDown = new QPushButton(splitter);
        pushDown->setObjectName(QStringLiteral("pushDown"));
        splitter->addWidget(pushDown);
        pushAdd = new QPushButton(splitter);
        pushAdd->setObjectName(QStringLiteral("pushAdd"));
        splitter->addWidget(pushAdd);
        pushSupp = new QPushButton(splitter);
        pushSupp->setObjectName(QStringLiteral("pushSupp"));
        splitter->addWidget(pushSupp);
        splitter_2->addWidget(splitter);

        retranslateUi(FormLayers);

        QMetaObject::connectSlotsByName(FormLayers);
    } // setupUi

    void retranslateUi(QWidget *FormLayers)
    {
        FormLayers->setWindowTitle(QApplication::translate("FormLayers", "Form", nullptr));
        labelTextBox->setText(QApplication::translate("FormLayers", "Layers", nullptr));
        buttonUp->setText(QApplication::translate("FormLayers", "Up", nullptr));
        pushDown->setText(QApplication::translate("FormLayers", "Down", nullptr));
        pushAdd->setText(QApplication::translate("FormLayers", "Add", nullptr));
        pushSupp->setText(QApplication::translate("FormLayers", "Supp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormLayers: public Ui_FormLayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLAYERS_H
