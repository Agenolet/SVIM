#include "graficador.h"
#include "imagen.h"
#include "pixel.h"



//-----------------------------------------
//Constructores
Graficador::Graficador(QWidget *parent) : QOpenGLWidget(parent)
{
                                                                // No hay nada más para hacer en el constructor.
}

void Graficador::CargarImagen(Imagen *pI)
{
    I = pI;
}

//-----------------------------------------
//MetodosGL + GraficarImagen
//-----------------------------------------
void Graficador::initializeGL()
{
    initializeOpenGLFunctions();    //ALE: PARA QUE ES ESTA FUNCION? EN UN EJEMPLO ESTA Y EN OTRO NO
    // Se define el color del fondo para los lugares en que no se grafica
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

//-----------------------------------------
void Graficador::paintGL()
{
    // Limpiar la pantalla:
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Relación de aspecto entre pixeles y dimensiones de la ventana
    float relAncho = ((float)width())  / ((float) I->GetPixancho() );
    float relAlto  = ((float)height()) / ((float) I->GetPixalto() );

    escala = 1.0f;
    deltax = 0.0f;
    deltay = 0.0f;

    // Probar comentando y descomentando el siguiente cálculo:
    if(relAncho < relAlto)
    {
        escala = relAncho;  // se establece la MENOR.
        deltay = (height() - I->GetPixalto()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        deltax = (width() - I->GetPixancho()*escala)*0.5f;
    }

    GraficarImagen();
}

//-----------------------------------------
void Graficador::GraficarImagen()
{
    glPushMatrix();                         // Iniciar un bloque(matriz) aislado para las transformaciones

        glTranslatef(deltax, deltay, 0.0f); // Desplaza la imagen al centro de la ventana


        glScalef(escala, escala, 1.0f);     // Escalar que mantenga sus proporciones al tamaño de ventana actual

        glBegin(GL_QUADS);                  // Cuadrados para los pixeles, se modifican de tamaño al cambiar el tamaño de la ventana.

        Pixel Paux;
                                            //bool aux=false;
        for(unsigned i=0; i<I->GetPixalto() ; ++i)
            for(unsigned j=0; j<I->GetPixancho() ; ++j)
                {
                    Paux = (*I)[i][j];          //Paux = I->GetPixel(i,j,aux);
                    float R = Paux.GetR();
                    float G = Paux.GetG();
                    float B = Paux.GetB();



                    glColor3f( R, G, B );

                    glVertex3f(j, I->GetPixalto()-i, 0);
                    glVertex3f(j, I->GetPixalto()-(i+1), 0);
                    glVertex3f(j+1, I->GetPixalto()-(i+1), 0);
                    glVertex3f(j+1, I->GetPixalto()-i, 0);

                };

        glEnd();

    // Finaliza el bloque de transformaciones:
    glPopMatrix();
}

//-----------------------------------------
void Graficador::resizeGL(int ancho, int alto)
{

    glViewport(0, 0, ancho, alto);  // Se define el viewport para que se utilice todo el espacio de la ventana

    glMatrixMode(GL_PROJECTION);    // Cambiamos al modo proyección para definirla

    glLoadIdentity();               // Se borran todas las matrices anteriores

    glOrtho(0, width(), 0, height(), -1, 1);

    glMatrixMode(GL_MODELVIEW);     // Se vuelve al modo modelview para que sea utilizado en el dibujo

    glLoadIdentity();               // Se borran odas las matrices anteriores
}


