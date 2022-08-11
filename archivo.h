#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <string>
#include "imagen.h"

using namespace std;
//-----------------------------------------

class Archivo
{   
private:

public:
    Archivo();
    virtual bool CargarImagen(string nombre, Imagen *I)=0;

    virtual bool GuardarImagen(string nombre, Imagen *I)=0;
    virtual ~Archivo();
};

#endif // ARCHIVO_H
