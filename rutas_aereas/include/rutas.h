
/* 
 * File:   rutas.h
 * Author: angel_rodriguez
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
    Ruta(list<Punto> puntos, string code) :
        puntos(puntos), code(code) {
    }
    
    /**
     * Constructor de copia.
     * @param other
     */
    Ruta(const Ruta& other) :
    puntos(other.puntos), code(other.code) {
    }


    /**
     * @brief Inserta un punto en la lista.
     * @param n punto a insertar pasado por referencia.
     */
    void Insertar(const Punto & n){
        puntos.push_back(n);
    }
    
    void Borrar(const Punto &n){
        
    }
    
    /**
     * Obtiene la lista de puntos de la ruta.
     * @return lista con los puntos que definen la ruta.
     */
    list<Punto> GetPuntos()const{
        return puntos;
    }
    
    /**
     * Obtiene el código de la ruta
     * @return Codigo de ruta
     */
    string GetCode()const{
        return code;
    }
    
    /**
     * Inserta el codigo de la ruta.
     * @param code codigo de la ruta.
     */
    void SetCode(const string & code){
        this->code = code;
    }
    
    /**
     * Inserta la lista con los puntos de la ruta.
     * @param puntos lista pasada por referencia cte. con los puntos de la ruta.
     */
    void SetPuntos(const list<Punto> & puntos) {
        this->puntos = puntos;
    }

    
    bool operator==(const Ruta &R)const;
    bool operator<(const Ruta &R)const;
    
    class iterator{
    private:
        list<Punto>::iterator p;
    public:
        //Implementar...
    };
    
    class const_iterator{
    private:
        list<Punto>::const_iterator p;
    public:
        //Implementar...
    };
    
    iterator begin();
    const_iterator begin()const;
    iterator end();
    const_iterator end()const;
    
    iterator find(const Punto &p);
    
    friend istream & operator>>(istream & is, Ruta & R);
    friend ostream & operator<<(ostream & os, const Ruta &R);
};


#endif /* RUTAS_H */

