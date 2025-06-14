#include <stdexcept>
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Minigin.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <chrono>
#include "TextObject.h"
#include <thread>
#include "Command.h"
#include <memory>
#include <steam_api.h>

SDL_Window* g_window{};

using namespace std::chrono;

long long dae::Minigin::DELTATIME{};

void PrintSDLVersion()
{
	SDL_version version{};
	SDL_VERSION(&version);
	printf("We compiled against SDL version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	SDL_GetVersion(&version);
	printf("We are linking against SDL version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

	SDL_IMAGE_VERSION(&version);
	printf("We compiled against SDL_image version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	version = *IMG_Linked_Version();
	printf("We are linking against SDL_image version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

	SDL_TTF_VERSION(&version)
	printf("We compiled against SDL_ttf version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	version = *TTF_Linked_Version();
	printf("We are linking against SDL_ttf version %u.%u.%u.\n",
		version.major, version.minor, version.patch);
}

dae::Minigin::Minigin(const std::string &dataPath)
{
	PrintSDLVersion();
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	g_window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		480,
		475,
		SDL_WINDOW_OPENGL
	);
	if (g_window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(g_window);

	ResourceManager::GetInstance().Init(dataPath);
}

dae::Minigin::~Minigin()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run(const std::function<void()>& load)
{
	load();

	auto& renderer = Renderer::GetInstance();
	auto& sceneManager = SceneManager::GetInstance();
	auto& input = InputManager::GetInstance();

	input.BeginPlay();

	// todo: this update loop could use some work.
	bool doContinue = true;
	auto lastTime = high_resolution_clock::now();

	// Tried taking refresh rate but it does not work
	/*HDC screen = GetDC(nullptr);
	std::chrono::milliseconds msPerFrame{ GetDeviceCaps(screen, VREFRESH) };*/
	std::chrono::milliseconds msPerFrame{ 6 };

	m_CurrentTime = high_resolution_clock::now();

	while (doContinue)
	{
		//const auto currentTime = high_resolution_clock::now();
		//const float deltaTime = duration<float>(currentTime - lastTime).count();
		//lastTime = currentTime;

		UpdateDeltaTime();

		doContinue = input.ProcessInput();
		sceneManager.Update();
		renderer.Render();
		sceneManager.LateUpdate();

		SteamAPI_RunCallbacks();

		const auto sleepTime = m_CurrentTime + milliseconds(msPerFrame) - high_resolution_clock::now();
		std::this_thread::sleep_for(sleepTime);
	}
}

void dae::Minigin::UpdateDeltaTime()
{
	high_resolution_clock::time_point tempTime = high_resolution_clock::now();

    DELTATIME = duration_cast<milliseconds>(tempTime - m_CurrentTime).count();
    m_CurrentTime = std::move(tempTime);
}
