#include "pixel.h"

//-----------------------------------------
//Constructores
Pixel::Pixel()
{
    R = 0;
    G = 0;
    B = 0;

}

Pixel::Pixel(float pR, float pG, float pB)
{
    if (verificar(pR))  //verifico ingreso de R
        R = pR;
        else
            R = 0;      //asigno cero si no cumple

    if (verificar(pG))  //verifico ingreso de G
        G = pG;
        else
            G = 0;      //asigno cero si no cumple

    if (verificar(pB))  //verifico ingreso de B
        B = pB;
        else
            B = 0;      //asigno cero si no cumple
}

//-----------------------------------------
//Set y Get de R G B
void Pixel::SetR(float pR)
{
    if (verificar(pR))  //verifico ingreso de R
        R = pR;
        else
            R = 0;      //asigno cero si no cumple

}
void Pixel::SetG(float pG)
{
    if (verificar(pG))  //verifico ingreso de G
        G = pG;
        else
            G = 0;      //asigno cero si no cumple
}
void Pixel::SetB(float pB)
{
    if (verificar(pB))  //verifico ingreso de B
        B = pB;
        else
            B = 0;      //asigno cero si no cumple
}

float Pixel::GetR()
{
    return R;
}

float Pixel::GetG()
{
    return G;
}

float Pixel::GetB()
{
    return B;
}

//-----------------------------------------
//Get Brillo
float Pixel::GetBrillo()
{
    return ((R + G + B)/3.0f); //retorno promedio de colores (va a ir de 0 a 1)
}

//-----------------------------------------
//Sobrecarga de ==
bool Pixel::operator ==(Pixel C)
{
  bool aux = false;
  float Raux = (this->GetR() - C.GetR());
  float Gaux = (this->GetG() - C.GetG());
  float Baux = (this->GetB() - C.GetB());

  if( ( Raux <= 0.2501f && Raux >= -0.2501) && ( Gaux <= 0.2501f && Gaux >= -0.2501) && ( Baux <= 0.2501f && Baux >= -0.2501))
      aux = true;

  return aux;
}

//-----------------------------------------
//Funcion para verificar el valor de RGB
bool Pixel::verificar(float parametro) //para verificar que los parametro esten entre 0 y 1
{
    bool estado = false;
    if(parametro >= 0 && parametro <= 1)
        estado = true;
    return estado;
}
