#ifndef ADULTO_H
#define ADULTO_H
#include <QDebug>
#include <QObject>

class adulto : public QObject {
private:
    QString nombre; // Miembro privado para almacenar el nombre

public:
    // Constructor que opcionalmente recibe un puntero a QObject (el padre)
    adulto(QObject *base = nullptr) : QObject(base) {}

    // Función para establecer el nombre
    void setNombre(const QString &nomb) {
        nombre = nomb;
    }

    // Función para obtener el nombre
    QString getNombre() const {
        return nombre;
    }

    // Destructor que muestra un mensaje cuando el objeto es destruido
    ~adulto() {
        qDebug() << "..objeto destruido...";
    }
};
#endif // ADULTO_H
