#ifndef METADATOS_H
#define METADATOS_H

#include <map>
#include <utility>
#include <string>

using namespace std;
//-----------------------------------------

class metadatos
{
private:
    map <string, string> lista;

public:
    metadatos();
    bool CargarMetadatos(string pentrada);
    bool InsertarMetadato(string pclave, string pvalor);
    string MostrarMetadatos();


};

#endif // METADATO_H
