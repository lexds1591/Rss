#include "../include/Sintactico.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;

Sintactico::Sintactico( void )
{

}

Sintactico::~Sintactico( void )
{
    //dtor
}

int Sintactico::analizar( Lexico lexico  )
{

    return R(&lexico);

}
int Sintactico::R( Lexico *lexico )
{
    lexico->sigPalabra();

    if( lexico->getTipo() == RSS_INICIO )
    {
        if( C(lexico) == EXITO )
        {
            if( lexico->getTipo() == RSS_FIN )
            {
                return EXITO;
            }
        }

    }
    return ERROR;
}
int Sintactico::C( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getTipo() == CHANNEL_INICIO )
    {
        if( O(lexico) == EXITO )
        {
            if( I(lexico) == EXITO )
            {
                if( lexico->getTipo() == CHANNEL_FIN )
                {
                    lexico->sigPalabra();
                    if( lexico->getTipo() == RSS_FIN )
                    {
                        return EXITO;
                    }
                    else if( C2(lexico) == EXITO )
                    {
                        return EXITO;
                    }
                }
            }
        }
    }

    return ERROR;
}
int Sintactico::C2( Lexico *lexico )
{
    if( lexico->getTipo() == CHANNEL_INICIO )
    {
        if( O(lexico) == EXITO )
        {
            if( I(lexico) == EXITO )
            {
                lexico->sigPalabra();
                if( lexico->getTipo() == CHANNEL_FIN )
                {
                    lexico->sigPalabra();
                    if( lexico->getTipo() == RSS_FIN )
                    {
                        return EXITO;
                    }
                    else if( C2(lexico) == EXITO )
                    {
                        return EXITO;
                    }
                }
            }
        }
    }

    return ERROR;
}
int Sintactico::O( Lexico *lexico )
{
    if( T(lexico) == EXITO )
    {
        if( L(lexico) == EXITO )
        {
            if( D(lexico) == EXITO )
            {
                return EXITO;
            }
        }
    }
    return ERROR;
}
int Sintactico::T( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getTipo() == TITLE_INICIO )
    {
        lexico->sigPalabra();
        if( lexico->getTipo() == CADENA )
        {
          lexico->sigPalabra();
            if( lexico->getTipo() == TITLE_FIN )
            {
                return EXITO;
            }
        }
    }
    return ERROR;
}
int Sintactico::L( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getTipo() == LINK_INICIO )
    {
        lexico->sigPalabra();
        if( lexico->getTipo() == CADENA )
        {
          lexico->sigPalabra();
            if( lexico->getTipo() == LINK_FIN )
            {
                return EXITO;
            }
        }
    }
    return ERROR;
}
int Sintactico::D( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getTipo() == DESCRIPTION_INICIO )
    {
        lexico->sigPalabra();
        if( lexico->getTipo() == CADENA )
        {
          lexico->sigPalabra();
            if( lexico->getTipo() == DESCRIPTION_FIN )
            {
                return EXITO;
            }
        }
    }
    return ERROR;
}
int Sintactico::I( Lexico *lexico )
{
    lexico->sigPalabra();
    if( lexico->getTipo() == ITEM_INCIO )
    {
        if( O(lexico) == EXITO )
        {
            lexico->sigPalabra();
            if( lexico->getTipo() == ITEM_FIN )
            {
                lexico->sigPalabra();
                if( lexico->getTipo() == CHANNEL_FIN )
                {
                    return EXITO;
                }
                else if( I2(lexico) == EXITO )
                {
                    return EXITO;
                }
            }
        }
    }
 return ERROR;
}
int Sintactico::I2( Lexico *lexico )
{
    if( lexico->getTipo() == ITEM_INCIO )
    {
        if( O(lexico) == EXITO )
        {
            lexico->sigPalabra();
            if( lexico->getTipo() == ITEM_FIN )
            {
                lexico->sigPalabra();
                if( lexico->getTipo() == CHANNEL_FIN )
                {
                    return EXITO;
                }
                else if( I2(lexico) == EXITO )
                {
                    return EXITO;
                }
            }
        }
    }
    return ERROR;
}
