#include "..\headers\housecont.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\headers\Tools.h"

HouseCont_t InitCont() {
    HouseCont_t *res;
    res = (HouseCont_t*)malloc(sizeof(HouseCont_t));
    (*res).HouseCount = 0;
    (*res).FirstContElem = NULL;
    (*res).LastContElem = NULL;

    return (*res);

}

unsigned int GetHouseCount(HouseCont_t housecont) {
    return housecont.HouseCount;
}

HouseContElem_t *GetFirstHouseElem(HouseCont_t housecont) {
    return housecont.FirstContElem;
};

HouseContElem_t *GetLastHouseElem(HouseCont_t housecont) {
    return housecont.LastContElem;
};

HouseContElem_t *GetNextHouseElem(HouseContElem_t housecontelem) {
    return housecontelem.nextHouse;
};

HouseContElem_t *GetPrevHouseElem(HouseContElem_t housecontelem) {
    return housecontelem.prevHouse;
};

unsigned int GetElemIndex(HouseCont_t *housecont, HouseContElem_t *housecontelem) {
    HouseContElem_t *list = housecontelem;
    unsigned int index = 0;
    while ((*list).prevHouse != NULL) {
        list = (*list).prevHouse;
        index+=1;
    }
    return index;

}

void AddHouseContElem(HouseCont_t *housecont, unsigned int index, House_t *house) {
    HouseContElem_t *housecontelem;
    housecontelem = (HouseContElem_t*)malloc(sizeof(HouseContElem_t));
    (*housecontelem).house = house;
    (*housecontelem).prevHouse = NULL;
    (*housecontelem).nextHouse = NULL;


    if (index > (*housecont).HouseCount) {
        perror("Невозможно добавить в контейнер, индекс превышает размер контейнера");
        exit(EXIT_FAILURE);
    }


    if ((*housecont).HouseCount == 0) {
        (*housecont).FirstContElem = housecontelem;
        (*housecont).LastContElem = housecontelem;
        (*housecont).HouseCount+=1;
        return;
    }

    if (index == (*housecont).HouseCount) {
        (*housecontelem).prevHouse = (*housecont).LastContElem;
        (*((*housecontelem).prevHouse)).nextHouse = housecontelem;
        (*housecont).LastContElem = housecontelem;
        (*housecont).HouseCount+=1;
        return;
    }

    HouseContElem_t *list = (*housecont).FirstContElem;
    for (int i = 0; i < index; i++) {
        list = (*list).nextHouse;
    }

    if ((*list).prevHouse != NULL) {
        (*(*list).prevHouse).nextHouse = housecontelem;
    }
    (*housecontelem).prevHouse = (*list).prevHouse;
    (*housecontelem).nextHouse = list;
    (*list).prevHouse = housecontelem;
    (*housecont).HouseCount+=1;
}

void DelHouseContElem(HouseCont_t *housecontP, unsigned int index) {

    if (index >= (*housecontP).HouseCount) {
        perror("Невозможно удалить из контейнера, индекс превышает размер контейнера");
        exit(EXIT_FAILURE);
    }

    HouseContElem_t *list = (*housecontP).FirstContElem;

    if (index == 0) {
        if ((*housecontP).HouseCount>0) {
            (*housecontP).FirstContElem = (*((*housecontP).FirstContElem)).nextHouse;
        } else {
            (*housecontP).FirstContElem = NULL;
        }
    }

    (*housecontP).HouseCount -= 1;
    
    for (int i = 0; i < index; i++) {
        list = (*list).nextHouse;
    }

    if ((*list).prevHouse != NULL) {
        (*((*list).prevHouse)).nextHouse = (*list).nextHouse;
    }

    if ((*list).nextHouse != NULL) {
        (*((*list).nextHouse)).prevHouse = (*list).prevHouse;
    }    

    FreeContElem(list);


}

