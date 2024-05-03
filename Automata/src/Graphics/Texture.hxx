#pragma once

#include "ampch.hxx"

namespace Automata {
    class Texture {
      private:
        GLuint ID = 0;
        int width = 0;
        int height = 0;

      public:
        Texture(const std::string &path);
        ~Texture();

        void Bind(GLuint slot) const;
        void Unbind() const;

        inline GLuint GetWidth() const {
            return width;
        }
        inline GLuint GetHeight() const {
            return height;
        }
        static inline std::shared_ptr<Texture> Create(const std::string &path) {
            return std::make_shared<Texture>(path);
        }
    };
} // namespace Automata
