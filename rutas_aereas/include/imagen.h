
/* 
 * File:   imagen.h
 * Author: angel_rodriguez
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include "imagenES.h"
#include <string>
#include <cassert>

using namespace std;

enum Tipo_Pegado {OPACO, BLENDING};

struct Pixel{
    unsigned char r,g,b;
    unsigned char transparencia; //255 es transparente, 0 no.
};

class Imagen{
private:
    Pixel **datos; // donde se almacena la información de la imagen. 
    int nf,nc;     // nf: numero de filas, nc: numero de columnas

public:

    /**
     * @brief Constructor paramétrico
     * @param nf numero de filas de la Imagen
     * @param nc numero de columnas de la Imagen
     */
    Imagen (int nf,int nc){
        this->nf = nf;
        this->nc = nc;
        datos = new Pixel*[nf];
        for (int i=0;i<nf;i++){
            datos[i]=new Pixel[nc];
            for (int j=0;j<nc;j++){
                datos[i][j].r=255;
                datos[i][j].g=255;
                datos[i][j].b=255;
                datos[i][j].transparencia=255;
            }   
        }  
    }
    
    /**
     * @brief Constructor por defecto.
     */
    Imagen(){
        Imagen(1,1);
    }
    
    /**
     * @brief Constructor de copia.
     * @param I Imagen a copiar
     */
    Imagen(const Imagen &I){
        Imagen(I.nf, I.nc);
    }
    
    /**
     * @brief Destructor.
     */
    ~Imagen(){
        for (int i = 0; i < nf; i++) {
            delete[] datos[i];
        }
        delete[] datos;  
    } 
    
    /**
     * @brief Obtiene el numero de filas de la Imagen
     * @return nf Numero de filas
     */
    int GetFilas()const{
        return nf;
    }
    
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
    
    
    Imagen & operator =(const Imagen & I){
        
        
        
        
    }
    
    Pixel & operator()(int i,int j){ // devuelve el pixel en la posicion i,j
    
        
        
        
    }
    
    /**
     * @brief Operador () sobrecargado para acceder a un pixel específico de la Imagen.
     * @param i fila del pixel 
     * @param j columna del pixel
     * @return Devuelve una referencia constante al pixel de la posición especificada.
     * @pre 0 <= i < nf  y  0 <= j <= nc (deben de estar dentro de los límites de la Imagen).  
     */
    const Pixel & operator ()(int i, int j){
        assert(i>=0 && i<nf && j>=0 && j<nc);
        return datos[i][j];
    }
    
    /**
     * 
     * @param nombre
     */
    void EscribirImagen(const char * nombre){ //escribe en disco la imagen
        unsigned char * aux = new unsigned char [nf*nc*3];
        unsigned char * m = new unsigned char [nf*nc];
      
        int total = nf*nc*3;
        for (int i=0;i<total;i+=3){
            int posi = i /(nc*3);
            int posj = (i%(nc*3))/3;
	    
	    aux[i]=datos[posi][posj].r;
	    aux[i+1]=datos[posi][posj].g;
	    aux[i+2]=datos[posi][posj].b;
	    m[i/3]=datos[posi][posj].transparencia;     
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
      
      
      Imagen I(f,c);
      int total = f*c*3;
      for (int i=0;i<total;i+=3){
	   int posi = i /(c*3);
	   int posj = (i%(c*3))/3;
	//   cout<<posi<<" " <<posj<<endl;
	     I.data[posi][posj].r=aux[i];
	     I.data[posi][posj].g=aux[i+1];
	     I.data[posi][posj].b=aux[i+2];
	     if (aux_mask!=0)
	      I.data[posi][posj].transp=aux_mask[i/3];
	     else  
	       I.data[posi][posj].transp=255;
	 }    
	  
      *this = I;   
      if (aux_mask!=0) delete[]aux_mask;
      delete []aux;
    }
    
    void LimpiarTransp(){
        
    }
    
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO){
        //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
        for (int i=0;i<I.nf;i++){
            for (int j=0;j<I.nc;j++){
                if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
                    if (I.data[i][j].transp!=0){
                        if (tippegado==OPACO)
                            data[i+posi][j+posj]=I.data[i][j];
                        else{
                            data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
                            data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
                            data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
                        }              
                    }  
                }
            }
        }
    }
    
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dmj);
};


#endif /* IMAGEN_H */
