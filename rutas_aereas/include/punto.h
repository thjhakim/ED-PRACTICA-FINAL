
/* 
 * @file   punto.h
 * Author angel_rodriguez
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
     * @param l latitud del Punto
     * @param L longitud del Punto
     * @param d descripción del Punto
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
     * Operador de menor (<) sobrecargado para comparar si un Punto es menor que otro.
     * @param p objeto de la clase Punto que va a ser comparado.
     * @return true si el Punto que llama a la funcion es menor que el Punto que se pasa por parámetro.
     *         false si no.
     */
    bool operator<(const Punto &p)const{
        if(latitud < p.latitud)
            return true;
        else if (latitud > p.latitud)
            return false;
        else //latitud == p.latitud
            return longitud < p.longitud; 
    }
    
    /**
     * @brief Operador de igualdad (==) sobrecargado. Comprueba si dos objetos 
     *        de la clase Punto son iguales.
     * @param p Objeto de la clase Punto para comparar.
     * @return true si son iguales, false si no lo son.
     */
    bool operator==(const Punto &p)const{
        return (latitud == p.latitud && longitud == p.longitud && descripcion == p.descripcion);        
    }
    
    /**
     * @brief Operador de extracción sobrecargado para leer un Punto desde un flujo de entradaa.
     * @param is Flujo de entrada para leer los datos.
     * @param p Objeto de la clase Punto donde se guardaran los datos leidos.
     * @return Devuelve una referencia constante al flujo de entrada.
     */
    friend istream & operator>>(istream & is, Punto &p){
        double l, L; 
        string des;
        
        cout << "Introduzca la latitud: ";
        is >> l;

        cout << "Introduzca la longitud: ";
        is >> L;

        cout << "Introduzca la descripción: ";
        getline(is >> ws, des); // getline para leer toda la línea  
        
        p.SetLatitud(l);
        p.SetLongitud(L);
        p.SetDescripcion(des);   
        
        return is;
    }
    
    /**
     * @brief Operador de insercción sobrecargado para mostrar un Punto a traves del flujo de salida.
     * @param os Flujo de salida por el que se imprimira el Punto.
     * @param p objeto de la clase Punto. Será el punto que se imprima.
     * @return Devuelve una referencia constante al flujo de salida. 
     */
    friend ostream & operator<<(ostream & os, const Punto &p){
        os << "(" << p.latitud << ', ' << p.longitud << ') Descripcion: ' << p.descripcion;
        return os;
    }
};


#endif /* PUNTO_H */

