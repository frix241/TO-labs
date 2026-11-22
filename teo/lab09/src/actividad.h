#pragma once
#include <QString>
#include <memory>
#include <stdexcept>

enum class TipoActividad { Tarea, Examen, Proyecto };
struct DatosActividad { QString titulo; int ponderacion; QString fecha; };
class Actividad {
public:
    explicit Actividad(DatosActividad datos) : datos_(std::move(datos)) {}
    virtual ~Actividad() = default;
    virtual QString tipo() const = 0;
    const DatosActividad& datos() const { return datos_; }
private:
    DatosActividad datos_;
};
class Tarea final : public Actividad { public: using Actividad::Actividad; QString tipo() const override { return "Tarea"; } };
class Examen final : public Actividad { public: using Actividad::Actividad; QString tipo() const override { return "Examen"; } };
class Proyecto final : public Actividad { public: using Actividad::Actividad; QString tipo() const override { return "Proyecto"; } };
class CreadorActividad {
public:
    virtual ~CreadorActividad() = default;
    std::unique_ptr<Actividad> crear(const DatosActividad& datos) const;
protected:
    virtual std::unique_ptr<Actividad> fabricar(const DatosActividad& datos) const = 0;
};
class CreadorTarea final : public CreadorActividad { protected: std::unique_ptr<Actividad> fabricar(const DatosActividad& d) const override { return std::make_unique<Tarea>(d); } };
class CreadorExamen final : public CreadorActividad { protected: std::unique_ptr<Actividad> fabricar(const DatosActividad& d) const override { return std::make_unique<Examen>(d); } };
class CreadorProyecto final : public CreadorActividad { protected: std::unique_ptr<Actividad> fabricar(const DatosActividad& d) const override { return std::make_unique<Proyecto>(d); } };
std::unique_ptr<Actividad> crearActividad(TipoActividad tipo, const DatosActividad& datos);
