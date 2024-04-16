#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColor>
#include<QMessageBox>
#include"process.h"
#include<QtAlgorithms>
#include"fcfs_algorithm.h"
#include"sjf_algorithm.h"
#include"priority_algorithm.h"
#include "round_robin.h"
#include <thread>
#include <chrono>
#include "preemative_sjf.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <mutex>
#include <QTimer>
#include <QDebug>
#include <QHash>
QVector<int> inProgress;
int totalWidth = 0; // Total width of all rectangles
int total_time=0;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_algorithm_comboBox_currentTextChanged(const QString &arg1)
{
    if( arg1=="3. Priority"){
        ui->preemptive->show();
        ui->Non_preemptive->show();
        ui->algo_type->show();

        ui->quantum_label->hide();
        ui->quantum_value->hide();

        ui->data_table->showColumn(3);
    }
    else if(arg1=="2. SJF" ){
        ui->preemptive->show();
        ui->Non_preemptive->show();
        ui->algo_type->show();

        ui->quantum_label->hide();
        ui->quantum_value->hide();

        ui->data_table->hideColumn(3);
    }
    else if(arg1=="4. Round Robin" ){
        ui->preemptive->hide();
        ui->Non_preemptive->hide();
        ui->algo_type->hide();

        ui->quantum_label->show();
        ui->quantum_value->show();

        ui->data_table->hideColumn(3);

    }
    else if("1. FCFS"){
        ui->preemptive->hide();
        ui->Non_preemptive->hide();
        ui->algo_type->hide();

        ui->quantum_label->hide();
        ui->quantum_value->hide();

        ui->data_table->hideColumn(3);
    }
}

void MainWindow::on_no_of_process_value_valueChanged(int arg1)
{
    ui->data_table->setRowCount(arg1);
}

QVector<Process> MainWindow::get_data_from_table(){
    int no_of_processes=ui->no_of_process_value->value();
    QVector<Process>v;

    for(int i=0;i<no_of_processes;i++){
       int priority=0;
       if(ui->algorithm_comboBox->currentText()=="3. Priority"){
           priority = ui->data_table->item(i,3)->text().toInt();
       }
       Process p(ui->data_table->item(i,0)->text().toInt(),
                 ui->data_table->item(i,1)->text().toInt(),
                 ui->data_table->item(i,2)->text().toInt(),
                 priority);
       v.push_back(p);
    }
    return v;
}

bool MainWindow::vaild_data(){
    QTableWidgetItem* item;
    QTableWidgetItem* item1;
    QTableWidgetItem* item2;
    QTableWidgetItem* item3;
    int no_of_processes=ui->no_of_process_value->value();
    for(int i=0;i<no_of_processes;i++){
        if(ui->algorithm_comboBox->currentText()=="3. Priority"){
             item = ui->data_table->item(i,3);
             if (!item || item->text().isEmpty() || item->text().toInt()<0)
             {
                 QMessageBox::critical(this,"error","please enter vaild data !!");
                return 0;
             }
        }
        item1 = ui->data_table->item(i,0);
        item2 = ui->data_table->item(i,1);
        item3 = ui->data_table->item(i,2);
        if (    (!item1 || item1->text().isEmpty()||item1->text().toInt()<0)    ||
                (!item2 || item2->text().isEmpty()||item2->text().toInt()<0)    ||
                (!item3 || item3->text().isEmpty()||item3->text().toInt()<0)   )
        {
            QMessageBox::critical(this,"error","please enter vaild data !!");
           return 0;
        }
    }
    return 1;

}

void MainWindow::on_simulate_button_clicked()
{
    if(ui->no_of_process_value->value()>0 && vaild_data()){
        QVector<Process>v = get_data_from_table();
        QString algorithm =ui->algorithm_comboBox->currentText();
        QString algo_type;
        if(algorithm =="3. Priority" || algorithm=="2. SJF"){
            if(ui->preemptive->isChecked()){
                algo_type ="preemptive";
            }else{
                algo_type="non_preemptive";
            }
        }
        float avg_waiting=0;
        QVector<Process>processes;
        if(algorithm=="1. FCFS"){
            processes=FCFS_Algorithm::fcfs(v,avg_waiting);
        }
        else if(algorithm=="2. SJF"){
            if(algo_type=="preemptive"){
                processes=findavgTime(v,avg_waiting);
            }else{
                processes=sjf_algorithm::sjf_non_preemptive(v,avg_waiting);
            }
        }
        else if(algorithm=="3. Priority"){
            if(algo_type=="preemptive"){
                processes=priority_algorithm::Priority_preemitive(v,avg_waiting);
            }else{
                processes=priority_algorithm::Priority_nonPreemptive(v,avg_waiting);
            }
        }
        else if(algorithm=="4. Round Robin"){
            int quantum=ui->quantum_value->value();
            if(quantum==0){
                QMessageBox::critical(this,"error","please enter vaild quantum !!");
                return;
            }
            processes=round_robin::RR(v,quantum,avg_waiting);
        }
        int totaltime=0;
        for(int i=0;i<processes.length();i++){
            totaltime+= processes[i].get_process_burst_time();
        }
        qDebug()<<"Total time = "<<totaltime;
        //Start the timer
        QTimer *timer = new QTimer(this);

        connect(timer, &QTimer::timeout, [=]() {
            static int secondsElapsed = 0;
            ui->timerLabel->setText(QString::number(secondsElapsed++) + " seconds");

            // Stop the timer after 60 seconds
            if (secondsElapsed >totaltime) {
                timer->stop();
                delete timer; // Cleanup the timer object
            }
        });
        timer->start(1000); // Update every second


        draw(processes,avg_waiting);
        set_process_time_line(processes);
    }
}

