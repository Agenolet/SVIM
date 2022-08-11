#include "metadatos.h"
#include <vector>
//#include <iostream>

using namespace std;
//-----------------------------------------
//Constructor
metadatos::metadatos()
{

}

//-----------------------------------------
//Cargar Metadatos
bool metadatos::CargarMetadatos(string str)
{
    bool aux = false;
       string recortado;
       string clave;
       string valor ;

       unsigned int cont1 = 0;
       int cont2 = 0;

          while( cont1<str.size() )
          {
           cont1 = str.find(":",cont1);           
           clave = str.substr(cont2 , cont1-cont2);
           cont2 = cont1+1;
           cont1 = str.find(";",cont1);
           valor = str.substr(cont2, cont1-cont2);
           cont2 = cont1+1;

           lista.insert (pair <string,string>(clave,valor) );
          }
        if(lista.size()>0)
         aux = true;
    return aux;
}

//-----------------------------------------
//Modificar Metadatos
bool metadatos::InsertarMetadato(string pclave, string pvalor)
{
    bool aux = false;

    if(lista.size()>0){
    lista[pclave] = pvalor;
    aux = true;
    }

    return aux;
}

//-----------------------------------------
//Mostrar Metadatos
string metadatos::MostrarMetadatos()
{
    string resp;

    map<string, string> :: iterator iti;
    map<string, string> :: iterator itf;
    itf = lista.end();
    iti = lista.begin();

    while(iti != itf){

        resp+= iti->first;
        resp+=":";
        resp+=iti->second;
        resp+=";";

        iti++;
    }

    if(lista.size()>0){

        resp.pop_back();

    }

    return resp;
}
