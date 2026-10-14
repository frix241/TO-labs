#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mostrarDatosPais(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    struct Pais {
        QString nombre;
        QString idioma;
        QString capital;
    };

    QVector<Pais> paises;
};

#endif // MAINWINDOW_H