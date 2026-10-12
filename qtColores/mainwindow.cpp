#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listColores->addItems({"Rojo", "Verde", "Azul", "Amarillo", "Naranja", "Morado"});
    ui->colorLabel->setText("Elige un color");

    // Signal: cambia el ítem seleccionado -> Slot: mostrar el nombre en el Label
    connect(ui->listColores, &QListWidget::currentTextChanged, this,
            [this](const QString &nombre) {
                ui->colorLabel->setText(nombre);

                // (opcional) pintar el texto con el color elegido
                static const QMap<QString, QString> css = {
                    {"Rojo", "red"}, {"Verde", "green"}, {"Azul", "blue"},
                    {"Amarillo", "goldenrod"}, {"Naranja", "orange"}, {"Morado", "purple"}
                };
                ui->colorLabel->setStyleSheet("color: " + css.value(nombre, "black") + ";");
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}