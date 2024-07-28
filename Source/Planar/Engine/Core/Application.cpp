#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/GLFW/GLFW.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"
#include "Planar/Engine/Scene/Scene.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/GLFW/glfw3.h"

namespace Planar::Engine::Core
{
    Application::Application(const std::string& window_name,
        Math::Size2Di window_size, bool maximize,
        Graphics::SupportedGraphicsAPI graphics_api) :
        window_name{ window_name }, window_size{ window_size },
        maximize{ maximize }, graphics_api{ graphics_api },
        main_scene{}
    {
        Log::TerminalLogger::get("Engine")->log(
            "Planar Engine " + Constants::VERSION);
    }

    Application::~Application()
    {

    }

    void Application::exit()
    {
        glfw_context.close_main_window();
        quit();
    }

    bool Application::init()
    {
        bool result = init_glfw() && create_window() &&
            init_glad() && init_imgui();

        if (result)
        {
            glfw_context.set_main_window_framebuffer_size_callback(
                [](GLFWwindow* window, int width, int height)
                {
                    glViewport(0, 0, width, height);
                }
            );

            GLFW::add_callback_pointer("App input", &input_controller);
            glfw_context.set_main_window_key_callback(
                [](GLFWwindow* window, int key, int scancode,
                    int action, int mods)
                {
                    GLFW::get_callback_pointer<Input::InputController>(
                        "App input")->add_key_event(key, scancode,
                        action, mods);
                }
            );

            GLFW::add_callback_pointer("App", this);
            glfw_context.set_main_window_close_callback(
                [](GLFWwindow* window)
                {
                    GLFW::get_callback_pointer<Application>("App")->
                        quit();
                }
            );
        }

        imgui_context.install_callback();

        object_manager.init();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return result;
    }

    void Application::quit()
    {
        if (main_scene)
        {
            main_scene->application_quit();
        }
    }

    void Application::run()
    {
        glfwSwapInterval(1);
        
        if (main_scene)
        {
            main_scene->start();
        }

        while (!glfw_context.main_window_should_close())
        {
            update_impl();

            if (main_scene)
            {
                main_scene->update();
                main_scene->late_update();
            }

            render_single_frame([&]
                {
                    if (main_scene)
                    {
                        main_scene->render();
                    }
                });
            
            glfw_context.poll_events();
        }
    }

    Math::Size2Di Application::get_game_framebuffer_size() const
    {
        return glfw_context.get_framebuffer_size();
    }

    void Application::render_single_frame(
        const std::function<void()>& render)
    {
        imgui_context.new_frame();

        glClearColor(0.0588f, 0.0588f, 0.0588f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        imgui_context.render();

        glfw_context.main_window_swap_buffers();
    }

    void Application::render_main_scene_single_frame()
    {
        render_single_frame(PLANAR_CAPTURE_THIS(main_scene->render));
    }

    void Application::load_scene(Scene::Scene* scene)
    {
        main_scene = scene;
        main_scene->init();
    }

    void Application::maximize_window() const
    {
        glfw_context.maximize_window();
    }

    void Application::set_window_name(const std::string& new_window_name)
    {
        window_name = new_window_name;
        glfw_context.set_main_window_name(new_window_name);
    }

    Asset::AssetDatabase* Application::get_asset_database()
    {
        return &asset_database;
    }

    Input::InputController& Application::get_input_controller()
    {
        return input_controller;
    }

    Graphics::OpenGL::Core::ObjectManager&
        Application::get_object_manager()
    {
        return object_manager;
    }

    Graphics::OpenGL::Shader::ShaderManager&
        Application::get_shader_manager()
    {
        return shader_manager;
    }

    Audio::AudioManager& Application::get_audio_manager()
    {
        return audio_manager;
    }

    bool Application::init_glfw()
    {
        return glfw_context.init();
    }

    bool Application::init_glad()
    {
        const int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0)
        {
            Log::TerminalLogger::get("Engine")->error(
                "OpenGL init failed");

            return false;
        }

        Log::TerminalLogger::get("Engine")->success(
            "OpenGL init successful");

        return true;
    }

    bool Application::init_imgui()
    {
        return imgui_context.init(glfw_context);
    }

    bool Application::create_window()
    {
        return glfw_context.create_window(graphics_api,
            window_size, window_name, maximize);
    }

    void Application::update_impl()
    {

    }
}
