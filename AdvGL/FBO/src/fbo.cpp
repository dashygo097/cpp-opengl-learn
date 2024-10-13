#include "fbo.h"

TexColorBuffer::TexColorBuffer(int width, int height)
{   
    glGenTextures(1, &ID);
    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void TexColorBuffer::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

void TexColorBuffer::UnBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TexColorBuffer::Delete()
{
    glDeleteTextures(1, &ID);
}


RBO::RBO(int width, int height)
{
    glGenRenderbuffers(1, &ID);
    Bind();
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
}

void RBO::Bind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, ID);
}

void RBO::UnBind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void RBO::Delete()
{
    glDeleteRenderbuffers(1, &ID);
}

FBO::FBO()
{
    glGenFramebuffers(1, &ID);
}

void FBO::LinkRBO(RBO rbo)
{
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo.ID); 
}

void FBO::LinkTCB(TexColorBuffer tcb)
{
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tcb.ID, 0);
}

void FBO::Link(TexColorBuffer tcb, RBO rbo)
{
    Bind();
    tcb.Bind();
    LinkTCB(tcb);
    rbo.Bind();
    LinkRBO(rbo);
    UnBind();
    tcb.UnBind();
    rbo.UnBind();
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    else 
        std::cout << "Succeed in linking FBO!" <<std::endl;
}

void FBO::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
}

void FBO::UnBind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FBO::Delete()
{
    glDeleteFramebuffers(1, &ID);
}