#include "legacy_adapter.h"
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <stdexcept>
std::vector<std::pair<TipoActividad, DatosActividad>> LectorCsvHeredado::leer(const QString& ruta) const {
    QFile file(ruta);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) throw std::runtime_error("No se pudo abrir el CSV");
    QTextStream input(&file);
    std::vector<std::pair<TipoActividad, DatosActividad>> rows;
    int line = 0;
    while (!input.atEnd()) {
        QString text = input.readLine().trimmed(); ++line;
        if (text.isEmpty() || (line == 1 && text.startsWith("clase;", Qt::CaseInsensitive))) continue;
        auto fields = text.split(';');
        if (fields.size() != 4) throw std::runtime_error("CSV: se requieren 4 campos en línea " + std::to_string(line));
        QString kind = fields[0].trimmed().toLower();
        TipoActividad tipo;
        if (kind == "t" || kind == "tarea") tipo = TipoActividad::Tarea;
        else if (kind == "e" || kind == "examen") tipo = TipoActividad::Examen;
        else if (kind == "p" || kind == "proyecto") tipo = TipoActividad::Proyecto;
        else throw std::runtime_error("CSV: tipo desconocido en línea " + std::to_string(line));
        bool ok = false;
        int peso = fields[2].trimmed().toInt(&ok);
        QDate fecha = QDate::fromString(fields[3].trimmed(), "dd/MM/yyyy");
        if (!ok || !fecha.isValid()) throw std::runtime_error("CSV: peso o fecha inválidos en línea " + std::to_string(line));
        rows.emplace_back(tipo, DatosActividad{fields[1].trimmed(), peso, fecha.toString(Qt::ISODate)});
    }
    return rows;
}
int AdaptadorCsv::importar(const QString& ruta) const {
    auto rows = lector_.leer(ruta);
    std::vector<std::unique_ptr<Actividad>> validated;
    for (const auto& [tipo, datos] : rows) validated.push_back(crearActividad(tipo, datos));
    for (auto& actividad : validated) repositorio_.guardar(std::move(actividad));
    return static_cast<int>(rows.size());
}
