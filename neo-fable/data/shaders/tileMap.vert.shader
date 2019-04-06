#version 330 core

layout(location = 0) in vec2 iPos;
layout(location = 1) in vec3 iColor;

out vec4 fColor;

uniform mat4 translation;
uniform mat4 proj;
uniform vec2 offsets[864]; // 36*24 or 3:2 aspect ratio

void main() {
	fColor = vec4(iColor, 1.0f);
	gl_Position = proj * translation * vec4(iPos + (offsets[gl_InstanceID]), 1.0f, 1.0f);
}