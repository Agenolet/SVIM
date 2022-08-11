#ifndef PROCESAMIENTO_H
#define PROCESAMIENTO_H
#include "imagen.h"
//-----------------------------------------

class Procesamiento
{
private:

    //Imagen *I;        //Protected

public:
    Procesamiento();
    virtual bool Procesar(Imagen *pI)=0;

    virtual ~Procesamiento();

protected:
    //Imagen *I;
};

#endif // PROCESAMIENTO_H
