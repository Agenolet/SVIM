#include "pixelado.h"

//-----------------------------------------
//Constructor
pixelado::pixelado()
{

}

//-----------------------------------------
//Procesar ( Pixelado )
bool pixelado::Procesar(Imagen *pI)
{
    Imagen V;

    unsigned int alto = (*pI).GetPixalto();
    unsigned int ancho = (*pI).GetPixancho();


    if(!ancho%2 == 0)
        ancho-=1;
    if(!alto%2 == 0)
        alto-=1;

    V.SetTamanio((alto/2),(ancho/2));
    unsigned filanueva=0;
    unsigned columnanueva=0;


    for(unsigned fila=0; fila< (alto-1) ; fila+=2)
    {
        for(unsigned columna=0; columna< (ancho-1) ; columna+=2)
        {
           Pixel p1 = pI->GetPixel(fila,columna);
           Pixel p2 = pI->GetPixel(fila,columna+1);
           Pixel p3 = pI->GetPixel(fila+1,columna);
           Pixel p4 = pI->GetPixel(fila+1,columna+1);

           float promR = (p1.GetR() + p2.GetR() + p3.GetR() + p4.GetR()) / 4;
           float promG = (p1.GetG() + p2.GetG() + p3.GetG() + p4.GetG()) / 4;
           float promB = (p1.GetB() + p2.GetB() + p3.GetB() + p4.GetB()) / 4;

           Pixel nuevo(promR,promG,promB);

           V.SetPixel(nuevo,filanueva,columnanueva);
           columnanueva++;
        }
        columnanueva = 0;
        filanueva++;
    }

    *pI = V;

    return true;
}

//-----------------------------------------
//Destructor
pixelado::~pixelado()
{

}

