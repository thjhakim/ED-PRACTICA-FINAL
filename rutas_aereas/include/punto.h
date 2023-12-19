
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
    double latitud, longitud; // Latitud y longitud del punto.
    string descripcion;       // Breve descripcion del punto.
    
public:
    
    /**
     * @brief Constructor por defecto. Inizializa latitud y longitud a 0, y descripcion a "".
     */
    Punto(){
        latitud = 0;
        longitud = 0;
        descripcion = 0;
    }
    
    /**
     * @brief Constructor paramétrico.
     * @param l latitud 
     * @param L longitud 
     * @param d descripción
     */
    Punto(double l, double L, const string & d){
        latitud = l;
        longitud = L;
        descripcion = d;    
    }
    
    /**
     * @brief Constructir por copia
     * @param other Punto a copiar. El nuevo Punto será igual que other.
     */
    Punto(const Punto& other){
        Punto(other.latitud, other.longitud, other.descripcion);
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
     * @brief Obtiene la descripcion del Punto.
     * @return Descripcion del Punto.
     */
    string GetDescripcion()const{
        return descripcion;
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
    
    /**
     * @brief Establece la descrpcion del Punto.
     * @param descripcion Descripción del Punto.
     */
    void SetDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    /**
     * 
     * @param p
     * @return 
     */
    bool operator<(const Punto &p)const;
    
    bool operator==(const Punto &p)const;
    
    friend istream & operator>>(istream & is, Punto &p);
    
    friend ostream & operator<<(ostream & os, const Punto &p);
};


#endif /* PUNTO_H */

