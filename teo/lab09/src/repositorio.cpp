#include "repositorio.h"
#include <stdexcept>
void RepositorioActividades::guardar(std::unique_ptr<Actividad> actividad) {
    if (!actividad) throw std::invalid_argument("Actividad nula");
    actividades_.push_back(std::move(actividad));
}
