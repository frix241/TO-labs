#pragma once
#include "actividad_controller.h"
#include <QMainWindow>
class QComboBox; class QLineEdit; class QSpinBox; class QDateEdit; class QListWidget;
class MainWindow final : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(ActividadController& controller);
private:
    ActividadController& controller_;
    QComboBox* tipo_; QLineEdit* titulo_; QSpinBox* ponderacion_; QDateEdit* fecha_; QListWidget* lista_;
    void actualizar();
};
