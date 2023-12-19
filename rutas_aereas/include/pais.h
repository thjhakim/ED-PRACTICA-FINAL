
/* 
 * File:   pais.h
 * Author: angel_rodriguez
 *
 * Created on 18 de diciembre de 2023, 16:44
 */

#ifndef PAIS_H
#define PAIS_H

#include <iostream>
#include "punto.h"
using namespace std;

class Pais{
  private:
    Punto punto;
    string pais;
    string bandera;
    
  public:
    Pais(){}
    
    /**
     * @brief Obtiene el punto del pais.
     * @return punto del pais.
     */
    Punto GetPunto()const{
        return punto;
    }
    
    /**
     * @brief Obtiene el nombre del pais.
     * @return Nombre del pais.
     */
    string GetPais()const{
        return pais;
    }
    
    /**
     * @brief Obtiene la bandera del pais.
     * @return Bandera del pais.
     */
    string GetBandera()const{
        return bandera;
    }
    
    bool operator<(const Pais &P)const;
	//Implementar...
    
    bool operator==(const Pais &P)const;
	//Implementar...
    
     bool operator==(const Punto &P)const;
	//Implementar...
    
    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;
	
	is>>lat>>lng>>P.pais>>P.bandera;
	
	P.punto=Punto(lat,lng,"");
	return is;
    }
     
    friend ostream & operator<<(ostream & os, const Pais &P){
	os<<P.punto<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
    }
};



#endif /* PAIS_H */

