#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include <QDebug>
#include <QInputDialog>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    qDebug() << "Slot corresponde al clic en el boton ...";

    bool ok;
    QString name = QInputDialog::getText(this, "Nueva tarea", "Nombre de la tarea:",
                                         QLineEdit::Normal, "Tarea", &ok);
    if (!ok || name.isEmpty())
        return;

    Task *task = new Task(name);
    mTasks.append(task);
    centralWidget()->layout()->addWidget(task);

    // señal de Task -> slot de MainWindow
    connect(task, &Task::statusChanged, this, &MainWindow::updateStatus);

    updateStatus();
}

void MainWindow::updateStatus()
{
    int hechas = 0;
    for (Task *t : mTasks) {
        if (t->isCompleted())
            hechas++;
    }
    int pendientes = mTasks.size() - hechas;

    ui->statusLabel->setText(QString("Status: %1 todo / %2 hecho")
                                 .arg(pendientes).arg(hechas));
}