#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>
#include <QElapsedTimer>

// Función plantilla para probar cualquier contenedor
template <typename Container>
void probarContenedor(const QString &nombre, int N)
{
    Container c;
    QElapsedTimer timer;

    // 1. Append (agregar al final)
    timer.start();
    for (int i = 0; i < N; ++i) {
        c.append(i);
    }
    qint64 tAppend = timer.elapsed();

    // 2. Prepend (agregar al inicio)
    timer.restart();
    for (int i = 0; i < N; ++i) {
        c.prepend(i);
    }
    qint64 tPrepend = timer.elapsed();

    // 3. Insert en el medio
    timer.restart();
    for (int i = 0; i < N; ++i) {
        c.insert(c.size() / 2, i);
    }
    qint64 tInsert = timer.elapsed();

    // 4. Acceso por índice
    timer.restart();
    volatile int suma = 0;
    for (int i = 0; i < c.size(); ++i) {
        suma += c.at(i);
    }
    qint64 tAccess = timer.elapsed();

    // 5. Eliminar el primero
    timer.restart();
    while (!c.isEmpty()) {
        c.removeFirst();
    }
    qint64 tRemoveFirst = timer.elapsed();

    qDebug() << "=== " << nombre << " ===";
    qDebug() << "Tamaño final:" << c.size();
    qDebug() << "Append:        " << tAppend << "ms";
    qDebug() << "Prepend:       " << tPrepend << "ms";
    qDebug() << "Insert medio:  " << tInsert << "ms";
    qDebug() << "Acceso:        " << tAccess << "ms";
    qDebug() << "RemoveFirst:   " << tRemoveFirst << "ms";
    qDebug() << "";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int N = 10000; // Puedes subirlo a 50000 para notar más diferencias

    qDebug() << "Demostración QVector vs QList (Qt" << QT_VERSION_STR << ")";
    qDebug() << "N =" << N << "\n";

    probarContenedor<QVector<int>>("QVector<int>", N);
    probarContenedor<QList<int>>("QList<int>", N);

    qDebug() << "Nota: En Qt6, QVector es un alias de QList.";
    qDebug() << "En Qt5, QVector usa memoria contigua y QList usa arreglo de punteros.";

    return 0; // No necesitamos event loop
}