#pragma once
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "house.h"
#include "housecont.h"
int strintcheck(char *str, int mode);
int csvcheck(char *str);
char *randbuilder(int N);
char *randregion(int N);
void generator(HouseCont_t *ContP, int N);
void printcont(HouseCont_t *Cont);
char *substr(char *str, int findex);