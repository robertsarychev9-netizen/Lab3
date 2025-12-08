#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "house.h"
#include "housecont.h"
#include "Tools.h"

typedef struct Flagtype {
    int generate;
    int sort;
    int print;
    int reverse;
    int out;
} Flagtype_t;

int main(int argc, char *argv[]) {
    Flagtype_t flag;
    flag.generate = 0;
    flag.sort = 0;
    flag.print = 0;
    flag.reverse = 0;
    flag.out = 0;
    setlocale(LC_ALL, "ru_RU.utf8");
    int N=0;
    char *ofilename;
    char *ifilename;
    HouseCont_t Cont;
    FILE *file;
    for (int i = 0; i < argc; ++i){
        if ((strcmp(argv[i], "--generate")==0 || strcmp(argv[i], "-g")==0) && i < argc - 1) {
            if (strintcheck(argv[i+1], 0) == 1){
                N = strintcheck(argv[i+1], 1);
                Cont = InitCont();
                generator(&Cont, N);
                printcont(&Cont);
                flag.generate = 1;
            }
        }
        if (strcmp(argv[i], "--sort")==0 || strcmp(argv[i], "-s")==0){
            flag.sort = 1;
        }
        if (strcmp(argv[i], "--print")==0 || strcmp(argv[i], "-P")==0){
            flag.print = 1;
        }
        if ((strstr(argv[i], "--out=") != NULL && strstr(argv[i], ".csv") != NULL) || (strcmp(argv[i], "-o") == 0 && i < argc - 1)) {
            if (strcmp(argv[i], "-o")==0 && csvcheck(argv[i+1]) == 1 && i < argc - 1){
                ofilename=argv[i+1];
            }
            if (strstr(argv[i], "--out=") != NULL && strstr(argv[i], ".csv") != NULL){
                ofilename=substr(argv[i], 6);
            }
            if (ofilename != NULL){
                flag.out = 1;
                file = fopen(ofilename, "w");
            }
        }
        if ((strstr(argv[i], "--in=") != NULL && strstr(argv[i], ".csv") != NULL) || (strcmp(argv[i], "-i") == 0 && i < argc - 1)) {
            if (strcmp(argv[i], "-i")==0 && csvcheck(argv[i+1]) == 1 && i < argc - 1){
                ifilename = argv[i+1];
            }
            if (strstr(argv[i], "--out=") != NULL && strstr(argv[i], ".csv") != NULL){
                printf("%s\n", argv[i]);
                ifilename=substr(argv[i], 6);
            }
            if (ifilename != NULL){
                file = fopen(ifilename, "r");
            }
        }
        if (strcmp(argv[i], "--type=asc")==0 || (strcmp(argv[i], "-i") == 0 && strcmp(argv[i], "A") == 0 && i < argc - 1)){
            flag.reverse = 1;
        }
        if (strcmp(argv[i], "--type=decs")==0 || (strcmp(argv[i], "-t") == 0 && strcmp(argv[i], "D") == 0 && i < argc - 1)){
            flag.reverse = -1;
        }
    }
    if (flag.generate == 1){
        if (flag.out == 1){
            int i = 0;
            HouseContElem_t *list = Cont.FirstContElem;
            while (i < Cont.HouseCount){
                House_t *House = (*list).house;
                fprintf(file, "%s,%s,%d,%u,%d,%d,%u,%u,%f\n",
                House->BuilderName,
                House->RegionName,
                House->HouseType,
                House->HouseBuildYear,
                House->HasElevator,
                House->HasTrash,
                House->FlatCount,
                House->FloorCount,
                House->AvgSquare);
                list = (*list).nextHouse;
                i++;
            }
        } else {
            printcont(&Cont);
        }
    }
    
    if (file != NULL){
        fclose(file);
    }
}
