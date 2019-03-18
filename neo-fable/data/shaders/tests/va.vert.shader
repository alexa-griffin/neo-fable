#version 330 core

layout(location = 0)in vec2 iPos;
layout(location = 1)in vec3 iColor;
layout(location = 2)in vec2 iTexCoord;

out vec3 fColor;
out vec2 fTexCoord;

uniform mat4 transform;
uniform mat4 projection;

void main() {
	fColor = iColor;
	fTexCoord = iTexCoord;
	gl_Position = transform * projection * vec4(iPos, 0.0, 1.0);
}