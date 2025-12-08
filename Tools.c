#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "house.h"
#include "housecont.h"

int strintcheck(char *str, int mode){
    int i = 0;
    while (str[i] != '\0'){
        if ((str[i]<'0') || (str[i]>'9')) {
            return 0;
        }
        i++;
    }
    int num=0;
    int pov=1;
    for (int j = i-1; j >= 0; j--){
        num += ((int)str[j] - 48) * pov;
        pov = pov * 10;
    }
    if (mode == 1){
        return num;
    }
    return 1;
}

int csvcheck(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i+=1;
    }
    if (i < 4){
        return 0;
    }
    if ((str[i-1] == 'v') || (str[i-2] == 's') || (str[i-3] == 'c') || (str[i-4] == '.')){
        return 1;
    }
    return 0;
}

char *randbuilder(int N){
    if (N == 0){
        return "BEcompany";
    }
    if (N == 1){
        return "NEcompany";
    }
    if (N == 2){
        return "PEcompany";
    }
    if (N == 3){
        return "NigBuilder";
    }
    if (N == 4){
        return "JewBuilder";
    }
    if (N == 5){
        return "BlackBuilder";
    }
    if (N == 6){
        return "WhiteBuilder";
    }
    if (N == 7){
        return "WalterWhiteBuilder";
    }
    if (N == 8){
        return "RageBiteBuild";
    }
    if (N == 9){
        return "NillKigBrothers";
    }
}

char *randregion(int N){
        if (N == 0){
        return "Russia";
    }
    if (N == 1){
        return "Ukraine";
    }
    if (N == 2){
        return "Belgium";
    }
    if (N == 3){
        return "USA";
    }
    if (N == 4){
        return "Canada";
    }
    if (N == 5){
        return "Brazil";
    }
    if (N == 6){
        return "France";
    }
    if (N == 7){
        return "German";
    }
    if (N == 8){
        return "Argintina";
    }
    if (N == 9){
        return "Africa";
    }
}
void generator(HouseCont_t *ContP, int N) {
    House_t *House;
    for (int i = 0; i<N; i++){
        char *buildername = randbuilder(rand() % 10);
        char *regionname = randregion(rand() % 10);
        HouseType_t housetype = (HouseType_t)((rand() % 3) + 1);
        unsigned int year = (rand() % 9000) + 1000;
        bool haselevator = (bool)(rand() % 1);
        bool hastrash = (bool)(rand() % 1);
        unsigned int flatcount = rand() % 1000;
        unsigned int floorcount = rand() % 1000;
        float avgsquare = (rand() % 50000) / 100.0;
        House = (House_t*)malloc(sizeof(House_t));
        *House = NewHouse(buildername, regionname, housetype, year, haselevator, hastrash,flatcount,floorcount, avgsquare);
        AddHouseContElem(ContP, i, House);
    }

}
void printcont(HouseCont_t *Cont) {
    HouseContElem_t *list = (*Cont).FirstContElem;
    House_t house;

    for (int i = 0; i < (*Cont).HouseCount; i++) {
        house = *((*list).house);
        printf("%s,%s,%d,%d,%d,%d,%d,%d,%.2f\n",
                house.BuilderName,house.RegionName,(int)(house.HouseType),house.HouseBuildYear,
                (int)(house.HasElevator),(int)(house.HasTrash),house.FlatCount,house.FloorCount,house.AvgSquare);
        list = (*list).nextHouse;
    }    

}
char *substr(char *str, int findex){
    if (findex >= strlen(str)) {
        return "Ошибка";
    }
    char *string = (char*)malloc(sizeof(char)*(strlen(str)-findex+1));
    int i = findex;
    while (str[i] != '\0'){
        string[i-findex] = str[i];
        i += 1;
    }
    return string;
}