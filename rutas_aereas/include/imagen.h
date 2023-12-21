
/* 
 * File:   imagen.h
 * Authors: Ángel Rodríguez Faya y Hakim Tahri
 * 
 * @brief Definición del TDA Imagen y sus métodos.
 */


#ifndef IMAGEN_H
#define IMAGEN_H

#include "imagenES.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

/**
 * @brief Enumerado para representar los tipos de pegado al insertar una imagen en otra.
 */
enum Tipo_Pegado { OPACO, BLENDING };	//Pegado opaco o con mezcla.

using namespace std;

/**
 * @brief Estructura para representar un pixel con componentes de color y transparencia.
 */
struct Pixel {
  unsigned char r, g, b; //Colores
  unsigned char transp; // 0 no 255 si
};


/**
 * @brief Clase que representa una imagen y proporciona operaciones basicas.
 */
class Imagen {
private:
    Pixel **datos; //Puntero a la matriz de pixeles.
    int nf, nc;   //Número de filas y columnas de la imagen.

    /**
     * @brief Funcion privada para liberar la memoria ocupada por la matriz de pixeles.
     */
    void Borrar();

    /**
     * @brief Funcion privada para copiar el contenido de otra imagen.
     * @param I Imagen a copiar.
     */	
    void Copiar(const Imagen& I);  

public:
    /**
     * @brief Constructor por defecto de la clase Imagen.
     */
    Imagen();

    /**
     * @brief Constructor de la clase Imagen.
     *
     * Este constructor inicializa una nueva instancia de la clase Imagen con las dimensiones especificadas.
     * Cada pixel en la imagen se establece con valores predeterminados, con todos los canales de color (r, g, b) en 255 (blanco) y la transparencia en 255 (no transparente).
     *
     * @param f Numero de filas de la imagen.
     * @param c Numero de columnas de la imagen.
     */
    Imagen(int f, int c);
  
    /**
     * @brief Constructor de copia.
     * @param I Imagen a copiar.
     */
    Imagen(const Imagen &I);
  
    /**
     * @brief Destructor.
     */
    ~Imagen();
   
       /**
     * @brief Obtiene el numero de columnas de la Imagen
     * @return nc Numero de columnas
     */
    int GetCols()const;
    
    /**
     * @brief Inserta el numero de filas de la Imagen
     * @param nf Numero de filas
     */
    void SetFilas(int nf);
    
    /**
     * @brief Inserta el numero de columnas de la Imagen
     * @param nc numero de columnas
     */
    void SetColumnas(int nc) {
        this->nc = nc;
    }

    /**
     * @brief Operador de asignacion.
     * @param I Imagen a asignar.
     * @return Referencia a la imagen actual despues de la asignacion.
     */
    Imagen & operator=(const Imagen &I);

    /**
     * @brief Operador de acceso para lectura y escritura.
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Referencia al pixel en la posicion (i, j).
     */
    Pixel & operator()(int i, int j);
  
    /**
     * @brief Operador de acceso constante para lectura.
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Referencia constante al píxel en la posición (i, j).
     */
    const Pixel & operator()(int i, int j) const;

    /**
     * @brief Escribe la imagen en un archivo con formato PPM y su mascara en formato PGM.
     * @param nombre Nombre del archivo de salida (sin extension).
     */
    void EscribirImagen(const char * nombre);
  
    /**
     * @brief Lee una imagen desde un archivo con formato PPM y, opcionalmente, su mascara desde un archivo PGM.
     * @param nombre Nombre del archivo de entrada (con extension).
     * @param nombremascara Nombre del archivo de máscara (opcional).
     */
    void LeerImagen(const char *nombre, const string &nombremascara);

    /**
     * @brief Limpia la transparencia de la imagen, estableciendo a 255 la transparencia de todos los pixeles.
     */
    void LimpiarTransp();
  
    /**
     * @brief Obtiene el numero de filas de la imagen.
     * @return Numero de filas.
     */
    int num_filas() const;
  
    /**
     * @brief Obtiene el numero de columnas de la imagen.
     * @return Numero de columnas.
     */
    int num_cols() const ;
  
    /**
     * @brief Pega una imagen en la posicion especificada con un tipo de pegado.
     * @param posi Fila de inicio para pegar la imagen.
     * @param posj Columna de inicio para pegar la imagen.
     * @param I Imagen a pegar.
     * @param tippegado Tipo de pegado (OPACO o BLENDING).
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado);
  
    /**
     * @brief Extrae una region de la imagen.
     * @param posi Fila de inicio de la region.
     * @param posj Columna de inicio de la region.
     * @param dimi Numero de filas de la region.
     * @param dimj Numero de columnas de la region.
     * @return Imagen extraida.
     */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
    
    Imagen Rota(const Imagen & Io,double angulo);
};

#endif  // IMAGEN_H
