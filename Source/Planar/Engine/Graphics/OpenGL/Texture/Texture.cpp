#include "Planar/Engine/Graphics/OpenGL/Texture/Texture.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    Texture::Texture() : Resource(free_impl),
        min_filter{ TextureMinFilter::NEAREST_MIPMAP_LINEAR },
        mag_filter{ TextureMagFilter::LINEAR }
    {

    }

    Texture::Texture(const std::filesystem::path& texture_path,
        Core::ObjectHandlingMode object_handling_mode) : Texture()
    {
        load(texture_path, object_handling_mode);
    }

    Texture::~Texture()
    {

    }

    bool Texture::load(const std::filesystem::path& texture_path,
        Core::ObjectHandlingMode object_handling_mode)
    {
        Image::STBImage stb_image;
        if (!stb_image.load(texture_path))
        {
            return false;
        }

        create(stb_image, object_handling_mode);

        return true;
    }

    bool Texture::load(const unsigned char* buffer, std::size_t length,
        Core::ObjectHandlingMode object_handling_mode)
    {
        Image::STBImage stb_image;
        if (!stb_image.load(buffer, length))
        {
            return false;
        }

        create(stb_image, object_handling_mode);

        return true;
    }

    TextureMinFilter Texture::get_min_filter() const
    {
        return min_filter;
    }

    TextureMagFilter Texture::get_mag_filter() const
    {
        return mag_filter;
    }

    void Texture::set_wrap_s(TextureWrap new_wrap_s,
        Core::ObjectHandlingMode object_handling_mode)
    {
        PLANAR_FATAL("Invalid operation");
    }

    void Texture::set_wrap_t(TextureWrap new_wrap_t,
        Core::ObjectHandlingMode object_handling_mode)
    {
        PLANAR_FATAL("Invalid operation");
    }

    void Texture::set_wrap_r(TextureWrap new_wrap_r,
        Core::ObjectHandlingMode object_handling_mode)
    {
        PLANAR_FATAL("Invalid operation");
    }

    void Texture::Texture::free_impl(GLuint id)
    {
        glDeleteTextures(1, &id);
    }
}
