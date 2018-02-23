#shader vertex
#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textureCoords;

uniform mat4 modelMatrix;
uniform mat4 projViewMatrix;

out vec2 pass_textureCoords;

void main(void) {

	gl_Position = projViewMatrix * modelMatrix * position;
	pass_textureCoords = textureCoords;
}

#shader fragment
#version 330

in vec2 pass_textureCoords;
out vec4 out_colour;

uniform vec4 colour;
uniform sampler2D fontAtlas;

void main(void) {
	out_colour = vec4(colour.r, colour.g, colour.b, texture(fontAtlas, pass_textureCoords).a);
	//out_colour = vec4(0, 1, 0, 1);
}
