/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   rutas.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:45
 */

#ifndef RUTAS_H
#define RUTAS_H

#include<iostream>
#include <string>
#include "punto.h"
using namespace std;

class Ruta{
private:
    list<Punto> puntos;
    string code;
    
public:
    Ruta();
    void Insertar(const Punto & n);
    void Borrar(const Punto &n);
    string GetCode()const;
    
    void SetCode(const string & code);
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

