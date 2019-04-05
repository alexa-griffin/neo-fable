#version 330 core

layout(location = 0) in vec2 iPos;
layout(location = 2) in vec2 iTexCoord;

out vec2 fTexCoord;

uniform mat4 translation;
uniform mat4 proj;

void main() {
	fTexCoord = iTexCoord;
	gl_Position = proj * translation * vec4(iPos, 1.0, 1.0);
}