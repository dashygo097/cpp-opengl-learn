#include "vao.h"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO, GLuint layout)
{
    VBO.Bind();
    GLvoid* offset = layout?(GLvoid*)(sizeof(GLfloat)*3): (GLvoid* )0;
    glVertexAttribPointer(layout, 3 ,GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), offset);
    glEnableVertexAttribArray(layout);
    VBO.UnBind();
}

void VAO::Bind()
{
    glBindVertexArray(ID);
}

void VAO::UnBind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}
