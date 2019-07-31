#include <cstdlib>
using namespace std;
#include <iostream>
#include <vector>
#include "initialize.h"
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "kleftis.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"
#include "xrisothiras.h"
#include "time.h"
#include <windows.h>
#include <csignal>
#include <algorithm>
#include <sstream>


//i arxikopoihsh topothetei ta ploia ston xarti otan protodimiourgountai
void arxikopoihsh(vector <Ploio*>& ptr, thalassa (*thal)[10][10])
{
    for (unsigned int i=0; i<ptr.size(); i++)
    {

        int x=ptr[i]->get_thesi_x();
        int y= ptr[i]->get_thesi_y();
        (*thal)[x][y].set_id_ploiou(ptr[i]->get_typos_ploiou());

    }
}

//tin menucaller tin kaloume otan theloume na tiposoume to menu mas
void menucaller()
{
    cout<<"\t\t\tMenu\n\n"<<endl;
    cout<<"Patiste A gia na deite plirofories tou ploiou tis epilogis sas"<<endl;
    cout<<"Patiste B gia na deite epiloges sigkekrimenis thesis tou xarti"<<endl;
    cout<<"Patiste C gia na deite plirofories gia tous tipous twn ploiwn" <<endl;
    cout<<"Patiste D gia na deite taksinomimena ta ploia kata apothema xrisou i kata trexousa antoxi" <<endl;
    cout<<"Patiste E gia na prosthafairesete ploia ston xarti"<<endl;
    cout<<"Patiste F gia na tropopoiisete mia thesi tou xarti"<<endl;
    cout<<"Patiste ESC gia na sinexisei to programma\n\n"<<endl;

}

//tin Cconsoleinput tin kaloume gia na ka8arisoume ton buffer apo proigoumenes times
void ClearConsoleInputBuffer()
{
    PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
    DWORD ClearingVar2;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ClearingVar1,256,&ClearingVar2);
    delete[] ClearingVar1;
}

//tin sort_apothema tin kaloume stin sort gia na taksinomisoume ta ploia me vasi to xrisafi
bool sort_apothema( Ploio  *P1, Ploio *P2)
{
    if (P1->get_apothema()>P2->get_apothema())
        return P1->get_apothema()>P2->get_apothema();

}

//tin sort_antoxi tin kaloume stin sort gia na taksinomisoume ta ploia me vasi tin trexoumeni antoxi tous
bool sort_antoxh( Ploio  *P1, Ploio *P2)
{
    if (P1->get_trexousa_antoxh()<P2->get_trexousa_antoxh())
        return P1->get_trexousa_antoxh()<P2->get_trexousa_antoxh();

}






