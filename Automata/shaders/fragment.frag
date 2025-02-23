#version 450 core

out vec4 oColor;

in vec2 TexturePosition;

uniform sampler2D slot;

void main() {
    oColor = texture(slot, TexturePosition);
}
