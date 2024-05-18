#include "Planar/Engine/Graphics/Load/Load.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"
#include "Planar/Engine/Graphics/Create/Create.hpp"

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

        Planar::Engine::Graphics::Create::create_texture(
            &texture, stb_image);

        return texture;
    }
}
