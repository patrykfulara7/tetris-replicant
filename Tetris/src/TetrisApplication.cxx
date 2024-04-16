#include <Core/main.hxx>

#include "tetpch.hxx"

#include "GameLayer.hxx"

namespace Automata
{
    class TetrisApplication : public Application
    {
    public:
        TetrisApplication()
            : Application(10 * 32, 20 * 32, "Tetris")
        {
            PushLayer(new GameLayer());
        }
    };

    Application* CreateApplication()
    {
        return new TetrisApplication();
    }
}

