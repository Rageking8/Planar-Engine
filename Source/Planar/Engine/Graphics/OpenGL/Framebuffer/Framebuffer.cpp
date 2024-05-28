#include "Planar/Engine/Graphics/OpenGL/Framebuffer/Framebuffer.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Engine::Graphics::OpenGL::Framebuffer
{
    Framebuffer::Framebuffer() : Resource(free_impl)
    {

    }

    Framebuffer::~Framebuffer()
    {

    }

    void Framebuffer::create(GLsizei width, GLsizei height,
        Core::ObjectHandlingMode object_handling_mode)
    {
        color_texture.create_raw(width, height, object_handling_mode);

        switch (object_handling_mode)
        {
        case Core::ObjectHandlingMode::BIND:
            glGenFramebuffers(1, &id);
            bind();

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                GL_TEXTURE_2D, color_texture.get_id(), 0);

            PLANAR_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) ==
                GL_FRAMEBUFFER_COMPLETE, "Framebuffer not complete");
            break;

        case Core::ObjectHandlingMode::DSA:
            glCreateFramebuffers(1, &id);

            glNamedFramebufferTexture(id, GL_COLOR_ATTACHMENT0,
                color_texture.get_id(), 0);

            PLANAR_ASSERT(glCheckNamedFramebufferStatus(id,
                GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE,
                "Framebuffer not complete");
            break;
        }

        unbind();
    }

    GLuint Framebuffer::get_color_texture_id() const
    {
        return color_texture.get_id();
    }

    void Framebuffer::resize_color_texture(GLsizei width, GLsizei height)
    {
        color_texture.resize(width, height);
    }

    void Framebuffer::bind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }

    void Framebuffer::unbind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Framebuffer::free_impl(GLuint id)
    {
        glDeleteFramebuffers(1, &id);
    }
}
