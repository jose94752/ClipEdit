/********************************************************************************
** Form generated from reading UI file 'formcliparts.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCLIPARTS_H
#define UI_FORMCLIPARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCollections
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *title_layout;
    QSpacerItem *title_left_spacer;
    QLabel *title;
    QSpacerItem *title_right_spacer;
    QLabel *label_collections;
    QHBoxLayout *button_layout;
    QSpacerItem *button_left_spacer;
    QPushButton *button_open;
    QSpacerItem *button_right_spacer;
    QSpacerItem *bottom_spacer;

    void setupUi(QWidget *FormCollections)
    {
        if (FormCollections->objectName().isEmpty())
            FormCollections->setObjectName(QStringLiteral("FormCollections"));
        FormCollections->resize(418, 357);
        verticalLayout = new QVBoxLayout(FormCollections);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title_layout = new QHBoxLayout();
        title_layout->setObjectName(QStringLiteral("title_layout"));
        title_left_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        title_layout->addItem(title_left_spacer);

        title = new QLabel(FormCollections);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setPointSize(20);
        title->setFont(font);
        title->setTextFormat(Qt::PlainText);

        title_layout->addWidget(title);

        title_right_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        title_layout->addItem(title_right_spacer);


        verticalLayout->addLayout(title_layout);

        label_collections = new QLabel(FormCollections);
        label_collections->setObjectName(QStringLiteral("label_collections"));
        label_collections->setTextFormat(Qt::PlainText);

        verticalLayout->addWidget(label_collections);

        button_layout = new QHBoxLayout();
        button_layout->setSpacing(0);
        button_layout->setObjectName(QStringLiteral("button_layout"));
        button_left_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        button_layout->addItem(button_left_spacer);

        button_open = new QPushButton(FormCollections);
        button_open->setObjectName(QStringLiteral("button_open"));
        button_open->setEnabled(false);

        button_layout->addWidget(button_open);

        button_right_spacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        button_layout->addItem(button_right_spacer);


        verticalLayout->addLayout(button_layout);

        bottom_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottom_spacer);


        retranslateUi(FormCollections);

        QMetaObject::connectSlotsByName(FormCollections);
    } // setupUi

    void retranslateUi(QWidget *FormCollections)
    {
        FormCollections->setWindowTitle(QApplication::translate("FormCollections", "Form", nullptr));
        title->setText(QApplication::translate("FormCollections", "Clipart Collections", nullptr));
        label_collections->setText(QApplication::translate("FormCollections", "Clipart Collection Manager :", nullptr));
        button_open->setText(QApplication::translate("FormCollections", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCollections: public Ui_FormCollections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCLIPARTS_H
