/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCr_cr;
    QAction *actionGreger;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_4;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 627);
        actionCr_cr = new QAction(MainWindow);
        actionCr_cr->setObjectName(QStringLiteral("actionCr_cr"));
        actionGreger = new QAction(MainWindow);
        actionGreger->setObjectName(QStringLiteral("actionGreger"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(frame_2);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(customPlot);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(700, 400));

        horizontalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 5, -1, -1);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_3);

        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximumSize(QSize(50, 16777215));
        spinBox_2->setMinimum(-1000);
        spinBox_2->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBox_2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_2);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(50, 0));
        spinBox->setMaximumSize(QSize(50, 50));
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBox);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_5);

        spinBox_4 = new QSpinBox(frame);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(spinBox_4);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_4);

        spinBox_3 = new QSpinBox(frame);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(spinBox_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCustomPlot Interaction Example", 0));
        actionCr_cr->setText(QApplication::translate("MainWindow", "cr\"cr", 0));
        actionGreger->setText(QApplication::translate("MainWindow", "greger", 0));
        label->setText(QApplication::translate("MainWindow", "Y =", 0));
        lineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Valider", 0));
        label_3->setText(QApplication::translate("MainWindow", "Min x =", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max x =", 0));
        label_5->setText(QApplication::translate("MainWindow", "Min y =", 0));
        label_4->setText(QApplication::translate("MainWindow", "Max y =", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
