
/* 
 * File:   almacenRutas.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:45
 */

#ifndef ALMACENRUTAS_H
#define ALMACENRUTAS_H

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "rutas.h"
#include "punto.h"
using namespace std;

class AlmacenRutas{
private:
    map<string,Ruta> rutas; //codigo de ruta y ruta
public:
    /**
     * @brief Constructor por defecto de la clase AlmacenRutas.
     */
    AlmacenRutas(){}
    
    /**
     * @brief Inserta una Ruta en el almacen de Rutas.
     * @param R ruta que queremos insertar.
     */
    void Insertar(const Ruta & R){
        rutas[R.GetCode()] = R;
    }
    
    
    void Borrar(const Ruta &R);
    Ruta GetRuta(const string &a);
    
    
    
    /**
     * @class iterator Es una clase anidada dentro de AlmacenRuta. 
     * @brief Sirve para iterar dentro del map de la clase AlmacenRuta.
     */
    class iterator{
    private:
        map<string,Ruta>::iterator p;
    public:
        /**
         * @brief Constructor por defecto de la clase iterator.
         */
        iterator(){}
        
        /**
         * @brief Constructor paramétrico de la clase iterator.
         * @param p Iterador del almacen de rutas.
         */
        iterator(map<string, Ruta>::iterator ite){
            this->p = ite ;
        }
        
        /**
         * @brief El operador ++ hace que se avance al siguiente elemneto.
         * @return Referencia al iterador (actualizado).
         */
        iterator& operator++(){
            p++;
            return *this;
        }

        /**
         * @brief El operador -- hace que se retroceda al anterior elemento.
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
        friend class AlmacenRutas;
        friend class const_iterator;       
    };
    
    
    /**
     * @class const_iterator Es una clase anidada dentro de AlmacenRuta. 
     * @brief Sirve para iterar dentro del map de la clase AlmacenRuta. PERO NO PUEDE MODIFICARLA.
     */
    class const_iterator{
    private:
        map<string,Ruta>::const_iterator p;
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
         * @brief El operador ++ hace que se avance al siguiente elemento.
         * @return Referencia al const_iterator (actualizado).
         */
        const_iterator& operator++(){
            p++;
            return *this;
        }

        /**
         * @brief El operador -- hace que se retroceda al anterior elemento.
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

        // Clases amigas de la clase iterator
        friend class AlmacenRutas;
        friend class const_iterator; 
    };
    
    /**
     * @brief Obtiene un iterador que apunta al inicio del map del almacen de ruta.
     * @return Referencia al iterador.
     */
    iterator begin(){
        return iterator(rutas.begin());       
    }
    
    /**
     * @brief Obtiene un iterador constante que apunta al inicio del map del almacen de ruta.
     * @return Referencia al iterador constante.
     */
    const_iterator begin()const{
        return const_iterator(rutas.begin());
    }
    
    /**
     * @brief Obtiene un iterador que apunta al final del map del almacen de ruta.
     * @return Referencia al iterador.
     */
    iterator end(){
        return iterator(rutas.end()); 
    }
    
    /**
     * @brief Obtiene un iterador constante que apunta al final del map del almacen de ruta.
     * @return Referencia al iterador constante.
     */
    const_iterator end()const{
        return const_iterator(rutas.end());
    }  
    
    
    /**
     * @brief Operador de extracción sobrecargado para leer una Ruta desde un flujo de entradaa.
     * @param is Flujo de entrada para leer los datos.
     * @param R Objeto de la clase Ruta donde se guardaran los datos leidos.
     * @return Devuelve una referencia constante al flujo de entrada.
     */
    friend istream & operator>>(istream & is, AlmacenRutas & AR){
        
    }
    
    /**
     * @brief Operador de insercción sobrecargado para mostrar el almacen de rutas a traves del flujo de salida.
     * @param os Flujo de salida por el que se imprimira.
     * @param R objeto de la clase AlmacenRutas. Será lo que se imprima por pantalla.
     * @return Devuelve una referencia constante al flujo de salida. 
     */
    friend ostream & operator<<(ostream & os, const AlmacenRutas &R){
        map<string,Ruta>::const_iterator cite;
        for(cite = R.begin(); cite != R.end(); cite++){
            os << cite->first << " " << cite -> second;
            os << endl;
        } 
        
        return os;
    }
    
    
};

#endif /* ALMACENRUTAS_H */

