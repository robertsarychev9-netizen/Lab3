#include "GnomSorted.h"
#include <string.h>
#include "Tools.h"

int CompareCont(HouseContElem_t *fhousecontelem, HouseContElem_t *shousecontelem, unsigned int index, int type) {
    if ((fhousecontelem == NULL) || (shousecontelem == NULL)) {
        return 0;
    }
    if (type == 1){
        if (index == 9){
            if ((*shousecontelem).house->AvgSquare == (*fhousecontelem).house->AvgSquare) {
                return 0;
            }   
            if ((*shousecontelem).house->AvgSquare > (*fhousecontelem).house->AvgSquare) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 8) {
            if ((*shousecontelem).house->FlatCount == (*fhousecontelem).house->FlatCount) {
                return 0;
            }
            if ((*shousecontelem).house->FlatCount > (*fhousecontelem).house->FlatCount) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 7){
            if ((*shousecontelem).house->FloorCount == (*fhousecontelem).house->FloorCount) {
                return 0;
            }   
            if ((*shousecontelem).house->FloorCount > (*fhousecontelem).house->FloorCount) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 6){
            if ((int)((*shousecontelem).house->HasTrash) == (int)((*fhousecontelem).house->HasTrash)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HasTrash) > (int)((*fhousecontelem).house->HasTrash)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 5){
            if ((int)((*shousecontelem).house->HasElevator) == (int)((*fhousecontelem).house->HasElevator)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HasElevator) > (int)((*fhousecontelem).house->HasElevator)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 4){
            if ((*shousecontelem).house->HouseBuildYear == (*fhousecontelem).house->HouseBuildYear) {
                return 0;
            }   
            if ((*shousecontelem).house->HouseBuildYear > (*fhousecontelem).house->HouseBuildYear) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 3){
            if ((int)((*shousecontelem).house->HouseType) == (int)((*fhousecontelem).house->HouseType)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HouseType) > (int)((*fhousecontelem).house->HouseType)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 2){
            if (strcmp((*shousecontelem).house->RegionName, (*fhousecontelem).house->RegionName) == 0) {
                return 0;
            }   
            if (strcmp((*shousecontelem).house->RegionName, (*fhousecontelem).house->RegionName) < 0) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 1){
            if (strcmp((*shousecontelem).house->BuilderName, (*fhousecontelem).house->BuilderName) == 0) {
                return 0;
            }   
            if (strcmp((*shousecontelem).house->BuilderName, (*fhousecontelem).house->BuilderName) < 0) {
                return 1;
            } else {
                return -1;
            }
        }
    } else {
        if (index == 9){
            if ((*shousecontelem).house->AvgSquare == (*fhousecontelem).house->AvgSquare) {
                return 0;
            }   
            if ((*shousecontelem).house->AvgSquare < (*fhousecontelem).house->AvgSquare) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 8) {
            if ((*shousecontelem).house->FlatCount == (*fhousecontelem).house->FlatCount) {
                return 0;
            }
            if ((*shousecontelem).house->FlatCount < (*fhousecontelem).house->FlatCount) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 7){
            if ((*shousecontelem).house->FloorCount == (*fhousecontelem).house->FloorCount) {
                return 0;
            }   
            if ((*shousecontelem).house->FloorCount < (*fhousecontelem).house->FloorCount) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 6){
            if ((int)((*shousecontelem).house->HasTrash) == (int)((*fhousecontelem).house->HasTrash)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HasTrash) < (int)((*fhousecontelem).house->HasTrash)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 5){
            if ((int)((*shousecontelem).house->HasElevator) == (int)((*fhousecontelem).house->HasElevator)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HasElevator) < (int)((*fhousecontelem).house->HasElevator)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 4){
            if ((*shousecontelem).house->HouseBuildYear == (*fhousecontelem).house->HouseBuildYear) {
                return 0;
            }   
            if ((*shousecontelem).house->HouseBuildYear < (*fhousecontelem).house->HouseBuildYear) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 3){
            if ((int)((*shousecontelem).house->HouseType) == (int)((*fhousecontelem).house->HouseType)) {
                return 0;
            }   
            if ((int)((*shousecontelem).house->HouseType) < (int)((*fhousecontelem).house->HouseType)) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 2){
            if (strcmp((*shousecontelem).house->RegionName, (*fhousecontelem).house->RegionName) == 0) {
                return 0;
            }   
            if (strcmp((*shousecontelem).house->RegionName, (*fhousecontelem).house->RegionName) > 0) {
                return 1;
            } else {
                return -1;
            }
        }
        if (index == 1){
            if (strcmp((*shousecontelem).house->BuilderName, (*fhousecontelem).house->BuilderName) == 0) {
                return 0;
            }   
            if (strcmp((*shousecontelem).house->BuilderName, (*fhousecontelem).house->BuilderName) > 0) {
                return 1;
            } else {
                return -1;
            }
        }
    }
}

void GnomSortedCont(HouseCont_t *housecont, int reverse){
    unsigned int HouseCount = GetHouseCount(*housecont);
    if (HouseCount<=1) {
        return;
    }

    HouseContElem_t *list, *listnext;
    list = GetFirstHouseElem(*housecont);
    list = GetNextHouseElem(*list);

    while (list != NULL) {
        listnext = GetNextHouseElem(*list);
        while (CompareCont(list,GetPrevHouseElem(*list),8,reverse)>0) {
            SwapContElemR(housecont,GetElemIndex(housecont,GetPrevHouseElem(*list)),GetElemIndex(housecont,list));
            if (GetPrevHouseElem(*list) == NULL) {
                break;
            }
        }
        list = listnext;
   }
}

int partiation(HouseCont_t *housecont, unsigned int findex, unsigned int sindex, int reverse) {
    HouseContElem_t *Elem = GetFirstHouseElem(*housecont); 
    for (int k = 0; k <(findex + sindex)/2; k++){
        Elem = GetNextHouseElem(*Elem);
    }
    int i = findex;
    int j = sindex;
    while (i <= j){
        HouseContElem_t *FElem = GetFirstHouseElem(*housecont);
        for (int k = 0; k < i; k++){
            FElem = GetNextHouseElem(*FElem);
        }
        HouseContElem_t *SElem = GetFirstHouseElem(*housecont);
        for (int k = 0; k < j; k++){
            SElem = GetNextHouseElem(*SElem);
        }

        while (CompareCont(Elem, FElem, 8, reverse) < 0){
            i += 1;
            FElem = GetNextHouseElem(*FElem);
        }
        while (CompareCont(Elem, SElem, 8, reverse) > 0){
            j = j - 1;
            SElem = GetPrevHouseElem(*SElem);
        }
        if (i >= j){
            break;
        }
        SwapContElemR(housecont, i++, j--);
    }
    return j;
}
void QuickSortCont(HouseCont_t *housecont, unsigned int findex, unsigned int sindex, int reverse){
    if (sindex > findex) {
        int q = partiation(housecont, findex, sindex, reverse);
        QuickSortCont(housecont, findex, q, reverse);
        QuickSortCont(housecont, q+1, sindex, reverse);
    }

}