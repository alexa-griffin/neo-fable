#version core 330

uniform mat4 transform;
uniform mat4 orthoProj;

void main() {
	gl_Position = translation * proj * vec4(iPos, 0.0, 1.0);
}