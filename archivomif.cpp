#include "archivomif.h"
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "imagen.h"
#include "pixel.h"
#include <cstring>

using namespace std;

//-----------------------------------------
//Constructor
ArchivoMIF::ArchivoMIF()
{

}

//-----------------------------------------
//Cargar ImagenMIF
bool ArchivoMIF::CargarImagen(string nombre, Imagen *I)
{

    ifstream infile;
    bool estado = false;
    unsigned int posicion = 0;                                            //Posicion en int del puntero de lectura (get)
    string carpeta = "imags/";
    nombre = carpeta+nombre;
    unsigned int pixalto, pixancho;
    float alto, ancho;
    string unidad;
    string metadatos;
    string mif=".mif";

    if(strstr(nombre.c_str() , mif.c_str()) !=NULL){            //usar funciones de string
        estado = true;
    }

    //-----------------Parte Texto
    infile.open(nombre.c_str());                                 //Abro archivo

    //Si se abrió el archivo, leo valores de la cabecera
    if(infile && estado)
    {
        infile >> pixancho;
        infile.ignore();
        infile >> pixalto;
        infile.ignore();
        infile >> ancho;
        infile.ignore();
        infile >> alto;
        infile.ignore();
        getline(infile, unidad);
        getline(infile, metadatos);
        posicion = infile.tellg();

        //Asignamos los valores leidos a la instancia de Imagen (I) y modificamos estado a True
        estado = I->SetTamanio(pixalto, pixancho);
        I->SetAncho(ancho);
        I->SetAlto(alto);
        I->SetUnidad(unidad);

        estado = I->SetMetadatos(metadatos);

        infile.close(); //Cierro el archivo

        //-----------------Parte Binaria
        infile.open(nombre.c_str(), ios::binary | ios::in);      //Abro archivo en modo binario y lectura

        //Si se abrió, leo los valores RGB
        if(infile && estado)
        {
            unsigned short S;
            float R;
            float G;
            float B;

            infile.seekg(posicion);                              //Posiciono el puntero Get, donde infile finalizo de leer en modo texto

            for(unsigned i=0 ; i<pixalto ; ++i)
                for(unsigned j=0 ; j<pixancho ; ++j)
                {
                infile.read((char*)&S , sizeof(unsigned short)); //Leo unsigned short rojo (R) y asigno a S
                R=S/65535.0f;                                     //Transformo el valor unsigned short (S) a float (F). F=S/65535.

                infile.read((char*)&S , sizeof(unsigned short)); //Lo mismo pero leo ahora el verde (G)
                G=S/65535.0f;

                infile.read((char*)&S , sizeof(unsigned short)); //Lo mismo pero leo ahora el azul (B)
                B=S/65535.0f;

                Pixel p (R,G,B);
                I->SetPixel(p,i,j);
                }
        }
        infile.close();
    }
    else estado = false;
    return estado;
}

//-----------------------------------------
//Guardar ImagenMIF
bool ArchivoMIF::GuardarImagen(string nombre,Imagen *I)
{
    ofstream outfile;
    bool estado = false;
    string carpeta = "imags/";
    nombre = carpeta+=nombre;
    //-----------------Parte Texto
    outfile.open(nombre.c_str());

    //Si se abrio en modo escritura, escribo atriburos, metadatos y pixeles ...
    if(outfile.good())
    {
        estado = true;
        outfile << I->GetPixancho() << ";" << I->GetPixalto() << ";" << I->GetAncho() << ";" << I->GetAlto() << ";" << I->GetUnidad() << endl;   //Escribimos en archivo "nombre" atributos de imagen "I"
        outfile << I->getMetadatos() << endl;                                                                                                 //Escribimos metadatos de "I"

        outfile.close();                                        //Cierro archivo abierto en modo texto
    }
       //-----------------Parte Binaria
    outfile.open(nombre.c_str(), ios::binary | ios::out | ios::app);       //Abro archivo en modo binario y de escritura (out)

    if(outfile.good())
    {
            unsigned short S;

            //S=F*65535, es la transformacion de Float al unsigned short

            for(unsigned i=0 ; i<I->GetPixalto() ; ++i)
                for(unsigned j=0 ; j<I->GetPixancho() ; ++j)
                {

                    //Transformo el Float (R/G/B) a Short y escribo en el archivo
                    S = (*I)[i][j].GetR() * 65535;
                    outfile.write((char*)&S , sizeof(unsigned short) );

                    S = (*I)[i][j].GetG() * 65535;
                    outfile.write((char*)&S , sizeof(unsigned short) );

                    S = (*I)[i][j].GetB() * 65535;
                    outfile.write((char*)&S , sizeof(unsigned short) );                 //ALE: NO ENTIENDO BIEN PORQUE DEBE SER (CHAR*)&...
                }
            estado = outfile.good();
            outfile.close();
     }


    return estado;
}

//-----------------------------------------
//Destructor
ArchivoMIF::~ArchivoMIF()
{


}
