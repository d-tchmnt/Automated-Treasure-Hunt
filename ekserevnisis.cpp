#include "initialize.h"
#include <iostream>
#include "Ploio.h"
#include <vector>
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"
#include "xrisothiras.h"
#include "time.h"

ekserevnisis::ekserevnisis()
{
    set_speed(2);
    set_typos_ploiou(4);
    set_megisth_antoxh(antoxh_ekser);
    set_trexousa_antoxh(antoxh_ekser);
    count_ekser++;
    id_ekser=count_ekser-xrisothiras::count_xrisothira;

}

int ekserevnisis::count_ekser=0;
int ekserevnisis::dmg_taken_ekser=0;


void ekserevnisis::leitourgia(Ploio *P,vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
{
    int x=P->get_thesi_x();
    int y=P->get_thesi_y();


    if(((*thal_ptr)[x-1][y].get_id_ploiou()==1 || (*thal_ptr)[x-1][y].get_entash_kairou()>7) && x>0 )  //an apo pano exei peiratiko h' kakokairia
    {


        if(x<9 && emove(x+1,y,thal_ptr) )  //an mporei na paei kato
        {
            x=x+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(y<9 && emove(x,y+1,thal_ptr) )  //an den mporei na paei kato kai mporei deksia
        {
            y=y+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(y>0 && emove(x,y-1,thal_ptr) )  //an den mporei na paei kato i deksia kai mporei aristera
        {
            y=y-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);

        }
        else
        {
            cout<<"To ploio eksereunisis "<<P->get_id()<<" den katafere na ektelesei tin leitourgia tou logo empodion"<<endl;
        }


    }
    else if(((*thal_ptr)[x+1][y].get_id_ploiou()==1 || (*thal_ptr)[x+1][y].get_entash_kairou()>7) && x<9 )  //an apo kato exei peiratiko h' kakokairia
    {


        if(x>0 && emove(x-1,y,thal_ptr) )  //an mporei na paei pano
        {
            x=x-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(y<9 && emove(x,y+1,thal_ptr) )  //an den mporei na paei pano kai mporei deksia
        {
            y=y+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(y>0 && emove(x,y-1,thal_ptr) ) //an den mporei na paei pano i deksia kai mporei aristera
        {
            y=y-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else
        {
            cout<<"To ploio eksereunisis "<<P->get_id()<<" den katafere na ektelesei tin leitourgia tou logo empodion"<<endl;
        }

    }


    else if(((*thal_ptr)[x][y-1].get_id_ploiou()==1 || (*thal_ptr)[x][y-1].get_entash_kairou()>7) && y>0 )  //an aristera exei peiratiko h' kakokairia
    {


        if(y<9 && emove(x,y+1,thal_ptr) )  //an mporei na paei deksia
        {
            y=y+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(x>0 && emove(x-1,y,thal_ptr) )  //an den mporei na paei deksia kai mporei pano
        {
            x=x-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(x<9 && emove(x+1,y,thal_ptr) )  //an den mporei na paei deksia kai mporei kato
        {
            x=x+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);

        }
        else
        {
            cout<<"To ploio eksereunisis "<<P->get_id()<<" den katafere na ektelesei tin leitourgia tou logo empodion"<<endl;
        }

    }
    else if(((*thal_ptr)[x][y+1].get_id_ploiou()==1 || (*thal_ptr)[x][y+1].get_entash_kairou()>7) && y<9 )  //an deksia exei peiratiko h' kakokairia
    {


        if(y>0 && emove(x,y-1,thal_ptr) )  //an mporei na paei aristera
        {
            y=y-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(x>0 && emove(x-1,y,thal_ptr) )  //an den mporei na paei aristera kai mporei pano
        {
            x=x-1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
        }
        else if(x<9 && emove(x+1,y,thal_ptr) )  //an den mporei na paei aristera kai pano  kai mporei kato
        {
            x=x+1;
            cout<<"To ploio eksereunisis "<<P->get_id()<<" ektelese tin leitourgia tou kai pige stin thesi "<<x<<","<<y<<endl;
            set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);

        }
        else
        {
            cout<<"To ploio eksereunisis "<<P->get_id()<<" den katafere na ektelesei tin leitourgia tou logo empodion"<<endl;
        }

    }

    P->set_thesi_xy(x,y,thal_ptr);



}

bool ekserevnisis::emove(int x, int y, thalassa (*thal_ptr)[10][10]) //an vrei opoiodipote ploio i kakokairia stin zitithisa thesi den paei ekei
{

    if(((*thal_ptr)[x][y].get_id_ploiou()>0) || (*thal_ptr)[x][y].get_entash_kairou()>7 ) return 0;
    else return 1;

}

int ekserevnisis::get_id()
{
    return id_ekser;
}