void SwapContElemR(HouseCont_t *housecontP, unsigned int findex, unsigned int sindex) {
    if ((findex > (*housecontP).HouseCount - 1) || (sindex > (*housecontP).HouseCount - 1)){
        errno = -1;
        perror("Невозможно переместить, индекс превышает размер контейнера");
        exit(EXIT_FAILURE);
    }

    if (findex == sindex) {
        perror("Невозможно переместить, индексы совпадают");
        exit(EXIT_FAILURE);
    }

    if (findex > sindex) {
        int t = findex;
        findex = sindex;
        sindex = t;
    }
 
    HouseContElem_t *first = (*housecontP).FirstContElem, *second = (*housecontP).FirstContElem;

    for (int i = 0; i < findex; i++) {
        first = (*first).nextHouse;
    }

    for (int i = 0; i < sindex; i++) {
        second = (*second).nextHouse;
    }

    HouseContElem_t **a1 = NULL, *a2, *a3, **a4 = NULL, **a5 = NULL, *a6, *a7, **a8 = NULL;
    
    if (first->prevHouse != NULL) {
        a1 = &(first->prevHouse->nextHouse);
    }
    a2 = first->prevHouse;
    a3 = first->nextHouse;
    if (first->nextHouse != NULL) {
        a4 = &(first->nextHouse->prevHouse);
    }
    if (second->prevHouse != NULL) {
        a5 = &(second->prevHouse->nextHouse);
    }
    a6 = second->prevHouse;
    a7 = second->nextHouse;
    if (second->nextHouse != NULL) {
        a8 = &(second->nextHouse->prevHouse);
    }

    if (a1 != NULL) {
        (*a1) = second;
    }
    if ((a4 != NULL) && (sindex-findex>1)) {
        (*a4) = second;
    }
    if ((a5 != NULL) && (sindex-findex>1)) {
        (*a5) = first;
    }
    if (a8 != NULL) {
        (*a8) = first;
    }
    if (sindex-findex>1) {
        first->prevHouse = a6;
        second->nextHouse = a3;
    } else {
        first->prevHouse = second;
        second->nextHouse = first;
    }
    first->nextHouse = a7;
    second->prevHouse = a2;

    if (findex == 0) {
        housecontP->FirstContElem = second;
    }
    if (findex == housecontP->HouseCount-1) {
        housecontP->LastContElem = second;
    }
    if (sindex == 0) {
        housecontP->FirstContElem = first;
    }
    if (sindex == housecontP->HouseCount-1) {
        housecontP->LastContElem = first;
    }    
}

void SwapContElem(HouseCont_t *housecontP, unsigned int findex, unsigned int sindex) {

    if ((findex > (*housecontP).HouseCount - 1) || (sindex > (*housecontP).HouseCount - 1)){
        errno = -1;
        perror("Невозможно переместить, индекс превышает размер контейнера");
        exit(EXIT_FAILURE);
    }

    if (findex == sindex) {
        perror("Невозможно переместить, индексы совпадают");
        exit(EXIT_FAILURE);
    }

    HouseContElem_t *first = (*housecontP).FirstContElem, *second = (*housecontP).FirstContElem;

    for (int i = 0; i < findex; i++) {
        first = (*first).nextHouse;
    }

    for (int i = 0; i < sindex; i++) {
        second = (*second).nextHouse;
    }


    House_t *fhouse = (House_t*)malloc(sizeof(House_t)), *shouse = (House_t*)malloc(sizeof(House_t));
    *fhouse = (*(*first).house);
    *shouse = (*(*second).house);

    AddHouseContElem(housecontP, sindex+1, fhouse);
    DelHouseContElem(housecontP,sindex);
    AddHouseContElem(housecontP, findex+1, shouse);
    DelHouseContElem(housecontP,findex);
}

House_t *MakeList(HouseCont_t housecont) {
    House_t *list = malloc(housecont.HouseCount*(sizeof(House_t)));
    HouseContElem_t *housecontelem = housecont.FirstContElem;
    int i=0;
    while (housecontelem != NULL) {
        list[i++] = NewHouse((*(*housecontelem).house).BuilderName, (*(*housecontelem).house).RegionName, (*(*housecontelem).house).HouseType, (*(*housecontelem).house).HouseBuildYear, (*(*housecontelem).house).HasElevator, (*(*housecontelem).house).HasTrash, (*(*housecontelem).house).FlatCount, (*(*housecontelem).house).FloorCount, (*(*housecontelem).house).AvgSquare);
        housecontelem = (*housecontelem).nextHouse;
    }   

    return list;
}

HouseCont_t MakeCont(House_t *list) {
    HouseCont_t Cont = InitCont();
    unsigned int i = 0;
    unsigned int len = sizeof(*list)/sizeof(House_t); 
    while (i < len){
        House_t conthouse = NewHouse((list[i]).BuilderName, (list[i]).RegionName, (list[i]).HouseType, (list[i]).HouseBuildYear, (list[i]).HasElevator, (list[i]).HasTrash, (list[i]).FlatCount, (list[i]).FloorCount, (list[i]).AvgSquare);
        AddHouseContElem(&Cont, i, &conthouse);
        i += 1;
    }
    Cont.HouseCount = len;
    return Cont;
}

void FreeContElem(HouseContElem_t *housecontelem) {
    FreeHouse(*((*housecontelem).house));
    free((*housecontelem).house);
    free(housecontelem);
}

void ClearCont(HouseCont_t housecont) {
    HouseContElem_t *housecontelem = housecont.FirstContElem;
    while (housecontelem != NULL) {
        FreeContElem(housecontelem);
        housecontelem = (*housecontelem).nextHouse;
    }
    housecont.FirstContElem = NULL;
    housecont.LastContElem = NULL;
    housecont.HouseCount = 0;

}