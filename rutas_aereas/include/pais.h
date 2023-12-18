
/* 
 * File:   pais.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:44
 */

#ifndef PAIS_H
#define PAIS_H

#include "punto.h"

class Pais{
  private:
    Punto p;
    string pais;
    string bandera;
    
  public:
    Pais(){}
    Punto GetPunto()const;//Implementar...
    string GetPais()const;//Implementar...
    string GetBandera()const;//Implementar...
    
    bool operator<(const Pais &P)const;
	//Implementar...
    
    bool operator==(const Pais &P)const;
	//Implementar...
    
     bool operator==(const Punto &P)const;
	//Implementar...
    
    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;
	
	is>>lat>>lng>>P.pais>>P.bandera;
	
	P.p=Punto(lat,lng,"");
	return is;
    }
     
    friend ostream & operator<<(ostream & os, const Pais &P){
	os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
    }
};



#endif /* PAIS_H */

