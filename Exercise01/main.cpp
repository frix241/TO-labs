#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1. Generar vector de 20 enteros aleatorios entre 1 y 100
    QVector<int> numeros;
    numeros.reserve(20);

    for (int i = 0; i < 20; ++i) {
        int valor = QRandomGenerator::global()->bounded(1, 101); // [1, 100]
        numeros.append(valor);
    }

    // 2. Mostrar el vector generado
    qDebug() << "Vector generado:";
    QString linea;
    for (int n : numeros) {
        linea += QString::number(n) + " ";
    }
    qDebug().noquote() << linea;

    // 3. Contar impares y menores de 20 usando std::count_if + lambda
    int cantidad = std::count_if(numeros.begin(), numeros.end(),
                                 [](int n) {
                                     return (n % 2 != 0) && (n < 20);
                                 });

    qDebug() << "Cantidad de impares y menores de 20:" << cantidad;

    return 0; // No necesitamos event loop, así que no llamamos exec()
}