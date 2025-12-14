#pragma once
#include "house.h"
#include "housecont.h"

void GnomSortedCont(HouseCont_t *housecontP, int reverse);
int CompareCont(HouseContElem_t *fhousecontelem, HouseContElem_t *shousecontelem, unsigned int index, int type);
void QuickSortCont(HouseCont_t *housecont, unsigned int findex, unsigned int sindex, int reverse);
int partiation(HouseCont_t *housecont,unsigned int findex, unsigned int sindex, int reverse);