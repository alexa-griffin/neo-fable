#version 330 core

layout(location = 0) in vec2 iPos;
layout(location = 1) in vec3 iColor;

out vec3 fColor;

uniform mat4 translation;
uniform mat4 proj;

void main() {
	fColor = iColor;
	gl_Position = translation * proj * vec4(iPos, 1.0, 1.0);
}