#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include <vector>
#include "episkevastiko.h"
#include "ekserevnisis.h"
#include "initialize.h"
#include "xrisothiras.h"
#include "time.h"

episkevastiko::episkevastiko()
{
    set_speed(2);
    set_typos_ploiou(3);
    set_megisth_antoxh(antoxh_episk);
    set_trexousa_antoxh(antoxh_episk);
    gold_episk=0;
    count_episk++;
    id_episk=count_episk;

}

int episkevastiko::count_episk=0;
int episkevastiko::dmg_taken_episk=0;

void episkevastiko::leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
{
    int x=P->get_thesi_x();
    int y=P->get_thesi_y();
    for (unsigned int i=0; i<ptr.size(); i++)
    {
        if ((ptr[i]->get_thesi_x()==(x-1)) && (ptr[i]->get_thesi_y()==y)
                ||
                ptr[i]->get_thesi_x()==(x+1) && ptr[i]->get_thesi_y()==y
                ||
                ptr[i]->get_thesi_x()==x && ptr[i]->get_thesi_y()==(y+1)
                ||
                ptr[i]->get_thesi_x()==x && ptr[i]->get_thesi_y()==(y-1))
        {
            if(ptr[i]->get_megisth_antoxh()-ptr[i]->get_trexousa_antoxh()>0 && ptr[i]->get_apothema()>=XREWSH && ptr[i]->get_typos_ploiou()>1)
            {
                ptr[i]->set_trexousa_antoxh(ptr[i]->get_trexousa_antoxh()+EPISKEVH);
                *P+*ptr[i];
                gold_episk=gold_episk+XREWSH;
                cout<<"To ploio episkevastiko "<<P->get_id()<<" episkeuase to "<<(!*ptr[i])<<ptr[i]->get_id()<<" kata "<<EPISKEVH;
                cout<<" me xrewsh "<<XREWSH<<endl;

            }


        }
    }



}

int episkevastiko::get_id()
{
    return id_episk;
}
int episkevastiko::get_gold_episk()
{
    return gold_episk;
}

void episkevastiko::set_gold_episk(int a)
{
    gold_episk=a;
}
