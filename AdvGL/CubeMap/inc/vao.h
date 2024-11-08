#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "vbo.h"

class VAO
{
public:
    GLuint ID;

    VAO();

    void LinkVBO(VBO& VBO, GLuint layout);
    void Bind();
    void UnBind();
    void Delete();
};

// class QuadVAO : public VAO
// {
// public:

//     void LinkVBO(VBO& VBO, GLuint layout);
// };


#endif 