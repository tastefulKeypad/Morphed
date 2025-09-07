#pragma once
#include "consts.h"
#include "components.h"
#include <assert.h>
#include <set>
#include <unordered_map>

class Scene {
    entity entityCount, entityId;
    std::set<entity> entities;
    std::unordered_map<entity, TransformComp> transformMap;
    std::unordered_map<entity, GeometryComp> geometryMap;
    std::unordered_map<entity, TextComp> textMap;
    std::unordered_map<entity, PhysComp> physMap;
    std::unordered_map<entity, ColorComp> colorMap;


    TransformComp transform;
    GeometryComp geometry;
    TextComp text;
    PhysComp phys;
    ColorComp color;

public:
    Scene();

    // Entities
    void CreateEntity();
    void EntityAddTransform(TransformComp transform);
    void EntityAddGeometry(GeometryComp geometry);
    void EntityAddText(TextComp text);
    void EntityAddPhys(PhysComp phys);
    void EntityAddColor(ColorComp color);

    // Updates
    void GetInputs();
    void Update();
    void Render();
};
