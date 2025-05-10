#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif


#include <memory>
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "./Components/TextComponent.h"
#include "./Components/FPSComponent.h"
#include "./Components/MoveComponent.h"
#include "./Components/RotateComponent.h"
#include "./Components/Exercise1Component.h"
#include "./Components/Exercise2Component.h"
#include "InputManager.h"
#include "Command.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"
#include "PlayerHealthInfo.h"
#include "PlayerScoreInfo.h"
#include "MoveCommand.h"
//#include <steam_api.h>
#include <iostream>
#include <glm.hpp>
#include "ServiceLocator.h"
#include "SoundSystem.h"
#include "SDLSoundSystem.h"
#include "./Commands/PlaySoundCommand.h"
#include "./Commands/PlayMusicCommand.h"
#include "./Commands/PauseMusicCommand.h"
#include "CollisionComponent.h"
//#include "CSteamAchievements.h"

// Defining our achievements
//enum EAchievements
//{
//	ACH_WIN_ONE_GAME = 0,
//	ACH_WIN_100_GAMES = 1,
//	ACH_TRAVEL_FAR_ACCUM = 2,
//	ACH_TRAVEL_FAR_SINGLE = 3,
//};

// Achievement array which will hold data about the achievements and their state
//dae::Achievement_t g_Achievements[] =
//{
//	_ACH_ID(ACH_WIN_ONE_GAME, "Winner"),
//	_ACH_ID(ACH_WIN_100_GAMES, "Champion"),
//	_ACH_ID(ACH_TRAVEL_FAR_ACCUM, "Interstellar"),
//	_ACH_ID(ACH_TRAVEL_FAR_SINGLE, "Orbiter"),
//};

// Global access to Achievements object
//static dae::CSteamAchievements* g_SteamAchievements = NULL;

