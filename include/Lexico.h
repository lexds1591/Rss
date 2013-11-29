#ifndef LEXICO_H
#define LEXICO_H


#include <string>
#include <iostream>
#include <cctype>

#define RSS_INICIO 	        0
#define RSS_FIN 	        1
#define CHANNEL_INICIO      2
#define CHANNEL_FIN	        3
#define TITLE_INICIO	    4
#define TITLE_FIN	        5
#define CADENA		        6//NO ELIMINAR ESPACIOS
#define LINK_INICIO	        7
#define LINK_FIN	        8
#define DESCRIPTION_INICIO  9
#define DESCRIPTION_FIN	    10
#define ITEM_INCIO	        11
#define ITEM_FIN      	    12

#define ERROR               -1
#define EXITO               0

using namespace std;

class Lexico
{
    public:

        Lexico( int estado , string cadena );
        virtual ~Lexico( void );

        unsigned int getEstado( void )
        {
            return estado_;
        }
        void setEstado( unsigned int val )
        {
            estado_ = val;
        }
        int getTipo()
        {
            return tipo_;
        }
        string getPalabra( void )
        {
            return palabra_;
        }
        void setPalabra( string  palabra )
        {
            palabra_ = palabra;
        }
        void setTipo( int val )
        {
            tipo_ = val;
        }
        void sigPalabra( void );
        int findNameTag( string palabra , unsigned int *posicion );
        void analizar( string palabra );

    protected:
    private:
        int estado_;
        int tipo_;
        unsigned int posicion;
        string cadena_;
        string palabra_;

};

#endif // LEXICO_H
