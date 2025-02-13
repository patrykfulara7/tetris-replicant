target_sources(${PROJECT_NAME}
    PRIVATE
    Board.cxx
    Board.hxx
    GameContext.hxx
    GameLayer.cxx
    GameLayer.hxx
    GameOverState.cxx
    GameOverState.hxx
    GameState.cxx
    GameState.hxx
    ImGuiLayer.hxx
    ImGuiLayer.cxx
    Sequence.cxx
    Sequence.hxx
    State.cxx
    State.hxx
    StateIdentifiers.hxx
    StateManager.cxx
    StateManager.hxx
    TetrisApplication.cxx
    Tetromino.cxx
    Tetromino.hxx
    tetpch.hxx
)

target_precompile_headers(${PROJECT_NAME}
    PRIVATE
    tetpch.hxx
)

configure_file(CMakePlaceholders.hxx.in ${CMAKE_CURRENT_LIST_DIR}/CMakePlaceholders.hxx)