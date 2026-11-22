#include "mainwindow.h"
#include <QComboBox>
#include <QDateEdit>
#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
MainWindow::MainWindow(ActividadController& controller) : controller_(controller) {
    setWindowTitle("Seguimiento académico · MVC"); resize(780, 540);
    auto* root = new QWidget(this); auto* layout = new QVBoxLayout(root);
    auto* heading = new QLabel("Seguimiento académico", root); heading->setObjectName("heading"); layout->addWidget(heading);
    auto* form = new QFormLayout;
    tipo_ = new QComboBox(root); tipo_->addItems({"Tarea", "Examen", "Proyecto"});
    titulo_ = new QLineEdit(root); titulo_->setPlaceholderText("Ej. Informe de patrones");
    ponderacion_ = new QSpinBox(root); ponderacion_->setRange(1,100); ponderacion_->setValue(20); ponderacion_->setSuffix(" %");
    fecha_ = new QDateEdit(QDate::currentDate(), root); fecha_->setCalendarPopup(true); fecha_->setDisplayFormat("yyyy-MM-dd");
    form->addRow("Tipo", tipo_); form->addRow("Título", titulo_); form->addRow("Ponderación", ponderacion_); form->addRow("Fecha", fecha_); layout->addLayout(form);
    auto* actions = new QHBoxLayout; auto* crear = new QPushButton("Crear actividad", root); auto* cargar = new QPushButton("Importar CSV heredado", root); actions->addWidget(crear); actions->addWidget(cargar); layout->addLayout(actions);
    layout->addWidget(new QLabel("Actividades registradas", root)); lista_ = new QListWidget(root); layout->addWidget(lista_); setCentralWidget(root);
    setStyleSheet("QMainWindow, QWidget { background:#f5f7fb; color:#1b2738; font-size:14px; } QLabel#heading { font-size:25px; font-weight:700; padding:8px 0; } QPushButton { background:#2457b8; color:white; border:0; border-radius:6px; padding:10px; } QPushButton:hover { background:#183f89; } QLineEdit, QComboBox, QSpinBox, QDateEdit, QListWidget { background:white; border:1px solid #bac6d8; border-radius:5px; padding:5px; }");
    connect(crear, &QPushButton::clicked, this, [this]{ if (controller_.crear(tipo_->currentIndex(), titulo_->text(), ponderacion_->value(), fecha_->date().toString(Qt::ISODate))) titulo_->clear(); });
    connect(cargar, &QPushButton::clicked, this, [this]{ auto file = QFileDialog::getOpenFileName(this, "CSV heredado", {}, "CSV (*.csv)"); if (!file.isEmpty()) controller_.cargarCsv(file); });
    connect(&controller_, &ActividadController::actividadesCambiadas, this, &MainWindow::actualizar);
    connect(&controller_, &ActividadController::error, this, [this](const QString& message){ QMessageBox::warning(this, "No se pudo guardar", message); });
    actualizar();
}
void MainWindow::actualizar() { lista_->clear(); lista_->addItems(controller_.listar()); }
