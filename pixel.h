#ifndef PIXEL_H
#define PIXEL_H
//-----------------------------------------

class Pixel
{
private:
    float R;
    float G;
    float B;
    float brillo;
    bool verificar(float parametro); //privada por ser de uso interno
public:
    Pixel(float pR, float pG, float pB);
    Pixel ();
    //Set y Get de R G B
    void SetR(float pR);
    void SetG(float pG);
    void SetB(float pB);
    float GetR();
    float GetG();
    float GetB();
    //Obtener brillo
    float GetBrillo();

    bool operator ==(Pixel C);
};

#endif // PIXEL_H
