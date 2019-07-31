
#include <cstdlib>
using namespace std;
#include "initialize.h"
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include <vector>
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"
#include "time.h"


kleftis::kleftis()
{
    set_speed(1);
    set_typos_ploiou(5);
    set_megisth_antoxh(antoxh_peiratikou);
    set_trexousa_antoxh(antoxh_peiratikou);
    count_klefti++;
    id_klefti=count_klefti;
    xrisafi_klemeno=0;
}
int kleftis::count_klefti=0;
int kleftis::dmg_taken_klefti=0;
int kleftis::get_id()
{
    return id_klefti;
}
int kleftis::get_xrisafi()
{
    return xrisafi_klemeno;
}
void kleftis::leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
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
            *P+*ptr[i];
            xrisafi_klemeno=xrisafi_klemeno+XRISOS_KLOPIS;
            cout<<"To ploio kleftis "<<P->get_id()<<" eklepse "<<XRISOS_KLOPIS<<" apo to ploio "<< !(*ptr[i])<<ptr[i]->get_id()<<endl;
        }

    }

}
