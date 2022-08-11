#ifndef FILTROCOLOR_H
#define FILTROCOLOR_H
#include "procesamiento.h"
#include "imagen.h"
#include "pixel.h"
//-----------------------------------------

class FiltroColor : public Procesamiento
{
private:
   Pixel referencia;

public:
    FiltroColor(Pixel pReferencia);
    virtual bool Procesar(Imagen *pI);
    virtual ~FiltroColor();
};

#endif // FILTROCOLOR_H
