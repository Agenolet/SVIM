#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "imagen.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "graficador.h"
#include "pixel.h"
//-----------------------------------------

class Graficador : public QOpenGLWidget, protected QOpenGLFunctions
{
private:
    Imagen *I;
    float escala;  //Escala de la imagen (Relacion de aspecto menor)
    int argc;
    char **argv;

    //Valores para desplazar la imagen al centro de la pantalla
    float deltax;
    float deltay;

public:
    Graficador(QWidget * parent = 0);   //Constructor
    void CargarImagen(Imagen *pI);
    void GraficarImagen();

protected:
    // Métodos obligatorios que se deben redefinir aquí en protected:
                                            //ALE: NO ENTIENDO COMO SE EJECUTAN ESTOS METODOS SI DESDE EL MAIN NO SE LLAMAN
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int ancho, int alto);

};

#endif // GRAFICADOR_H
