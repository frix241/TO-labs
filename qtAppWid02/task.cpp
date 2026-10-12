#include "task.h"
#include "ui_task.h"
#include <QFont>

Task::Task(const QString &name, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);

    // objeto del formulario Task.ui -> slot de la propia clase Task
    connect(ui->checkbox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->Mitext->setText(name);
}

QString Task::name() const
{
    return ui->Mitext->text();
}

bool Task::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void Task::checked(bool checked)
{
    QFont font(ui->Mitext->font());
    font.setStrikeOut(checked);        // tacha el texto si está hecha
    ui->Mitext->setFont(font);

    emit statusChanged(this);          // avisa a MainWindow
}