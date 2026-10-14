#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Datos de países
    paises = {
        {"Perú", "Español", "Lima"},
        {"Argentina", "Español", "Buenos Aires"},
        {"Brasil", "Portugués", "Brasilia"},
        {"Chile", "Español", "Santiago"},
        {"Colombia", "Español", "Bogotá"},
        {"México", "Español", "Ciudad de México"},
        {"Francia", "Francés", "París"},
        {"Italia", "Italiano", "Roma"},
        {"Alemania", "Alemán", "Berlín"},
        {"Japón", "Japonés", "Tokio"},
        {"China", "Chino mandarín", "Pekín"},
        {"EE.UU.", "Inglés", "Washington D.C."}
    };

    // Llenar QListWidget
    for (const Pais &p : paises) {
        ui->listaPaises->addItem(p.nombre);
    }

    // Conectar señal itemClicked con slot
    connect(ui->listaPaises, &QListWidget::itemClicked,
            this, &MainWindow::mostrarDatosPais);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarDatosPais(QListWidgetItem *item)
{
    if (!item)
        return;

    QString nombrePais = item->text();

    for (const Pais &p : paises) {
        if (p.nombre == nombrePais) {
            ui->labelResultado->setText(
                QString("País: %1\nIdioma: %2\nCapital: %3")
                    .arg(p.nombre)
                    .arg(p.idioma)
                    .arg(p.capital)
                );
            return;
        }
    }

    ui->labelResultado->setText("País no encontrado");
}