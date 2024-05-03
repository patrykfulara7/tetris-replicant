#include "Core/Core.hxx"

#include "Graphics/Shader.hxx"

#include "Utils/FileIO.hxx"

namespace Automata {
    Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
        std::unordered_map<GLenum, std::string> sources;

        sources[GL_VERTEX_SHADER] = FileIO::ReadFile(vertexPath);
        sources[GL_FRAGMENT_SHADER] = FileIO::ReadFile(fragmentPath);

        const char *vertexSource = sources[GL_VERTEX_SHADER].c_str();
        const char *fragmentSource = sources[GL_FRAGMENT_SHADER].c_str();

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(vertexShader, 1, &vertexSource, nullptr);
        glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);

        GLint compiled;

        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            GLint length;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);

            std::vector<GLchar> infoLog(length);
            glGetShaderInfoLog(vertexShader, length, &length, &infoLog[0]);

            std::cout << infoLog.data() << std::endl;

            AM_ASSERT(0);
        }

        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            GLint length;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);

            std::vector<GLchar> infoLog(length);
            glGetShaderInfoLog(fragmentShader, length, &length, &infoLog[0]);

            std::cout << infoLog.data() << std::endl;

            AM_ASSERT(0);
        }

        ID = glCreateProgram();

        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);

        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            GLint length;
            glGetProgramiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);

            std::vector<GLchar> infoLog(length);
            glGetProgramInfoLog(fragmentShader, length, &length, &infoLog[0]);

            std::cout << infoLog.data() << std::endl;

            AM_ASSERT(0);
        }

        glDetachShader(ID, vertexShader);
        glDetachShader(ID, fragmentShader);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
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
