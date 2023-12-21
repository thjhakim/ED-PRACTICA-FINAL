
/* 
 * File:    imagen.cpp
 * Authors: Ángel Rodríguez Faya y Hakim Tahri
 * 
 * @brief Implementación del archivo cabecera del TDA Imagen.
 */

#include "../include/imagen.h"
#include "../include/imagenES.h"

//------------------------------------------------------------------------------
void Imagen::Borrar(){
    for (int i = 0; i < nf; ++i) {
        delete[] datos[i];
    }
    delete[] datos;
}

//------------------------------------------------------------------------------
void Imagen::Copiar(const Imagen& I){
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

//------------------------------------------------------------------------------
Imagen::Imagen(){
    datos=nullptr;
    nf = 0;
    nc = 0;
}

//------------------------------------------------------------------------------
Imagen::Imagen(int f, int c) {
    nf = f;
    nc = c;
    datos = new Pixel *[nf];
    for (int i = 0; i < nf; i++) {
        datos[i] = new Pixel[nc];
	for (int j = 0; j < nc; j++) {
            datos[i][j].r = 0;
            datos[i][j].g = 0;
            datos[i][j].b = 0;
            datos[i][j].transp = 0;
	}
    }
}

//------------------------------------------------------------------------------
Imagen::Imagen(const Imagen &I){
        Copiar(I);
  }

//------------------------------------------------------------------------------
Imagen::~Imagen() {
    Borrar();
}
    
//------------------------------------------------------------------------------
int Imagen::GetCols() const{
    return nc;
}

//------------------------------------------------------------------------------
void Imagen::SetFilas(int nf) {
    this->nf = nf;
}

//------------------------------------------------------------------------------
Imagen & Imagen::operator=(const Imagen &I) {
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

//------------------------------------------------------------------------------
Pixel & Imagen::operator()(int i, int j) {
    assert(i >= 0 && i < nf && j >= 0 && j < nc);
    return datos[i][j];
}

//------------------------------------------------------------------------------
const Pixel & Imagen::operator()(int i, int j) const {
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return datos[i][j];
}

//------------------------------------------------------------------------------
void Imagen::EscribirImagen(const char * nombre){ //Escribe en disco la imagen.
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

//------------------------------------------------------------------------------
void Imagen::LeerImagen(const char* nombre, const string& nombremascara){ //Leer una imagen de disco.
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
    }else
	aux_mask=0;
         
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

//------------------------------------------------------------------------------
void Imagen::LimpiarTransp() {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            datos[i][j].transp = 0;  //255??
	}
    }
}

//------------------------------------------------------------------------------
int Imagen::num_filas() const { 
    return nf; 
}

//------------------------------------------------------------------------------
int Imagen::num_cols() const { 
    return nc; 
}

//------------------------------------------------------------------------------
void Imagen::PutImagen(int posi, int posj, const Imagen& I, Tipo_Pegado tippegado){
    tippegado = OPACO;
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

//------------------------------------------------------------------------------
Imagen Imagen::ExtraeImagen(int posi, int posj, int dimi, int dimj){
    // Implementa la lógica para extraer una subimagen
    Imagen subimagen(dimi, dimj);
    for (int i = 0; i < dimi; ++i) {
        for (int j = 0; j < dimj; ++j) {
            subimagen(i, j) = datos[posi + i][posj + j];
        }
    }
    return subimagen;
}

