#ifndef SISTEMA_H
#define SISTEMA_H
#include "stdio.h"
#include "imagen.h"
#include "archivo.h"
#include "archivomif.h"

using namespace std;
//-----------------------------------------

//Struct:
struct modulo {
    Imagen Im;
    string info="";
};


class Sistema
{

private:
    Imagen *I;
    Imagen V;
    vector <modulo> listado;
    unsigned largoactual=0;
    int argc;
    char **argv;

public:
    Sistema();
    //Cargar y Guardar
    bool CargarImagen(string nombre);
    bool GuardarImagen (string nombre);
    //Atributos
    bool MostrarAtributos();
    bool InsertarAtributos(string clave, string valor);
    //Graficacion
    bool Graficar(int argc, char *argv[]);
    //Procesamientos
    bool FiltrarColor(float refR, float refG, float refB);
    bool DetectarEstruc(unsigned fila, unsigned columna);
    bool Pixelar();
    //Trabajo del banco de imagenes
    string ListarBanco(unsigned short &tamanio);
    bool FijarImagenActual(unsigned short opcion);
    void NuevaImagen(string datos);

};

#endif // SISTEMA_H
