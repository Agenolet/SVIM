#include "filtrocolor.h"

//-----------------------------------------
//Constructor
FiltroColor::FiltroColor(Pixel pReferencia)
{
    referencia = pReferencia;
}

//-----------------------------------------
//Procesar (FiltroColor)
bool FiltroColor::Procesar(Imagen *pI)
{

    for(unsigned i=0; i<pI->GetPixalto() ; ++i)
        for(unsigned j=0; j<pI->GetPixancho() ; ++j)
            {
                if(!((*pI)[i][j] == referencia))
                {
                    float Brillo = (*pI)[i][j].GetBrillo() ;
                    (*pI)[i][j].SetR( Brillo ) ;
                    (*pI)[i][j].SetG( Brillo ) ;
                    (*pI)[i][j].SetB( Brillo ) ;
                }
            }

    return true;
}

//-----------------------------------------
//Destructor
FiltroColor::~FiltroColor()
{

}
