#include "Planar/Engine/UI/ImGui/Renderer/TextRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/MoveMode.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Renderer
{
    TextRenderer::TextRenderer()
    {

    }

    void TextRenderer::render_center_viewport(const std::string& text)
    {
        render_center(text, get_main_viewport_size().width);
    }

    void TextRenderer::render_center_window(const std::string& text,
        bool vertical)
    {
        const Math::Size2Df window_size = get_window_size();
        render_center(text, window_size.width,
            vertical ? window_size.height : -1.f);
    }

    void TextRenderer::render_center_truncate(const std::string& text,
        float width, float line_delta, unsigned lines,
        const std::string& truncate_text)
    {
        std::pair<std::vector<std::pair<std::string, float>>, bool>
            split_result = split_text(text, width, lines);

        float frame_padding_x = ::ImGui::GetStyle().FramePadding.x;

        if (split_result.second)
        {
            std::string last = split_result.first.back().first;

            while (!last.empty() && ::ImGui::CalcTextSize(
                (last + truncate_text).c_str()).x > width)
            {
                last.pop_back();
            }

            if (!last.empty())
            {
                split_result.first.back() = { last + truncate_text,
                    ::ImGui::CalcTextSize((last + truncate_text).
                    c_str()).x };
            }
            else if (!split_result.first.empty())
            {
                split_result.first.pop_back();
            }
        }

        for (unsigned i = 0; i < split_result.first.size(); ++i)
        {
            Core::Cursor::move_x(Core::Cursor::MoveMode::DUMMY,
                (width * 0.5f) + frame_padding_x -
                (split_result.first[i].second * 0.5f) - 24.f);
            Core::Cursor::move_y(Core::Cursor::MoveMode::SET_CURSOR,
                static_cast<float>(i) * line_delta, false);
            ImGui::text(split_result.first[i].first);
        }
    }

    std::pair<std::vector<std::pair<std::string, float>>, bool>
        TextRenderer::split_text(const std::string& text,
        float width, unsigned lines)
    {
        std::pair<std::vector<std::pair<std::string, float>>, bool>
            result{};
        std::string current;

        for (const auto i : text)
        {
            current += i;

            float size_x = ::ImGui::CalcTextSize(current.c_str()).x;

            if (size_x > width)
            {
                if (result.first.size() >= lines)
                {
                    result.second = true;

                    return result;
                }

                char back = current.back();

                current.pop_back();
                result.first.push_back({ current,
                    ::ImGui::CalcTextSize(current.c_str()).x });

                current = back;
            }
        }

        if (result.first.size() >= lines && !current.empty())
        {
            result.second = true;
        }
        else if (result.first.size() < lines && !current.empty())
        {
            result.first.push_back({ current,
                ::ImGui::CalcTextSize(current.c_str()).x });
        }

        return result;
    }

    void TextRenderer::render_center(const std::string& text,
        float width, float height)
    {
        const float text_width = ::ImGui::CalcTextSize(text.c_str()).x;
        const bool vertical = height != -1.f;

        Core::Cursor::set_x((width - text_width) * 0.5f, false);

        if (vertical)
        {
            Core::Cursor::set_y(height * 0.5f, false);
        }

        ImGui::text(text, vertical);
    }
}
