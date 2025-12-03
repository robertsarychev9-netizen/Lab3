#include "GnomSorted.h"
#include <string.h>
 
int CompareCont(HouseContElem_t *fhousecontelem, HouseContElem_t *shousecontelem, unsigned int index) {
    if (index == 8){
        if ((*shousecontelem).house->FlatCount >= (*fhousecontelem).house->FlatCount) {
            return 1;
        } else {
            return -1;
        }
    }
}

HouseCont_t *GnomSortedCont(HouseCont_t housecont){
    HouseContElem_t *Cont = housecont.FirstContElem;
    for (int i = 1; i < housecont.HouseCount; i++){
        Cont = (*Cont).nextHouse;
        HouseContElem_t *PrevCont = Cont->prevHouse;
        for (int j = i-1; j >= 0; j--){
            if (CompareCont(PrevCont, Cont, 8) < 0){
                SwapContElem(housecont, j, j+1);
                PrevCont = (*Cont).prevHouse;
            } else {
                Cont = (*Cont).nextHouse;
                PrevCont = (*PrevCont).prevHouse;
            }
        }
    }
}