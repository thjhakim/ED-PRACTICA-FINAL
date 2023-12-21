
/* 
 * File:   rutas.h
 * Authors: Ángel Rodríguez Faya y Hakim Tahri
 * 
 * @brief Definición del TDA Rutas y sus métodos.
 */


#ifndef RUTAS_H
#define RUTAS_H

#include <iostream>
#include <string>
#include <list>

#include "punto.h"

using namespace std;

/**
 * @class Ruta
 * @brief Representa una ruta aérea con una serie de puntos y un codigo que la identifica.
 */
class Ruta{
private:
    list<Punto> puntos;
    string code;
    
public:
    
    /**
     * Constructor por defecto.
     */
    Ruta(){
        code = "";        
    }
    
    /**
     * Constructor paramétrico
     * @param puntos
     * @param code
     */
    Ruta(list<Punto> puntos, string code){
        this->puntos = puntos;
        this->code   = code;
    }
    
    /**
     * Constructor de copia.
     * @param other
     */
    Ruta(const Ruta& other): puntos(other.puntos), code(other.code) {}

    /**
     * @brief Inserta un punto en la lista.
     * @param n punto a insertar pasado por referencia.
     */
    void Insertar(const Punto & n){
        puntos.push_back(n);
    }
    
    /**
     * @brief Elimina todas las instancias de n que se encuentren dentro de la lista puntos.
     * @param n objeto de la clase Punto para eliminarlo de la lista.
     */
    void Borrar(const Punto &n){
        this->puntos.remove(n);        
    }
    
    /**
     * @brief Obtiene la lista de puntos de la ruta.
     * @return lista con los puntos que definen la ruta.
     */
    list<Punto> GetPuntos()const{
        return puntos;
    }
    
    /**
     * @brief Obtiene el código de la ruta
     * @return Codigo de ruta
     */
    string GetCode()const{
        return code;
    }
    
    /**
     * @brief Inserta el codigo de la ruta.
     * @param code codigo de la ruta.
     */
    void SetCode(const string & code){
        this->code = code;
    }
    
    /**
     * @brief Inserta la lista con los puntos de la ruta.
     * @param puntos lista pasada por referencia cte. con los puntos de la ruta.
     */
    void SetPuntos(const list<Punto> & puntos) {
        this->puntos = puntos;
    }

    /**
     * @brief Operador de igualdad (==) sobrecargado. Comprueba si dos Rutas son iguales.
     * @param R Objeto de la clase Ruta para comparar.
     * @return true si son iguales, false si no lo son.
     */
    bool operator==(const Ruta &R)const{
        return (puntos == R.puntos) && (code == R.code);
    }
    
    /**
     * @brief Operador (<). Comprueba si una Ruta es menor que otra.
     * Para ello, comprueba que clase tiene más puntos.
     * @param R Objeto de la clase Ruta para comparar.
     * @return true si son iguales, false si no lo son.
     */
    bool operator<(const Ruta &R)const{
        return (puntos.size() < R.puntos.size());
    }
    
    /**
     * @class iterator Es una clase anidada dentro de Ruta. 
     * @brief Sirve para iterar dentro de la lista de puntos de la clase Ruta.
     */
    class iterator{
    private:
        list<Punto>::iterator p;
    public:
        
        /**
         * @brief Constructor por defecto de la clase iterator.
         */
        iterator(){}
        
        /**
         * @brief Constructor paramétrico de la clase iterator.
         * @param ite Iterador de la lista de puntos.
         */
        iterator(list<Punto>::iterator &ite){
            this->p = ite;
        }
        
        /**
         * @brief El operador ++ hace que se avance al siguiente elmneto de la lista.
         * @return Referencia al iterador (actualizado).
         */
        iterator& operator++(){
            p++;
            return *this;
        }

        /**
         * @brief El operador -- hace que se retroceda al anterior elemento de la lista.
         * @return Referencia al iterador (actualizado).
         */
        iterator& operator--(){
            p--;
            return *this;
        }
        
        /**
         * @brief El operador de asignacion para la clase iterator.
         * @param ite Iterador para asignar su valor a este iterador.
         * @return Referencia al iterador (actualizado).
         */
        iterator& operator=(const iterator& ite){
            p = ite.p;
            return *this;
        }
        
        /**
         * @brief El operador de igualdad compara dos iteradores.
         * @param ite Iterador para comparar con este iterador.
         * @return true si son iguales, false si no lo son.
         */
        bool operator==(const iterator& ite)const{
            return p == ite.p;            
        }
        
        /**
         * @brief El operador * accede al valor que apunta el iterador.
         * @return Referencia al iterador (actualizado).
         */
        Punto& operator*()const{
            return *p;
        }

        // Clases amigas de la clase iterator
        friend class Ruta;
        friend class const_iterator;
    };
    
    
    
