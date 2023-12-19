
/* 
 * File:   pais.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:44
 */

#ifndef PAIS_H
#define PAIS_H

#include "punto.h"
#include <iostream>
#include <cstring>
using namespace std;

/**
 * @brief La clase Pais representa un país con información geográfica.
 */
class Pais {
private:
    Punto p; //Coordenadas geográficas del país.
    string pais; // Nombre del país.
    string bandera; //Bandera del país.

public:
    /**
     * @brief Constructor por defecto para la clase Pais.
     */
    Pais() {}

    /**
     * @brief Obtener las coordenadas geográficas del país.
     * @return Las coordenadas geográficas como un objeto Punto.
     */
    Punto GetPunto() const {
        return p;
    }

    /**
     * @brief Obtener el nombre del país.
     * @return Devuelve el nombre del país como un string.
     */
    string GetPais() const {
        return pais;
    }

    /**
     * @brief Obtener la bandera del país.
     * @return Devuelve un string.
     */
    string GetBandera() const {
        return bandera;
    }

    /**
     * @brief Operador de comparación menor que sobrecargado para comparar países según sus coordenadas.
     * @param P El país con el que se va a comparar.
     * @return True si el país actual tiene coordenadas menores que el otro país.
     */
    bool operator<(const Pais &P) const {
        return p < P.p;
    }

    /**
     * @brief Operador de igualdad sobrecargado para comparar países según coordenadas, nombre y bandera.
     * @param P El país con el que se va a comparar.
     * @return True si los países son iguales en coordenadas, nombre y bandera.
     */
    bool operator==(const Pais &P) const {
        return (p == P.p) && (pais == P.pais) && (bandera == P.bandera);
    }

    /**
     * @brief Operador de igualdad sobrecargado para comparar con un objeto Punto según coordenadas.
     * @param P El objeto Punto con el que se va a comparar.
     * @return True si las coordenadas son iguales.
     */
    bool operator==(const Punto &P) const {
        return p == P;
    }

    /**
     * @brief Operador de flujo de entrada sobrecargado para leer información del país.
     * @param is El flujo de entrada.
     * @param P El objeto Pais en el que se va a leer.
     * @return El flujo de entrada después de la lectura.
     */
    friend istream & operator>>(istream & is, Pais & P) {
        double lat, lng;
        is >> lat >> lng >> P.pais >> P.bandera;
        P.p = Punto(lat, lng, "");
        return is;
    }

    /**
     * @brief Operador de flujo de salida sobrecargado para imprimir información del país.
     * @param os El flujo de salida.
     * @param P El objeto Pais que se va a imprimir.
     * @return El flujo de salida después de la impresión.
     */
    friend ostream & operator<<(ostream &os, const Pais &P) {
        os << P.p << " " << P.pais << " " << P.bandera << endl;
        return os;
    }
};

#endif // PAIS_H


