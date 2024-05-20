#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::UI::ImGui::Element
{
    class PLANAR_API Button : public Element
    {
    public:
        Button(const std::string& label = "",
            Planar::Engine::Math::Size2Df size = {}, GLuint texture = 0);

        void set(const std::string& new_label,
            Planar::Engine::Math::Size2Df new_size, GLuint new_texture = 0);

        virtual void render() override;

        bool is_clicked();
        bool is_left_double_clicked();

    private:
        std::string label;
        Planar::Engine::Math::Size2Df size;
        GLuint texture;
        bool clicked;
        bool left_double_clicked;
    };
}
