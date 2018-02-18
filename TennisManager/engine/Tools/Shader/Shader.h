#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
#include <unordered_map>

#include "../math/glm.h"


struct ShaderProgramSource {
	std::string VertexShader;
	std::string FragmentShader;
};

class Shader {
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	mutable std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	//Set uniforms
	void SetUniformMat4(const std::string& name, const glm::mat4 matrix) const;
	void SetUniform4f(const std::string& name, const glm::vec4 value) const;
	void SetUniform2f(const std::string& name, float v0, float v1) const;
	unsigned int GetUniformLocation(const std::string& name) const;


private:
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(const std::string& filepath);
};