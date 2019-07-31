#include <cstdlib>
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include <vector>
#include "ekserevnisis.h"
#include "xrisothiras.h"
#include "initialize.h"
#include "time.h"
#include <fstream>

using namespace std;

Ploio::Ploio()
{

    megisth_antoxh=10;
    trexousa_antoxh=10;
    speed=2;
    apothema=10;
    thesi_y=rand()%10;
    thesi_x=rand()%10;
    typos_ploiou=0;
    synolikh_metakinhsh=0;
    synoliko_dmg=0;
}

int Ploio::synoliko_gold=0;


Ploio::~Ploio()
{



}

int Ploio::get_synolikh_metakinhsh()
{
    return synolikh_metakinhsh;
}

int Ploio::get_synoliko_dmg()
{
    return synoliko_dmg;
}


int Ploio::get_megisth_antoxh()
{
    return megisth_antoxh;
}
int Ploio::get_trexousa_antoxh()
{
    return trexousa_antoxh;
}
int Ploio::get_speed()
{
    return speed;
}
int Ploio::get_apothema()
{
    return apothema;
}
int Ploio::get_thesi_y()
{
    return thesi_y;
}
int Ploio::get_thesi_x()
{
    return thesi_x;
}
int Ploio::get_typos_ploiou()
{

    return typos_ploiou;
}


void Ploio::set_synolikh_metakinhsh(int a)
{
    synolikh_metakinhsh=a;
}

void Ploio::set_synoliko_dmg(int a)
{
    synoliko_dmg=a;
}

void Ploio::set_megisth_antoxh(int a)
{
    megisth_antoxh=a;
}

void Ploio::set_trexousa_antoxh(int t)
{
    if((t)>megisth_antoxh)
    {
        trexousa_antoxh=megisth_antoxh;
    }
    else trexousa_antoxh=t;

}



void Ploio::set_speed(int s)
{
    speed=s;
}
void Ploio::set_apothema(int ap)
{
    apothema=ap;
}
void Ploio::set_thesi_xy(int x, int y, thalassa (*thal_ptr)[10][10])
{
    int old_x=get_thesi_x();
    int old_y=get_thesi_y();
    (*thal_ptr)[old_x][old_y].set_id_ploiou(0);
    thesi_x=x;
    thesi_y=y;
    (*thal_ptr)[thesi_x][thesi_y].set_id_ploiou(get_typos_ploiou());

}
void Ploio::set_typos_ploiou(int i)
{
    typos_ploiou=i;
}

//void set_idploiou(int id){thalassa.set_id_ploiou(id);}

void Ploio::metakinisi(thalassa (*thal_ptr)[10][10])

