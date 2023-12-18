
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
 * @brief Representa una ruta aérea con una serie de puntos.
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
     * @brief Inserta un punto en la lista.
     * @param n punto a insertar pasado por referencia.
     */
    void Insertar(const Punto & n){
        puntos.push_back(n);
    }
    
    void Borrar(const Punto &n){
        
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

