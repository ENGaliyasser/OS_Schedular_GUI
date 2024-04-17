/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *project_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *algo_label;
    QComboBox *algorithm_comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *no_process_label;
    QSpinBox *no_of_process_value;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *algo_type;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *Non_preemptive;
    QRadioButton *preemptive;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *quantum_label;
    QSpinBox *quantum_value;
    QTableWidget *data_table;
    QPushButton *simulate_button;
    QTableWidget *gantt_chart;
    QLabel *avg_wait;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *timeline;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1217, 773);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        project_label = new QLabel(centralwidget);
        project_label->setObjectName("project_label");
        project_label->setGeometry(QRect(310, 10, 251, 61));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        project_label->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(32, 92, 551, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        algo_label = new QLabel(layoutWidget);
        algo_label->setObjectName("algo_label");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        algo_label->setFont(font1);

        horizontalLayout->addWidget(algo_label);

        algorithm_comboBox = new QComboBox(layoutWidget);
        algorithm_comboBox->addItem(QString());
        algorithm_comboBox->addItem(QString());
        algorithm_comboBox->addItem(QString());
        algorithm_comboBox->addItem(QString());
        algorithm_comboBox->setObjectName("algorithm_comboBox");
        algorithm_comboBox->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(algorithm_comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        no_process_label = new QLabel(layoutWidget);
        no_process_label->setObjectName("no_process_label");
        no_process_label->setFont(font1);

        horizontalLayout_2->addWidget(no_process_label);

        no_of_process_value = new QSpinBox(layoutWidget);
        no_of_process_value->setObjectName("no_of_process_value");

        horizontalLayout_2->addWidget(no_of_process_value);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(32, 240, 551, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        algo_type = new QLabel(layoutWidget1);
        algo_type->setObjectName("algo_type");
        algo_type->setFont(font1);

        horizontalLayout_4->addWidget(algo_type);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Non_preemptive = new QRadioButton(layoutWidget1);
        Non_preemptive->setObjectName("Non_preemptive");

        horizontalLayout_3->addWidget(Non_preemptive);

        preemptive = new QRadioButton(layoutWidget1);
        preemptive->setObjectName("preemptive");

        horizontalLayout_3->addWidget(preemptive);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 280, 551, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        quantum_label = new QLabel(layoutWidget2);
        quantum_label->setObjectName("quantum_label");
        quantum_label->setFont(font1);

        horizontalLayout_5->addWidget(quantum_label);

        quantum_value = new QSpinBox(layoutWidget2);
        quantum_value->setObjectName("quantum_value");

        horizontalLayout_5->addWidget(quantum_value);

        data_table = new QTableWidget(centralwidget);
        data_table->setObjectName("data_table");
        data_table->setGeometry(QRect(30, 330, 551, 261));
        simulate_button = new QPushButton(centralwidget);
        simulate_button->setObjectName("simulate_button");
        simulate_button->setGeometry(QRect(30, 600, 161, 51));
        gantt_chart = new QTableWidget(centralwidget);
        gantt_chart->setObjectName("gantt_chart");
        gantt_chart->setGeometry(QRect(30, 660, 1141, 91));
        avg_wait = new QLabel(centralwidget);
        avg_wait->setObjectName("avg_wait");
        avg_wait->setGeometry(QRect(770, 470, 401, 61));
        QFont font2;
        font2.setPointSize(12);
        avg_wait->setFont(font2);
        avg_wait->setStyleSheet(QString::fromUtf8(" border-style: solid;\n"
"  border-color: black;\n"
"  border-width: 7px;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(770, 90, 401, 311));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font2);

        verticalLayout_2->addWidget(label);

        timeline = new QTableWidget(widget);
        timeline->setObjectName("timeline");

        verticalLayout_2->addWidget(timeline);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        project_label->setText(QCoreApplication::translate("MainWindow", "OS Scheduler", nullptr));
        algo_label->setText(QCoreApplication::translate("MainWindow", "Scheduling Algorithm", nullptr));
        algorithm_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1. FCFS", nullptr));
        algorithm_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2. SJF", nullptr));
        algorithm_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3. Priority", nullptr));
        algorithm_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4. Round Robin", nullptr));

        no_process_label->setText(QCoreApplication::translate("MainWindow", "Number of Process", nullptr));
        algo_type->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        Non_preemptive->setText(QCoreApplication::translate("MainWindow", "Non Preemptive", nullptr));
        preemptive->setText(QCoreApplication::translate("MainWindow", "Preemptive", nullptr));
        quantum_label->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        simulate_button->setText(QCoreApplication::translate("MainWindow", "Simulate", nullptr));
        avg_wait->setText(QCoreApplication::translate("MainWindow", "Average Waiting Time : ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Processes  Time Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
