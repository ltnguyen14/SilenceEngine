#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 inTextureCoord;
layout(location = 2) in vec4 in_color;

uniform mat4 projViewMatrix;
uniform mat4 modelMatrix;

out vec4 out_color;
out vec2 passTextureCoord;

void main() {
	gl_Position = projViewMatrix * modelMatrix * position;
	out_color = in_color;
	passTextureCoord = inTextureCoord;
};


#shader fragment
#version 330 core

out vec4 outColour;
in vec4 out_color;
in vec2 passTextureCoord;

uniform sampler2D texSampler;

void main() {
	outColour = vec4(1, 0.5f, 0.5f, 1.0f);
	outColour = texture(texSampler, passTextureCoord);
};