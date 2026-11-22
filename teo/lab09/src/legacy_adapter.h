#pragma once
#include "repositorio.h"
#include <QString>
// Formato heredado: clase;nombre;peso;dia/mes/año, con encabezado opcional.
class LectorCsvHeredado {
public:
    std::vector<std::pair<TipoActividad, DatosActividad>> leer(const QString& ruta) const;
};
class AdaptadorCsv final {
public:
    explicit AdaptadorCsv(IRepositorio& repositorio) : repositorio_(repositorio) {}
    int importar(const QString& ruta) const;
private:
    IRepositorio& repositorio_;
    LectorCsvHeredado lector_;
};
