#pragma once

#include "ampch.hxx"

#include "Graphics/BufferLayout.hxx"
#include "Graphics/ElementBuffer.hxx"
#include "Graphics/VertexBuffer.hxx"

namespace Automata {
    class VertexArray {
      private:
        GLuint ID;
        std::shared_ptr<VertexBuffer> vertexBuffer = nullptr;
        std::shared_ptr<BufferLayout> bufferLayout = nullptr;
        std::shared_ptr<ElementBuffer> elementBuffer = nullptr;

      public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer);
        void SetBufferLayout(const std::shared_ptr<BufferLayout> &bufferLayout);
        void SetElementBuffer(const std::shared_ptr<ElementBuffer> &elementBuffer);

        inline const std::shared_ptr<VertexBuffer> &GetVertexBuffer() const {
            return vertexBuffer;
        }

        inline const std::shared_ptr<BufferLayout> &GetBufferLayout() const {
            return bufferLayout;
        }

        inline const std::shared_ptr<ElementBuffer> &GetElementBuffer() const {
            return elementBuffer;
        }

        static inline std::unique_ptr<VertexArray> Create() {
            return std::make_unique<VertexArray>();
        }
    };
} // namespace Automata
