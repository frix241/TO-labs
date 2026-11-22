#include "actividad_controller.h"
#include <QSignalSpy>
#include <QTemporaryFile>
#include <QtTest>
class CoreTest : public QObject {
    Q_OBJECT
private slots:
    void factoryAndValidation() {
        auto a = crearActividad(TipoActividad::Proyecto, {"Entrega",30,"2026-11-22"});
        QCOMPARE(a->tipo(), QString("Proyecto"));
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, crearActividad(TipoActividad::Tarea, {"",20,"2026-11-22"}));
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, crearActividad(TipoActividad::Examen, {"Parcial",101,"2026-11-22"}));
    }
    void controllerWithoutGui() {
        RepositorioActividades repo; ActividadController controller(repo);
        QSignalSpy changed(&controller, &ActividadController::actividadesCambiadas);
        QSignalSpy errors(&controller, &ActividadController::error);
        QVERIFY(controller.crear(0,"Lectura",10,"2026-11-22"));
        QVERIFY(!controller.crear(1,"",10,"2026-11-22"));
        QCOMPARE(changed.size(),1); QCOMPARE(errors.size(),1); QCOMPARE(controller.listar().size(),1);
    }
    void adapterIsAtomicOnValidationError() {
        RepositorioActividades repo; ActividadController controller(repo);
        QTemporaryFile csv; QVERIFY(csv.open());
        csv.write("clase;nombre;peso;fecha\nt;Informe;20;22/11/2026\ne;Examen;200;23/11/2026\n"); csv.flush();
        QVERIFY(!controller.cargarCsv(csv.fileName())); QCOMPARE(repo.listar().size(),size_t(0));
        csv.resize(0); csv.seek(0); csv.write("p;Proyecto final;40;24/11/2026\n"); csv.flush();
        QVERIFY(controller.cargarCsv(csv.fileName())); QCOMPARE(repo.listar().size(),size_t(1));
        QCOMPARE(repo.listar()[0]->datos().fecha, QString("2026-11-24"));
    }
};
QTEST_GUILESS_MAIN(CoreTest)
#include "test_core.moc"
