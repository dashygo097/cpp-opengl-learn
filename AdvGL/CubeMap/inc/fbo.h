#ifndef FBO_CLASS_H
#define FBO_CLASS_H

#include "vbo.h"
#include "texture.h"

class TexColorBuffer
{
public:
    GLuint ID;
    TexColorBuffer(int width, int height);

    void Bind();
    void UnBind();
    void Delete();
};


class RBO
{
public:

    GLuint ID;
    RBO(int width, int height);

    void Bind();
    void UnBind();
    void Delete();

};



class FBO
{
public:

    GLuint ID;
    FBO();

    void LinkTCB(TexColorBuffer tcb);
    void LinkRBO(RBO rbo);

    void Link(TexColorBuffer tcb, RBO rbo);

    void Bind();
    void UnBind();
    void Delete();

};


#endif