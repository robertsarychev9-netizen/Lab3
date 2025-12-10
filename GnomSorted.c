#include "GnomSorted.h"
#include <string.h>
#include "Tools.h"

int CompareCont(HouseContElem_t *fhousecontelem, HouseContElem_t *shousecontelem, unsigned int index) {
        if (index == 8){
        if ((*shousecontelem).house->FlatCount >= (*fhousecontelem).house->FlatCount) {
            return 1;
        } else {
            return -1;
        }
    }
}

HouseCont_t *GnomSortedCont(HouseCont_t *housecont){
    
    HouseContElem_t *GlobCont = (*housecont).FirstContElem;
    HouseContElem_t *PrevCont;
    HouseContElem_t *Cont = GlobCont->nextHouse;
    for (int i = 1; i < (*housecont).HouseCount; i++){
        /*
        PrevCont = (*Cont).prevHouse;
        for (int j = i; j>0; j--){
            printf("%d %d %d\n", CompareCont(PrevCont, Cont, 8), (*Cont).house->FlatCount, (*PrevCont).house->FlatCount);
            if (CompareCont(PrevCont, Cont, 8) < 0){
                SwapContElem(housecont, j, j-1);
            }
            Cont = (*Cont).prevHouse;
            PrevCont = (*PrevCont).prevHouse;
        }
        printf("\n");
        GlobCont = (*GlobCont).nextHouse;
        Cont = (*GlobCont).nextHouse;
        */
        SwapContElem(housecont, i-1, i);
    }
    printcont(housecont);
}