    /**
     * @class const_iterator Es una clase anidada dentro de Ruta. 
     * @brief Sirve para iterar dentro de la lista de puntos de la clase Ruta. PERO NO PUEDE MODIFICARLA.
     */
    class const_iterator{
    private:
        list<Punto>::const_iterator p;
    public:
        /**
         * @brief Constructor por defecto de la clase const_iterator.
         */
        const_iterator(){}
        
        /**
         * @brief Constructor paramétrico de la clase const_iterator.
         * @param cite Referencia al const_iterador de la lista de puntos.
         */
        const_iterator(list<Punto>::const_iterator &cite){
            this->p = cite;
        }
        
        /**
         * @brief El operador ++ hace que se avance al siguiente elemento de la lista.
         * @return Referencia al const_iterator (actualizado).
         */
        const_iterator& operator++(){
            p++;
            return *this;
        }

        /**
         * @brief El operador -- hace que se retroceda al anterior elemento de la lista.
         * @return Referencia al const_iterator (actualizado).
         */
        const_iterator& operator--(){
            p--;
            return *this;
        }
        
        /**
         * @brief El operador de asignacion para la clase const_iterator.
         * @param cite Iterador para asignar su valor a este iterador.
         * @return Referencia al const_iterador (actualizado).
         */
        const_iterator& operator=(const const_iterator& cite){
            p = cite.p;
            return *this;
        }
        
        /**
         * @brief El operador de igualdad compara dos const_iterator.
         * @param cite Iterador para comparar con este const_iterator.
         * @return true si son iguales, false si no lo son.
         */
        bool operator==(const iterator& cite)const{
            return p == cite.p;            
        }
        
        /**
         * @brief El operador * accede al valor que apunta el const_iterador.
         * @return Referencia al const_iterador (actualizado).
         */
        const Punto& operator*()const{
            return *p;
        }
        
        // Clases amigas de la clase const_iterator
        friend class Ruta;
        friend class iterator;
    };
    
    /**
     * @brief Obtiene un iterador que apunta al inicio de la lista de los puntos de la Ruta.
     * @return Referencia al iterador.
     */
    iterator begin(){
        iterator ite;
        ite.p = puntos.begin();
        return ite;
    }
    
    /**
     * @brief Obtiene un iterador constante que apunta al inicio de la lista de los puntos de la Ruta.
     * @return Referencia al iterador constante.
     */
    const_iterator begin()const{
        const_iterator cite;
        cite.p = puntos.begin();
        return cite;
    }
    
    /**
     * @brief Obtiene un iterador que apunta al final de la lista de los puntos de la Ruta.
     * @return Referencia al iterador.
     */
    iterator end(){
        iterator ite;
        ite.p = puntos.end();
        return ite;
    }
    
    /**
     * @brief Obtiene un iterador constante que apunta al final de la lista de los puntos de la Ruta.
     * @return Referencia al iterador constante.
     */
    const_iterator end()const{
        const_iterator cite;
        cite.p = puntos.end();
        return cite;
    }
    
    /**
     * @brief Este método busca un punto en la lista de puntos de la ruta.
     * @param p Objeto de la clase punto que va a ser buscado dentro de la lista puntos.
     * @return Devuelve un iterador al punto si es que lo encuentra, de ser así,
     *         devuelve un iterador que apunta al final de la lista.
     */
    iterator find(const Punto &punto){
        iterator ite;
        list<Punto>::iterator it;
        for (it = puntos.begin(); it != puntos.end() && !((*it) == punto); it++);
        ite.p = it;
        return it;
    }
    
    /**
     * @brief Operador de extracción sobrecargado para leer una Ruta desde un flujo de entradaa.
     * @param is Flujo de entrada para leer los datos.
     * @param R Objeto de la clase Ruta donde se guardaran los datos leidos.
     * @return Devuelve una referencia constante al flujo de entrada.
     */
    friend istream & operator>>(istream & is, Ruta & R){
        int numPuntos = -1;
        Punto p;
        R.puntos.clear();
        is >> R.code;       // Se guarda el codigo de la ruta.
        is >> numPuntos;    // Se leen el número de puntos de la ruta.
        
        for(int i = 0; i < numPuntos; i++){
            is >> p;
            R.puntos.push_back(p);  // Se van leyendo los puntos y guardadndolos en la lista de Ruta
        }
        
        return is;
        
    }
    
    /**
     * @brief Operador de insercción sobrecargado para mostrar un Punto a traves del flujo de salida.
     * @param os Flujo de salida por el que se imprimira el Punto.
     * @param R objeto de la clase Punto. Será la Ruta que se imprima por pantalla.
     * @return Devuelve una referencia constante al flujo de salida. 
     */
    friend ostream & operator<<(ostream & os, const Ruta &R){
//        os << R.GetCode() << " " << R.puntos.size() << " "; 
        list<Punto>::const_iterator cite;
        for(cite = R.puntos.begin(); cite != R.puntos.end(); cite++){
            os << *cite << " ";
        }
        
        os << "\n";
        
        return os;
    }
};


#endif /* RUTAS_H */

