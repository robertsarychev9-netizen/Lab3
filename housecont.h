#pragma once
#include "house.h"

typedef struct HouseContElem {
    House_t *house;
    struct HouseContElem *prevHouse, *nextHouse;
} HouseContElem_t;

typedef struct {
    HouseContElem_t *FirstContElem, *LastContElem;
    unsigned int HouseCount; 
} HouseCont_t;

HouseCont_t InitCont();
unsigned int GetHouseCount(HouseCont_t housecont);
HouseContElem_t *GetFirstHouseElem(HouseCont_t housecont);
HouseContElem_t *GetLastHouseElem(HouseCont_t housecont);
HouseContElem_t *GetNextHouseElem(HouseContElem_t housecont);
HouseContElem_t *GetPrevHouseElem(HouseContElem_t housecont);
void AddHouseContElem(HouseCont_t housecont, unsigned int index, House_t *house);
void DelHouseContElem(HouseCont_t housecont, unsigned int index);
void SwapContElem(HouseCont_t housecont, unsigned int findex, unsigned int sindex);
void FreeContElem(HouseContElem_t *housecontelem);
House_t *MakeList(HouseCont_t housecont);
HouseCont_t MakeCont(House_t* list);
void ClearCont(HouseCont_t housecont);