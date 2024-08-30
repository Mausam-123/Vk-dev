#version 450

layout(location = 0) out vec3 fragColors;

vec2 position[3] = vec2[](vec2(0.0f, -0.5f),
			  vec2(0.5f, 0.5f),
			  vec2(-0.5f, 0.5f));
							
vec3 colors[3] = vec3[](vec3(1.0f, 0.0f, 0.0f),
			vec3(0.0f, 1.0f, 0.0f),
			vec3(0.0f, 0.0f, 1.0f));

void main(){
	gl_Position = vec4(position[gl_VertexIndex], 0.0f, 1.0f);
	fragColors = colors[gl_VertexIndex];
}