void MainWindow::draw(QVector<Process>v,float avg_w){
    int n=v.size();
    ui->gantt_chart->setColumnCount(n);
    ui->gantt_chart->setRowCount(1);
    QStringList h;
    h<<"time";
    ui->gantt_chart->setVerticalHeaderLabels(h);

    QStringList h2;
    int total_time=0;
    for(int i=0;i<n;i++){
        total_time+=v[i].get_process_burst_time();
        h2<<"p"+QString::number(v[i].get_process_Id());
        QString s=QString::number(v[i].get_process_burst_time());
        ui->gantt_chart->setItem(0,i, new QTableWidgetItem);
        ui->gantt_chart->item(0,i)->setText(s);
        ui->gantt_chart->item(0,i)->setTextAlignment(Qt::AlignCenter);
        ui->gantt_chart->item(0,i)->setBackground(Qt::gray);
    }
    for(int i=0;i<n;i++){
        if(v[i].get_process_burst_time())
            ui->gantt_chart->setColumnWidth(i,  v[i].get_process_burst_time()*1080/total_time);
    }
    ui->gantt_chart->setHorizontalHeaderLabels(h2);
    ui->avg_wait->setText("Average Waiting Time: "+QString::number(avg_w));
    //timer.start(total_time * 1000);
   // elapsedTimer.start();
}

void MainWindow::set_process_time_line(QVector<Process>v){
    int n=v.size();
    ui->timeline->setColumnCount(3);
    ui->timeline->setRowCount(n);
    QStringList h;
    h<<"process Id"<<"start time"<<"end time";
    ui->timeline->setHorizontalHeaderLabels(h);

    for(int i=0;i<n;i++){
        ui->timeline->setItem(i,0, new QTableWidgetItem);
        ui->timeline->setItem(i,1, new QTableWidgetItem);
        ui->timeline->setItem(i,2, new QTableWidgetItem);
        ui->timeline->item(i,0)->setText(QString::number(v[i].get_process_Id()));
        ui->timeline->item(i,1)->setText(QString::number(v[i].get_start_time()));
        ui->timeline->item(i,2)->setText(QString::number(v[i].get_end_time()));
    }
}



class Widget : public QWidget {
public:
    QTimer *timer = new QTimer(this);
    Widget(QWidget *parent = nullptr) : QWidget(parent), currentIndex(0) {
        connect(timer, &QTimer::timeout, this, &Widget::updateValue);
        timer->start(1000); // Trigger every 1 second
        setFixedSize(2000, 200);
    }

    QSize sizeHint() const {
        return QSize(qMax(totalWidth, 400), 200); // Set the size hint to the maximum of the total width and 400
    }




protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event)
        QPainter painter(this);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12));

        int rectWidth = 50; // Width of each rectangle
        int margin = 20; // Margin around the rectangles

        // Draw rectangles and values
        for (int i = 0; i < values.size(); ++i) {
            QRect rect(margin + i * rectWidth, margin, rectWidth, height() - 2 * margin);
            painter.drawText(rect, Qt::AlignCenter, QString::number(values[i]));
            painter.drawRect(rect);
        }
    }

private slots:
    void updateValue() {
        // Update values here from another function
        values.append(inProgress[value]);
        ++value;
        totalWidth += 50; // Increment total width
        if(value < inProgress.size()) {
            update(); // Trigger repaint
            updateGeometry(); // Notify layout system about size change
        } else {
            update(); // Trigger repaint
            updateGeometry(); // Notify layout system about size change
            timer->stop();
        }
    }


private:
    QList<int> values; // Values to display inside the rectangles
    int value = 0; // Current value
    int currentIndex; // Index to update in the values array

};

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString init="1. FCFS";
    on_algorithm_comboBox_currentTextChanged(init);

    ui->data_table->setColumnCount(4);
    ui->data_table->setRowCount(0);
    ui->data_table->hideColumn(3);
    QStringList h;
    h<<"process id"<<"burst time"<<"arrival time"<<"priority";
    ui->data_table->setHorizontalHeaderLabels(h);
    ui->data_table->setItem(0,0, new QTableWidgetItem);
    ui->quantum_value->setValue(2);

    //QPushButton *button = new QPushButton("Live Gantt chart", this);
    connect(ui->LiveGantt, &QPushButton::clicked, this, &MainWindow::openWidget);

}

void MainWindow::openWidget() {
    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea;

    // Create your Widget
    Widget *widget = new Widget;

    // Set widget's attribute
    widget->setAttribute(Qt::WA_DeleteOnClose); // Delete widget on close

    // Set up the scroll area
    scrollArea->setWidget(widget);
    scrollArea->setWidgetResizable(true); // Resize the widget to the size of the scroll area

    // Set scroll policy for horizontal scrollbar
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // Show the scroll area
    scrollArea->show();
}


