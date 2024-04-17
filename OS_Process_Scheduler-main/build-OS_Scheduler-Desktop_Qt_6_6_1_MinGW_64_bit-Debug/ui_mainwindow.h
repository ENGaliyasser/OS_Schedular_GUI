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
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *timeline;
    QPushButton *LiveGantt;
    QLabel *timerLabel;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *data_table_2;
    QLabel *label_3;
    QPushButton *AddDynamically;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1217, 773);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 18, 18);\n"
"color: rgb(85, 170, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        project_label = new QLabel(centralwidget);
        project_label->setObjectName("project_label");
        project_label->setGeometry(QRect(500, 20, 271, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font.setPointSize(31);
        font.setBold(true);
        project_label->setFont(font);
        project_label->setStyleSheet(QString::fromUtf8(" border-style: dashed;\n"
"  border-color: #343434;\n"
"  border-width: 5px;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(32, 92, 381, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        algo_label = new QLabel(layoutWidget);
        algo_label->setObjectName("algo_label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
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
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(52, 52, 52, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(29, 84, 92, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        QBrush brush4(QColor(0, 120, 212, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        algorithm_comboBox->setPalette(palette);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        algorithm_comboBox->setFont(font2);
        algorithm_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);\n"
"color: rgb(255, 255, 255);\n"
""));
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
        no_of_process_value->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 4px solid;\n"
"border-color: rgb(18, 18, 18);\n"
"background-color: rgb(52, 52, 52);"));

        horizontalLayout_2->addWidget(no_of_process_value);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(32, 240, 381, 37));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        algo_type = new QLabel(layoutWidget1);
        algo_type->setObjectName("algo_type");
        algo_type->setEnabled(true);
        algo_type->setFont(font1);

        horizontalLayout_4->addWidget(algo_type);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Non_preemptive = new QRadioButton(layoutWidget1);
        Non_preemptive->setObjectName("Non_preemptive");
        Non_preemptive->setFont(font2);

        horizontalLayout_3->addWidget(Non_preemptive);

        preemptive = new QRadioButton(layoutWidget1);
        preemptive->setObjectName("preemptive");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font3.setKerning(true);
        preemptive->setFont(font3);

        horizontalLayout_3->addWidget(preemptive);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 280, 381, 38));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        quantum_label = new QLabel(layoutWidget2);
        quantum_label->setObjectName("quantum_label");
        quantum_label->setFont(font1);

        horizontalLayout_5->addWidget(quantum_label);

        quantum_value = new QSpinBox(layoutWidget2);
        quantum_value->setObjectName("quantum_value");
        quantum_value->setEnabled(true);
        quantum_value->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 4px solid;\n"
"border-color: rgb(18, 18, 18);\n"
"background-color: rgb(52, 52, 52);"));

        horizontalLayout_5->addWidget(quantum_value);

        data_table = new QTableWidget(centralwidget);
        data_table->setObjectName("data_table");
        data_table->setGeometry(QRect(30, 327, 421, 261));
        data_table->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);"));
        data_table->setTextElideMode(Qt::ElideLeft);
        simulate_button = new QPushButton(centralwidget);
        simulate_button->setObjectName("simulate_button");
        simulate_button->setGeometry(QRect(30, 600, 161, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font4.setPointSize(15);
        simulate_button->setFont(font4);
        simulate_button->setCursor(QCursor(Qt::OpenHandCursor));
        simulate_button->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);\n"
"color: rgb(255, 255, 255);\n"
"hover :{ background-color: rgb(0, 0, 0); };"));
        gantt_chart = new QTableWidget(centralwidget);
        gantt_chart->setObjectName("gantt_chart");
        gantt_chart->setGeometry(QRect(30, 660, 1141, 91));
        gantt_chart->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 18, 18);"));
        avg_wait = new QLabel(centralwidget);
        avg_wait->setObjectName("avg_wait");
        avg_wait->setGeometry(QRect(520, 430, 531, 61));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font5.setPointSize(20);
        avg_wait->setFont(font5);
        avg_wait->setStyleSheet(QString::fromUtf8(" border-style: dashed;\n"
"  border-color: #343434;\n"
"  border-width: 5px;"));
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(840, 80, 361, 311));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName("label");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font6.setPointSize(24);
        label->setFont(font6);

        verticalLayout_2->addWidget(label);

        timeline = new QTableWidget(layoutWidget3);
        timeline->setObjectName("timeline");
        timeline->setFont(font2);
        timeline->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);"));

        verticalLayout_2->addWidget(timeline);

        LiveGantt = new QPushButton(centralwidget);
        LiveGantt->setObjectName("LiveGantt");
        LiveGantt->setGeometry(QRect(240, 600, 151, 51));
        QPalette palette1;
        QBrush brush5(QColor(85, 170, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(85, 170, 255, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        LiveGantt->setPalette(palette1);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font7.setPointSize(14);
        LiveGantt->setFont(font7);
        LiveGantt->setCursor(QCursor(Qt::OpenHandCursor));
        LiveGantt->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);"));
        timerLabel = new QLabel(centralwidget);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setGeometry(QRect(530, 240, 181, 91));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font8.setPointSize(28);
        timerLabel->setFont(font8);
        timerLabel->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
" border-style: dashed;\n"
"  border-color: #343434;\n"
"  border-width: 5px;"));
        timerLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 180, 151, 41));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font9.setPointSize(36);
        font9.setBold(true);
        label_2->setFont(font9);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(530, 570, 521, 87));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        data_table_2 = new QTableWidget(horizontalLayoutWidget);
        if (data_table_2->columnCount() < 4)
            data_table_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        data_table_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        data_table_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        data_table_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        data_table_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (data_table_2->rowCount() < 1)
            data_table_2->setRowCount(1);
        data_table_2->setObjectName("data_table_2");
        data_table_2->setRowCount(1);
        data_table_2->setColumnCount(4);

        horizontalLayout_7->addWidget(data_table_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 530, 441, 31));
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        AddDynamically = new QPushButton(centralwidget);
        AddDynamically->setObjectName("AddDynamically");
        AddDynamically->setGeometry(QRect(1060, 590, 141, 51));
        AddDynamically->setFont(font4);
        AddDynamically->setCursor(QCursor(Qt::OpenHandCursor));
        AddDynamically->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);\n"
"color: rgb(255, 255, 255);\n"
"hover :{ background-color: rgb(0, 0, 0); };"));
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

        no_process_label->setText(QCoreApplication::translate("MainWindow", "Number of Processes", nullptr));
        algo_type->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        Non_preemptive->setText(QCoreApplication::translate("MainWindow", "Non Preemptive", nullptr));
        preemptive->setText(QCoreApplication::translate("MainWindow", "Preemptive", nullptr));
        quantum_label->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        simulate_button->setText(QCoreApplication::translate("MainWindow", "Simulate", nullptr));
        avg_wait->setText(QCoreApplication::translate("MainWindow", "Average Waiting Time : ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Processes  Timeline", nullptr));
        LiveGantt->setText(QCoreApplication::translate("MainWindow", "Live Gantt Chart", nullptr));
        timerLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data_table_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Process Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data_table_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Burst time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = data_table_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Arrival time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = data_table_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "priority", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Add Process during Runtime", nullptr));
        AddDynamically->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
