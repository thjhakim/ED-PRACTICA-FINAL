
/* 
 * File:   punto.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:44
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class Punto{
    private:
        double latitud, longitud;
    public:
        Punto(){
            latitud = 0;
            longitud = 0;
        }
    
    Punto(double l, double L, const string & d) :latitud(l), longitud(L){}
    double Getlatitud()const;
    double GetLongitud()const;
    void SetLatitud(double l);
    void SetLongitud(double l);
    bool operator<(const Punto &p)const;
    bool operator==(const Punto &p)const;
    friend istream & operator>>(istream & is, Punto &p);
    friend ostream & operator<<(ostream & os, const Punto &p);
};


#endif /* PUNTO_H */

