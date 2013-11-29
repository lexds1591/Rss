#include "../include/Lexico.h"
#include "../include/Funciones.h"
#include <algorithm>
#include <cctype>

Lexico::Lexico( int estado , string cadena )
{
    estado_ = estado;
    posicion = 0;
    tipo_ = -1;
    cadena_ = cadena;
}

Lexico::~Lexico( void )
{
    //dtor
}

void Lexico::analizar( string palabra )
{

    int tipoNameTag;
     for( unsigned int i = 0 ; i < palabra.length() && estado_ != ERROR ; i++ )
     {
         switch(estado_)
         {
             case 0:
                    if( palabra[i] == '<' )
                    {
                        estado_ = 1;
                    }
                    else if( isascii(palabra[i]) )
                    {
                        estado_ = 27;
                    }
                    else
                        estado_ = ERROR;

             break;
             case 1:
                    if( palabra[i] == '/' )
                    {
                        estado_ = 14;
                    }
                    else
                    {
                        tipoNameTag = findNameTag( palabra , &i );
                        switch( tipoNameTag )
                        {
                            case 1://RSS
                                    estado_ = 12;
                            break;
                            case 2://CHANNEL
                                    estado_ = 2;
                            break;
                            case 3://TITLE
                                    estado_ = 6;
                            break;
                            case 4://LINK
                                    estado_ = 8;
                            break;
                            case 5://DESCRIPTION
                                    estado_ = 10;
                            break;
                            case 6://ITEM
                                    estado_ = 4;
                            break;
                            default:
                                    estado_ = ERROR;
                            break;
                        }
                    }
             break;
             case 2:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 3;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 3://terminal

             break;
             case 4:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 5;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 5://terminal

             break;
             case 6:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 7;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 7://terminal

             break;
             case 8:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 9;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 9://terminal

             break;
             case 10:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 11;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 11://terminal

             break;
             case 12:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 13;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 13://terminal

             break;
             case 14:
                    tipoNameTag = findNameTag( palabra , &i );
                    switch( tipoNameTag )
                    {
                        case 1://RSS
                                estado_ = 25;
                        break;
                        case 2://CHANNEL
                                estado_ = 15;
                        break;
                        case 3://TITLE
                                estado_ = 19;
                        break;
                        case 4://LINK
                                estado_ = 21;
                        break;
                        case 5://DESCRIPTION
                                estado_ = 23;
                        break;
                        case 6://ITEM
                                estado_ = 17;
                        break;
                        default:
                                estado_ = ERROR;
                        break;
                    }
             break;
             case 15:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 16;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 16://terminal

             break;
             case 17:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 18;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 18://terminal

             break;
             case 19:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 20;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 20://terminal

             break;
             case 21:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 22;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 22://terminal

             break;
             case 23:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 24;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 24://terminal

             break;
             case 25:
                    if( palabra[i] == '>' )
                    {
                        estado_ = 26;
                    }
                    else
                    {
                        estado_ = ERROR;
                    }
             break;
             case 26://terminal

             break;
             case 27://terminal
                    if( isascii(palabra[i]) )
                    {
                        estado_ = 27;
                    }
                    else
                        estado_ = ERROR;
             break;

             default:
                    tipo_ = ERROR;
             break;
         }
     }
     switch( estado_ )
     {
         case 27:
                tipo_ = CADENA;
         break;
         case 13:
                tipo_ = RSS_INICIO;
         break;
         case 26:
                tipo_ = RSS_FIN;
         break;
         case 3:
                tipo_ = CHANNEL_INICIO;
         break;
         case 16:
                tipo_ = CHANNEL_FIN;
         break;
         case 7:
                tipo_ = TITLE_INICIO;
         break;
         case 20:
                tipo_ = TITLE_FIN;
         break;
         case 9:
                tipo_ = LINK_INICIO;
         break;
         case 22:
                tipo_ = LINK_FIN;
         break;
         case 11:
                tipo_ = DESCRIPTION_INICIO;
         break;
         case 24:
                tipo_ = DESCRIPTION_FIN;
         break;
         case 5:
                tipo_ = ITEM_INCIO;
         break;
         case 18:
                tipo_ = ITEM_FIN;
         break;
         default:
         break;
     }
}
void Lexico::sigPalabra( void )
{

    setEstado( 0 );
    setPalabra( producirPalabra( cadena_ , & posicion) );
    analizar( palabra_ );
}
int Lexico:: findNameTag( string palabra , unsigned int *posicion )
{
    string name;
    unsigned int encontrado = palabra.find("/");

    if( encontrado >palabra.size()-1 )
    {
        encontrado = palabra.find(">")-1;
        name = palabra.substr( (*posicion), encontrado );
    }
    else
    {
        encontrado = palabra.find(">")-1;
        name = palabra.substr( (*posicion), encontrado-1 );
    }



    transform(name.begin(), name.end(),name.begin(), ::toupper);

    if( name == "RSS" )
    {
        (*posicion) = encontrado;
        return 1;
    }
    else if( name == "CHANNEL" )
    {
        (*posicion) = encontrado;
        return 2;
    }
    else if( name == "TITLE" )
    {
        (*posicion) = encontrado;
        return 3;
    }
    else if( name == "LINK" )
    {
        (*posicion) = encontrado;
        return 4;
    }
    else if( name == "DESCRIPTION" )
    {
        (*posicion) = encontrado;
        return 5;
    }
    else if( name == "ITEM" )
    {
        (*posicion) = encontrado;
        return 6;
    }

    return -1;
}
