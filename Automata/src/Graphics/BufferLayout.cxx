#include "Graphics/BufferLayout.hxx"
#include "Graphics/GLTypes.hxx"

namespace Automata {
    void BufferLayout::PushAttribute(const Attribute &attribute) {
        bufferLayout.emplace_back(attribute);
        stride += GLTypes::GetSize(attribute.type) * attribute.size;
    }

    void BufferLayout::PushAttribute(GLint size, GLenum type, GLboolean normalized) {
        bufferLayout.emplace_back(size, type, normalized);
        stride += GLTypes::GetSize(type) * size;
    }

    void BufferLayout::Enable() const {
        uint32_t pointer = 0;
        GLuint index = 0;
        for (auto &attribute : bufferLayout) {
            glVertexAttribPointer(index, attribute.size, attribute.type, attribute.normalized, stride, reinterpret_cast<const GLvoid *>(pointer));
            glEnableVertexAttribArray(index);

            pointer += GLTypes::GetSize(attribute.type) * attribute.size;
            index++;
        }
    }
} // namespace Automata
