#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
//layout(location = 1) in vec2 textureCoord;

//uniform mat4 modelMatrix;
//uniform mat4 projViewMatrix;

//out vec2 passTextureCoord;
out vec4 passColor;

void main() {
	gl_Position = position;
	//gl_Position = projViewMatrix * modelMatrix * position;
	//passTextureCoord = textureCoord;
	passColor = color;
};


#shader fragment
#version 330 core

out vec4 outColour;
//in vec2 passTextureCoord;
in vec4 passColor;

//uniform sampler2D guiTexture;
//uniform vec4 colour;

void main() {
	//outColour = vec4(colour.r, colour.g, colour.b, texture(guiTexture, passTextureCoord).a);
	outColour = passColor;
};