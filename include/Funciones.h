#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>
#include <fstream>
#include <sstream>

#define TAM         10000

using namespace std;

string producirPalabra( string cadena , unsigned int *posicion );
int esEspacio( char caracter );
bool esEtiqueta( char caracter );


string producirPalabra( string cadena , unsigned int *posicion )
{
    char palabra[TAM];
    int cont = 0;

    while( esEspacio( cadena[*posicion] ) )
    {
        (*posicion)++;
    }

    do
    {
        palabra[cont] = cadena[*posicion];
        cont++;
        (*posicion)++;
    }while( !esEtiqueta( cadena[*posicion] ));
    if( cadena[*posicion] != '<')
    {
        palabra[cont] = cadena[*posicion];
        cont++;
        (*posicion)++;
    }

    palabra[cont]='\0';
    return palabra;
}
int esEspacio( char caracter )
{
    if( caracter == '\n' || caracter == '\t' || caracter == '\r' || caracter == ' ' )
        return true;
    return false;
}
bool esEtiqueta( char caracter )
{
    if( caracter == '<' || caracter == '>' )
        return true;
    return false;
}


#endif // FUNCIONES_H_INCLUDED
