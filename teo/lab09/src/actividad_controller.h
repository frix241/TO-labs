#pragma once
#include "legacy_adapter.h"
#include <QObject>
#include <QStringList>
class ActividadController final : public QObject {
    Q_OBJECT
public:
    explicit ActividadController(IRepositorio& repositorio, QObject* parent = nullptr);
    bool crear(int tipo, const QString& titulo, int ponderacion, const QString& fecha);
    bool cargarCsv(const QString& ruta);
    QStringList listar() const;
signals:
    void actividadesCambiadas();
    void error(const QString& mensaje);
private:
    IRepositorio& repositorio_;
    AdaptadorCsv adaptador_;
};
