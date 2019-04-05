#version 330 core

layout(location = 0) in vec2 iPos;
layout(location = 1) in vec3 iColor;
layout(location = 2) in vec2 iTexCoord;

out vec4 fColor;
out vec2 fTexCoord;

uniform mat4 translation;
uniform mat4 proj;

void main() {
	fColor = vec4(iColor, 1.0f);
	fTexCoord = iTexCoord;
	gl_Position = proj * translation * vec4(iPos, 1.0, 1.0);
}