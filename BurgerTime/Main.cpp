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
#include "TextComponent.h"
#include "FPSComponent.h"
#include "MoveComponent.h"
#include "RotateComponent.h"
#include "Exercise1Component.h"
#include "Exercise2Component.h"
#include "InputManager.h"
#include "Command.h"
#include "MoveLeft.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"
#include "PlayerHealthInfo.h"
#include "PlayerScoreInfo.h"
//#include <steam_api.h>
#include <iostream>
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

	// Burger guys rotating
	// Make a point for the burger guys to rotate around (otherwise it would rotate around world 0, 0
	/* auto burgerGuysCenterPoint = new dae::GameObject();
	burgerGuysCenterPoint->SetWorldPosition(200, 200);
	scene.Add(burgerGuysCenterPoint);

	auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("burgerGuy.tga");
	burgerGuy->SetParent(burgerGuysCenterPoint);
	burgerGuy->SetLocalPosition({ 30.f, 30.f, 0.f });
	burgerGuy->AddComponent<dae::RotateComponent>(0.1f);
	scene.Add(burgerGuy);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga");
	burgerGuy2->SetParent(burgerGuy);
	burgerGuy2->SetLocalPosition({ 30.f, 30.f, 0.f });
	burgerGuy2->AddComponent<dae::RotateComponent>(-.5f);
	scene.Add(burgerGuy2);*/

	// Exercise with thrashing
	/*auto imGuiTest = new dae::GameObject();
	imGuiTest->AddComponent<dae::Exercise1Component>();
	imGuiTest->AddComponent<dae::Exercise2Component>();
	scene.Add(imGuiTest);*/

	// Command exercise
	/*auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("burgerGuy.tga");
	burgerGuy->SetLocalPosition({ 200.f, 30.f, 0.f });
	burgerGuy->SetSpeed(0.1f);
	scene.Add(burgerGuy);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga");
	burgerGuy2->SetLocalPosition({ 400.f, 30.f, 0.f });
	burgerGuy2->SetSpeed(0.2f);
	scene.Add(burgerGuy2);*/

	auto smallerFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);

	auto playerHeathInfoP1 = new dae::GameObject();
	playerHeathInfoP1->AddComponent<dae::TextComponent>();
	playerHeathInfoP1->AddComponent<dae::PlayerHealthInfo>();
	playerHeathInfoP1->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	playerHeathInfoP1->SetWorldPosition(10, 100);
	scene.Add(playerHeathInfoP1);

	auto playerScoreInfoP1 = new dae::GameObject();
	playerScoreInfoP1->AddComponent<dae::TextComponent>();
	playerScoreInfoP1->AddComponent<dae::PlayerScoreInfo>();
	playerScoreInfoP1->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	playerScoreInfoP1->SetWorldPosition(10, 125);
	scene.Add(playerScoreInfoP1);

	auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("burgerGuy.tga");
	burgerGuy->SetLocalPosition({ 200.f, 30.f, 0.f });
	burgerGuy->SetSpeed(0.1f);
	burgerGuy->AddComponent<dae::HealthComponent>();
	burgerGuy->GetComponent<dae::HealthComponent>()->AddObserver(*playerHeathInfoP1->GetComponent<dae::PlayerHealthInfo>());
	burgerGuy->AddComponent<dae::ScoreComponent>();
	burgerGuy->GetComponent<dae::ScoreComponent>()->AddObserver(*playerScoreInfoP1->GetComponent<dae::PlayerScoreInfo>());
	//burgerGuy->GetComponent<dae::ScoreComponent>()->AddObserver(*g_SteamAchievements);
	scene.Add(burgerGuy);

	auto playerHeathInfoP2 = new dae::GameObject();
	playerHeathInfoP2->AddComponent<dae::TextComponent>();
	playerHeathInfoP2->AddComponent<dae::PlayerHealthInfo>();
	playerHeathInfoP2->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	playerHeathInfoP2->SetWorldPosition(10, 150);
	scene.Add(playerHeathInfoP2);

	auto playerScoreInfoP2 = new dae::GameObject();
	playerScoreInfoP2->AddComponent<dae::TextComponent>();
	playerScoreInfoP2->AddComponent<dae::PlayerScoreInfo>();
	playerScoreInfoP2->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	playerScoreInfoP2->SetWorldPosition(10, 175);
	scene.Add(playerScoreInfoP2);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga");
	burgerGuy2->SetLocalPosition({ 400.f, 30.f, 0.f });
	burgerGuy2->SetSpeed(0.2f);
	burgerGuy2->AddComponent<dae::HealthComponent>();
	burgerGuy2->GetComponent<dae::HealthComponent>()->AddObserver(*playerHeathInfoP2->GetComponent<dae::PlayerHealthInfo>());
	burgerGuy2->AddComponent<dae::ScoreComponent>();
	burgerGuy2->GetComponent<dae::ScoreComponent>()->AddObserver(*playerScoreInfoP2->GetComponent<dae::PlayerScoreInfo>());
	//burgerGuy2->GetComponent<dae::ScoreComponent>()->AddObserver(*g_SteamAchievements);
	scene.Add(burgerGuy2);

	auto& input = dae::InputManager::GetInstance();
	input.AddPlayer1(*burgerGuy);
	input.AddPlayer2(*burgerGuy2);
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