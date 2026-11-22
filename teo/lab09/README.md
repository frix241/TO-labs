# TO · Laboratorio 09 — seguimiento académico

Código fuente de la aplicación Qt 6 Widgets en C++20. `src` separa Modelo (`Actividad`, `IRepositorio`, `RepositorioActividades`), Vista (`MainWindow`) y Controlador (`ActividadController`). El modelo usa Factory Method para tarea, examen y proyecto; `AdaptadorCsv` importa el CSV heredado `clase;nombre;peso;fecha` con fecha `dd/MM/yyyy`.

## Compilar con CMake

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/seguimiento_academico
```

## Alternativa con qmake6

```sh
mkdir -p build/app build/tests
cd build/app && qmake6 ../../seguimiento.pro && make -j2
cd ../tests && qmake6 ../../tests/core_tests.pro && make -j2 && ./academico_tests -txt
```

La vista invoca solo al controlador. Las pruebas de Qt Test ejecutan modelo, controlador y adaptador sin iniciar la GUI. El importador valida el lote antes de guardarlo; un registro inválido no agrega actividades.
