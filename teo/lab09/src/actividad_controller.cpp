#include "actividad_controller.h"
#include <exception>
ActividadController::ActividadController(IRepositorio& repositorio, QObject* parent)
    : QObject(parent), repositorio_(repositorio), adaptador_(repositorio) {}
bool ActividadController::crear(int tipo, const QString& titulo, int ponderacion, const QString& fecha) {
    try {
        if (tipo < 0 || tipo > 2) throw std::invalid_argument("Tipo desconocido");
        repositorio_.guardar(crearActividad(static_cast<TipoActividad>(tipo), {titulo, ponderacion, fecha}));
        emit actividadesCambiadas(); return true;
    } catch (const std::exception& ex) { emit error(QString::fromUtf8(ex.what())); return false; }
}
bool ActividadController::cargarCsv(const QString& ruta) {
    try { adaptador_.importar(ruta); emit actividadesCambiadas(); return true; }
    catch (const std::exception& ex) { emit error(QString::fromUtf8(ex.what())); return false; }
}
QStringList ActividadController::listar() const {
    QStringList result;
    for (const auto& a : repositorio_.listar()) result << QString("%1 | %2 | %3% | %4").arg(a->tipo(), a->datos().titulo, QString::number(a->datos().ponderacion), a->datos().fecha);
    return result;
}