int main()
{
    //Arxikopoihsh ploiwn kai xarth
    thalassa thal[10][10];

    srand(time(NULL));


    vector<Ploio*> ptr; //dimiourgoume vector ploion gia na valoume mesa ta ploia pou dimiourgountai

    //Dimiourgoume merika ploia apo oles tis klaseis
    peiratiko* nikos=new peiratiko();
    ptr.push_back(nikos);

    peiratiko* kostas=new peiratiko();
    ptr.push_back(kostas);

    xrisothiras* jerry=new xrisothiras();
    ptr.push_back(jerry);

    xrisothiras* gkofas=new xrisothiras();
    ptr.push_back(gkofas);

    emporiko* levy=new emporiko();
    ptr.push_back(levy);

    emporiko* abba=new emporiko();
    ptr.push_back(abba);

    ekserevnisis* colombus=new ekserevnisis();
    ptr.push_back(colombus);

    episkevastiko* bob=new episkevastiko();
    ptr.push_back(bob);

    episkevastiko* mastoras=new episkevastiko();
    ptr.push_back(mastoras);

    kleftis* takis=new kleftis();
    ptr.push_back(takis);

    kleftis* makis=new kleftis();
    ptr.push_back(makis);


    arxikopoihsh(ptr,&thal); //kaloume tin arxikopoiisi gia na valoume ta ploia stin sosti thesi ston xarti




    //ekkinisi rohs ekteleshs tou programmatos
    int winner=0;
    int GYROI=0;


    while (ptr.empty()==0 && winner==0 )   // KSEKINAME TI ROH EKTELESHS TOU PROGRAMMATOS
    {

        if( GetAsyncKeyState(VK_ESCAPE))  //an patisoume escape metavainoume sto menu
        {
            //eimaste mesa sto menu
            system("CLS");
            menucaller();
            while (true)
            {

                if(GetAsyncKeyState(VK_ESCAPE)) break;  //an ksanapatisoume escape synexizei to programma
                if (GetAsyncKeyState(0x41))
                {       //plirofories gia sygkekrimeno ploio

                    system("CLS");
                    cout<<"Epilekste ena ploio."<<endl;
                    for (unsigned int i=0; i<ptr.size(); i++)
                    {
                        cout<<i<<")"<<!(*ptr[i])<<ptr[i]->get_id()<<endl;

                    }
                    int epilogh;




                    ClearConsoleInputBuffer();
                    cin>>epilogh;
                    system("CLS");
                    cout<<*ptr[epilogh];

                    menucaller();

                }
                if (GetAsyncKeyState(0x42))
                {       //plirofories gia sygkekrimeni thesi sto xarti

                    system("CLS");
                    int xx=55;
                    int yy=55;
                    ClearConsoleInputBuffer();
                    while(xx>9 || xx<0 || yy>9 || yy<0)
                    {
                        system("CLS");
                        cout<<"Dwste x:";
                        cin>>xx;
                        cout<<"Dwste y:";
                        cin>>yy;
                        if(xx<=9 && xx>=0 && yy<=9 && yy>=0)
                        {
                            cout<<"H thesh tou xarth "<<xx<<","<<yy<<" perilamvanei : "<<thal[xx][yy].get_exei_thisavro()<<" thisavro, ";
                            cout<<thal[xx][yy].get_einai_limani()<<" limani kai "<<thal[xx][yy].get_entash_kairou()<<" entash kairou."<<endl;
                        }

                    }



                    int typos=thal[xx][yy].get_id_ploiou();

                    if (typos>0)
                    {
                        cout<<"Epishs, exei ploio "<<endl;


                        if(typos==1) cout<<"peiratiko.\n\n";
                        else if(typos==2) cout<<"emporiko.\n\n";
                        else if(typos==3) cout<<"episkevastiko.\n\n";
                        else if(typos==4) cout<<"ekserevnhshs.\n\n";
                        else if(typos==5) cout<<"kleftis.\n\n";
                        else if(typos==6) cout<<"xrysothira.\n\n";



                    }
                    else cout<<"Den vrisketai ploio sth thesh afth.\n\n"<<endl;

                    menucaller();
                }
                if (GetAsyncKeyState(0x43))
                {       //provolh stoixeiwn gia kathe typo ploiou

                    system("CLS");

                    cout<<"1.peiratiko."<<endl;
                    cout<<"2.emporiko."<<endl;
                    cout<<"3.episkevastiko"<<endl;
                    cout<<"4.ekserevnhshs."<<endl;
                    cout<<"5.kleftis."<<endl;
                    cout<<"6.xrysothira."<<endl;


                    ClearConsoleInputBuffer();
                    cout<<"Poio eidos ploiwn thelete na deite?";
                    int epil;
                    cin>>epil;
                    int peiratika_alive=0;
                    xrisothiras* jerry=new xrisothiras();
                    ptr.push_back(jerry);
                    int emporika_alive=0;
                    int ekser_alive=0;
                    int episk_alive=0;
                    int klefti_alive=0;
                    int xrisothira_alive=0;
                    switch (epil)
                    {
                    case 1:
                        cout<<"Exoume dhmiourghsei "<<peiratiko::count_peiratiko<<" peiratika ploia."<<endl;
                        cout<<"Exoun dextei "<<peiratiko::dmg_taken_peiratikou<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==1) peiratika_alive++;
                        }
                        cout<<"Zoun "<<peiratika_alive<<" peiratika ploia."<<endl;
                        break;

                    case 2:
                        cout<<"Exoume dhmiourghsei "<<emporiko::count_emporiko<<" emporika ploia."<<endl;
                        cout<<"Exoun dextei "<<emporiko::dmg_taken_emporikou<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==2) emporika_alive++;
                        }
                        cout<<"Zoun "<<emporika_alive<<" emporika ploia."<<endl;
                        break;


                    case 3:
                        cout<<"Exoume dhmiourghsei "<<episkevastiko::count_episk<<" episkevastika ploia."<<endl;
                        cout<<"Exoun dextei "<<episkevastiko::dmg_taken_episk<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==3) episk_alive++;
                        }
                        cout<<"Zoun "<<episk_alive<<" episkevastika ploia."<<endl;
                        break;

                    case 4:
                        cout<<"Exoume dhmiourghsei "<<ekserevnisis::count_ekser<<" ploia ekserevnisis."<<endl;
                        cout<<"Exoun dextei "<<ekserevnisis::dmg_taken_ekser<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==4) ekser_alive++;
                        }
                        cout<<"Zoun "<<ekser_alive<<" ploia ekserevnisis."<<endl;
                        break;
                    case 5:
                        cout<<"Exoume dhmiourghsei "<<kleftis::count_klefti<<" ploia klefti."<<endl;
                        cout<<"Exoun dextei "<<kleftis::dmg_taken_klefti<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==5) klefti_alive++;
                        }
                        cout<<"Zoun "<<klefti_alive<<" ploia klefti."<<endl;
                        break;
                    case 6:
                        cout<<"Exoume dhmiourghsei "<<xrisothiras::count_xrisothira<<" ploia xrysothira."<<endl;
                        cout<<"Exoun dextei "<<xrisothiras::dmg_taken_xrisothira<<" synolikh zhmia."<<endl;
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            if (ptr[i]->get_typos_ploiou()==6) xrisothira_alive++;
                        }
                        cout<<"Zoun "<<xrisothira_alive<<" ploia xrysothira."<<endl;
                        break;

                    }
                    menucaller();
                }
                if (GetAsyncKeyState(0x44))
                {       //katataksh ploiou me vash to xryso pou exoun h th zhmia pou exoun prokalesei

                    system("CLS");
                    cout<<"Patiste 1 gia katataksh ploiwn vash xrysou h 2 gia katatataksh vash zhmias pou exoun prokalesei"<<endl;
                    ClearConsoleInputBuffer();
                    int epp;
                    cin>>epp;
                    switch (epp)
                    {

                    case 1:
                        sort(ptr.begin(),ptr.end(),sort_apothema);
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" exei apothema "<<ptr[i]->get_apothema()<<endl;
                        }

                        break;
                    case 2:
                        sort(ptr.begin(),ptr.end(),sort_antoxh);
                        for (unsigned int i=0; i<ptr.size(); i++)
                        {
                            cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" exei antoxh "<<ptr[i]->get_trexousa_antoxh()<<endl;
                        }


                        break;
                    }
                    menucaller();
                }
                if (GetAsyncKeyState(0x45))
                {       //dimiourgia i katastrofi enos ploiou

                    system("CLS");
                    cout<<"Patiste 1 gia dhmiourgia ploiou, h 2 gia katastrofh ploiou."<<endl;
                    ClearConsoleInputBuffer();
                    int epp;
                    cin>>epp;
                    switch (epp)
                    {

                    case 1://dhmiourgia ploiou
                    {


                        cout<<"Epilekste ti eidous Ploio thelete na dimiourghsete"<<endl;
                        cout<<"1.peiratiko."<<endl;
                        cout<<"2.emporiko."<<endl;
                        cout<<"3.episkevastiko"<<endl;
                        cout<<"4.ekserevnhshs."<<endl;
                        cout<<"5.kleftis."<<endl;
                        cout<<"6.xrysothira."<<endl;

                        int epp1;
                        cin>>epp1;
                        switch (epp1)
                        {
                        case 1:
                        {
                            peiratiko* peiratis=new peiratiko();
                            ptr.push_back(peiratis);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        case 2:
                        {
                            emporiko* emporas=new emporiko();
                            ptr.push_back(emporas);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        case 3:
                        {
                            episkevastiko* episkevastis=new episkevastiko();
                            ptr.push_back(episkevastis);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        case 4:
                        {
                            ekserevnisis* ekserevnitis=new ekserevnisis();
                            ptr.push_back(ekserevnitis);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        case 5:
                        {
                            kleftis* kleftroni=new kleftis();
                            ptr.push_back(kleftroni);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        case 6:
                        {
                            xrisothiras* scrooge=new xrisothiras();
                            ptr.push_back(scrooge);
                            arxikopoihsh(ptr,&thal);
                            break;
                        }
                        }
                        break;
                        case 2:
                        {

                            for (unsigned int i=0; i<ptr.size(); i++)
                            {
                                cout<<i<<")"<<!(*ptr[i])<<ptr[i]->get_id()<<endl;
                            }
                            cout<<"Epilekste poio ploio thelete na diagrapsete:";
                            int epil_ploio;
                            cin>> epil_ploio;
                            int x= ptr[epil_ploio]->get_thesi_x();
                            int y=  ptr[epil_ploio]->get_thesi_y();
                            thal[x][y].set_id_ploiou(0); //an yparxei, diagrafoume ston xarth thalassas oti h thesh tou exei ploio, kai metatrepoume ti thesh tou se thisavro
                            cout<<"To ploio "<<!(*ptr[epil_ploio])<<ptr[epil_ploio]->get_id()<<" katastrafike."<<endl;

                            delete ptr[epil_ploio];
                            ptr.erase(ptr.begin()+epil_ploio);

                            break;
                        }

                    }







                    }
                    menucaller();
                }

                if (GetAsyncKeyState(0x46))
                {       //tropopoiisi mia thesis tou xarti

                    system("CLS");
                    int xx=55;
                    int yy=55;
                    int limani;
                    int thisavros;
                    ClearConsoleInputBuffer();
                    while(xx>9 || xx<0 || yy>9 || yy<0)
                    {
                        system("CLS");
                        cout<<"Epilekste poia thesi ston xarti thelete na tropopoihsete."<<endl;
                        cout<<"Dwste x:";
                        cin>>xx;
                        cout<<"Dwste y:";
                        cin>>yy;
                    }


                    cout<<"Patiste 1 gia na prosthesete limani stin epilegmeni thesi h 0 gia na afairesete"<<endl;
                    cin>>limani;
                    if(limani==1)
                        thal[xx][yy].set_einai_limani(1);
                    else if(limani==0)
                        thal[xx][yy].set_einai_limani(0);
                    cout<<"Patiste 1 gia na prosthesete thisavro stin epilegmeni thesi h 0 gia na afairesete"<<endl;
                    cin>>thisavros;
                    if(thisavros==1)
                        thal[xx][yy].set_exei_thisavro(1);
                    else if(thisavros==0)
                        thal[xx][yy].set_exei_thisavro(0);

                    menucaller();

                }



            }




        }

        if( GetAsyncKeyState(VK_SPACE))
        {       //pantontas space exoume valei to programma na pagonei mexri na ksanapati8ei space
            while(1)
            {
                if( GetAsyncKeyState(VK_SPACE))break;
            }
        }
        system("CLS");
        cout<<"Patiste ESC gia na emfanistei to Menu, h SPACE gia pafsh \n\n\n";


        GYROI++;





        for (unsigned int i=0; i<(ptr.size()); i++) // elegxoume tis theseis twn ploiwn pou exoume dhmiourgisei
        {
            int x_ploiou=ptr[i]->get_thesi_x();
            int y_ploiou=ptr[i]->get_thesi_y();
            int kairos=thal[x_ploiou][y_ploiou].get_entash_kairou(); //vriskoume tin entash tou kairou sti theseis twn ploiwn


            if (kairos>KAKOS_KAIROS)
            {

                ptr[i]->set_trexousa_antoxh(ptr[i]->get_trexousa_antoxh()-DMG_KAIROU); //apothikevoume tin nea trexousa antoxh meta th zhmia pou dextike to ploio
                ptr[i]->set_synoliko_dmg(ptr[i]->get_synoliko_dmg()+DMG_KAIROU); // metrame th zhmeia olwn ploiwm
                cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" dextike "<<DMG_KAIROU<<" zhmia apo thn kakokairia, sth thesh "<<x_ploiou<<","<<y_ploiou<<endl;


                int ch=ptr[i]->get_typos_ploiou();
                switch(ch)
                {
                case 1:
                    peiratiko::dmg_taken_peiratikou=peiratiko::dmg_taken_peiratikou+DMG_KAIROU;
                    break;
                case 2:
                    emporiko::dmg_taken_emporikou=emporiko::dmg_taken_emporikou+DMG_KAIROU;
                    break;
                case 3:
                    episkevastiko::dmg_taken_episk=episkevastiko::dmg_taken_episk+DMG_KAIROU;
                    break;
                case 4:
                    ekserevnisis::dmg_taken_ekser=ekserevnisis::dmg_taken_ekser+DMG_KAIROU;
                    break;
                case 5:
                    kleftis::dmg_taken_klefti=kleftis::dmg_taken_klefti+DMG_KAIROU;
                    break;
                case 6:
                    xrisothiras::dmg_taken_xrisothira=xrisothiras::dmg_taken_xrisothira+DMG_KAIROU;
                    break;
                }



            }
            int thisavros=thal[x_ploiou][y_ploiou].get_exei_thisavro(); //vriskoume ton thisavro sth thalassa

            if (thisavros) //an vroume thisavro
            {
                ptr[i]->set_apothema(ptr[i]->get_apothema()+THISAVROS_THAL); //prosthetoume mia statheri posotita sto apothema kathe ploiou
                cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" vrike thisavro "<<THISAVROS_THAL<<" sth thesh "<<x_ploiou<<","<<y_ploiou<<endl;


                Ploio::synoliko_gold=Ploio::synoliko_gold+THISAVROS_THAL; // synolikos 8ysauros pou exei anakth8ei
            }
            //elegxoume an gyrw apo kathetai se limani
            if (thal[x_ploiou][y_ploiou].get_einai_limani()==1)
            {
                if (ptr[i]->get_typos_ploiou()!=1)
                {
                    int old_trexousa=ptr[i]->get_trexousa_antoxh();
                    int megisth=ptr[i]->get_megisth_antoxh();
                    int heal =megisth*POSOSTO_EPISK;
                    ptr[i]->set_trexousa_antoxh(heal+ptr[i]->get_trexousa_antoxh());
                    cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" episkevastike kata "<<ptr[i]->get_trexousa_antoxh()-old_trexousa<<" apo to limani pou vrisketai sto "<<x_ploiou<<","<<y_ploiou<<endl;

                }
                else
                {
                    ptr[i]->set_trexousa_antoxh(ptr[i]->get_trexousa_antoxh()-DMG_LIMANIOU);
                    ptr[i]->set_synoliko_dmg(ptr[i]->get_synoliko_dmg()+DMG_LIMANIOU); // auksanoume th synolikh zhmeia tou peiratikou apo th zhmeia pou tou kanei to limani
                    peiratiko::dmg_taken_peiratikou=peiratiko::dmg_taken_peiratikou+DMG_LIMANIOU;
                    cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" dexthke "<<DMG_LIMANIOU<<" zhmia apo to limani tis thesis "<<x_ploiou<<","<<y_ploiou<<endl;


                }
            }
        }
        for (unsigned int k=0; k<ptr.size(); k++)
        {
            ptr[k]->metakinisi(&thal);
        }
        for (unsigned int k=0; k<ptr.size(); k++)
        {
            ptr[k]->leitourgia(ptr[k],ptr, &thal);
        }
        cout<<endl;
        int idpl;

        for (int ik=0; ik<10; ik++)                 //edo tipono ton xarti
        {
            for (int jk=0; jk<10; jk++)
            {
                int xi=thal[ik][jk].get_id_ploiou();
                for(unsigned int i=0; i<ptr.size(); i++)
                {
                    int xpl=ptr[i]->get_thesi_x();
                    int ypl=ptr[i]->get_thesi_y();
                    if((xpl==ik)&&(ypl==jk))
                    {
                        idpl = ptr[i]->get_id();
                    }

                }

                if(xi==1) cout<<"Pr"<<idpl<<'\t';
                else if(xi==2) cout<<"Em"<<idpl<<'\t';
                else if(xi==3) cout<<"Ep"<<idpl<<'\t';
                else if(xi==4) cout<<"Ek"<<idpl<<'\t';
                else if(xi==5) cout<<"Kl"<<idpl<<'\t';
                else if(xi==6) cout<<"Xr"<<idpl<<'\t';
                else cout<<"[ ]"<<'\t';

            }
            cout<<endl;
        }


        //telos rohs prgrammatos

        for (unsigned int i=0; i<ptr.size(); i++)
        {
            if (ptr[i]->get_trexousa_antoxh()<0)
            {
                //elegxoume an yparxei ploio xwris antoxh ston xarth
                int  x= ptr[i]->get_thesi_x();
                int y=  ptr[i]->get_thesi_y();           //an yparxei, diagrafoume ston xarth thalassas oti h thesh tou exei ploio, kai metatrepoume ti thesh tou se thisavro
                thal[x][y].set_id_ploiou(0);
                thal[x][y].set_exei_thisavro(1);
                cout<<"To ploio "<<!(*ptr[i])<<ptr[i]->get_id()<<" katastrafike."<<endl;
                delete ptr[i];
                ptr.erase(ptr.begin()+i);
                i--;                            //afou diagrapsoume to ploio ths theshs i, prepei na ksanatrexoume

            }
        }








        for ( int i=0; i<10; i++)   //tyxaia afksomeiwsh tou kairou kata 1
        {
            for (int j=0; j<10; j++)
            {

                if (rand()%2==0)
                {
                    if (thal[i][j].get_entash_kairou()<10)
                        thal[i][j].set_entash_kairou(thal[i][j].get_entash_kairou()+1);
                }
                else
                {
                    if (thal[i][j].get_entash_kairou()>1)
                        thal[i][j].set_entash_kairou(thal[i][j].get_entash_kairou()-1);
                }
            }
        }


        for (unsigned int i=0; i<ptr.size(); i++) //anazhtoume an yparxei telikos nikitis
        {
            if (ptr[i]->get_apothema()>=STOXOS) winner++;
        }
        GYROI++;
   Sleep(2000);



    }
//elegxos an nikise kapoio ploio kai poio
    system("CLS");
    if (ptr.empty())
        cout<<"Katastrafikan ola ta ploia. RIP";
    else
    {

        for (unsigned int i=0; i<ptr.size(); i++)
        {
            if (ptr[i]->get_apothema()>=STOXOS) cout<<"Nikise to Ploio me stoixeia \n"<<*ptr[i]<<"meta apo "<<GYROI<<" gyrous."<<endl;

        }

    }
    cout<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"Statistika stoixeia: \n"<<endl;
    cout<<"Synolikos arithmos peiratikwn ploiwn pou dhmiourghthikan: "<<peiratiko::count_peiratiko-kleftis::count_klefti<<endl;
    cout<<"Synolikos arithmos emporikwn ploiwn pou dhmiourghthikan: "<<emporiko::count_emporiko<<endl;
    cout<<"Synolikos arithmos episkevastikwn ploiwn pou dhmiourghthikan: "<<episkevastiko::count_episk<<endl;
    cout<<"Synolikos arithmos ploiwn ekserevnhshs pou dhmiourghthikan: "<<ekserevnisis::count_ekser-xrisothiras::count_xrisothira<<endl;
    cout<<"Synolikos arithmos ploiwn kleftwn pou dhmiourghthikan: "<<kleftis::count_klefti<<endl;
    cout<<"Synolikos arithmos ploiwn xrysothirwn pou dhmiourghthikan: "<<xrisothiras::count_xrisothira<<endl;







}
