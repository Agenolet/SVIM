#include "interfazconsola.h"
#include <iostream>
#include "sistema.h"

using namespace std;

//-----------------------------------------
//Constructor
InterfazConsola::InterfazConsola()
{
    S = new Sistema();
}

//-----------------------------------------
//Inicio de Consola
void InterfazConsola::Run(int argc, char *argv[]){

unsigned short opcion=99;
bool seguir = true;
    cout<<endl<<endl;
    cout<<"               |-----------------------------------------------------------|" << endl ;
    cout<<"               |Bienvenido al Sistema de Visualizacion de Imagenes Medicas.|"<<endl
        <<"               |Las tareas que puede realizar este sistema son:            |"<<endl;
    cout<<"               |-----------------------------------------------------------|"<<endl<<endl;

while (seguir){
    mostrarTareas();
    cin>>opcion;

    if (opcion <= 7)
    {
        if (opcion == 1)
            menuCargar();
         else
        if (opcion == 2)
            menuGuardar();
         else
        if (opcion == 3)
            menuMostrarA();
         else
        if (opcion == 4)
            menuInsertarA();
         else
        if (opcion == 5)
            menuGraficar(argc, argv);
         else
        if (opcion == 6)
            menuProcesos();
         else
        if (opcion == 7)
            menuGestion();
         else
        if (opcion == 0)
            seguir = false;

    cout<<endl<<endl<<
        "------------------------------------"
        <<endl<<endl;
    }
    else
        cout<<endl<< "La opcion que ingreso no corresponde a una tarea." << endl << "Vuelva a ingresar una opcion." << endl << endl;
}

cout<<"Gracias por usar nuestro programa,"<<endl<<"Fede y Ale."<<endl;

}

//-----------------------------------------
//Mostrar Menu
void InterfazConsola::mostrarTareas()
{
    cout<<"======"<<endl;
    cout<<"1. "  <<"Cargar imagen en el sistema."<<endl
        <<"2. "  <<"Guardar imagen en disco."<<endl
        <<"3. "  <<"Mostrar atributos de la imagen."<<endl
        <<"4. "  <<"Modificar atributos de la imagen."<<endl
        <<"5. "  <<"Visualizar imagen."<<endl
        <<"6. "  <<"Aplicar procesamiento."<<endl
        <<"7. "  <<"Gestionar banco de imagenes."<<endl<<endl;

    cout<<"0. "  <<"Salir."<<endl;
    cout<<"======"<<endl;

    cout<<"Ingrese el numero correspondiente a la tarea que desea realizar: ";

}

//-----------------------------------------
//Opcion 1: Cargar Imagen
void InterfazConsola::menuCargar()
{
    string nombre;
    cout<<endl<<"Ingrese el nombre del archivo que desea abrir: ";
    cin>>nombre;
    if (S->CargarImagen(nombre)){
        S->NuevaImagen(nombre);
        cout<<"La imagen ha sido cargada con exito.";
        cargar = true;
    } else {
        cout<<"La imagen NO HA PODIDO SER CARGADA!!.";
        cargar = false;
    }

}
//-----------------------------------------
//Opcion 2: Guardar Imagen
void InterfazConsola::menuGuardar()
{
    string nombre;
    if(cargar){
        cout<<endl<<"Ingrese el nombre con el que desea guardar la imagen: ";
        cin>>nombre;
        if(S->GuardarImagen(nombre)){
            cout<<"La imagen ha sido guardada con exito en "<< nombre;
            guardar = true;
        }else{
            cout<<"La imagen NO HA PODIDO SER GUARDADA!!.";
            guardar = false;
        }
    }
}

//-----------------------------------------
//Opcion 3: Mostrar atributos de Imagen
void InterfazConsola::menuMostrarA()
{
    if(cargar)
    S->MostrarAtributos();
}

//-----------------------------------------
//Opcion 4: Modificar atributos
void InterfazConsola::menuInsertarA()
{
    string clave;
    string valor;

    cout<<"ingrese la clave a modificar: ";
    cin>>clave;
    cout<<"ingrese el nuevo valor: ";
    cin>>valor;

    S->InsertarAtributos(clave,valor);
}

