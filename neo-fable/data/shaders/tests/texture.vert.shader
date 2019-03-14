#version 330 core

in vec2 iPos;
in vec3 iColor;
in vec2 iTexCoord;

out vec3 fColor;
out vec2 fTexCoord;

uniform mat4 translation;
uniform mat4 proj;


void main() {
	fColor = iColor;
	fTexCoord = iTexCoord;
	gl_Position = translation * proj * vec4(iPos, 0.0, 1.0);
}