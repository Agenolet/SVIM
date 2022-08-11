#ifndef PIXELADO_H
#define PIXELADO_H
#include "procesamiento.h"
#include "imagen.h"
#include "pixel.h"
#include <vector>

using namespace std;
//-----------------------------------------

class pixelado : public Procesamiento
{
private:



public:
    pixelado();

    virtual bool Procesar(Imagen *pI);

    virtual ~pixelado();   //Destructor

};

#endif // PIXELADO_H
