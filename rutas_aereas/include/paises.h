/* 
 * File:   paises.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:44
 */

#ifndef PAISES_H
#define PAISES_H

#include <iostream>
#include "pais.h"
#include <set>
using namespace std;

/**
 * @brief La clase Paises gestiona un conjunto de paises.
 */
class Paises {
private:
    set<Pais> datos; //Conjunto de paises.

public:
    /**
     * @brief Constructor por defecto para la clase Paises.
     */
    Paises() {}

    /**
     * @brief Inserta un pais en el conjunto.
     * @param P El pais a insertar.
     */
    void Insertar(const Pais& P) {
        datos.insert(P);
    }

    /**
     * @brief Elimina un pais del conjunto.
     * @param P El pais a eliminar.
     */
    void Borrar(const Pais& P) {
        datos.erase(P);
    }

    /**
     * @brief Clase iterator para iterar sobre los paises.
     */
    class iterator;

    /**
     * @brief Clase iterator constante para iterar sobre los paises de manera constante.
     */
    class const_iterator {
    private:
        set<Pais>::const_iterator pto; //Iterador constante sobre el conjunto de paises.

    public:
        /**
         * @brief Constructor por defecto para const_iterator.
         */
        const_iterator() {}

        /**
         * @brief Avanza el iterador constante al siguiente elemento.
         * @return Una referencia al iterador constante despues de avanzar.
         */
        const_iterator& operator++() {
            ++pto;
            return *this;
        }

        /**
         * @brief Retrocede el iterador constante al elemento anterior.
         * @return Una referencia al iterador constante despues de retroceder.
         */
        const_iterator& operator--() {
            --pto;
            return *this;
        }

        /**
         * @brief Obtiene el pais actual al que apunta el iterador constante.
         * @return Una referencia al pais actual.
         */
        const Pais& operator*() const {
            return *pto;
        }

        /**
         * @brief Compara dos iteradores constantes por desigualdad.
         * @param it El iterador constante con el que comparar.
         * @return True si los iteradores no son iguales.
         */
        bool operator!=(const const_iterator& it) const {
            return pto != it.pto;
        }

        /**
         * @brief Compara dos iteradores constantes por igualdad.
         * @param it El iterador constante con el que comparar.
         * @return True si los iteradores son iguales.
         */
        bool operator==(const const_iterator& it) const {
            return pto == it.pto;
        }

        friend class Paises;
    };

    /**
     * @brief Clase iterator para iterar sobre los paises.
     */
    class iterator {
    private:
        set<Pais>::iterator pto; //Iterador sobre el conjunto de paises.

    public:
        /**
         * @brief Constructor por defecto para iterator.
         */
        iterator() {}

        /**
         * @brief Avanza el iterador al siguiente elemento.
         * @return Una referencia al iterador despues de avanzar.
         */
        iterator& operator++() {
            ++pto;
            return *this;
        }

        /**
         * @brief Retrocede el iterador al elemento anterior.
         * @return Una referencia al iterador despues de retroceder.
         */
        iterator& operator--() {
            --pto;
            return *this;
        }

        /**
         * @brief Obtiene el pais actual al que apunta el iterador.
         * @return Una referencia al pais actual.
         */
        Pais& operator*() {
            return *pto;
        }

        /**
         * @brief Compara dos iteradores por desigualdad.
         * @param it El iterador con el que comparar.
         * @return True si los iteradores no son iguales.
         */
        bool operator!=(const iterator& it) const {
            return pto != it.pto;
        }

        /**
         * @brief Compara dos iteradores por igualdad.
         * @param it El iterador con el que comparar.
         * @return True si los iteradores son iguales.
         */
        bool operator==(const iterator& it) const {
            return pto == it.pto;
        }

        friend class Paises;
        friend class const_iterator;
    };

    /**
     * @brief Obtiene un iterador al principio del conjunto de paises.
     * @return Un iterador al principio del conjunto.
     */
    iterator begin() {
        iterator it;
        it.pto = datos.begin();
        return it;
    }

    /**
     * @brief Obtiene un iterador constante al principio del conjunto de paises.
     * @return Un iterador constante al principio del conjunto.
     */
    const_iterator begin() const {
        const_iterator it;
        it.pto = datos.begin();
        return it;
    }

    /**
     * @brief Obtiene un iterador al final del conjunto de paises.
     * @return Un iterador al final del conjunto.
     */
    iterator end() {
        iterator it;
        it.pto = datos.end();
        return it;
    }

    /**
     * @brief Obtiene un iterador constante al final del conjunto de paises.
     * @return Un iterador constante al final del conjunto.
     */
    const_iterator end() const {
        const_iterator it;
        it.pto = datos.end();
        return it;
    }

    /**
     * @brief Busca un país en el conjunto segun sus atributos.
     * @param p El pais a buscar.
     * @return Un iterador apuntando al pais encontrado o al final si no se encuentra.
     */
    iterator find(const Pais &p) {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
        it.pto = i;
        return it;
    }

    /**
     * @brief Busca un pais en el conjunto según sus coordenadas.
     * @param p El objeto Punto a buscar.
     * @return Un iterador apuntando al país encontrado o al final si no se encuentra.
     */
    iterator find(const Punto &p) {
        iterator it;
        set<Pais>::iterator i;
        for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i);
        it.pto = i;
        return it;
    }

    /**
     * @brief Sobrecarga del operador de entrada para leer un conjunto de paises desde un flujo de entrada.
     * @param is El flujo de entrada.
     * @param R El objeto Paises en el que se va a leer.
     * @return El flujo de entrada despues de la lectura.
     */
    friend istream& operator>>(istream& is, Paises& R) {
        Paises rlocal;
        // Leemos el comentario
        if (is.peek() == '#') {
            string a;
            getline(is, a);
        }

        Pais P;
        while (is >> P) {
            rlocal.Insertar(P);
        }

        R = rlocal;
        return is;
    }

    /**
     * @brief Sobrecarga del operador de salida para imprimir un conjunto de paises en un flujo de salida.
     * @param os El flujo de salida.
     * @param R El objeto Paises que se va a imprimir.
     * @return El flujo de salida después de la impresion.
     */
    friend ostream& operator<<(ostream& os, const Paises& R) {
        Paises::const_iterator it;
        for (it = R.begin(); it != R.end(); ++it) {
            os << *it << "\t";
        }
        return os;
    }
};

#endif // PAISES_H
