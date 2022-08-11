#ifndef ARCHIVOMIF_H
#define ARCHIVOMIF_H
#include <fstream>
#include <string>
#include "archivo.h"
#include "imagen.h"

using namespace std;
//-----------------------------------------

class ArchivoMIF : public Archivo
{
private:
    //ifstream infile;
    //ofstream outfile;
public:
    ArchivoMIF();

    virtual bool CargarImagen(string nombre, Imagen *I);
    virtual bool GuardarImagen(string nombre, Imagen *I);
    virtual ~ArchivoMIF();

};



#endif // ARCHIVOMIF_H
