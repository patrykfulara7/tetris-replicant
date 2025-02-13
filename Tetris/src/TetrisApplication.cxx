#include <Automata/Main.hxx>

#include "tetpch.hxx"

#include "GameLayer.hxx"
#include "ImGuiLayer.hxx"

namespace Automata {
    class TetrisApplication : public Application {
      public:
        TetrisApplication() : Application(320, 640, "Tetris Replicant") {
            PushLayer(std::make_unique<GameLayer>());
            PushLayer(std::make_unique<ImGuiLayer>());
        }
    };

    Application *CreateApplication() {
        return new TetrisApplication();
    }
} // namespace Automata
