#ifndef FITCH_TOOLS_H
#define FITCH_TOOLS_H

#include <string>
#include <vector>
#include <Box2D/Box2D.h>
#include "graphics/Texture2D.h"
#include "game/Block.h"

namespace fitchio {

    const char* loadFile(const char* file_path);
    Texture2D loadBMP(const char* image_path);
    std::vector<std::string> splitString(const std::string& str, char delim);
    std::vector<Block>* loadLevel(const char* file_path);
    unsigned char* loadImage(const char* image_path, int* w, int* h);

}

namespace fitchtools {

    float pixToWorld(float pix);
    float worldToPix(float world);
    glm::vec2 worldToPix(b2Vec2 world);
    b2Vec2 pixToWorld(glm::vec2 pix);

}

#endif //FITCH_TOOLS_H
