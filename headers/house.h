#pragma once
#include <stdbool.h>

typedef enum {
        panel, brick, monolit //1 панельный, 2 кирпичный, 3 монолитный
    } HouseType_t;

typedef struct {
    char *BuilderName;
    char *RegionName;
    HouseType_t HouseType;
    unsigned int HouseBuildYear;
    bool HasElevator;
    bool HasTrash;
    unsigned int FlatCount;
    unsigned int FloorCount;
    float AvgSquare;

} House_t;

House_t NewHouse (const char *BuilderName, const char *RegionName, HouseType_t HouseType,
                    unsigned int HouseBuildYear, bool HasElevator, bool HasTrash, unsigned int FlatCount, unsigned int FloorCount,
                    float AvgSquare);

void FreeHouse(House_t house);