#include "Engine.h"

#include "Renderer.h"
#include "GLFW/glfw3.h"
#include "GameTime.h"
#include "../hierarchy/SceneManager.h"


void error_callback(int error, const char* description)
{
	spdlog::error("Error: {}\n", description);
}

Engine::Engine() 
	: m_pRenderer(nullptr)
	, m_pGameTime(nullptr)
	, m_pSceneManager(nullptr)
{
	spdlog::set_level(spdlog::level::debug);

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		spdlog::critical("Failed to Init glfw3");

	m_pRenderer = std::make_unique<Renderer>();
	m_pGameTime = std::make_unique<GameTime>();
	m_pSceneManager = std::make_unique<SceneManager>();

	glfwSetKeyCallback(m_pRenderer->GetWindow(), InputCallBack);
}

Engine::~Engine()
{
	m_pSceneManager.reset();
	m_pRenderer.reset();
	m_pGameTime.reset();

	glfwTerminate();
}

void Engine::Run()
{
	while (!glfwWindowShouldClose(m_pRenderer->GetWindow()))
	{
		m_pGameTime->Update();



		// draw
		
		m_pRenderer->Update();
	}
}

void Engine::InputCallBack(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
}