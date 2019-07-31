#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include <vector>
#include "emporiko.h"
#include "episkevastiko.h"
#include "initialize.h"
#include "xrisothiras.h"
#include "time.h"
emporiko::emporiko()
{
    set_speed(2);
    set_typos_ploiou(2);
    set_megisth_antoxh(antoxh_emporikou);
    set_trexousa_antoxh(antoxh_emporikou);
    set_apothema(2);
    gold_limania=0;
    count_emporiko++;
    id_emporikou=count_emporiko;

}

int emporiko::count_emporiko=0;
int emporiko::dmg_taken_emporikou=0;

void emporiko::leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
{
    int x=get_thesi_x();
    int y=get_thesi_y();

    if ((*thal_ptr)[x+1][y].get_einai_limani() || (*thal_ptr)[x-1][y].get_einai_limani() || (*thal_ptr)[x][y+1].get_einai_limani() || (*thal_ptr)[x][y-1].get_einai_limani())
    {
        P->set_apothema(P->get_apothema()+KERDOS);
        gold_limania=gold_limania+KERDOS; // ta synolika esoda apo limania

        cout<<"To emporiko "<<P->get_id()<<" phre apo to limani "<<KERDOS<<" xrysafi"<<endl;


    }



}


void emporiko::set_gold_limania(int a)
{
    gold_limania=a;
}

int emporiko::get_gold_limania()
{
    return gold_limania;
}

int emporiko::get_id()
{
    return id_emporikou;
}
