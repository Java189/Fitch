#include <utility>
#include <iostream>

#include "Block.h"
#include "../tools.h"

Block::Block(glm::vec2 position, BlockType type) : position(position), type(type), drawMat(glm::mat4(1)),
    shaderProgram(new Shader(0)) {}

Block::Block(glm::vec2 position, BlockType type, const char* texture_path) : position(position), type(type), drawMat(glm::mat4(1)),
    shaderProgram(new Shader(0)) {

    texture = fitchio::loadBMP(texture_path);

}

int Block::getSize() {

    return BLOCK_SIZE;

}

BlockType Block::getType() const {
    return this->type;
}

bool Block::isRenderable() const {
    return !(this->type == Air || this->type == Start);
}

glm::vec2 Block::getPos() const {
    return this->position;
}

void Block::setTexture(Texture2D tex) {
    this->texture = tex;
}

void Block::setShader(Shader* shader) { this->shaderProgram = shader; }

std::ostream& operator<<(std::ostream& stream, BlockType type) {

    if (type == Solid)
        stream << (std::string)"Solid";
    else if (type == Air)
        stream << (std::string)"Air";
    else if (type == Start)
        stream << (std::string)"Start";

    return stream;

}

void Block::setMatrix(glm::mat4 mat) { this->drawMat = mat; }

void Block::init() {

    this->vao = VAO::create();
    this->vbo = VBO::create(GL_ARRAY_BUFFER);

    glm::vec2 screenPos(position.x * BLOCK_SIZE, position.y * BLOCK_SIZE);

    auto vertices = new float[16] {

            screenPos.x, screenPos.y, 0.0f, 0.0f,
            screenPos.x + BLOCK_SIZE, screenPos.y, 1.0f, 0.0f,
            screenPos.x, screenPos.y + BLOCK_SIZE, 0.0f, 1.0f,
            screenPos.x + BLOCK_SIZE, screenPos.y + BLOCK_SIZE, 1.0f, 1.0f

    };

    this->vbo.sendData(vertices, 16, GL_DYNAMIC_DRAW);

    delete[] vertices;

}

void Block::update() {

    glm::vec2 screenPos(position.x * BLOCK_SIZE, position.y * BLOCK_SIZE);

    auto vertices = new float[16] {

            screenPos.x, screenPos.y, 0.0f, 0.0f,
            screenPos.x + BLOCK_SIZE, screenPos.y, 1.0f, 0.0f,
            screenPos.x, screenPos.y + BLOCK_SIZE, 0.0f, 1.0f,
            screenPos.x + BLOCK_SIZE, screenPos.y + BLOCK_SIZE, 1.0f, 1.0f

    };

    this->vbo.sendData(vertices, 16, GL_DYNAMIC_DRAW);

    delete[] vertices;

}

void Block::draw() {

    this->vao.bind();
    this->vbo.bind();

    this->shaderProgram->bind();
    this->texture.bind();

    GLint MatrixID = glGetUniformLocation(this->shaderProgram->getID(), "projMat");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &drawMat[0][0]);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}

glm::vec2 Block::screenPos() {
    return glm::vec2(position.x * BLOCK_SIZE, position.y * BLOCK_SIZE);
}
