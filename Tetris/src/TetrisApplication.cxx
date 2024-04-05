#include <Automata.hxx>
#include <Core/main.hxx>

#include "GameLayer.hxx"

#include <iostream>

namespace Automata
{
    class TetrisApplication : public Application
    {
    public:
        TetrisApplication()
            : Application(400, 800, "Tetris")
        {
            PushLayer(new GameLayer());
        }
    };

    Application* CreateApplication()
    {
        return new TetrisApplication();
    }
}

