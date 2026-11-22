#pragma once
#include "actividad.h"
#include <vector>
class IRepositorio {
public:
    virtual ~IRepositorio() = default;
    virtual void guardar(std::unique_ptr<Actividad> actividad) = 0;
    virtual const std::vector<std::unique_ptr<Actividad>>& listar() const = 0;
};
class RepositorioActividades final : public IRepositorio {
public:
    void guardar(std::unique_ptr<Actividad> actividad) override;
    const std::vector<std::unique_ptr<Actividad>>& listar() const override { return actividades_; }
private:
    std::vector<std::unique_ptr<Actividad>> actividades_;
};
