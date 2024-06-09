#include "Planar/Engine/UI/ImGui/Font/Font.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Font
{
    void load_font(const unsigned char* buffer,
        std::size_t buffer_size, float font_size)
    {
        ImFontConfig config{};
        config.FontDataOwnedByAtlas = false;
        config.RasterizerMultiply = 1.5f;

        ::ImGui::GetIO().Fonts->AddFontFromMemoryTTF(
            const_cast<void*>(static_cast<const void*>(buffer)),
            static_cast<int>(buffer_size), font_size, &config);
    }
}
