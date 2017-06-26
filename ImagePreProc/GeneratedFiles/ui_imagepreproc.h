/********************************************************************************
** Form generated from reading UI file 'imagepreproc.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPREPROC_H
#define UI_IMAGEPREPROC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagePreProcClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *ed_train;
    QLabel *label_2;
    QLineEdit *ed_src;
    QPushButton *bt_browseFinal;
    QLineEdit *ed_final;
    QLabel *label;
    QPushButton *bt_browseSrc;
    QPushButton *bt_browseTrain;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_start;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *ed_classID;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *bt_trainInfo;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QLineEdit *ed_trainFdr;
    QPushButton *bt_trainSummary;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ImagePreProcClass)
    {
        if (ImagePreProcClass->objectName().isEmpty())
            ImagePreProcClass->setObjectName(QStringLiteral("ImagePreProcClass"));
        ImagePreProcClass->resize(955, 325);
        verticalLayout = new QVBoxLayout(ImagePreProcClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(ImagePreProcClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        ed_train = new QLineEdit(ImagePreProcClass);
        ed_train->setObjectName(QStringLiteral("ed_train"));

        gridLayout->addWidget(ed_train, 5, 0, 1, 1);

        label_2 = new QLabel(ImagePreProcClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        ed_src = new QLineEdit(ImagePreProcClass);
        ed_src->setObjectName(QStringLiteral("ed_src"));

        gridLayout->addWidget(ed_src, 1, 0, 1, 1);

        bt_browseFinal = new QPushButton(ImagePreProcClass);
        bt_browseFinal->setObjectName(QStringLiteral("bt_browseFinal"));
        QFont font1;
        font1.setPointSize(10);
        bt_browseFinal->setFont(font1);

        gridLayout->addWidget(bt_browseFinal, 3, 1, 1, 1);

        ed_final = new QLineEdit(ImagePreProcClass);
        ed_final->setObjectName(QStringLiteral("ed_final"));

        gridLayout->addWidget(ed_final, 3, 0, 1, 1);

        label = new QLabel(ImagePreProcClass);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        bt_browseSrc = new QPushButton(ImagePreProcClass);
        bt_browseSrc->setObjectName(QStringLiteral("bt_browseSrc"));
        bt_browseSrc->setFont(font1);

        gridLayout->addWidget(bt_browseSrc, 1, 1, 1, 1);

        bt_browseTrain = new QPushButton(ImagePreProcClass);
        bt_browseTrain->setObjectName(QStringLiteral("bt_browseTrain"));
        bt_browseTrain->setFont(font1);

        gridLayout->addWidget(bt_browseTrain, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bt_start = new QPushButton(ImagePreProcClass);
        bt_start->setObjectName(QStringLiteral("bt_start"));
        bt_start->setFont(font);

        horizontalLayout->addWidget(bt_start);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(ImagePreProcClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        ed_classID = new QLineEdit(ImagePreProcClass);
        ed_classID->setObjectName(QStringLiteral("ed_classID"));
        ed_classID->setFont(font1);

        gridLayout_3->addWidget(ed_classID, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        bt_trainInfo = new QPushButton(ImagePreProcClass);
        bt_trainInfo->setObjectName(QStringLiteral("bt_trainInfo"));
        bt_trainInfo->setFont(font);

        gridLayout_3->addWidget(bt_trainInfo, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        label_4 = new QLabel(ImagePreProcClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        ed_trainFdr = new QLineEdit(ImagePreProcClass);
        ed_trainFdr->setObjectName(QStringLiteral("ed_trainFdr"));
        ed_trainFdr->setFont(font1);

        gridLayout_2->addWidget(ed_trainFdr, 1, 1, 1, 1);

        bt_trainSummary = new QPushButton(ImagePreProcClass);
        bt_trainSummary->setObjectName(QStringLiteral("bt_trainSummary"));
        bt_trainSummary->setFont(font);

        gridLayout_2->addWidget(bt_trainSummary, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ImagePreProcClass);

        QMetaObject::connectSlotsByName(ImagePreProcClass);
    } // setupUi

    void retranslateUi(QWidget *ImagePreProcClass)
    {
        ImagePreProcClass->setWindowTitle(QApplication::translate("ImagePreProcClass", "ImagePreProc", 0));
        label_3->setText(QApplication::translate("ImagePreProcClass", "Classified Directory", 0));
        label_2->setText(QApplication::translate("ImagePreProcClass", "Resized Directory", 0));
        bt_browseFinal->setText(QApplication::translate("ImagePreProcClass", "browse", 0));
        label->setText(QApplication::translate("ImagePreProcClass", "Source Directory", 0));
        bt_browseSrc->setText(QApplication::translate("ImagePreProcClass", "browse", 0));
        bt_browseTrain->setText(QApplication::translate("ImagePreProcClass", "browse", 0));
        bt_start->setText(QApplication::translate("ImagePreProcClass", "Resize Source Images", 0));
        label_5->setText(QApplication::translate("ImagePreProcClass", "Object Class ID Number", 0));
        ed_classID->setText(QApplication::translate("ImagePreProcClass", "0", 0));
        bt_trainInfo->setText(QApplication::translate("ImagePreProcClass", "Create Training Info in Final Directory", 0));
        label_4->setText(QApplication::translate("ImagePreProcClass", "Train Image Folder Name", 0));
        ed_trainFdr->setText(QApplication::translate("ImagePreProcClass", "data/obj", 0));
        bt_trainSummary->setText(QApplication::translate("ImagePreProcClass", "Create Summary train.txt", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagePreProcClass: public Ui_ImagePreProcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPREPROC_H
