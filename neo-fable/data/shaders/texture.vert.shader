#version 330 core

in vec2 iPos;
in vec3 iColor;
in vec2 iTexCoord;

out vec3 fColor;
out vec2 fTexCoord;

void main() {
	fColor = iColor;
	fTexCoord = iTexCoord;
	gl_Position = vec4(iPos, 0.0, 1.0);
}