#include "archivoppm.h"

//-----------------------------------------------------
//Constructor
ArchivoPPM::ArchivoPPM()
{

}

//-----------------------------------------------------
// Cargar Imagen PPM
bool ArchivoPPM::CargarImagen(string nombre, Imagen *I)
{
    ifstream infile;

    bool estado = false;

    unsigned pos;
    string NumeroMagico;
    unsigned MaxColor;
    unsigned int pixalto, pixancho;
    //string comentario;

    string carpeta = "imags/PPM/";
    nombre = carpeta+nombre;

    if ( nombre.find(".ppm") != string::npos )
        estado = true;

    // ------ Parte Texto ------
    infile.open(nombre.c_str() , ios::in);

    if (infile && estado)
    {

        infile >> NumeroMagico;

        infile.ignore();

        if( NumeroMagico != "P6")                       //Si el numero magico es distinto a P6 ,  el archivo no es realmente un PPM
            estado = false;
        else
        {
            //Encabezado
                                                                //infile >> comentario; //No poseen comentario
            infile >> pixancho;                                 //Puede faltar un infile.ingore()

            infile.ignore();

            infile >> pixalto;

            infile >> MaxColor;                                 //MaxColor 255 siempre en los PPM de la catedra

            infile.ignore();

            pos = infile.tellg();

            //Asignamos los valores leidos a la instancia de Imagen (I)
            I->SetTamanio(pixalto, pixancho);
            I->SetAlto((float)pixalto);
            I->SetAncho((float)pixancho);
                                                                //I.SetMetadatos(comentario);



            infile.close();

            // ------ Parte Binaria ------
            unsigned char R, G, B;
            float R_nuevo , G_nuevo , B_nuevo;

            infile.open(nombre.c_str() , ios::in | ios::binary );
            if(infile.good())
             {
                infile.seekg(pos , ios::beg);

                for(unsigned i=0 ; i<pixalto ; ++i)
                    for(unsigned j=0 ; j<pixancho ; ++j)
                    {
                        infile.read( (char*)&R , sizeof(unsigned char) );
                        R_nuevo=(1.0f*R/255);

                        infile.read( (char*)&G , sizeof(unsigned char) );
                        G_nuevo=(1.0f*G/255);

                        infile.read( (char*)&B , sizeof(unsigned char) );
                        B_nuevo=(1.0f*B/255);

                        Pixel p (R_nuevo,G_nuevo,B_nuevo);
                        I->SetPixel(p,i,j);
                    }
            }
            infile.close(); //Cierro el archivo
         }
     }
    else estado = false;

    return estado;
}

//-----------------------------------------------------
// Guardar Imagen PPM
bool ArchivoPPM::GuardarImagen(string nombre, Imagen *I)
{
    ofstream outfile;
    bool estado = false;

    string carpeta = "imags/PPM/";
    nombre = carpeta+=nombre;
    unsigned MaxColor = 255 ;

    // ------ Parte Texto ------
    outfile.open(nombre.c_str());

    if(outfile.good())
        {
            estado = true;
            outfile << "P6" << endl;                                        //Como estoy guardando un PPM, su Numero Magico es P6
                                                                            //outfile << I.GetMetadato() << endl; //Si la imagen es PPM, en Metadato se almacena el Comentario
            outfile << I->GetPixancho() << ends << I->GetPixalto() << endl ;  //Escribo el ancho y el alto
            outfile << MaxColor << endl;                                    //Escribo el ColorMax del PPM
        }
     outfile.close();

     // ------ Parte Binaria ------
     outfile.open( nombre.c_str() , ios::binary | ios::out | ios::app);

     unsigned char C;
     for(unsigned i=0 ; i<I->GetPixalto() ; ++i)
        for(unsigned j=0 ; j<I->GetPixancho() ; ++j)
            {
                //Transformo el Float devuelto por el Get% (% =R|G|B) a Unsigned char y escribo en el archivo dicho Unsigned char

                C = (unsigned char)((*I)[i][j].GetR() * MaxColor );
                outfile.write( (char*)&C , sizeof(unsigned char) );

                C = (unsigned char)((*I)[i][j].GetG() * MaxColor );
                outfile.write( (char*)&C , sizeof(unsigned char) );

                C = (unsigned char)((*I)[i][j].GetB() * MaxColor );
                outfile.write( (char*)&C , sizeof(unsigned char) );
            }
     estado = outfile.good();
     outfile.close();
     return estado;
}

//-----------------------------------------------------
// Destructor
ArchivoPPM::~ArchivoPPM()
{

}
