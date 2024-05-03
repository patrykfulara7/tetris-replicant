#include "Graphics/Renderer.hxx"
#include "Graphics/Shader.hxx"
#include "Graphics/VertexArray.hxx"

namespace Automata {
    static glm::mat4 projection;
    static std::unique_ptr<Shader> shader = nullptr;
    static std::unique_ptr<VertexArray> vertexArray = nullptr;

    void Renderer::Init(int width, int height) {
        projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

        shader = Shader::Create("Automata/shaders/vertex.glsl", "Automata/shaders/fragment.glsl");

        shader->Bind();
        shader->SetMatrix4fv("projection", projection);
        shader->Set1i("slot", 0);

        vertexArray = VertexArray::Create();

        std::array<GLfloat, 16> vertcies = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
        auto vertexBuffer = VertexBuffer::Create(vertcies.size() * sizeof(GLfloat), vertcies.data(), GL_STATIC_DRAW);
        vertexArray->SetVertexBuffer(vertexBuffer);

        auto bufferLayout = BufferLayout::Create();
        bufferLayout->PushAttribute(2, GL_FLOAT, GL_FALSE);
        bufferLayout->PushAttribute(2, GL_FLOAT, GL_FALSE);
        vertexArray->SetBufferLayout(bufferLayout);

        std::array<GLuint, 6> indicies = {0, 1, 2, 1, 2, 3};
        auto elementBuffer = ElementBuffer::Create(indicies.size() * sizeof(GLuint), indicies.data(), GL_STATIC_DRAW, GL_UNSIGNED_INT);
        vertexArray->SetElementBuffer(elementBuffer);
    }

    void Renderer::Clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Draw(const glm::vec2 &position, const Texture &texture) {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position, 0.0f)) *
                          glm::scale(glm::mat4(1.0f), glm::vec3(texture.GetWidth(), texture.GetHeight(), 1.0f));

        shader->Bind();
        shader->SetMatrix4fv("model", model);

        texture.Bind(0);

        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, vertexArray->GetElementBuffer()->GetCount(), vertexArray->GetElementBuffer()->GetType(), 0);
    }
} // namespace Automata
