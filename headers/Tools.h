#pragma once
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..\headers\house.h"
#include "..\headers\housecont.h"
char* manual_realloc(char* old_ptr, size_t old_size, size_t new_size);
char **manual_realloc_two(char** old_ptr, size_t old_size, size_t new_size);
int strintcheck(char *str, int mode);
int csvcheck(char *str);
char *randbuilder(int N);
char *randregion(int N);
void generator(HouseCont_t *ContP, int N);
void printcont(HouseCont_t *Cont);
char *substr(char *str, int findex);
House_t strtohouse(char *str);