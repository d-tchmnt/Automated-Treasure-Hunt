
#ifndef KLEFTIS_H
#define KLEFTIS_H
#include <cstdlib>
using namespace std;
#include <vector>
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"



class kleftis : public peiratiko
{
public:
    kleftis();
    void leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    static int count_klefti;
    static int dmg_taken_klefti;
    int get_id();
    int get_xrisafi();
private:
    int id_klefti;
    int xrisafi_klemeno;

};

#endif // PEIRATIKO_H