{
    int counter=get_speed();//pairnoume tin taxitita wste na doume poses theseis tha metakinithei to ploio
    int x=get_thesi_x(); // pairnoume tin thesi tou ploiou
    int y=get_thesi_y();



    while (counter>0)
    {

        int ch;

        ch=rand() % 4; //exoume 4 megistes dynates metakiniseis

        switch(ch)
        {
        case 0:
            if (x<9 && (*thal_ptr)[x+1][y].get_id_ploiou()==0)
            {
                x=x+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }

            else if (x>0 && (*thal_ptr)[x-1][y].get_id_ploiou()==0)
            {
                x=x-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y<9 && (*thal_ptr)[x][y+1].get_id_ploiou()==0)
            {
                y=y+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y>0 && (*thal_ptr)[x][y-1].get_id_ploiou()==0)
            {
                y=y-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            break;

        case 1:
            if (x>0 && (*thal_ptr)[x-1][y].get_id_ploiou()==0)
            {
                x=x-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (x<9 && (*thal_ptr)[x+1][y].get_id_ploiou()==0)
            {
                x=x+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y>0 && (*thal_ptr)[x][y-1].get_id_ploiou()==0)
            {
                y=y-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y<9 && (*thal_ptr)[x][y+1].get_id_ploiou()==0)
            {
                y=y+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            break;

        case 2:
            if (y<9 && (*thal_ptr)[x][y+1].get_id_ploiou()==0)
            {
                y=y+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y>0 && (*thal_ptr)[x][y-1].get_id_ploiou()==0)
            {
                y=y-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (x>0 && (*thal_ptr)[x-1][y].get_id_ploiou()==0)
            {
                x=x-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (x<9 && (*thal_ptr)[x+1][y].get_id_ploiou()==0)
            {
                x=x+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            break;

        case 3:
            if (y>0 && (*thal_ptr)[x][y-1].get_id_ploiou()==0)
            {
                y=y-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (y<9 && (*thal_ptr)[x][y+1].get_id_ploiou()==0)
            {
                y=y+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (x<9 && (*thal_ptr)[x+1][y].get_id_ploiou()==0)
            {
                x=x+1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            else if (x>0 && (*thal_ptr)[x-1][y].get_id_ploiou()==0)
            {
                x=x-1;
                set_synolikh_metakinhsh(get_synolikh_metakinhsh()+1);
            }
            break;

        }

        counter=counter-1;
        set_thesi_xy(x,y,thal_ptr);



    };
    cout<<"To ploio ";
    string c;
    int xi=get_typos_ploiou();
    if(xi==1) c="peiratiko ";
    else if(xi==2) c="emporiko ";
    else if(xi==3) c="episkevastiko ";
    else if(xi==4) c="ekserevnhshs ";
    else if(xi==5) c="klefths ";
    else if(xi==6) c="xrysothiras ";

    cout<<c<<get_id()<<" metakinithike stin thesi "<<x<<","<<y<<endl;
}

void Ploio::leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10])
{

}//virtual void leitourgia()=0; //h pure virtual synarthsh mas pou tha ginetai overwrite se kathe ypoklasi tou ploiou

int Ploio::get_id()
{

}


string operator!(Ploio &P)
{
    string c;
    int x=P.get_typos_ploiou();
    if(x==1) c="peiratiko ";

    else if(x==2) c="emporiko ";
    else if(x==3) c="episkevastiko ";
    else if(x==4) c="ekserevnhshs ";
    else if(x==5) c="kleftis ";
    else if(x==6) c="xrisothiras ";

    return c;

}

Ploio operator-(Ploio &P, int dmg)
{

    P.set_trexousa_antoxh(P.trexousa_antoxh-dmg);
    return(P);

}

Ploio operator+(Ploio &P, Ploio &k)

{

    if(P.get_typos_ploiou()==1) // otan kanei epi8esh to peiratiko
    {
        P.set_apothema(P.get_apothema()+(0.2*k.get_apothema()));
        cout<<" kai tou eklepse "<<int(0.2*k.get_apothema())<<" xrysafi"<<endl;
        k.set_apothema(0.8*k.get_apothema());

    }
    else if(P.get_typos_ploiou()==1)
    {
        P.set_apothema(P.get_apothema()+XRISOS_KLOPIS);
        k.set_apothema(k.get_apothema()-XRISOS_KLOPIS);
    }
    else
    {
        P.set_apothema(P.get_apothema()+XREWSH);
        k.set_apothema(k.get_apothema()-XREWSH);
    }

    return(P);

}

ostream& operator<< (ostream &out, Ploio &P)
{
    int x=P.get_id();
    switch(P.typos_ploiou)
    {
    case 1:
        out <<"PEIRATIKO "<<x<<endl;
        break;
    case 2:
        out<<"EMPORIKO "<<x<<endl;
        break;
    case 3:
        out<<"EPISKEVASTIKO "<<x<<endl;
        break;
    case 4:
        out<<"EKSEREVNHSHS "<<x<<endl;
        break;
    case 5:
        out<<"KLEFTHS "<<x<<endl;
        break;
    case 6:
        out<<"XRISOTHIRAS "<<x<<endl;
        break;
    }
    out <<"H megisth antoxh tou ploiou einai: "<<P.megisth_antoxh<<endl<<"H trexousa antoxh tou ploiou einai: "<<P.trexousa_antoxh<<endl<<
        "H taxythta tou ploiou einai : "<<P.speed<<endl<<"To apothema thisavrou einai: "<<P.apothema<<endl<<"H thesh x tou ploiou einai: "<<P.thesi_x<<endl
        <<"H thesh y tou ploiou einai: "<<P.thesi_y<<endl<<endl;
    return out;
}





