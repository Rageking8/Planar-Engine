#include "Planar/Engine/Graphics/Image/STBImage.hpp"

#include "ThirdParty/stb/stb_image.h"

namespace Planar::Engine::Graphics::Image
{
    STBImage::STBImage() : data{}, width{}, height{}
    {

    }

    STBImage::~STBImage()
    {
        free();
    }

    bool STBImage::load(const std::filesystem::path& image_path)
    {
        data = stbi_load(image_path.string().c_str(), &width,
            &height, nullptr, 4);

        return data;
    }

    void STBImage::free()
    {
        stbi_image_free(data);
        data = nullptr;
    }

    unsigned char* STBImage::get_data() const
    {
        return data;
    }

    int STBImage::get_width() const
    {
        return width;
    }

    int STBImage::get_height() const
    {
        return height;
    }
}
