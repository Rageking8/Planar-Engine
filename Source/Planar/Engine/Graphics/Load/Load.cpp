#include "Planar/Engine/Graphics/Load/Load.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"

namespace Planar::Engine::Graphics::Load
{
    GLuint load_image(const std::filesystem::path& image_path)
    {
        GLuint texture = 0;

        Planar::Engine::Graphics::Image::STBImage stb_image;
        if (!stb_image.load(image_path))
        {
            return texture;
        }
        
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
            GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
            GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
            GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
            GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, stb_image.get_width(),
            stb_image.get_height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
            stb_image.get_data());
        glGenerateMipmap(GL_TEXTURE_2D);

        return texture;
    }
}
