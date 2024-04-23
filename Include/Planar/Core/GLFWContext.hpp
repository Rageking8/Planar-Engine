#pragma once

namespace Planar::Core
{
    class GLFWContext
    {
    public:
        GLFWContext();
        ~GLFWContext();

        bool init();
        void terminate();

    private:
        bool has_init;
    };
}
