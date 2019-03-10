#version 330 core

in vec2 fTexCoord;
in vec3 fColor;

out vec4 oColor;

uniform sampler2D img;

void main() {
	oColor = texture(img, fTexCoord);
}