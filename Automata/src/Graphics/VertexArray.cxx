#include "Graphics/VertexArray.hxx"

namespace Automata {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &ID);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &ID);
    }

    void VertexArray::Bind() const {
        glBindVertexArray(ID);
    }

    void VertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void VertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) {
        glBindVertexArray(ID);
        vertexBuffer->Bind();
        this->vertexBuffer = vertexBuffer;
    }

    void VertexArray::SetBufferLayout(const std::shared_ptr<BufferLayout> &bufferLayout) {
        glBindVertexArray(ID);
        bufferLayout->Enable();
        this->bufferLayout = bufferLayout;
    }

    void VertexArray::SetElementBuffer(const std::shared_ptr<ElementBuffer> &elementBuffer) {
        glBindVertexArray(ID);
        elementBuffer->Bind();
        this->elementBuffer = elementBuffer;
    }
} // namespace Automata
