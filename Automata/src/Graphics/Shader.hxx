#pragma once

#include "ampch.hxx"

namespace Automata {
    class Shader {
      private:
        GLuint ID = 0;

      public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void Set1i(const std::string &name, GLint v0);
        void SetMatrix4fv(const std::string &name, const glm::mat4 &value);

        inline static std::unique_ptr<Shader> Create(const std::string &vertexPath, const std::string &fragmentPath) {
            return std::make_unique<Shader>(vertexPath, fragmentPath);
        }
    };
} // namespace Automata
