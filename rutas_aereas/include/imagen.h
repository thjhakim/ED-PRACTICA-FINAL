
/* 
 * File:   imagen.h
 * Author: angel_rodriguez
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include "imagenES.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

/**
 * @brief Enumeracion para representar los tipos de pegado al insertar una imagen en otra.
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
    void Borrar() {
        for (int i = 0; i < nf; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
    }

    /**
     * @brief Funcion privada para copiar el contenido de otra imagen.
     * @param I Imagen a copiar.
     */	
    void Copiar(const Imagen& I) {
    nf = I.nf;
    nc = I.nc;

    datos = new Pixel*[nf];
    for (int i = 0; i < nf; ++i) {
        datos[i] = new Pixel[nc];
        for (int j = 0; j < nc; ++j) {
            datos[i][j] = I.datos[i][j];
        }
    }
}  

public:
  /**
   * @brief Constructor por defecto de la clase Imagen.
   */
  Imagen() : data(nullptr), nf(0), nc(0) {}

	/**
	 * @brief Constructor de la clase Imagen.
	 *
	 * Este constructor inicializa una nueva instancia de la clase Imagen con las dimensiones especificadas.
	 * Cada pixel en la imagen se establece con valores predeterminados, con todos los canales de color (r, g, b) en 255 (blanco) y la transparencia en 255 (no transparente).
	 *
	 * @param f Numero de filas de la imagen.
	 * @param c Numero de columnas de la imagen.
	 */
	Imagen(int f, int c) {
	  nf = f;
	  nc = c;
	  datos = new Pixel *[nf];
	  for (int i = 0; i < nf; i++) {
		datos[i] = new Pixel[nc];
		for (int j = 0; j < nc; j++) {
		  datos[i][j].r = 255;
		  datos[i][j].g = 255;
		  datos[i][j].b = 255;
		  datos[i][j].transp = 255;
		}
	  }
	}

     /**
     * @brief Constructor por defecto.
     */
  Imagen();
  
     /**
     * @brief Constructor de copia.
     * @param I Imagen a copiar.
     */
  Imagen(const Imagen &I){
        Copiar(I);
  }
  
     /**
     * @brief Destructor.
     */
  ~Imagen() {
          for (int i = 0; i < nf; i++) {
            delete[] datos[i];
        }
        delete[] datos; 
   };
   
       /**
     * @brief Obtiene el numero de columnas de la Imagen
     * @return nc Numero de columnas
     */
    int GetCols()const{
        return nc;
    }
    
    /**
     * @brief Inserta el numero de filas de la Imagen
     * @param nf Numero de filas
     */
    void SetFilas(int nf) {
        this->nf = nf;
    }
    
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
	Imagen & operator=(const Imagen &I) {
		// Verificar la autoasignación
		if (this == &I) {
		    return *this;
		}

		// Liberar la memoria ocupada por la imagen actual
		Borrar();

		// Copiar la imagen I en la imagen actual
		Copiar(I);

		return *this;
	}

  /**
   * @brief Destructor de la clase Imagen.   
   */
  ~Imagen() {
      Borrar();
  }


     /**
     * @brief Operador de acceso para lectura y escritura.
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Referencia al pixel en la posicion (i, j).
     */
	Pixel & operator()(int i, int j) {
		assert(i >= 0 && i < nf && j >= 0 && j < nc);

		return datos[i][j];
	}
  
     /**
     * @brief Operador de acceso constante para lectura.
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Referencia constante al píxel en la posición (i, j).
     */
  const Pixel & operator()(int i, int j) const {
          assert(i>=0 && i<nf && j>=0 && j<nc);

        return datos[i][j];
    }

      /**
      * @brief Escribe la imagen en un archivo con formato PPM y su mascara en formato PGM.
      * @param nombre Nombre del archivo de salida (sin extension).
      */
    void EscribirImagen(const char * nombre){ //Escribe en disco la imagen.
        unsigned char * aux = new unsigned char [nf*nc*3];
        unsigned char * m = new unsigned char [nf*nc];
      
        int total = nf*nc*3;
        for (int i=0;i<total;i+=3){
            int posi = i /(nc*3);
            int posj = (i%(nc*3))/3;
	    
	    aux[i]=datos[posi][posj].r;
	    aux[i+1]=datos[posi][posj].g;
	    aux[i+2]=datos[posi][posj].b;
	    m[i/3]=datos[posi][posj].transp;     
	}    
	
        if (!EscribirImagenPPM (nombre, aux,nf,nc)){
            cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
        }	  
        delete[]aux;
        string n_aux = "mascara_";
        n_aux =n_aux+nombre;
        std::size_t found =n_aux.find(".ppm");
        if (found!=std::string::npos){
            n_aux =n_aux.substr(0,found);
        }
        n_aux =n_aux+".pgm";

      
        if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
            cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
        }	    
        delete []m;
    }
  
      /**
      * @brief Lee una imagen desde un archivo con formato PPM y, opcionalmente, su mascara desde un archivo PGM.
      * @param nombre Nombre del archivo de entrada (con extension).
      * @param nombremascara Nombre del archivo de máscara (opcional).
      */
    void LeerImagen(const char *nombre, const string &nombremascara=""){ //Leer una imagen de disco.
          int f,c;
      unsigned char * aux,*aux_mask ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f*c*3];
      LeerImagenPPM (nombre, f,c,aux);
      if (nombremascara!=""){
	int fm,cm;
	LeerTipoImagen(nombremascara.c_str(), fm, cm);
	aux_mask = new unsigned char [fm*cm];
	LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
      }
      else{
	aux_mask=0;
      }
      
        Imagen I(f, c);
	  int total = f * c * 3;
	  for (int i = 0; i < total; i += 3) {
		int posi = i / (c * 3);
		int posj = (i % (c * 3)) / 3;

		I.datos[posi][posj].r = aux[i];
		I.datos[posi][posj].g = aux[i + 1];
		I.datos[posi][posj].b = aux[i + 2];
		if (aux_mask != 0)
		  I.datos[posi][posj].transp = aux_mask[i / 3];
		else
		  I.datos[posi][posj].transp = 255;
	  }

	  *this = I;
	  if (aux_mask != 0)
		delete[] aux_mask;
	  delete[] aux;
	}

    /**
     * @brief Limpia la transparencia de la imagen, estableciendo a 255 la transparencia de todos los pixeles.
     */
	void LimpiarTransp() {
		for (int i = 0; i < nf; i++) {
		    for (int j = 0; j < nc; j++) {
		        datos[i][j].transp = 0;  //255??
		    }
		}
	}
  
      /**
      * @brief Obtiene el numero de filas de la imagen.
      * @return Numero de filas.
      */
  int num_filas() const { return nf; }
  
      /**
      * @brief Obtiene el numero de columnas de la imagen.
      * @return Numero de columnas.
      */
  int num_cols() const { return nc; }
  
      /**
      * @brief Pega una imagen en la posicion especificada con un tipo de pegado.
      * @param posi Fila de inicio para pegar la imagen.
      * @param posj Columna de inicio para pegar la imagen.
      * @param I Imagen a pegar.
      * @param tippegado Tipo de pegado (OPACO o BLENDING).
      */
  void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado = OPACO){
        //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
        for (int i=0;i<I.nf;i++){
            for (int j=0;j<I.nc;j++){
                if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
                    if (I.datos[i][j].transp!=0){
                        if (tippegado==OPACO)
                            datos[i+posi][j+posj]=I.datos[i][j];
                        else{
                            datos[i+posi][j+posj].r=(datos[i+posi][j+posj].r+I.datos[i][j].r)/2;
                            datos[i+posi][j+posj].g=(datos[i+posi][j+posj].r+I.datos[i][j].g)/2;
                            datos[i+posi][j+posj].b=(datos[i+posi][j+posj].r+I.datos[i][j].b)/2;
                        }              
                    }  
                }
            }
        }  
  }
  
      /**
      * @brief Extrae una region de la imagen.
      * @param posi Fila de inicio de la region.
      * @param posj Columna de inicio de la region.
      * @param dimi Numero de filas de la region.
      * @param dimj Numero de columnas de la region.
      * @return Imagen extraida.
      */
  Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj){
    // Implementa la lógica para extraer una subimagen
    Imagen subimagen(dimi, dimj);
    for (int i = 0; i < dimi; ++i) {
        for (int j = 0; j < dimj; ++j) {
            subimagen(i, j) = datos[posi + i][posj + j];
        }
    }
    return subimagen;
  }
};

#endif  // IMAGEN_H