void load()
{
	auto testSound = std::make_unique<dae::SDLSoundSystem>();
	dae::ServiceLocator::RegisterSoundSystem(std::move(testSound));

	dae::ServiceLocator::GetSoundSystem().AddSound(dae::make_sdbm_hash("Enter"), "../Data/EnterEffect.wav");
	dae::ServiceLocator::GetSoundSystem().AddMusic(dae::make_sdbm_hash("MainMusic"), "../Data/MusicChoosePlayerScreen.mp3");
	dae::ServiceLocator::GetSoundSystem().ChangeMasterVolume(100);

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	dae::GameObject* go = new dae::GameObject();
	go->SetTexture("background.tga");
	scene.Add(go);

	go = new dae::GameObject();
	go->SetTexture("logo.tga");
	go->SetWorldPosition(216, 180);
	scene.Add(go);

	//W1 Fps component
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	dae::GameObject* title = new dae::GameObject();
	title->AddComponent<dae::TextComponent>();
	dae::TextComponent* test = title->GetComponent<dae::TextComponent>();
	test->SetText("Programming 4 Assignment");
	test->SetFont(font);
	title->SetWorldPosition(180, 20);
	scene.Add(title);

	auto fps = new dae::GameObject();
	fps->AddComponent<dae::TextComponent>();
	fps->AddComponent<dae::FPSComponent>(*fps->GetComponent<dae::TextComponent>());
	fps->GetComponent<dae::TextComponent>()->SetFont(font);
	fps->SetWorldPosition(10, 20);
	scene.Add(fps);

	/*// Burger guys rotating
	// Make a point for the burger guys to rotate around (otherwise it would rotate around world 0, 0
	auto burgerGuysCenterPoint = new dae::GameObject();
	burgerGuysCenterPoint->SetWorldPosition(200, 200);
	scene.Add(burgerGuysCenterPoint);

	auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("burgerGuy.tga");
	burgerGuy->SetParent(burgerGuysCenterPoint);
	burgerGuy->SetLocalPosition({ 30.f, 30.f, 0.f });
	//burgerGuy->AddComponent<dae::RotateComponent>(0.1f);
	scene.Add(burgerGuy);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga");
	burgerGuy2->SetParent(burgerGuy);
	burgerGuy2->SetLocalPosition({ 30.f, 30.f, 0.f });
	//burgerGuy2->AddComponent<dae::RotateComponent>(-.5f);
	scene.Add(burgerGuy2);

	// Exercise with thrashing
	/*auto imGuiTest = new dae::GameObject();
	imGuiTest->AddComponent<dae::Exercise1Component>();
	imGuiTest->AddComponent<dae::Exercise2Component>();
	scene.Add(imGuiTest);*/

	// Command exercise
	auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("BurgerTime.tga", 16.f, 16.f);
	burgerGuy->SetLocalPosition({ 200.f, 30.f, 0.f });
	burgerGuy->SetSpeed(0.1f);
	burgerGuy->SetCanCollide(true);
	burgerGuy->SetScaling(2.f, 2.f, 2.f);
	burgerGuy->AddTag(dae::make_sdbm_hash("Player1"));
	burgerGuy->AddComponent<dae::CollisionComponent>();
	scene.Add(burgerGuy);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga", 16.f, 16.f);
	burgerGuy2->SetLocalPosition({ 400.f, 30.f, 0.f });
	burgerGuy2->SetSpeed(0.2f);
	burgerGuy2->SetCanCollide(true);
	burgerGuy2->AddComponent<dae::CollisionComponent>();
	scene.Add(burgerGuy2);

	auto ladder = new dae::GameObject();
	ladder->SetTexture("Ladder.tga");
	ladder->SetLocalPosition({ 100.f, 55.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(ladder);

	auto smallerFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 17);

	//auto playerHeathInfoP1 = new dae::GameObject();
	//playerHeathInfoP1->AddComponent<dae::TextComponent>();
	//playerHeathInfoP1->AddComponent<dae::PlayerHealthInfo>();
	//playerHeathInfoP1->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	//playerHeathInfoP1->SetWorldPosition(10, 100);
	//scene.Add(playerHeathInfoP1);

	//auto playerScoreInfoP1 = new dae::GameObject();
	//playerScoreInfoP1->AddComponent<dae::TextComponent>();
	//playerScoreInfoP1->AddComponent<dae::PlayerScoreInfo>();
	//playerScoreInfoP1->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	//playerScoreInfoP1->SetWorldPosition(10, 125);
	//scene.Add(playerScoreInfoP1);

	//auto burgerGuy = new dae::GameObject();
	//burgerGuy->SetTexture("burgerGuy.tga");
	//burgerGuy->SetLocalPosition({ 200.f, 30.f, 0.f });
	//burgerGuy->SetSpeed(0.1f);
	//burgerGuy->AddComponent<dae::HealthComponent>();
	//burgerGuy->GetComponent<dae::HealthComponent>()->AddObserver(*playerHeathInfoP1->GetComponent<dae::PlayerHealthInfo>());
	//burgerGuy->AddComponent<dae::ScoreComponent>();
	//burgerGuy->GetComponent<dae::ScoreComponent>()->AddObserver(*playerScoreInfoP1->GetComponent<dae::PlayerScoreInfo>());
	////burgerGuy->GetComponent<dae::ScoreComponent>()->AddObserver(*g_SteamAchievements);
	//scene.Add(burgerGuy);

	//auto playerHeathInfoP2 = new dae::GameObject();
	//playerHeathInfoP2->AddComponent<dae::TextComponent>();
	//playerHeathInfoP2->AddComponent<dae::PlayerHealthInfo>();
	//playerHeathInfoP2->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	//playerHeathInfoP2->SetWorldPosition(10, 150);
	//scene.Add(playerHeathInfoP2);

	//auto playerScoreInfoP2 = new dae::GameObject();
	//playerScoreInfoP2->AddComponent<dae::TextComponent>();
	//playerScoreInfoP2->AddComponent<dae::PlayerScoreInfo>();
	//playerScoreInfoP2->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	//playerScoreInfoP2->SetWorldPosition(10, 175);
	//scene.Add(playerScoreInfoP2);

	//auto burgerGuy2 = new dae::GameObject();
	//burgerGuy2->SetTexture("burgerGuy.tga");
	//burgerGuy2->SetLocalPosition({ 400.f, 30.f, 0.f });
	//burgerGuy2->SetSpeed(0.2f);
	//burgerGuy2->AddComponent<dae::HealthComponent>();
	//burgerGuy2->GetComponent<dae::HealthComponent>()->AddObserver(*playerHeathInfoP2->GetComponent<dae::PlayerHealthInfo>());
	//burgerGuy2->AddComponent<dae::ScoreComponent>();
	//burgerGuy2->GetComponent<dae::ScoreComponent>()->AddObserver(*playerScoreInfoP2->GetComponent<dae::PlayerScoreInfo>());
	////burgerGuy2->GetComponent<dae::ScoreComponent>()->AddObserver(*g_SteamAchievements);
	//scene.Add(burgerGuy2);

	auto instructions = new dae::GameObject();
	instructions->SetLocalPosition(glm::vec3{ 10.f, 150.f, 0.f });
	instructions->AddComponent<dae::TextComponent>();
	instructions->GetComponent<dae::TextComponent>()->SetText("Press Q to play a sound effect and E to start the music! Press P to pause/unpause the music!");
	instructions->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	scene.Add(instructions);

	auto moveLeft = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ 1.f, 0.f, 0.f });
	//auto moveUp = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ 0.f, -1.f, 0.f });
	//auto moveDown = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ 0.f, 1.f, 0.f });

	auto moveLeft2 = std::make_unique<dae::MoveCommand>(*burgerGuy2, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight2 = std::make_unique<dae::MoveCommand>(*burgerGuy2, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp2 = std::make_unique<dae::MoveCommand>(*burgerGuy2, glm::vec3{ 0.f, -1.f, 0.f });
	auto moveDown2 = std::make_unique<dae::MoveCommand>(*burgerGuy2, glm::vec3{ 0.f, 1.f, 0.f });

	auto playEnterSoundEffect = std::make_unique<dae::PlaySoundCommand>(*burgerGuy, dae::make_sdbm_hash("Enter"));
	auto playMusic = std::make_unique<dae::PlayMusicCommand>(*burgerGuy, dae::make_sdbm_hash("MainMusic"));
	auto pauseMusic = std::make_unique<dae::PauseMusicCommand>(*burgerGuy);

	auto& input = dae::InputManager::GetInstance();
	input.BindInputKeyboard(SDL_SCANCODE_A, std::move(moveLeft));
	input.BindInputKeyboard(SDL_SCANCODE_D, std::move(moveRight));
	//input.BindInputKeyboard(SDLK_w, std::move(moveUp));
	//input.BindInputKeyboard(SDLK_s, std::move(moveDown));
	input.BindInputKeyboard(SDL_SCANCODE_Q, std::move(playEnterSoundEffect));
	input.BindInputKeyboard(SDL_SCANCODE_E, std::move(playMusic));
	input.BindInputKeyboard(SDL_SCANCODE_P, std::move(pauseMusic));

	input.AddController();
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_LEFT, true, std::move(moveLeft2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_RIGHT, true, std::move(moveRight2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_UP, true, std::move(moveUp2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_DOWN, true, std::move(moveDown2));
}

int main(int, char* []) {
	/*if (!SteamAPI_Init())
	//{
		//std::cerr << "Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed)." << std::endl;
		//return 1;
	//}
	//else
		//std::cout << "Successfully initialized steam." << std::endl;

	//g_SteamAchievements = new dae::CSteamAchievements(g_Achievements, 4);*/

	dae::Minigin engine("../Data/");
	engine.Run(load);

	//SteamAPI_Shutdown();
	// Delete the SteamAchievements object
	/*if (g_SteamAchievements)
		delete g_SteamAchievements;*/

	return 0;
}