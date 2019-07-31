#include <cstdlib>
using namespace std;
#include "initialize.h"
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include <vector>
#include "peiratiko.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"
#include "xrisothiras.h"
#include "time.h"
#include "kleftis.h"


peiratiko::peiratiko()
{
    set_speed(1);
    set_dynamh(3);
    set_typos_ploiou(1);
    set_megisth_antoxh(antoxh_peiratikou);
    set_trexousa_antoxh(antoxh_peiratikou);
    prokal_dmg=0;           //to sinoliko dmg pou prokalei to ploio
    count_peiratiko++;
    id_peiratikou=count_peiratiko-kleftis::count_klefti;

}
int peiratiko::count_peiratiko=0;
int peiratiko::dmg_taken_peiratikou=0;

int peiratiko::get_id()
{
    return id_peiratikou;
}

int peiratiko::get_dynamh()
{
    return dynamh;
}
void peiratiko::set_dynamh(int d)
{
    dynamh=d;
}
void peiratiko::set_prokal_dmg(int d)
{
    prokal_dmg=d;
}

int peiratiko::get_prokal_dmg()
{
    return prokal_dmg;
}


void peiratiko::leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
{
    int x=get_thesi_x();
    int y=get_thesi_y();


    for (int i=0; i<ptr.size(); i++)
    {

        if ((ptr[i]->get_thesi_x()==(x-1)) && (ptr[i]->get_thesi_y()==y)
                ||
                ptr[i]->get_thesi_x()==(x+1) && ptr[i]->get_thesi_y()==y
                ||
                ptr[i]->get_thesi_x()==x && ptr[i]->get_thesi_y()==(y+1)
                ||
                ptr[i]->get_thesi_x()==x && ptr[i]->get_thesi_y()==(y-1))
        {
            int ch=ptr[i]->get_typos_ploiou();
            switch(ch)
            {
            case 1:
                peiratiko::dmg_taken_peiratikou=peiratiko::dmg_taken_peiratikou+DMG;
                break;
            case 2:
                emporiko::dmg_taken_emporikou=emporiko::dmg_taken_emporikou+DMG;
                break;
            case 3:
                episkevastiko::dmg_taken_episk=episkevastiko::dmg_taken_episk+DMG;
                break;
            case 4:
                ekserevnisis::dmg_taken_ekser=ekserevnisis::dmg_taken_ekser+DMG;
                break;
            }

            *ptr[i]-DMG;
            prokal_dmg = prokal_dmg+DMG; //auksanoume th synolikh zhmia pou exei prokalesei
            ptr[i]->set_synoliko_dmg(ptr[i]->get_synoliko_dmg()+DMG); //auksanoume th synolikh zhmeia tou amunwmenou ploiou
            cout<<"To peiratiko "<<id_peiratikou<<" ekane "<<DMG<<" zhmia sto "<<(!*ptr[i])<<ptr[i]->get_id();
            *P+*ptr[i];





            break;
        }
    }
}






