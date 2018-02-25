#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 inTextureCoord;

uniform mat4 projViewMatrix;
uniform mat4 modelMatrix;

out vec4 out_color;
out vec2 passTextureCoord;

void main() {
	gl_Position = projViewMatrix * modelMatrix * position;
	passTextureCoord = inTextureCoord;
};


#shader fragment
#version 330 core

out vec4 outColour;
in vec2 passTextureCoord;

uniform sampler2D texSampler;

void main() {
	outColour = texture(texSampler, passTextureCoord);
	outColour = vec4(1.0f, 0.0f, 0.0f, 1.0f);
};