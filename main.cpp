/**@Proyecto Individual RSS
 *Alejandro Duarte Sánchez
 *Seccion:D02
 */

/*************************** TO DO *********************************************
*
*
*
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/Lexico.h"
#include "include/Sintactico.h"
#include "include/ArchivoIO.h"


using namespace std;

int main()
{
    string cadena;
    int estado = 0;
    string palabra;
    char ruta[] = "entrada.txt";
    char rutaSalida[]="salida.txt";
    char permisos[] = "r";

    cadena = leerArchivo( ruta ,permisos );//se obtiene toda la cadena del archivo

    Lexico lexico( estado , cadena );
    Sintactico sintactico( rutaSalida );

    sintactico.analizar( lexico );//se realiza analisis sintactico

    return EXIT_SUCCESS;
}
