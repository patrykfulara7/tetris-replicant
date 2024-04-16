#include "GameLayer.hxx"

GameLayer::GameLayer()
    : tetromino(0, 0, INITIAL_POSITION), board(10, 20)
{
    for (uint8_t i = 0; i < 8; i++)
        blockTextures[i] = Automata::Texture::Create("res/tex/" + std::to_string(i) + ".png");

    tetromino.SetTetromino(std::chrono::system_clock::now().time_since_epoch().count() % 7);
    board.AddTetromino(tetromino);
}

void GameLayer::OnAttach()
{
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnEvent(Automata::Event& event)
{
    if (event.GetEventType() != Automata::EventType::KeyPressed)
        return;

    auto key = dynamic_cast<Automata::KeyPressedEvent*>(&event)->GetKeyCode();

    switch (key)
    {
        case Automata::Key::C:
            Automata::Application::Close();
            break;

        case Automata::Key::J:
            nextAction = Action::MoveDown;
            break;

        case Automata::Key::H:
            nextAction = Action::MoveLeft;
			break;

        case Automata::Key::L:
            nextAction = Action::MoveRight;
			break;

        case Automata::Key::Q:
            nextAction = Action::RotateLeft;
			break;

        case Automata::Key::E:
            nextAction = Action::RotateRight;
			break;
    }
}

void GameLayer::OnUpdate(double deltaTime)
{
    (void)deltaTime;

    board.RemoveTetromino(tetromino);
    glm::ivec2 previousPosition = tetromino.GetPosition();
    uint8_t previousRotation = tetromino.GetRotation();

    switch (nextAction)
    {
        case Action::MoveDown:
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(0, 1));
            break;

        case Action::MoveLeft:
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(-1, 0));
            break;

        case Action::MoveRight:
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(1, 0));
            break;

        case Action::RotateLeft:
            tetromino.SetRotation((tetromino.GetRotation() + 1) % 4);
            break;

        case Action::RotateRight:
            tetromino.SetRotation((tetromino.GetRotation() + 3) % 4);
            break;

        case Action::None:
            break;
    }

    if (board.DoesTetrominoFit(tetromino))
    {
        board.AddTetromino(tetromino);
    }
    else
    {
        tetromino.SetPosition(previousPosition);
        tetromino.SetRotation(previousRotation);
        board.AddTetromino(tetromino);

        if (nextAction == Action::MoveDown)
        {
            tetromino.SetTetromino(std::chrono::system_clock::now().time_since_epoch().count() % 7);
            tetromino.SetPosition(INITIAL_POSITION);
            tetromino.SetRotation(0);
            board.AddTetromino(tetromino);
        }
    }

    nextAction = Action::None;
}

void GameLayer::OnRender()
{
    for (uint8_t i = 0; i < board.GetHeight(); i++)
    {
        for (uint8_t j = 0; j < board.GetWidth(); j++)
        {
            if (board[i][j] != 0)
            {
                Automata::Renderer::Draw(glm::vec2(j * 32.0f, i * 32.0f), blockTextures[board[i][j] - 1]);
            }
        }
    }
}
