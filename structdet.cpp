#include "structdet.h"

//-----------------------------------------
//Constructor
StructDet::StructDet(unsigned pFila, unsigned pColumna)
{
    fila = pFila;
    columna = pColumna;
}

//-----------------------------------------
//Prosesar (Detector de Struc.)
bool StructDet::Procesar(Imagen *pI)
{
    bool estado = false;

    if( fila <= (*pI).GetPixalto() && columna <= (*pI).GetPixancho() )
        {
            ResizeBool( (*pI).GetPixalto() , (*pI).GetPixancho() );

            Referencia.SetR( (*pI)[fila][columna].GetR() );
            Referencia.SetG( (*pI)[fila][columna].GetG() );
            Referencia.SetB( (*pI)[fila][columna].GetB() );

            estado= Detector ( fila, columna, pI );
            Colorear(pI);
            Pixel rojo (1,0,0);
            (*pI).SetPixel(rojo, fila, columna); //pinto de rojo al pixel seleccionado por el usuario
        }
    return estado;
}

//-----------------------------------------
//Resize de matrices de Bool
void StructDet::ResizeBool(unsigned alto, unsigned ancho)
{
    analizado.resize( alto );
    pintado.resize( alto );

    for(unsigned int i=0 ; i<alto ; i++)
    {
        analizado[i].resize( ancho , false );  //Asigno a todos los bool a 0 (false)
        pintado[i].resize( ancho , false );  //Asigno a todos los bool a 0 (false)
    }
}

//-----------------------------------------
//Algoritmo Recursivo, del pintor.
bool StructDet::Detector(unsigned PosFila, unsigned PosColumna, Imagen *pI )
{
    bool aux = true;
    if( PosFila < ((*pI).GetPixalto()) &&  PosColumna < ((*pI).GetPixancho())  )
       if( !(analizado[PosFila][PosColumna]) )
            {
                analizado[PosFila][PosColumna] = true;

                if( Referencia == ( (*pI).GetPixel(PosFila, PosColumna) ) )
                        {
                           pintado[PosFila][PosColumna]= true;  //Pintado

                           Detector( PosFila+1 , PosColumna+0 , pI );
                           Detector( PosFila+1 , PosColumna-1 , pI );
                           Detector( PosFila+0 , PosColumna-1 , pI );
                           Detector( PosFila-1 , PosColumna-1 , pI );
                           Detector( PosFila-1 , PosColumna+0 , pI );
                           Detector( PosFila-1 , PosColumna+1 , pI );
                           Detector( PosFila+0 , PosColumna+1 , pI );
                           Detector( PosFila+1 , PosColumna+1 , pI );
                           aux = true;
                }
            }

    return aux;
}

//-----------------------------------------
//Colorea la imagen, segun la matriz bool: pintado
void StructDet::Colorear(Imagen *pI)
{
    Pixel verde(0.0f,1.0f,0.0f);
    Pixel negro(0.0f,0.0f,0.0f);

    for(unsigned PosFila=0; PosFila<pI->GetPixalto() ; ++PosFila)
        for(unsigned PosColumna=0; PosColumna<pI->GetPixancho() ; ++PosColumna)
            {
                if(pintado[PosFila][PosColumna]){
                (*pI).SetPixel(verde, PosFila, PosColumna);
                } else {
                (*pI).SetPixel(negro, PosFila, PosColumna);
                }
            }
}

//-----------------------------------------
//Destructor
StructDet::~StructDet()
{

}
