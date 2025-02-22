#version 450 core

layout(location = 0) in vec2 iPosition;
layout(location = 1) in vec2 iTexturePosition;

out vec2 TexturePosition;

uniform mat4 projection;
uniform mat4 model;

void main(void) {
    TexturePosition = iTexturePosition;

    gl_Position = projection * model * vec4(iPosition, 0.0, 1.0);
}
