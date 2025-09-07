#include <raylib.h>

#include "consts.h"
#include "components.h"
#include "scene.h"

#include <cmath>
#include <assert.h>
#include <random>

int main() {
    Scene game;
    SetExitKey(0);
    SetTargetFPS(60);
    DrawFPS(32,32);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test!");

    
    // Create random text at random locations
    std::string alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPLKJHGFDSXCVBNM1234567890";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distChar(0, alpha.size());
    std::uniform_int_distribution<unsigned char> distCol(0, 255);
    std::uniform_real_distribution<float> distSize(1,32),
                                    distRot(0.0f,360.0f),
                                    distPos(0, SCREEN_WIDTH);


    for (int i = 0; i < 100; ++i) {
        TransformComp tr = {{distPos(gen), distPos(gen)}, {distSize(gen),distSize(gen)}, distRot(gen)};
        ColorComp cl = {distCol(gen), distCol(gen), distCol(gen), 255};
        
        std::string str(distSize(gen), 'a');
        for (size_t k = 0; k != str.size(); ++k) {
            str[k] = alpha[distChar(gen)];
        }

        TextComp txt = {str};

        game.CreateEntity();
        game.EntityAddTransform(tr);
        game.EntityAddColor(cl);
        game.EntityAddText(txt);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.GetInputs();
        game.Update();
        EndDrawing();
    }

    return 0;
}
