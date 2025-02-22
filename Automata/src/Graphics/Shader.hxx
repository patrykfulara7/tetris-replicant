#pragma once

#include "ampch.hxx"

namespace Automata {
    class Shader {
      private:
        GLuint ID = 0;

      public:
        Shader(const std::unordered_map<GLenum, std::string> &shaderPaths);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void Set1i(const std::string &name, GLint v0);
        void SetMatrix4fv(const std::string &name, const glm::mat4 &value);

        inline static std::unique_ptr<Shader> Create(const std::unordered_map<GLenum, std::string> &shaderPaths) {
            return std::make_unique<Shader>(shaderPaths);
        }
    };
} // namespace Automata
