#ifndef EPISKEVASTIKO_H
#define EPISKEVASTIKO_H
#include <vector>
#include <cstdlib>
using namespace std;

#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "peiratiko.h"
#include "emporiko.h"
#include "ekserevnisis.h"


class episkevastiko : public Ploio
{
public:
    episkevastiko();
    void leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    int get_gold_episk();
    int get_id();
    void set_gold_episk(int a);
    static int count_episk;
    static int dmg_taken_episk;

private:
    int gold_episk;
    int id_episk;

};

#endif // EPISKEVASTIKO_H
