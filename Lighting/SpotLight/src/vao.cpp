#include "vao.h"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO, GLuint layout)
{
    VBO.Bind();

    GLvoid* offset;
    GLuint in_size;
    
    switch (layout)
    {
        case 0:
        {
            offset = (GLvoid*)(sizeof(GLfloat) * 0);
            in_size = 3;
            break;
        }
        case 1:
        {
            offset = (GLvoid*)(sizeof(GLfloat) * 3);
            in_size = 3;
            break;
        }
        case 2:
        {
            offset = (GLvoid*)(sizeof(GLfloat) * 6);
            in_size = 3;
            break;
        }
        case 3:
        {
            offset = (GLvoid*)(sizeof(GLfloat) * 9);
            in_size = 2;
            break;
        } 
        default:
        {
            break;
        }
    }

    glVertexAttribPointer(layout, in_size ,GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), offset);
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
