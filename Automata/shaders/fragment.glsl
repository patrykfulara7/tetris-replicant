#version 460 core

out vec4 oColor;

in vec2 TexturePosition;

uniform sampler2D slot;

void
main(void) {
    oColor = texture(slot, TexturePosition);
}
