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
#include "MoveOnLadderCommand.h"
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
#include "Utils.h"
#include "./Components/MoveDownLadderComponent.h"
#include "./Components/PlayerCollisionComponent.h"
#include "BurgerPartsCollisionComponent.h"
#include "FoodFallingComponent.h"
#include "FallingCondition.h"
#include "FallingState.h"
#include "FSMComponent.h"
#include "IdleState.h"
#include "ScoreObserver.h"
#include "BurgerCollisionComponent.h"
#include "ScoreDisplayComponent.h"

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

	/*dae::GameObject* go = new dae::GameObject();
	go->SetTexture("background.tga");
	scene.Add(go);*/

	/*go = new dae::GameObject();
	go->SetTexture("logo.tga");
	go->SetWorldPosition(216, 180);
	scene.Add(go);*/

	//W1 Fps component
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//dae::GameObject* title = new dae::GameObject();
	//title->AddComponent<dae::TextComponent>();
	//dae::TextComponent* test = title->GetComponent<dae::TextComponent>();
	//test->SetText("Programming 4 Assignment");
	//test->SetFont(font);
	//title->SetWorldPosition(180, 20);
	//scene.Add(title);

	/*auto fps = new dae::GameObject();
	fps->AddComponent<dae::TextComponent>();
	fps->AddComponent<dae::FPSComponent>(*fps->GetComponent<dae::TextComponent>());
	fps->GetComponent<dae::TextComponent>()->SetFont(font);
	fps->SetWorldPosition(10, 20);
	scene.Add(fps);*/

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

	auto ladder = new dae::GameObject();
	ladder->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder->SetSourceRectTexture(0, 6, 10, 34);
	ladder->SetLocalPosition({ 100.f, 50.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(ladder);

	auto ladder3 = new dae::GameObject();
	ladder3->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder3->SetSourceRectTexture(0, 6, 10, 34);
	ladder3->SetLocalPosition({ 100.f, 115.f, 0.f });
	ladder3->SetCanCollide(true);
	ladder3->SetScaling(2.f, 2.f, 2.f);
	ladder3->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder3->AddComponent<dae::CollisionComponent>();
	scene.Add(ladder3);

	auto ladderPlatform1 = new dae::GameObject();
	ladderPlatform1->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform1->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform1->SetLocalPosition({ 94.f, 53.f, 0.f });
	ladderPlatform1->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform1->AddTag(dae::make_sdbm_hash("Platform"));
	//ladderPlatform1->SetCanCollide(true);
	//ladderPlatform1->AddComponent<dae::CollisionComponent>();
	scene.Add(ladderPlatform1);

	auto burgerPlatform1 = new dae::GameObject();
	burgerPlatform1->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform1->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform1->SetLocalPosition({ 126.f, 53.f, 0.f });
	burgerPlatform1->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform1->SetCanCollide(true);
	scene.Add(burgerPlatform1);

	auto ladderPlatform2 = new dae::GameObject();
	ladderPlatform2->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform2->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform2->SetLocalPosition({ 190.f, 53.f, 0.f });
	ladderPlatform2->SetScaling(2.f, 2.f, 2.f);
	scene.Add(ladderPlatform2);

	//auto ladder2 = new dae::GameObject();
	//ladder2->SetTexture("BackgroundSheet.tga", 10, 34);
	//ladder2->SetSourceRectTexture(0, 6, 10, 34);
	//ladder2->SetLocalPosition({ 148.f, 115.f, 0.f });
	//ladder2->SetCanCollide(true);
	//ladder2->SetScaling(2.f, 2.f, 2.f);
	//ladder2->AddTag(dae::make_sdbm_hash("Ladder"));
	//ladder2->AddComponent<dae::CollisionComponent>();
	//scene.Add(ladder2);

	auto burgerPlatform2 = new dae::GameObject();
	burgerPlatform2->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform2->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform2->SetLocalPosition({ 126.f, 118.f, 0.f });
	burgerPlatform2->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform2->SetCanCollide(true);
	burgerPlatform2->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform2->AddComponent<dae::CollisionComponent>();
	scene.Add(burgerPlatform2);

	auto lol = new dae::GameObject();
	lol->SetTexture("BackgroundSheet.tga", 32, 3);
	lol->SetSourceRectTexture(0, 0, 32, 3);
	lol->SetLocalPosition({ 126.f, 185.f, 0.f });
	lol->SetScaling(2.f, 2.f, 2.f);
	lol->SetCanCollide(true);
	lol->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	lol->AddComponent<dae::CollisionComponent>();
	scene.Add(lol);

	auto burgerPlatform4 = new dae::GameObject();
	burgerPlatform4->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform4->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform4->SetLocalPosition({ 126.f, 250.f, 0.f });
	burgerPlatform4->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform4->SetCanCollide(true);
	burgerPlatform4->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform4->AddComponent<dae::CollisionComponent>();
	scene.Add(burgerPlatform4);

	auto ladderPlatform3 = new dae::GameObject();
	ladderPlatform3->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform3->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform3->SetLocalPosition({ 94.f, 118.f, 0.f });
	ladderPlatform3->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform3->AddTag(dae::make_sdbm_hash("Platform"));
	scene.Add(ladderPlatform3);

	auto ladderPlatform5 = new dae::GameObject();
	ladderPlatform5->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform5->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform5->SetLocalPosition({ 94.f, 185.f, 0.f });
	ladderPlatform5->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform5->AddTag(dae::make_sdbm_hash("Platform"));
	scene.Add(ladderPlatform5);

	//auto ladderPlatform2 = new dae::GameObject();
	//ladderPlatform2->SetTexture("BackgroundSheet.tga", 16, 3);
	//ladderPlatform2->SetSourceRectTexture(0, 3, 16, 3);
	//ladderPlatform2->SetLocalPosition({ 190.f, 53.f, 0.f });
	//ladderPlatform2->SetScaling(2.f, 2.f, 2.f);
	//scene.Add(ladderPlatform2);

	auto ladderPlatform4 = new dae::GameObject();
	ladderPlatform4->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform4->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform4->SetLocalPosition({ 190.f, 118.f, 0.f });
	ladderPlatform4->SetScaling(2.f, 2.f, 2.f);
	scene.Add(ladderPlatform4);

	auto plate1 = new dae::GameObject();
	plate1->SetTexture("BackgroundSheet.tga", 38, 6);
	plate1->SetSourceRectTexture(0, 40, 38, 6);
	plate1->SetLocalPosition({ 120.f, 400.f, 0.f });
	plate1->SetScaling(2.f, 2.f, 2.f);
	plate1->SetCanCollide(true);
	plate1->AddTag(dae::make_sdbm_hash("Plate"));
	plate1->AddComponent<dae::CollisionComponent>();
	scene.Add(plate1);

	auto pScoreObserver = std::make_unique<dae::ScoreObserver>();
	auto scoreDisplay = new dae::GameObject();
	scoreDisplay->AddComponent<dae::ScoreDisplayComponent>();
	scene.Add(scoreDisplay);

	auto burgerBun1 = new dae::GameObject();
	burgerBun1->SetLocalPosition({ 127.f, 43.f, 0.f });
	burgerBun1->SetShouldRender(false);
	burgerBun1->SetCanCollide(true);
	burgerBun1->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBun1->SetScaling(2.f, 2.f, 2.f);

	auto burgerBun1Part1 = new dae::GameObject();
	burgerBun1Part1->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part1->SetSourceRectTexture(112, 49, 8, 7);
	burgerBun1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	burgerBun1Part1->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part1->SetCanCollide(true);
	burgerBun1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	burgerBun1Part1->SetParent(burgerBun1);
	burgerBun1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(burgerBun1Part1);

	auto burgerBun1Part2 = new dae::GameObject();
	burgerBun1Part2->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part2->SetSourceRectTexture(120, 49, 8, 7);
	burgerBun1Part2->SetLocalPosition({ 16.f, 0.f, 0.f });
	burgerBun1Part2->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part2->SetCanCollide(true);
	burgerBun1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	burgerBun1Part2->SetParent(burgerBun1);
	burgerBun1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(burgerBun1Part2);

	auto burgerBun1Part3 = new dae::GameObject();
	burgerBun1Part3->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part3->SetSourceRectTexture(128, 49, 8, 7);
	burgerBun1Part3->SetLocalPosition({ 32.f, 0.f, 0.f });
	burgerBun1Part3->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part3->SetCanCollide(true);
	burgerBun1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	burgerBun1Part3->SetParent(burgerBun1);
	burgerBun1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(burgerBun1Part3);

	auto burgerBun1Part4 = new dae::GameObject();
	burgerBun1Part4->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part4->SetSourceRectTexture(136, 49, 8, 7);
	burgerBun1Part4->SetLocalPosition({ 48.f, 0.f, 0.f });
	burgerBun1Part4->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part4->SetCanCollide(true);
	burgerBun1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	burgerBun1Part4->SetParent(burgerBun1);
	burgerBun1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(burgerBun1Part4);

	//burgerBun1->AddComponent<dae::FSMComponent>();
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddState<dae::IdleState>(dae::make_sdbm_hash("BurgerIdleState"));
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddState<dae::FallingState>(dae::make_sdbm_hash("BurgerFallingState"), 0.2f);
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddCondition<dae::FallingCondition>(dae::make_sdbm_hash("BurgerToFallingCondition"), *burgerBun1, true);
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddCondition<dae::FallingCondition>(dae::make_sdbm_hash("BurgerFromFallingCondition"), *burgerBun1, false);
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddTransition(dae::make_sdbm_hash("BurgerIdleState"), dae::make_sdbm_hash("BurgerFallingState"), dae::make_sdbm_hash("BurgerToFallingCondition"));
	//burgerBun1->GetComponent<dae::FSMComponent>()->AddTransition(dae::make_sdbm_hash("BurgerFallingState"), dae::make_sdbm_hash("BurgerIdleState"), dae::make_sdbm_hash("BurgerFromFallingCondition"));
	burgerBun1->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBun1->AddComponent<dae::BurgerCollisionComponent>();
	burgerBun1->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*scoreDisplay->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(burgerBun1);

	/*auto lettuce1 = new dae::GameObject();
	lettuce1->SetLocalPosition({ 127.f, 108.f, 0.f });
	lettuce1->SetShouldRender(false);
	lettuce1->SetCanCollide(false);

	auto lettuce1Part1 = new dae::GameObject();
	lettuce1Part1->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part1->SetSourceRectTexture(112, 89, 8, 7);
	lettuce1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	lettuce1Part1->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part1->SetCanCollide(true);
	lettuce1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	lettuce1Part1->SetParent(lettuce1);
	lettuce1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(lettuce1Part1);

	auto lettuce1Part2 = new dae::GameObject();
	lettuce1Part2->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part2->SetSourceRectTexture(120, 89, 8, 7);
	lettuce1Part2->SetLocalPosition({ 16.f, 0.f, 0.f });
	lettuce1Part2->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part2->SetCanCollide(true);
	lettuce1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	lettuce1Part2->SetParent(lettuce1);
	lettuce1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(lettuce1Part2);

	auto lettuce1Part3 = new dae::GameObject();
	lettuce1Part3->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part3->SetSourceRectTexture(128, 89, 8, 7);
	lettuce1Part3->SetLocalPosition({ 32.f, 0.f, 0.f });
	lettuce1Part3->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part3->SetCanCollide(true);
	lettuce1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	lettuce1Part3->SetParent(lettuce1);
	lettuce1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(lettuce1Part3);

	auto lettuce1Part4 = new dae::GameObject();
	lettuce1Part4->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part4->SetSourceRectTexture(136, 89, 8, 7);
	lettuce1Part4->SetLocalPosition({ 48.f, 0.f, 0.f });
	lettuce1Part4->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part4->SetCanCollide(true);
	lettuce1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	lettuce1Part4->SetParent(lettuce1);
	lettuce1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(lettuce1Part4);

	lettuce1->AddComponent<dae::FSMComponent>();
	lettuce1->GetComponent<dae::FSMComponent>()->AddState<dae::IdleState>(dae::make_sdbm_hash("BurgerIdleState"));
	lettuce1->GetComponent<dae::FSMComponent>()->AddState<dae::FallingState>(dae::make_sdbm_hash("BurgerFallingState"), 0.2f);
	lettuce1->GetComponent<dae::FSMComponent>()->AddCondition<dae::FallingCondition>(dae::make_sdbm_hash("BurgerToFallingCondition"), *lettuce1, true);
	lettuce1->GetComponent<dae::FSMComponent>()->AddCondition<dae::FallingCondition>(dae::make_sdbm_hash("BurgerFromFallingCondition"), *lettuce1, false);
	lettuce1->GetComponent<dae::FSMComponent>()->AddTransition(dae::make_sdbm_hash("BurgerIdleState"), dae::make_sdbm_hash("BurgerFallingState"), dae::make_sdbm_hash("BurgerToFallingCondition"));
	lettuce1->GetComponent<dae::FSMComponent>()->AddTransition(dae::make_sdbm_hash("BurgerFallingState"), dae::make_sdbm_hash("BurgerIdleState"), dae::make_sdbm_hash("BurgerFromFallingCondition"));
	scene.Add(lettuce1);*/

	// Command exercise
	auto burgerGuy = new dae::GameObject();
	burgerGuy->SetTexture("BurgerTime.png", 16.f, 16.f);
	burgerGuy->SetSourceRectTexture(0, 0, 16, 16);
	burgerGuy->SetLocalPosition({ 200.f, 21.f, 0.f });
	burgerGuy->SetSpeed(0.1f);
	burgerGuy->SetCanCollide(true);
	burgerGuy->SetScaling(2.f, 2.f, 2.f);
	burgerGuy->AddTag(dae::make_sdbm_hash("Player"));
	burgerGuy->AddComponent<dae::MoveDownLadderComponent>();
	burgerGuy->AddComponent<dae::PlayerCollisionComponent>();
	scene.Add(burgerGuy);

	auto burgerGuy2 = new dae::GameObject();
	burgerGuy2->SetTexture("burgerGuy.tga", 16.f, 16.f);
	burgerGuy2->SetSourceRectTexture(0, 0, 16, 16);
	burgerGuy2->SetLocalPosition({ 400.f, 29.f, 0.f });
	burgerGuy2->SetSpeed(0.2f);
	burgerGuy2->SetCanCollide(true);
	burgerGuy2->AddComponent<dae::PlayerCollisionComponent>();
	scene.Add(burgerGuy2);

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

	/*auto instructions = new dae::GameObject();
	instructions->SetLocalPosition(glm::vec3{ 10.f, 150.f, 0.f });
	instructions->AddComponent<dae::TextComponent>();
	instructions->GetComponent<dae::TextComponent>()->SetText("Press Q to play a sound effect and E to start the music! Press P to pause/unpause the music!");
	instructions->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	scene.Add(instructions);*/

	auto moveLeft = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight = std::make_unique<dae::MoveCommand>(*burgerGuy, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, -1.f);
	auto moveDown = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, 1.f);

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
	input.BindInputKeyboard(SDL_SCANCODE_W, std::move(moveUp));
	input.BindInputKeyboard(SDL_SCANCODE_S, std::move(moveDown));
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