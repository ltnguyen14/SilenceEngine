#pragma once
#include "../../Tools/Shader/Shader.h"
#include "../Entities/GuiEntity.h"

class GUIRenderer {
public:
	GUIRenderer();
	~GUIRenderer();

	void renderGUI(GuiEntity& gui);

private:
	Shader m_shader;
};