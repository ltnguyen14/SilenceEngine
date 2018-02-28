#pragma once
#include <string>

#include "Window/Window.h"
#include "Renderers/GUIRenderer.h"
#include "Renderers/TextRenderer.h"
#include "Renderers/ChunkRenderer.h"
#include "../ResManager/ResManager.h"
#include "Entities/Player/Player.h"
#include "Entities/Camera.h"

class Graphics {
public:
	Graphics(Window* window, ResManager& resManager);

	void clearWindow() { m_window->clear(); };
	void updateWindow() { m_window->update(); };

	void drawquad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName);
	void drawText(glm::vec2 position, std::string content, float width, glm::vec4 color);

	void addChunk(glm::vec3 position, glm::vec3 scale, const std::string& material);
	void renderChunks(Camera* camera);

	Player* createPlayer();
	Camera* getCamera() { return m_camera; };

private:
	Window* m_window;
	GUIRenderer m_guiRenderer;
	TextRenderer m_textRenderer;
	ResManager m_resManager;
	ChunkRenderer m_chunkRenderer;
	Player * m_player = new Player(m_window);
	Camera * m_camera = new Camera(m_window);
};
