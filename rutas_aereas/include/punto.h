
/* 
 * File:   punto.h
 * Author: angel_rodriguez
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

/**
 * @class Punto
 * @brief Representa un punto en un sistema de coordenadas.
 */
class Punto{
private:
    double latitud, longitud;
public:
    
    /**
     * @brief Constructor por defecto. Inizializa latitud y longitud a 0.
     */
    Punto(){
        latitud = 0;
        longitud = 0;
    }
    
    /**
     * @brief Constructor paramétrico.
     * @param l
     * @param L
     * @param d
     */
    Punto(double l, double L, const string & d) :latitud(l), longitud(L){
    
    }
    
    /**
     * @brief Obtiener la latitud del Punto
     * @return Valor de la latitud
     */
    double Getlatitud()const{
        return latitud;
    }
    
    /**
     * @brief Obtiene la longitud del Punto.
     * @return Valor de la longitud.
     */
    double GetLongitud()const{
        return longitud;
    }
    
    /**
     * @brief Establece la latitud del punto.
     * @param l Valor de la latitud.
     */
    void SetLatitud(double l){
        latitud = l;        
    }
    
    /**
     * @brief Establece la longitud del punto.
     * @param l Valor de la longitud.
     */
    void SetLongitud(double l){
        longitud = l;
    }
    
    bool operator<(const Punto &p)const;
    
    bool operator==(const Punto &p)const;
    
    friend istream & operator>>(istream & is, Punto &p);
    
    friend ostream & operator<<(ostream & os, const Punto &p);
};


#endif /* PUNTO_H */

