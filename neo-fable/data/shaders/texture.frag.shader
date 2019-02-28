#version 330 core

out vec4 oColor;

in vec2 iTexCoord;
in vec4 iColor;

uniform sampler2D img;

void main() {
	oColor = texture(img, iTexCoord);
}