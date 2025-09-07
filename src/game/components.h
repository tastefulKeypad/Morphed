#pragma once
#include <raylib.h>
#include <string>
#include <array>
#include "consts.h"

#define COMP_AMOUNT 5


struct TransformComp {
    Vector2 pos;
    Vector2 size;
    float rot;
};

struct ColorComp {
    Color col;
};

struct TextComp {
    std::string text;
};

struct GeometryComp {
    shape geometry;  
};

struct PhysComp {
    Vector2 vel;
    Vector2 accel;
};

