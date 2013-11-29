#ifndef ARCHIVOIO_H_INCLUDED
#define ARCHIVOIO_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>

#define FIN_ARCHIVO 0
#define TAM         10000

using namespace std;

string leerArchivo( char* ruta , char* permisos );

string leerArchivo( char* ruta , char* permisos )
{
    FILE * archivo;
    char cadena[TAM];
    char caracter;
    int i = 0;

    archivo = fopen( ruta , permisos );

    if( archivo != NULL )
    {
        while( fread( &caracter , sizeof( char ) , 1 ,archivo ) > FIN_ARCHIVO  )
        {
            cadena[i] = caracter;
            i++;
        }

        cadena[i] = '\0';
    }
    else
    {
        cout << "No se pudo abrir el archivo: " << ruta << endl;
        //exit(0);
    }

    fclose( archivo );

    return cadena;
}
void escribeSalida( char ruta[] , int dato )
{

    ofstream salida;
    salida.open( ruta , ios::out | ios::trunc );

    salida << dato;


    cout << "Archivo salida.txt ha sido creado!" << endl;
    salida.close();
}
#endif // ARCHIVOIO_H_INCLUDED
