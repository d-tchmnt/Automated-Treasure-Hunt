#ifndef EKSEREVNISIS_H
#define EKSEREVNISIS_H
#include <vector>
#include <cstdlib>
using namespace std;

#include <iostream>
#include "Ploio.h"
#include "thalassa.h"




class ekserevnisis : public Ploio
{
public:
    ekserevnisis();
    void leitourgia(Ploio *P, vector <Ploio*>& ptr, thalassa (*thal_ptr)[10][10]);
    bool emove(int x, int y, thalassa (*thal_ptr)[10][10]);
    static int count_ekser;
    static int dmg_taken_ekser;
    int get_id();


private:
    int id_ekser;

};


#endif
