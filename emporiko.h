#ifndef EMPORIKO_H
#define EMPORIKO_H

#include <cstdlib>
using namespace std;
#include <vector>
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"


class emporiko : public Ploio
{
public:
    emporiko();
    void leitourgia(Ploio *P,vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    void set_gold_limania(int a);
    int get_gold_limania();
    int get_id();
    static int count_emporiko;
    static int dmg_taken_emporikou;

private:
    int gold_limania;
    int id_emporikou;

};

#endif // EMPORIKO_H
