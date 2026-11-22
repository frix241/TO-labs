#include "mainwindow.h"
#include "repositorio.h"
#include <QApplication>
#include <QDir>
#include <QTimer>
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    RepositorioActividades repositorio;
    ActividadController controller(repositorio);
    MainWindow window(controller); window.show();
    // Capturas del widget real para documentar el flujo cuando no hay acceso al compositor.
    if (argc == 3 && QString::fromUtf8(argv[1]) == "--demo-capture") {
        const QString dir = QString::fromUtf8(argv[2]); QDir().mkpath(dir);
        auto frame = [&window, dir](int n) { window.grab().save(QString("%1/estado%2.png").arg(dir).arg(n)); };
        QTimer::singleShot(250, &app, [&, frame] { frame(0); controller.crear(0,"Informe MVC",20,"2026-11-25"); frame(1);
            controller.crear(1,"Parcial III",30,"2026-11-27"); controller.crear(2,"Proyecto final",50,"2026-11-30"); frame(2); app.quit(); });
    }
    return app.exec();
}
