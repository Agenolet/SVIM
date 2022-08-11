#ifndef ARCHIVOPPM_H
#define ARCHIVOPPM_H
#include "imagen.h"
#include <vector>
#include <fstream>
#include <string>
#include "archivo.h"

using namespace std;
//-----------------------------------------

class ArchivoPPM : public Archivo
{
private:

public:
    ArchivoPPM();

    virtual bool CargarImagen(string nombre, Imagen *I);
    virtual bool GuardarImagen(string nombre, Imagen *I);

    virtual ~ArchivoPPM();

};

#endif // ARCHIVOPPM_H
