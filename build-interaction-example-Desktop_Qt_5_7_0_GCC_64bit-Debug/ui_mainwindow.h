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
#include <QtWidgets/QDoubleSpinBox>
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
    QHBoxLayout *hLayout;
    QLabel *erreurMessage;
    QPushButton *pushButton;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *expression;
    QDoubleSpinBox *precision;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *xMin;
    QLabel *label_2;
    QSpinBox *xMax;
    QLabel *label_5;
    QSpinBox *yMin;
    QLabel *label_4;
    QSpinBox *yMax;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Nettoyer;
    QPushButton *valider;
    QHBoxLayout *horizontalLayout_4;
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
        hLayout = new QHBoxLayout();
        hLayout->setSpacing(6);
        hLayout->setObjectName(QStringLiteral("hLayout"));
        hLayout->setContentsMargins(-1, 17, -1, -1);
        erreurMessage = new QLabel(centralWidget);
        erreurMessage->setObjectName(QStringLiteral("erreurMessage"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(233, 28, 6, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 116, 101, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(244, 72, 53, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(116, 14, 3, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(155, 18, 4, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(244, 141, 130, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        erreurMessage->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        erreurMessage->setFont(font);

        hLayout->addWidget(erreurMessage, 0, Qt::AlignHCenter);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));

        hLayout->addWidget(pushButton, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(hLayout);

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

        expression = new QLineEdit(frame);
        expression->setObjectName(QStringLiteral("expression"));
        expression->setMaximumSize(QSize(700, 400));

        horizontalLayout->addWidget(expression);

        precision = new QDoubleSpinBox(frame);
        precision->setObjectName(QStringLiteral("precision"));
        precision->setMinimum(0.01);
        precision->setValue(1);

        horizontalLayout->addWidget(precision);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 5, -1, -1);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_3);

        xMin = new QSpinBox(frame);
        xMin->setObjectName(QStringLiteral("xMin"));
        xMin->setMaximumSize(QSize(50, 16777215));
        xMin->setMinimum(-1000);
        xMin->setMaximum(1000);
        xMin->setValue(-5);

        horizontalLayout_3->addWidget(xMin);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_2);

        xMax = new QSpinBox(frame);
        xMax->setObjectName(QStringLiteral("xMax"));
        xMax->setMinimumSize(QSize(50, 0));
        xMax->setMaximumSize(QSize(50, 50));
        xMax->setMinimum(-1000);
        xMax->setMaximum(1000);
        xMax->setValue(5);

        horizontalLayout_3->addWidget(xMax);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_5);

        yMin = new QSpinBox(frame);
        yMin->setObjectName(QStringLiteral("yMin"));
        yMin->setMaximumSize(QSize(50, 50));
        yMin->setMinimum(-1000);
        yMin->setMaximum(1000);
        yMin->setValue(-10);

        horizontalLayout_3->addWidget(yMin);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_4);

        yMax = new QSpinBox(frame);
        yMax->setObjectName(QStringLiteral("yMax"));
        yMax->setMaximumSize(QSize(50, 16777215));
        yMax->setValue(10);

        horizontalLayout_3->addWidget(yMax);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 14, -1, -1);
        Nettoyer = new QPushButton(frame);
        Nettoyer->setObjectName(QStringLiteral("Nettoyer"));

        horizontalLayout_2->addWidget(Nettoyer);

        valider = new QPushButton(frame);
        valider->setObjectName(QStringLiteral("valider"));

        horizontalLayout_2->addWidget(valider);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 23, -1, -1);

        verticalLayout->addLayout(horizontalLayout_4);

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
        erreurMessage->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#f9372f;\">TextLabel</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "OK", 0));
        label->setText(QApplication::translate("MainWindow", "Y =", 0));
        expression->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Min x =", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max x =", 0));
        label_5->setText(QApplication::translate("MainWindow", "Min y =", 0));
        label_4->setText(QApplication::translate("MainWindow", "Max y =", 0));
        Nettoyer->setText(QApplication::translate("MainWindow", "Nettoyer le graphique", 0));
        valider->setText(QApplication::translate("MainWindow", "Valider", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
