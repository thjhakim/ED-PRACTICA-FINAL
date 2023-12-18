
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
#include "rutas.h"

class AlmacenRutas{
private:
    map<string,Ruta> rutas; //codigo de ruta y ruta
public:
    AlmacenRutas();
    void Insertar(const Ruta & R);
    void Borrar(const Ruta &R);
    Ruta GetRuta(const string &a);
    class iterator{
    private:
        map<string,Ruta>::iterator p;
    public:
        //Implementar
    };
    
    class const_iterator{
    private:
        map<string,Ruta>::const_iterator p;
    public:
        //Implementar
    };
    
    iterator begin();
    const_iterator begin()const;
    iterator end();
    const_iterator end()const;    
    friend istream & operator>>(istream & is, AlmacenRutas & AR);
    friend ostream & operator<<(ostream & os, const AlmacenRutas &R);
};

#endif /* ALMACENRUTAS_H */

