#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui { class Task; }

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString &name = QString(), QWidget *parent = nullptr);
    ~Task();

    void setName(const QString &name);
    QString name() const;
    bool isCompleted() const;

signals:
    void statusChanged(Task *task);   // señal hacia MainWindow

private slots:
    void checked(bool checked);       // slot interno del checkbox

private:
    Ui::Task *ui;
};

#endif // TASK_H