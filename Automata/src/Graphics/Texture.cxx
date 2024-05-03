#include "Core/Core.hxx"
#include <memory>

#include "Graphics/Texture.hxx"

namespace Automata {
    Texture::Texture(const std::string &path) {
        int channels;
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);

        AM_ASSERT(data != nullptr);

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        GLint internalFormat;
        GLenum format;
        switch (channels) {
            case 3: {
                internalFormat = GL_RGB8;
                format = GL_RGB;
            } break;

            case 4: {
                internalFormat = GL_RGBA8;
                format = GL_RGBA;
            } break;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &ID);
    }

    void Texture::Bind(GLuint slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void Texture::Unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
} // namespace Automata
