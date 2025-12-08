#pragma once
#include "house.h"
#include "housecont.h"

HouseCont_t *GnomSortedCont(HouseCont_t *housecontP);
int CompareCont(HouseContElem_t *fhousecontelem, HouseContElem_t *shousecontelem, unsigned int index);