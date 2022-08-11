#ifndef INTERFAZCONSOLA_H
#define INTERFAZCONSOLA_H
#include "sistema.h"
//-----------------------------------------

class InterfazConsola
{
private:
    Sistema *S;

    void mostrarTareas();
    void menuGestion();
    void menuCargar();
    void menuGuardar();
    void menuMostrarA();
    void menuInsertarA();
    void menuGraficar(int argc, char *argv[]);
    void menuProcesos();
    void menuFiltroColor();
    void menuDetectorEstruc();
    void menuPixelado();


    bool cargar = false;
    bool mostrarA = false;
    bool insertarA = false;
    bool guardar = false;



public:
    InterfazConsola();
    void Run(int argc, char *argv[]);
//    ~InterfazConsola();

};

#endif // INTERFAZCONSOLA_H
