#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <filesystem>

namespace Planar::Engine::Graphics::Image
{
    class PLANAR_API STBImage
    {
    public:
        STBImage();
        ~STBImage();

        bool load(const std::filesystem::path& image_path);
        void free();

        unsigned char* get_data() const;
        int get_width() const;
        int get_height() const;

    private:
        unsigned char* data;
        int width;
        int height;
    };
}
