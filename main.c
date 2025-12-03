#include <locale.h>
#include <stdio.h>
#include "house.h"
#include "housecont.h"


int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    
    House_t house = NewHouse("","",panel,1925,false, false,1,1,10.0);
    
    HouseCont_t cont = InitCont();

    printf("%d", GetHouseCount(cont));

    return 0;
}