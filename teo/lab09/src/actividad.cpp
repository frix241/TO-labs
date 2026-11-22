#include "actividad.h"
#include <QDate>
std::unique_ptr<Actividad> CreadorActividad::crear(const DatosActividad& datos) const {
    if (datos.titulo.trimmed().isEmpty()) throw std::invalid_argument("El título es obligatorio");
    if (datos.ponderacion < 1 || datos.ponderacion > 100) throw std::invalid_argument("La ponderación debe estar entre 1 y 100");
    if (!QDate::fromString(datos.fecha, Qt::ISODate).isValid()) throw std::invalid_argument("La fecha debe ser válida (AAAA-MM-DD)");
    return fabricar(datos);
}
std::unique_ptr<Actividad> crearActividad(TipoActividad tipo, const DatosActividad& datos) {
    switch (tipo) {
    case TipoActividad::Tarea: return CreadorTarea{}.crear(datos);
    case TipoActividad::Examen: return CreadorExamen{}.crear(datos);
    case TipoActividad::Proyecto: return CreadorProyecto{}.crear(datos);
    }
    throw std::invalid_argument("Tipo de actividad desconocido");
}
