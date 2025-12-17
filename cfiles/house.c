#include <stdbool.h>
#include "..\headers\house.h"
#include <stdlib.h>
#include <string.h>

House_t NewHouse (const char *BuilderName, const char *RegionName, HouseType_t HouseType,
                    unsigned int HouseBuildYear, bool HasElevator, bool HasTrash, unsigned int FlatCount, unsigned int FloorCount,
                    float AvgSquare) {
    if ((HouseBuildYear<1000) || (HouseBuildYear>9999)) {
        perror("Некорректный год постройки");
        exit(EXIT_FAILURE);
    }

    House_t *resP=(House_t*)malloc(sizeof(House_t)), res;
    res = *resP;

    res.BuilderName = malloc(sizeof(char)*(strlen(BuilderName)+1));
    strcpy(res.BuilderName, BuilderName);
    res.RegionName = malloc(sizeof(char)*(strlen(RegionName)+1));
    strcpy(res.RegionName, RegionName);
    res.HouseType = HouseType;
    res.HouseBuildYear = HouseBuildYear;
    res.HasElevator = HasElevator;
    res.HasTrash = HasTrash;
    res.FlatCount = FlatCount;
    res.FloorCount = FloorCount;
    res.AvgSquare = AvgSquare;

    return res; 

};

void FreeHouse(House_t house) {
    free(house.BuilderName);
    free(house.RegionName);
}

/*
Индексы для сортировки
1 - Название застройщика: строка
2 - Название микрорайона: строка
3 - Тип: перечисление (панельный, кирпичный,монолитный)
4 - Год постройки: четырехзначное число
5 - Наличие лифта: логическое значение
6 - Наличие мусоропровода: логическое значение
7 - Количество квартир: целое число
8 - Количество этажей: целое число
9 - Средняя площадь квартиры: вещественное число
*/