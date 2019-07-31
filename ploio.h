#ifndef THALASSA_H
#define THALASSA_H
#include <cstdlib>
using namespace std;
#include <vector>
#include <iostream>
#include "Ploio.h"



class thalassa
{

private:
    int entash_kairou ;
    bool exei_thisavro;
    bool einai_limani;
    int id_ploiou;




public:
    thalassa();
    //void arxikopoihsh(vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    void set_entash_kairou(int entash);
    void set_einai_limani(bool limani);
    void set_exei_thisavro(bool thisavros);
    int get_entash_kairou();
    bool get_exei_thisavro();
    bool get_einai_limani();
    int get_id_ploiou();
    void set_id_ploiou(int i);









};

#endif
