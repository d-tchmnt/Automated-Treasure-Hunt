
#ifndef XRISOTHIRAS_H
#define XRISOTHIRAS_H
#include <cstdlib>
using namespace std;
#include <vector>
#include <iostream>
#include "Ploio.h"
#include "thalassa.h"
#include "emporiko.h"
#include "episkevastiko.h"
#include "ekserevnisis.h"


class xrisothiras : public ekserevnisis
{
public:
    xrisothiras();
    void leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    bool emove(int x, int y, thalassa (*thal_ptr)[10][10]);
    static int count_xrisothira;
    static int dmg_taken_xrisothira;
    int get_id();
    int get_xrisafi();
private:
    int id_xrisothira;
    int xrisafi_digged;

};

#endif

