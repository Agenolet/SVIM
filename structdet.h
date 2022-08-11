#ifndef STRUCTDET_H
#define STRUCTDET_H
#include "procesamiento.h"
#include "imagen.h"
#include <vector>
using namespace std;
//-----------------------------------------

class StructDet : public Procesamiento
{
private:
    unsigned int fila;
    unsigned int columna;
    vector < vector<bool> > pintado;       //Matriz de bool para controlar pintados
    vector < vector<bool> > analizado;      //Matriz de bool para controlar analizados

    Pixel Referencia;
    void ResizeBool(unsigned alto, unsigned ancho);
    bool Detector (unsigned PosFila, unsigned PosColumna, Imagen *pI);  //Algoritmo recursivo
    void Colorear(Imagen *pI);

public:
    StructDet(unsigned pFila, unsigned pColumna);   //Constructor
    virtual bool Procesar(Imagen *pI );

    virtual ~StructDet();   //Destructor
};

#endif // STRUCTDET_H
