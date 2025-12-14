#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "house.h"
#include "housecont.h"

char* manual_realloc(char* old_ptr, size_t old_size, size_t new_size) {
    if (new_size<=old_size){
        return "Ошибка выделения памяти";
    }
    char* new_ptr = (char*)malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }
    if (old_ptr != NULL) {
        strcpy(new_ptr, old_ptr);
    }
    return new_ptr;
}

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
        HouseType_t housetype = (HouseType_t)((rand() % 3) );
        unsigned int year = (rand() % 9000) + 1000;
        bool haselevator = (bool)(rand() % 2);
        bool hastrash = (bool)(rand() % 2);
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
        /*
        printf("%s,%s,%d,%d,%d,%d,%d,%d,%.2f\n",
                house.BuilderName,house.RegionName,(int)(house.HouseType),house.HouseBuildYear,
                (int)(house.HasElevator),(int)(house.HasTrash),house.FlatCount,house.FloorCount,house.AvgSquare);
        */
        printf("%-20s", house.BuilderName);
        printf("%-12s", house.RegionName);
        if ((int)(house.HouseType) == 0){
            printf("%-10s", "PANEL");
        }
        if ((int)(house.HouseType) == 1){
            printf("%-10s", "BRICK");
        }
        if ((int)(house.HouseType) == 2){
            printf("%-10s", "MONOLIT");
        }
        printf("%-5d", house.HouseBuildYear);
        if ((int)(house.HasElevator) == 1){
            printf("%-5s", "YES");
        } else {
            printf("%-5s", "NO");
        }
        if ((int)(house.HasTrash) == 1){
            printf("%-5s", "YES");
        } else {
            printf("%-5s", "NO");
        }
        printf("%-6d", house.FlatCount);
        printf("%-6d", house.FloorCount);
        printf("%-6f\n", house.AvgSquare);


        /*
        if (tp == 1) {
            if ((*list).prevHouse !=NULL) {
                printf("  P %s",list->prevHouse->house->BuilderName);
            }
            if ((*list).nextHouse !=NULL) {
                printf("  N %s",list->nextHouse->house->BuilderName);
            }
            printf("\n");
        }
            */
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
House_t strtohouse(char *str){
    int len = strlen(str);
    int j = 0;
    int k = 0;
    char* list = (char*)malloc(2*sizeof(char));
    char *BuilderName;
    char *RegionName;
    HouseType_t HouseType;
    unsigned int HouseBuildYear;
    bool HasElevator;
    bool HasTrash;
    unsigned int FlatCount;
    unsigned int FloorCount;
    float AvgSquare;
    for (int i = 0; i <= len; i++){
        if (str[i] != ',' && str[i] != '\0'){
            list[k] = str[i];
            list[k+1] = '\0';
            list = manual_realloc(list, strlen(list)*sizeof(char), (strlen(list)+2)*sizeof(char));
            k += 1;
        } else {
            //printf("%s,", list);
            if (j == 0){
                BuilderName=(char*)malloc((strlen(list)+1)*sizeof(char));
                strcpy(BuilderName, list);
                j += 1;
            } else
            if (j == 1){
                RegionName=(char*)malloc((strlen(list)+1)*sizeof(char));
                strcpy(RegionName, list);
                j += 1;
            } else
            if (j == 2){
                HouseType = atoi(list);
                j += 1;
            } else
            if (j == 3){
                HouseBuildYear=atoi(list);
                j += 1;
            } else
            if (j == 4){
                HasElevator=(bool)atoi(list);
                j += 1;
            } else
            if (j == 5){
                HasTrash=(bool)atoi(list);
                j += 1;
            } else
            if (j == 6){
                FlatCount=atoi(list);
                j += 1;
            } else
            if (j == 7){
                FloorCount=atoi(list);
                j += 1;
            } else
            if (j == 8){
                AvgSquare=atof(list);
                j += 1;
            }
            free(list);
            list=(char*)malloc(2*sizeof(char));
            k = 0;
        }
    }
    return NewHouse(BuilderName, RegionName, HouseType, HouseBuildYear, HasElevator, HasTrash, FloorCount, FloorCount, AvgSquare);
}
char **manual_realloc_two(char** old_ptr, size_t old_size, size_t new_size) {
    if (new_size<=old_size){
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    char **new_ptr = (char**)malloc(new_size*sizeof(char*));
    if (new_ptr == NULL) {
        return NULL;
    }
    if (old_ptr != NULL) {
        for (int i = 0; i < old_size; i++){
            new_ptr[i]=old_ptr[i];
        }
    }
    return new_ptr;
}
