#include "imagen.h"
#include <vector>

//-----------------------------------------
//Constructores
Imagen::Imagen()
{

}

Imagen::Imagen(unsigned int ppixalto, unsigned int ppixancho, bool &aux)
{
    pixalto = ppixalto;
    pixancho = ppixancho;

    aux = SetTamanio(pixalto,pixancho);
}

//-----------------------------------------
//Set Tamaño
bool Imagen::SetTamanio(unsigned int ppixalto, unsigned int ppixancho)    //Set tamaño matriz
{
    bool aux = true;

    matriz.resize(ppixalto);        //Resize de altura a ppixalto
    if(matriz.size() != ppixalto)
            aux = false;
    else
        pixalto = ppixalto;         //Al atributo "pixalto = ppixalto"

    for(unsigned int i=0; i<matriz.size() && aux; i++)
    {
        matriz[i].resize(ppixancho);    //Resize de ancho a ppixancho
        if(matriz[i].size() != ppixancho)
            aux = false;
        else
            pixancho = ppixancho;       //Al atributo "pixancho = ppixancho"
    }
    return aux;
}

//-----------------------------------------
//Metados
bool Imagen::SetMetadatos(string pentrada)
{
    return info.CargarMetadatos(pentrada);
}

bool Imagen::InsertarMetadato(string pclave, string pvalor)
{
    return info.InsertarMetadato(pclave, pvalor);
}

string Imagen::getMetadatos()
{
    return info.MostrarMetadatos();
}

//-----------------------------------------
//Set y Get pixel
void Imagen::SetPixel(Pixel p, unsigned int i, unsigned int j)
{
    if(i<pixalto && j<pixancho)
    matriz [i][j] = p;

}

Pixel Imagen::GetPixel(unsigned int i, unsigned int j)
{
    Pixel paux;
    if(i<pixalto && j<pixancho){
         paux = matriz[i][j];
    }

    return paux;

}

//-----------------------------------------
//Set y Get de tamaño en pixeles
unsigned int Imagen::GetPixancho()
{
    return pixancho;
}

unsigned int Imagen::GetPixalto()
{
    return pixalto;
}

//-----------------------------------------
//Set y Get de tamaño real
void Imagen::SetAncho(float pancho)
{
    ancho = pancho;
}
float Imagen::GetAncho()
{
    return ancho;
}

void Imagen::SetAlto(float palto)
{
    alto = palto;
}
float Imagen::GetAlto()
{
    return alto;
}

void Imagen::SetUnidad(string punidad)
{
    unidad = punidad;
}

string Imagen::GetUnidad()
{
    return unidad;
}

//-----------------------------------------
//Sobrecarga de operador []
vector<Pixel>& Imagen::operator [](unsigned int i)  //Sobrecarga de []
{
    return matriz[i];
}