//-----------------------------------------
//Opcion 5: Graficar Imagen
void InterfazConsola::menuGraficar(int argc, char *argv[])
{
          if(cargar)
              S->Graficar(argc, argv);
}

//-----------------------------------------
//Opcion 6: Menu de procesos
void InterfazConsola::menuProcesos()
{
    unsigned short opcion=99;
    cout<<endl;
    cout<<"1. "  <<"Aplicar filtro de color."<<endl
        <<"2. "  <<"Aplicar detector de estructuras."<<endl
        <<"3. "  <<"Aplicar pixelado."<<endl
        <<"Opcion:";
    cin>>opcion;

    if (opcion <= 8)
    {
        if (opcion == 1)
            menuFiltroColor();
         else
        if (opcion == 2)
            menuDetectorEstruc();
         else
        if (opcion == 3)
            menuPixelado();
    }
}

//-----------------------------------------
//Opcion 6.1: Filtro Color
void InterfazConsola::menuFiltroColor()
{
    float refR, refG, refB;
    cout<<"Ingrese valor R a filtrar: "<<endl;
    cin>>refR;
    cout<<"Ingrese valor G a filtrar: "<<endl;
    cin>>refG;
    cout<<"Ingrese valor B a filtrar: "<<endl;
    cin>>refB;

    if(0<=refR && refR<=1 && 0<=refG && refG<=1 && 0<=refB && refB<=1)
    {
        //Llamo a Nueva Imagen
        string datos;
        datos += "FiltroColor ";
        datos += "R:" + to_string(refR) + " G:" += to_string(refG) + "B:" + to_string(refB);
        S->NuevaImagen(datos);

        //Llamo a Filtro Color
        S->FiltrarColor(refR, refG, refB);
    }
    else
        cout<<endl<<"Verifique los valores ingresados, deben estar entre [0 , 1]"<<endl;
}

//-----------------------------------------
//Opcion 6.2: Detector de Estructuras
void InterfazConsola::menuDetectorEstruc()
{
    bool estado=false;
    unsigned int fila, columna;
    cout<<"Aclaracion, el primer pixel es el X=0 , Y=0" << endl;
    cout<<"Ingrese fila del pixel: "<<endl;
    cin>>fila;
    cout<<"Ingrese columna del pixel: "<<endl;
    cin>>columna;

    //Llamo a Nueva Imagen
    string datos;
    datos += "Detector Est. ";
    datos += "F:" + to_string(fila) + " C:" + to_string(columna);
    S->NuevaImagen(datos);

    //Llamo a Detectar Estructura
    estado=S->DetectarEstruc(fila, columna);

    if(!estado)
        cout<<"No se pudo aplicar el detector. Verifique si ingreso valores correctos."<<endl;
    else
        cout<<"Estructura detectada"<<endl;
}

//-----------------------------------------
//Opcion 6.3: Pixelado
void InterfazConsola::menuPixelado()
{
    bool estado =false;

    //Llamo a Nueva Imagen
    string datos;
    datos += "Pixelado";    
    S->NuevaImagen(datos);

    //Llamo a Pixelar
    estado = S->Pixelar();

    if (estado)
        cout<<"Filtro aplicado."<<endl;
}

//-----------------------------------------
//Opcion 7: Gestion de Banco de Imagenes
void InterfazConsola::menuGestion()
{
    bool aux = false;
    unsigned short opcion = 99;
    unsigned short tamanio=0;
    bool salir = false;

    cout<<"Seleccione la imagen actual"<<endl;
    cout<<S->ListarBanco(tamanio);
    cout<<endl<<"0. Salir"<<endl;
    cout<<"Opcion: ";

    while(!salir)
    {
        cin>>opcion;
        aux = S->FijarImagenActual(opcion);
        if(opcion!=0 || aux)
            salir = true;
        else cout<<"El valor ingresado no es correcto";
    }
}
