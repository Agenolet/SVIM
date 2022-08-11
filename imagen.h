#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <iostream>
#include "pixel.h"
#include "metadatos.h"

using namespace std; // si no usamos string lo volamos a esto y a iostream
//-----------------------------------------

class Imagen
{
private:
    //Dimensiones de la imagen en pixeles
    unsigned int pixalto=0;
    unsigned int pixancho=0;

    //Dimensiones de la imagen en medidas reales
    float ancho=0;
    float alto=0;
    string unidad="N/a";

    metadatos info;

    vector <vector <Pixel> > matriz; //Matriz de pixeles

public:
    Imagen();
    Imagen (unsigned int ppixalto, unsigned int ppixancho, bool &aux);

    bool SetTamanio(unsigned int ppixalto, unsigned int ppixancho);     //Set tamaño de matriz

    bool SetMetadatos(string pentrada);
    bool InsertarMetadato(string pclave, string pvalor);
    string getMetadatos();


    //Set y Get de Pixel
    void SetPixel(Pixel p, unsigned int i, unsigned int j);
    Pixel GetPixel(unsigned int i, unsigned int j);

    //Get de tamaño en pixeles
    unsigned int GetPixancho();
    unsigned int GetPixalto();

    //Set y Get de tamaño en medidas reales
    void SetAncho(float pancho);
    float GetAncho();
    void SetAlto(float palto);
    float GetAlto();
    void SetUnidad(string punidad);
    string GetUnidad();

    vector<Pixel> &operator [](unsigned int i);     //Sobrecarga de []
};

#endif // IMAGEN_H
