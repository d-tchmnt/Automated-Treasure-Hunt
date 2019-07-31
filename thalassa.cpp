#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "initialize.h"
#include "xrisothiras.h"
#include <vector>
#include <cstdlib>
#include "time.h"

using std::endl;
using std::cin;
using std::cout;



thalassa::thalassa()//constructor gia thn aftomath arxikopoihsh antikeimenwn thalassa


{
    entash_kairou=rand()%10+1;

    if((rand()%10)>THISAVROI) exei_thisavro=0;   //exei 40% pi8anotita na exei thisavro
    else exei_thisavro=1;

    if((rand()%10)>LIMANIA) einai_limani=0;   //exei 10% pi8anotita na einai limani
    else einai_limani=1;
    id_ploiou=0;

}









void thalassa::set_entash_kairou(int entash)
{
    entash_kairou=entash;
}
int thalassa::get_entash_kairou()
{
    return entash_kairou;
}
void thalassa::set_exei_thisavro(bool thisavros)
{
    exei_thisavro=thisavros;
}
bool thalassa::get_exei_thisavro()
{
    return exei_thisavro;
}
void thalassa::set_einai_limani  (bool limani)
{
    einai_limani=limani;
}
bool thalassa::get_einai_limani()
{
    return einai_limani;
}
int thalassa::get_id_ploiou()
{
    return id_ploiou;
}
void thalassa::set_id_ploiou(int i)
{
    id_ploiou=i;
}






