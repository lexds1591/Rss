#ifndef SINTACTICO_H
#define SINTACTICO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/Lexico.h"
#include <vector>

#define COLUMNAS 9
#define FILAS    15
#define REGLAS   7

#define S               7
#define E               8

#define DESPLAZAMIENTO  0
#define REDUCCION       1


using namespace std;

class Sintactico
{
    public:
        Sintactico( char *rutaSalida );
        virtual ~Sintactico( void );
        int analizar( Lexico lexico );
    protected:
    private:
            ofstream salida_;
            int R( Lexico *lexico );
            int C( Lexico *lexico );
            int C2( Lexico *lexico );
            int O( Lexico *lexico );
            int T( Lexico *lexico );
            int L( Lexico *lexico );
            int D( Lexico *lexico );
            int I( Lexico *lexico );
            int I2( Lexico *lexico );

};

#endif // SINTACTICO_H
