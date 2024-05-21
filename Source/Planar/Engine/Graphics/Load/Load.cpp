#include "Planar/Engine/Graphics/Load/Load.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"
#include "Planar/Engine/Graphics/OpenGL/Create/Create.hpp"

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

        Planar::Engine::Graphics::OpenGL::Create::create_texture(
            &texture, stb_image);

        return texture;
    }

    GLuint load_image(const unsigned char* buffer, std::size_t length)
    {
        GLuint texture = 0;

        Planar::Engine::Graphics::Image::STBImage stb_image;
        if (!stb_image.load(buffer, length))
        {
            return texture;
        }

        Planar::Engine::Graphics::OpenGL::Create::create_texture(
            &texture, stb_image);

        return texture;
    }
}
