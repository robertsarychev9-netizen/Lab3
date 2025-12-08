#include "housecont.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

void AddHouseContElem(HouseCont_t *housecont, unsigned int index, House_t *house) {
    HouseContElem_t *housecontelem;
    housecontelem = (HouseContElem_t*)malloc(sizeof(HouseContElem_t));
    (*housecontelem).house = house;
    (*housecontelem).prevHouse = NULL;
    (*housecontelem).nextHouse = NULL;

    if (index > (*housecont).HouseCount) {
        perror("Невозможно добавить в контейнер, индекс превышает размер контейнера");
    }


    if ((*housecont).HouseCount == 0) {
        (*housecont).FirstContElem = housecontelem;
        (*housecont).LastContElem = housecontelem;
        (*housecont).HouseCount+=1;
        return;
    }

    if (index = (*housecont).HouseCount) {
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
        (*list).nextHouse = housecontelem;
    }
    (*housecontelem).prevHouse = (*list).prevHouse;
    (*housecontelem).nextHouse = list;
    (*housecont).HouseCount+=1;
}

void DelHouseContElem(HouseCont_t *housecontP, unsigned int index) {
    HouseCont_t housecont = *housecontP;

    if (index >= housecont.HouseCount) {
        perror("Невозможно удалить из контейнера, индекс превышает размер контейнера");
    }

    if (index == 0) {
        if (housecont.HouseCount>0) {
            housecont.FirstContElem = (*(housecont.FirstContElem)).nextHouse;
        } else {
            housecont.FirstContElem = NULL;
        }
    }

    housecont.HouseCount -= 1;
    HouseContElem_t *list = housecont.FirstContElem;
    
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

void SwapContElem(HouseCont_t *housecontP, unsigned int findex, unsigned int sindex) {
    HouseCont_t housecont = *housecontP;

    if ((findex > housecont.HouseCount + 1) || (sindex > housecont.HouseCount + 1)){
        perror("Невозможно переместить, индекс превышает размер контейнера");
    }

    if (findex == sindex) {
        perror("Невозможно переместить, индексы совпадают");
    }

    HouseContElem_t *first = housecont.FirstContElem, *second = housecont.FirstContElem;

    for (int i = 0; i < findex; i++) {
        first = (*first).nextHouse;
    }

    for (int i = 0; i < sindex; i++) {
        second = (*second).nextHouse;
    }

    HouseContElem_t *fp = (*first).prevHouse, *fn = (*first).nextHouse, *sp = (*second).prevHouse, *sn = (*second).nextHouse;

    if (fp != NULL) {
        (*fp).nextHouse = second;
    }
    (*second).prevHouse = fp;

    if (fn !=NULL) {
        (*fn).prevHouse = second;
    }    
    (*second).nextHouse = fn;

    if (sp != NULL) {
        (*sp).nextHouse = first;
    }
    (*first).prevHouse = sp;

    if (sn != NULL) {
        (*sn).prevHouse = first;
    }
    (*first).nextHouse = sn;
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