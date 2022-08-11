#include "sistema.h"
#include "stdio.h"
#include "imagen.h"
#include "archivo.h"
#include "archivomif.h"
#include "graficador.h"
#include "procesamiento.h"
#include "filtrocolor.h"
#include "structdet.h"
#include "pixelado.h"
#include "archivoppm.h"
#include <QApplication>

using namespace std;

//-----------------------------------------
//Constructor
Sistema::Sistema()
{
    listado.resize(10);
    I = &V;
}

//-----------------------------------------
//Opcion 1: Cargar imagen
bool Sistema::CargarImagen(string nombre)
{
    bool retorno = false;
    Archivo *A;
    I = &V;                // =====****************=====****************==========************====== MODIFICACION 1

    if( nombre.find(".mif") != string::npos)        //Llamar a Cargar de ArchivoMIF
    {
        A = new ArchivoMIF();
        retorno = A->CargarImagen(nombre, I);
    }
    else
        if(nombre.find(".ppm") != string::npos)     //Llamar a Cargar de ArchivoPPM
        {
            A = new ArchivoPPM();
            retorno = A->CargarImagen(nombre, I);
        }

    delete A;
    return retorno;
}

//-----------------------------------------
//Opcion 2: Guardar imagen
bool Sistema::GuardarImagen(string nombre)
{
    bool retorno = false;
    Archivo *A;
                            // =====****************=====****************==========************====== REALIZAR LA MODIFICACION 1???????????

    if( nombre.find(".mif") != string::npos)
    {
        A = new ArchivoMIF();
        retorno = A->GuardarImagen(nombre, I);
    }
    else
        if(nombre.find(".ppm") != string::npos)
        {
            A = new ArchivoPPM();
            retorno = A->GuardarImagen(nombre, I);
        }

    delete A;
    return retorno;
}

//-----------------------------------------
//Opcion 3: Mostrar Atributos de Imagen
bool Sistema::MostrarAtributos()
{
    bool aux = false;
    //Mostrar atributos
    cout<<endl<<endl<<I->GetPixancho()<<';'<<I->GetPixalto()<<';'<<I->GetAncho()<<';'<<I->GetAlto()<<';'<<I->GetUnidad()<<endl;

    if(cout<<I->getMetadatos())
        aux = true;

    return aux;

    // return false;
}

//-----------------------------------------
//Opcion 4: Modificar Atributos

bool Sistema::InsertarAtributos(string clave, string valor)
{ 
    bool aux = false;
    aux = I->InsertarMetadato(clave,valor);
    return aux;
}

//-----------------------------------------
//Opcion 5: Graficar Imagen
bool Sistema::Graficar(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    Graficador G;
    G.resize(400,300);
    G.CargarImagen(I);
    //G.GraficarImagen();
    G.show();
    a.exec();

return true;
}

//-----------------------------------------
//Opcion 6.1: Aplicar Filtro de Color
bool Sistema::FiltrarColor(float refR, float refG, float refB)
{
    bool estado=false;
    Pixel refP(refR,refG,refB);

    Procesamiento *Pro;
    Pro = new FiltroColor(refP);

    //I = &V;                // =====****************=====****************==========************====== MODIFICACION 1

    estado = Pro->Procesar(I);
    if(!estado)
        cout<<"No se pudo aplicar el filtro. "<<endl;
    else
        cout<<"Filtro aplicado"<<endl;
    delete Pro;
    return estado;
}

//-----------------------------------------
//Opcion 6.2: Aplicar Detector de Estructuras
bool Sistema::DetectarEstruc(unsigned fila , unsigned columna)
{
    bool estado=false;
    Procesamiento *Pro;
    Pro = new StructDet(fila, columna);

    //I = &V;                // =====****************=====****************==========************====== MODIFICACION 1


    estado = Pro->Procesar(I);

    delete Pro;
    return estado;
}

//-----------------------------------------
//Opcion 6.3: Aplicar Pixelado
bool Sistema::Pixelar()
{
    bool estado=false;

    Procesamiento *Pro;
    Pro = new pixelado();

    //I = &V;                // =====****************=====****************==========************====== MODIFICACION 1

    estado = Pro->Procesar(I);

    delete Pro;
    return estado;
}

//-----------------------------------------
//Listar Banco de imagenes
string Sistema::ListarBanco(unsigned short &tamanio)
{
    tamanio=0;
    string aux="";
    while (tamanio<(listado.size()))
    {
        aux+= to_string(tamanio+1);
        aux+=".  ";
        aux+= listado[tamanio].info;
        aux+="\n";
        tamanio++;
    }
    return aux;
}

//-----------------------------------------
//Fijar imagen Actual
bool Sistema::FijarImagenActual(unsigned short opcion)
{
    bool aux = false;
    if(opcion<=listado.size())
    {
        I = &( (listado[opcion-1]).Im );
        aux = true;
    }
    return aux;
}
//-----------------------------------------     //LOS CAMBIOS EN CARGAR IMAGEN, SON SOBRE *I , QUE ESTÁ APUNTANDO A LISTADO[0], ENTONCES "CARGO IMAGEN" MODIFICANDO LOS VALORES QUE TIENE LA PRIMER IMAGEN DEL VECTOR DE MODULOS
//Nueva Imagen
void Sistema::NuevaImagen(string datos)
{
    modulo aux;

    aux.info += datos;
    aux.Im = *I;

    listado[largoactual]=aux;

    FijarImagenActual(largoactual+1);
    largoactual++;
}
