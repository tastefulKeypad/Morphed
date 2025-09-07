#include <raylib.h>
#include "scene.h"

Scene::Scene() {
    entityCount = 0;
    entityId = 0;
}

// Entities
void Scene::CreateEntity() {
    entities.insert(++entityId);
    ++entityCount;
    assert(entityCount != MAX_ENTITY_COUNT);
}

void Scene::EntityAddTransform(TransformComp transform) {
    transformMap[entityId] = transform;
}

void Scene::EntityAddGeometry(GeometryComp geometry) {
    geometryMap[entityId] = geometry;
}

void Scene::EntityAddText(TextComp text) {
    textMap[entityId] = text;
}

void Scene::EntityAddPhys(PhysComp phys) {
    physMap[entityId] = phys;
}

void Scene::EntityAddColor(ColorComp color) {
    colorMap[entityId] = color;
}



// Updates
void Scene::GetInputs() {
//todo
}

void Scene::Update() {
    for (entity e : entities) {
        std::array<bool, COMP_AMOUNT> mask = {false};

        if (transformMap.find(e) != transformMap.end()) {
            transform = transformMap[e];
            mask[0] = true;
        }

        if (geometryMap.find(e) != geometryMap.end()) {
            geometry = geometryMap[e];
            mask[1] = true;
        }

        if (textMap.find(e) != textMap.end()) {
            text = textMap[e];
            mask[2] = true;
        }

        if (physMap.find(e) != physMap.end()) {
            phys = physMap[e];
            mask[3] = true;
        }

        if (colorMap.find(e) != colorMap.end()) {
            color = colorMap[e];
            mask[4] = true;
        }

        if (mask[0]) {
            transformMap[e].rot += 0.1f;
            transform.rot = transformMap[e].rot;
        }

        if (mask[2] && mask[0]) DrawTextPro(GetFontDefault(), text.text.c_str(), 
                                            transform.pos, transform.pos, transform.rot,
                                            transform.size.x, transform.size.y, color.col);
    }
}

void Scene::Render() {
}

