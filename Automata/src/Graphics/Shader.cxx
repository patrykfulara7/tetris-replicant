#include "Core/Core.hxx"

#include "Graphics/Shader.hxx"

#include "Utils/FileIO.hxx"

namespace Automata {
    Shader::Shader(const std::unordered_map<GLenum, std::string> &shaderPaths) {
        std::unordered_map<GLenum, GLuint> shaders;

        for (auto &[shader, shaderPath] : shaderPaths) {
            std::string source = FileIO::ReadFile(shaderPath);

            shaders[shader] = glCreateShader(shader);

            const char *tmp = source.c_str();
            glShaderSource(shaders[shader], 1, &tmp, nullptr);

            GLint compiled;

            glCompileShader(shaders[shader]);

#ifdef AM_DEBUG
            glGetShaderiv(shaders[shader], GL_COMPILE_STATUS, &compiled);
            if (compiled == GL_FALSE) {
                GLint length;
                glGetShaderiv(shaders[shader], GL_INFO_LOG_LENGTH, &length);

                std::vector<GLchar> infoLog(length);
                glGetShaderInfoLog(shaders[shader], length, &length, &infoLog[0]);

                std::cerr << infoLog.data() << std::endl;

                AM_ASSERT(0);
            }
#endif
        }

        ID = glCreateProgram();

        for (auto &[shader, shaderID] : shaders) {
            glAttachShader(ID, shaderID);
        }

        glLinkProgram(ID);

#ifdef AM_DEBUG
        glGetProgramiv(ID, GL_LINK_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            GLint length;
            glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &length);

            std::vector<GLchar> infoLog(length);
            glGetProgramInfoLog(ID, length, &length, &infoLog[0]);

            std::cerr << infoLog.data() << std::endl;

            AM_ASSERT(0);
        }
#endif

        for (auto &[shader, shaderID] : shaders) {
            glDetachShader(ID, shaderID);
            glDeleteShader(shaderID);
        }
    }

    Shader::~Shader() {
        glDeleteProgram(ID);
    }

    void Shader::Bind() const {
        glUseProgram(ID);
    }

    void Shader::Unbind() const {
        glUseProgram(0);
    }

    void Shader::Set1i(const std::string &name, GLint v0) {
        GLint location = glGetUniformLocation(ID, name.data());
        glUniform1i(location, v0);
    }

    void Shader::SetMatrix4fv(const std::string &name, const glm::mat4 &value) {
        GLint location = glGetUniformLocation(ID, name.data());
        glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
    }
} // namespace Automata
