#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "house.h"
#include "housecont.h"
#include "Tools.h"
#include "GnomSorted.h"

typedef struct Flagtype {
    int generate;
    int sort;
    int print;
    int reverse;
    int out;
    int in;
} Flagtype_t;

int main(int argc, char *argv[]) {
    Flagtype_t flag;
    flag.generate = 0;
    flag.sort = 0;
    flag.print = 0;
    flag.reverse = 0;
    flag.out = 0;
    flag.in = 0;
    setlocale(LC_ALL, "ru_RU.utf8");
    int N=0;
    char *ofilename;
    char *ifilename;
    HouseCont_t Cont;
    FILE *ofile;
    FILE *ifile;
    for (int i = 0; i < argc; ++i){
        if ((strcmp(argv[i], "--generate")==0 || strcmp(argv[i], "-g")==0) && i < argc - 1) {
            if (strintcheck(argv[i+1], 0) == 1){
                N = strintcheck(argv[i+1], 1);
                Cont = InitCont();
                generator(&Cont, N);
                flag.generate = 1;
            }
        }
        if (strcmp(argv[i], "--sort")==0 || strcmp(argv[i], "-s")==0) {
            flag.sort = 1;
        }
        if (strcmp(argv[i], "--print")==0 || strcmp(argv[i], "-P")==0) {
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
                ofile = fopen(ofilename, "w");
            }
        }
        if ((strstr(argv[i], "--in=") != NULL && strstr(argv[i], ".csv") != NULL) || (strcmp(argv[i], "-i") == 0 && i < argc - 1)) {
            if (strcmp(argv[i], "-i")==0 && csvcheck(argv[i+1]) == 1 && i < argc - 1){
                ifilename = argv[i+1];
                flag.in = 1;
            }
            if (strstr(argv[i], "--out=") != NULL && strstr(argv[i], ".csv") != NULL){
                ifilename=substr(argv[i], 6);
                flag.in = 1;
            }
            if (ifilename != NULL){
                ifile = fopen(ifilename, "r");
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
        if (ofile == NULL){
            perror("Ошибка открытия файла");
            exit(EXIT_FAILURE);
        }
        if (flag.out == 1){
            int i = 0;
            HouseContElem_t *list = Cont.FirstContElem;
            while (i < Cont.HouseCount){
                House_t *House = (*list).house;
                fprintf(ofile, "%s,%s,%d,%u,%d,%d,%u,%u,%f\n",
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
    if (flag.sort == 1) {
        if (ifile == NULL){
            perror("Ошибка открытия файла");
            exit(EXIT_FAILURE);
        }
        HouseCont_t Cont = InitCont();
        House_t *House;
        int c;
        char **list;
        char *str=(char*)malloc(2*sizeof(char));
        int i = 0;
        int j = 0;
        while ((c = fgetc(ifile)) != EOF) {
            if (c != '\n') {
                str[i] = c;
                str[i+1] = '\0';
                str = manual_realloc(str, strlen(str)*sizeof(char), (strlen(str)+2)*sizeof(char));
                i+=1;
            } else {
                list[j] = (char*)malloc((strlen(str)+1)*sizeof(char));
                strcpy(list[j], str);
                free(str);
                str = (char*)malloc(2*sizeof(char));
                i = 0;
                j += 1;
            }
        }
        for (int k = 0; k < j; k++){
            House_t *house = (House_t*)malloc(sizeof(House_t));
            (*house) = strtohouse(list[k]);
            AddHouseContElem(&Cont, k, house);
        }
        printcont(&Cont); printf("%s","\n");
        SwapContElem(&Cont, 1, 0);
        printcont(&Cont); printf("%s","\n");
        SwapContElem(&Cont, 2, 1);
        printcont(&Cont); printf("%s","\n");
        SwapContElem(&Cont, 3, 2);
        printcont(&Cont); printf("%s","\n");
        SwapContElem(&Cont, 4, 3);

        //GnomSortedCont(&Cont);
        printf("\n"); printcont(&Cont); printf("%s","\n");
    }
        if (flag.in == 1){
        fclose(ifile);
    }
    if (flag.out == 1){
        fclose(ofile);
    }
}
