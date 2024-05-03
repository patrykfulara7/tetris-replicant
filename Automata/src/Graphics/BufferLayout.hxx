#pragma once

#include "ampch.hxx"

namespace Automata {
    class BufferLayout {
      private:
        struct Attribute {
            GLint size = 0;
            GLenum type = 0;
            GLboolean normalized = 0;

            Attribute(GLint size, GLenum type, GLboolean normalized) : size(size), type(type), normalized(normalized) {
            }
        };

        std::vector<Attribute> bufferLayout;
        GLsizei stride = 0;

      public:
        void Enable() const;

        void PushAttribute(const Attribute &attribute);
        void PushAttribute(GLint size, GLenum type, GLboolean normalized);

        static inline std::shared_ptr<BufferLayout> Create() {
            return std::make_shared<BufferLayout>();
        }
    };
} // namespace Automata
