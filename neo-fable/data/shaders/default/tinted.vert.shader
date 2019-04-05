#version 330 core

layout(location = 0) in vec2 iPos;
layout(location = 1) in vec3 iColor;

out vec4 fColor;

uniform mat4 translation;
uniform mat4 proj;

void main() {
	fColor = vec4(iColor, 1.0f);
	gl_Position = proj * translation * vec4(iPos, 1.0f, 1.0f);
}