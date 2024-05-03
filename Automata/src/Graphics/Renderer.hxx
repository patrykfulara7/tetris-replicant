#pragma once

#include "ampch.hxx"

#include "Graphics/Texture.hxx"

namespace Automata {
    class Renderer {
      public:
        static void Init(int width, int height);

        static void Clear();
        static void Draw(const glm::vec2 &position, const Texture &texture);
    };
} // namespace Automata
