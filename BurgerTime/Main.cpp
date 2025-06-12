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
#include "MuteSoundCommand.h"
#include "HealthDisplayComponent.h"
#include "DecreaseLivesCommand.h"

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

	dae::ServiceLocator::GetSoundSystem().AddSound(dae::make_sdbm_hash("BurgerStep"), "../Data/Sounds/BurgerStep.wav");
	dae::ServiceLocator::GetSoundSystem().AddSound(dae::make_sdbm_hash("BurgerLand"), "../Data/Sounds/BurgerLand.wav");
	dae::ServiceLocator::GetSoundSystem().AddMusic(dae::make_sdbm_hash("MainMusic"), "../Data/Sounds/BGM.mp3");
	dae::ServiceLocator::GetSoundSystem().ChangeMasterVolume(50);

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	/*dae::GameObject* go = std::make_unique<dae::GameObject>();
	go->SetTexture("background.tga");
	scene.Add(go);*/

	/*go = std::make_unique<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetWorldPosition(216, 180);
	scene.Add(go);*/

	//W1 Fps component
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//dae::GameObject* title = std::make_unique<dae::GameObject>();
	//title->AddComponent<dae::TextComponent>();
	//dae::TextComponent* test = title->GetComponent<dae::TextComponent>();
	//test->SetText("Programming 4 Assignment");
	//test->SetFont(font);
	//title->SetWorldPosition(180, 20);
	//scene.Add(title);

	/*auto fps = std::make_unique<dae::GameObject>();
	fps->AddComponent<dae::TextComponent>();
	fps->AddComponent<dae::FPSComponent>(*fps->GetComponent<dae::TextComponent>());
	fps->GetComponent<dae::TextComponent>()->SetFont(font);
	fps->SetWorldPosition(10, 20);
	scene.Add(fps);*/

	/*// Burger guys rotating
	// Make a point for the burger guys to rotate around (otherwise it would rotate around world 0, 0
	auto burgerGuysCenterPoint = std::make_unique<dae::GameObject>();
	burgerGuysCenterPoint->SetWorldPosition(200, 200);
	scene.Add(burgerGuysCenterPoint);

	auto burgerGuy = std::make_unique<dae::GameObject>();
	burgerGuy->SetTexture("burgerGuy.tga");
	burgerGuy->SetParent(burgerGuysCenterPoint);
	burgerGuy->SetLocalPosition({ 30.f, 30.f, 0.f });
	//burgerGuy->AddComponent<dae::RotateComponent>(0.1f);
	scene.Add(burgerGuy);

	auto burgerGuy2 = std::make_unique<dae::GameObject>();
	burgerGuy2->SetTexture("burgerGuy.tga");
	burgerGuy2->SetParent(burgerGuy);
	burgerGuy2->SetLocalPosition({ 30.f, 30.f, 0.f });
	//burgerGuy2->AddComponent<dae::RotateComponent>(-.5f);
	scene.Add(burgerGuy2);

	// Exercise with thrashing
	/*auto imGuiTest = std::make_unique<dae::GameObject>();
	imGuiTest->AddComponent<dae::Exercise1Component>();
	imGuiTest->AddComponent<dae::Exercise2Component>();
	scene.Add(imGuiTest);*/
	auto ladder19 = std::make_unique<dae::GameObject>();
	ladder19->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder19->SetSourceRectTexture(0, 46, 10, 50);
	ladder19->SetLocalPosition({ 324.f, 267.f, 0.f });
	ladder19->SetCanCollide(true);
	ladder19->SetScaling(2.f, 2.f, 2.f);
	ladder19->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder19->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder19));

	auto ladder18 = std::make_unique<dae::GameObject>();
	ladder18->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder18->SetSourceRectTexture(0, 46, 10, 50);
	ladder18->SetLocalPosition({ 372.f, 267.f, 0.f });
	ladder18->SetCanCollide(true);
	ladder18->SetScaling(2.f, 2.f, 2.f);
	ladder18->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder18->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder18));

	auto ladder17 = std::make_unique<dae::GameObject>();
	ladder17->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder17->SetSourceRectTexture(0, 46, 10, 50);
	ladder17->SetLocalPosition({ 420.f, 267.f, 0.f });
	ladder17->SetCanCollide(true);
	ladder17->SetScaling(2.f, 2.f, 2.f);
	ladder17->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder17->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder17));

	auto ladder16 = std::make_unique<dae::GameObject>();
	ladder16->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder16->SetSourceRectTexture(0, 6, 10, 34);
	ladder16->SetLocalPosition({ 228.f, 299.f, 0.f });
	ladder16->SetCanCollide(true);
	ladder16->SetScaling(2.f, 2.f, 2.f);
	ladder16->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder16->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder16));

	auto ladder15 = std::make_unique<dae::GameObject>();
	ladder15->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder15->SetSourceRectTexture(0, 6, 10, 34);
	ladder15->SetLocalPosition({ 132.f, 299.f, 0.f });
	ladder15->SetCanCollide(true);
	ladder15->SetScaling(2.f, 2.f, 2.f);
	ladder15->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder15->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder15));

	auto ladder14 = std::make_unique<dae::GameObject>();
	ladder14->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder14->SetSourceRectTexture(0, 6, 10, 34);
	ladder14->SetLocalPosition({ 36.f, 299.f, 0.f });
	ladder14->SetCanCollide(true);
	ladder14->SetScaling(2.f, 2.f, 2.f);
	ladder14->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder14->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder14));

	auto ladder13 = std::make_unique<dae::GameObject>();
	ladder13->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder13->SetSourceRectTexture(0, 6, 10, 34);
	ladder13->SetLocalPosition({ 228.f, 235.f, 0.f });
	ladder13->SetCanCollide(true);
	ladder13->SetScaling(2.f, 2.f, 2.f);
	ladder13->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder13->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder13));

	auto ladder12 = std::make_unique<dae::GameObject>();
	ladder12->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder12->SetSourceRectTexture(0, 6, 10, 34);
	ladder12->SetLocalPosition({ 324.f, 204.f, 0.f });
	ladder12->SetCanCollide(true);
	ladder12->SetScaling(2.f, 2.f, 2.f);
	ladder12->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder12->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder12));

	auto ladder11 = std::make_unique<dae::GameObject>();
	ladder11->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder11->SetSourceRectTexture(0, 6, 10, 34);
	ladder11->SetLocalPosition({ 324.f, 204.f, 0.f });
	ladder11->SetCanCollide(true);
	ladder11->SetScaling(2.f, 2.f, 2.f);
	ladder11->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder11->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder11));

	auto ladder20 = std::make_unique<dae::GameObject>();
	ladder20->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder20->SetSourceRectTexture(0, 46, 10, 50);
	ladder20->SetLocalPosition({ 132.f, 204.f, 0.f });
	ladder20->SetCanCollide(true);
	ladder20->SetScaling(2.f, 2.f, 2.f);
	ladder20->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder20->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder20));

	auto ladder21 = std::make_unique<dae::GameObject>();
	ladder21->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder21->SetSourceRectTexture(0, 46, 10, 50);
	ladder21->SetLocalPosition({ 276.f, 139.f, 0.f });
	ladder21->SetCanCollide(true);
	ladder21->SetScaling(2.f, 2.f, 2.f);
	ladder21->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder21->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder21));

	auto ladder22 = std::make_unique<dae::GameObject>();
	ladder22->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder22->SetSourceRectTexture(0, 46, 10, 50);
	ladder22->SetLocalPosition({ 180.f, 75.f, 0.f });
	ladder22->SetCanCollide(true);
	ladder22->SetScaling(2.f, 2.f, 2.f);
	ladder22->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder22->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder22));

	auto ladder23 = std::make_unique<dae::GameObject>();
	ladder23->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder23->SetSourceRectTexture(0, 46, 10, 50);
	ladder23->SetLocalPosition({ 228.f, 75.f, 0.f });
	ladder23->SetCanCollide(true);
	ladder23->SetScaling(2.f, 2.f, 2.f);
	ladder23->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder23->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder23));

	auto ladder10 = std::make_unique<dae::GameObject>();
	ladder10->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder10->SetSourceRectTexture(0, 6, 10, 34);
	ladder10->SetLocalPosition({ 228.f, 173.f, 0.f });
	ladder10->SetCanCollide(true);
	ladder10->SetScaling(2.f, 2.f, 2.f);
	ladder10->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder10->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder10));

	auto ladder9 = std::make_unique<dae::GameObject>();
	ladder9->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder9->SetSourceRectTexture(0, 6, 10, 34);
	ladder9->SetLocalPosition({ 420.f, 139.f, 0.f });
	ladder9->SetCanCollide(true);
	ladder9->SetScaling(2.f, 2.f, 2.f);
	ladder9->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder9->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder9));

	auto ladder8 = std::make_unique<dae::GameObject>();
	ladder8->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder8->SetSourceRectTexture(0, 6, 10, 34);
	ladder8->SetLocalPosition({ 324.f, 139.f, 0.f });
	ladder8->SetCanCollide(true);
	ladder8->SetScaling(2.f, 2.f, 2.f);
	ladder8->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder8->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder8));

	auto ladder7 = std::make_unique<dae::GameObject>();
	ladder7->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder7->SetSourceRectTexture(0, 6, 10, 34);
	ladder7->SetLocalPosition({ 132.f, 139.f, 0.f });
	ladder7->SetCanCollide(true);
	ladder7->SetScaling(2.f, 2.f, 2.f);
	ladder7->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder7->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder7));

	auto forgottenLadder = std::make_unique<dae::GameObject>();
	forgottenLadder->SetTexture("BackgroundSheet.tga", 10, 36);
	forgottenLadder->SetSourceRectTexture(0, 6, 10, 34);
	forgottenLadder->SetLocalPosition({ 420.f, 75.f, 0.f });
	forgottenLadder->SetCanCollide(true);
	forgottenLadder->SetScaling(2.f, 2.f, 2.f);
	forgottenLadder->AddTag(dae::make_sdbm_hash("Ladder"));
	forgottenLadder->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(forgottenLadder));

	auto ladder6 = std::make_unique<dae::GameObject>();
	ladder6->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder6->SetSourceRectTexture(0, 6, 10, 34);
	ladder6->SetLocalPosition({ 324.f, 75.f, 0.f });
	ladder6->SetCanCollide(true);
	ladder6->SetScaling(2.f, 2.f, 2.f);
	ladder6->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder6->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder6));

	auto ladder5 = std::make_unique<dae::GameObject>();
	ladder5->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder5->SetSourceRectTexture(0, 6, 10, 34);
	ladder5->SetLocalPosition({ 132.f, 75.f, 0.f });
	ladder5->SetCanCollide(true);
	ladder5->SetScaling(2.f, 2.f, 2.f);
	ladder5->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder5->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder5));

	auto ladder3 = std::make_unique<dae::GameObject>();
	ladder3->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder3->SetSourceRectTexture(0, 46, 10, 50);
	ladder3->SetLocalPosition({ 84.f, 204.f, 0.f });
	ladder3->SetCanCollide(true);
	ladder3->SetScaling(2.f, 2.f, 2.f);
	ladder3->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder3->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder3));

	auto ladder4 = std::make_unique<dae::GameObject>();
	ladder4->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder4->SetSourceRectTexture(0, 46, 10, 50);
	ladder4->SetLocalPosition({ 36.f, 204.f, 0.f });
	ladder4->SetCanCollide(true);
	ladder4->SetScaling(2.f, 2.f, 2.f);
	ladder4->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder4->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder4));

	auto ladder = std::make_unique<dae::GameObject>();
	ladder->SetTexture("BackgroundSheet.tga", 10, 36);
	ladder->SetSourceRectTexture(0, 6, 10, 34);
	ladder->SetLocalPosition({ 36.f, 75.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder));

	//auto ladder3 = std::make_unique<dae::GameObject>();
	//ladder3->SetTexture("BackgroundSheet.tga", 10, 36);
	//ladder3->SetSourceRectTexture(0, 6, 10, 34);
	//ladder3->SetLocalPosition({ 36.f, 115.f, 0.f });
	//ladder3->SetCanCollide(true);
	//ladder3->SetScaling(2.f, 2.f, 2.f);
	//ladder3->AddTag(dae::make_sdbm_hash("Ladder"));
	//ladder3->AddComponent<dae::CollisionComponent>();
	//scene.Add(ladder3);

	auto ladderPlatform1 = std::make_unique<dae::GameObject>();
	ladderPlatform1->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform1->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform1->SetLocalPosition({ 30.f, 78.f, 0.f });
	ladderPlatform1->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform1->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform1->SetCanCollide(true);
	ladderPlatform1->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform1));

	auto ladderPlatform2 = std::make_unique<dae::GameObject>();
	ladderPlatform2->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform2->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform2->SetLocalPosition({ 126.f, 78.f, 0.f });
	ladderPlatform2->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform2->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform2->SetCanCollide(true);
	ladderPlatform2->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform2));

	auto ladderPlatform3 = std::make_unique<dae::GameObject>();
	ladderPlatform3->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform3->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform3->SetLocalPosition({ 222.f, 78.f, 0.f });
	ladderPlatform3->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform3->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform3->SetCanCollide(true);
	ladderPlatform3->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform3));

	auto ladderPlatform4 = std::make_unique<dae::GameObject>();
	ladderPlatform4->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform4->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform4->SetLocalPosition({ 318.f, 78.f, 0.f });
	ladderPlatform4->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform4->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform4->SetCanCollide(true);
	ladderPlatform4->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform4));

	auto ladderPlatform5 = std::make_unique<dae::GameObject>();
	ladderPlatform5->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform5->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform5->SetLocalPosition({ 414.f, 78.f, 0.f });
	ladderPlatform5->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform5->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform5->SetCanCollide(true);
	ladderPlatform5->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform5));

	auto ladderPlatform6 = std::make_unique<dae::GameObject>();
	ladderPlatform6->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform6->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform6->SetLocalPosition({ 30.f, 142.f, 0.f });
	ladderPlatform6->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform6->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform6->SetCanCollide(true);
	ladderPlatform6->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform6));

	auto ladderPlatform7 = std::make_unique<dae::GameObject>();
	ladderPlatform7->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform7->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform7->SetLocalPosition({ 126.f, 142.f, 0.f });
	ladderPlatform7->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform7->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform7->SetCanCollide(true);
	ladderPlatform7->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform7));

	auto ladderPlatform8 = std::make_unique<dae::GameObject>();
	ladderPlatform8->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform8->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform8->SetLocalPosition({ 222.f, 142.f, 0.f });
	ladderPlatform8->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform8->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform8->SetCanCollide(true);
	ladderPlatform8->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform8));

	auto ladderPlatform9 = std::make_unique<dae::GameObject>();
	ladderPlatform9->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform9->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform9->SetLocalPosition({ 318.f, 142.f, 0.f });
	ladderPlatform9->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform9->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform9->SetCanCollide(true);
	ladderPlatform9->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform9));

	auto ladderPlatform10 = std::make_unique<dae::GameObject>();
	ladderPlatform10->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform10->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform10->SetLocalPosition({ 414.f, 142.f, 0.f });
	ladderPlatform10->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform10->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform10->SetCanCollide(true);
	ladderPlatform10->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform10));

	auto ladderPlatform11 = std::make_unique<dae::GameObject>();
	ladderPlatform11->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform11->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform11->SetLocalPosition({ 126.f, 174.f, 0.f });
	ladderPlatform11->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform11->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform11->SetCanCollide(true);
	ladderPlatform11->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform11));

	auto ladderPlatform12 = std::make_unique<dae::GameObject>();
	ladderPlatform12->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform12->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform12->SetLocalPosition({ 222.f, 174.f, 0.f });
	ladderPlatform12->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform12->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform12->SetCanCollide(true);
	ladderPlatform12->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform12));

	auto ladderPlatform13 = std::make_unique<dae::GameObject>();
	ladderPlatform13->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform13->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform13->SetLocalPosition({ 30.f, 206.f, 0.f });
	ladderPlatform13->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform13->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform13->SetCanCollide(true);
	ladderPlatform13->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform13));

	auto ladderPlatform14 = std::make_unique<dae::GameObject>();
	ladderPlatform14->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform14->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform14->SetLocalPosition({ 126.f, 206.f, 0.f });
	ladderPlatform14->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform14->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform14->SetCanCollide(true);
	ladderPlatform14->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform14));

	auto ladderPlatform15 = std::make_unique<dae::GameObject>();
	ladderPlatform15->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform15->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform15->SetLocalPosition({ 318.f, 206.f, 0.f });
	ladderPlatform15->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform15->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform15->SetCanCollide(true);
	ladderPlatform15->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform15));

	auto ladderPlatform16 = std::make_unique<dae::GameObject>();
	ladderPlatform16->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform16->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform16->SetLocalPosition({ 414.f, 206.f, 0.f });
	ladderPlatform16->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform16->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform16->SetCanCollide(true);
	ladderPlatform16->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform16));

	auto ladderPlatform17 = std::make_unique<dae::GameObject>();
	ladderPlatform17->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform17->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform17->SetLocalPosition({ 126.f, 238.f, 0.f });
	ladderPlatform17->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform17->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform17->SetCanCollide(true);
	ladderPlatform17->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform17));

	auto ladderPlatform18 = std::make_unique<dae::GameObject>();
	ladderPlatform18->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform18->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform18->SetLocalPosition({ 222.f, 238.f, 0.f });
	ladderPlatform18->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform18->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform18->SetCanCollide(true);
	ladderPlatform18->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform18));

	auto ladderPlatform19 = std::make_unique<dae::GameObject>();
	ladderPlatform19->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform19->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform19->SetLocalPosition({ 318.f, 238.f, 0.f });
	ladderPlatform19->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform19->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform19->SetCanCollide(true);
	ladderPlatform19->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform19));

	auto ladderPlatform20 = std::make_unique<dae::GameObject>();
	ladderPlatform20->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform20->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform20->SetLocalPosition({ 318.f, 270.f, 0.f });
	ladderPlatform20->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform20->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform20->SetCanCollide(true);
	ladderPlatform20->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform20));

	auto ladderPlatform21 = std::make_unique<dae::GameObject>();
	ladderPlatform21->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform21->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform21->SetLocalPosition({ 414.f, 270.f, 0.f });
	ladderPlatform21->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform21->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform21->SetCanCollide(true);
	ladderPlatform21->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform21));

	auto ladderPlatform22 = std::make_unique<dae::GameObject>();
	ladderPlatform22->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform22->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform22->SetLocalPosition({ 30.f, 302.f, 0.f });
	ladderPlatform22->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform22->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform22->SetCanCollide(true);
	ladderPlatform22->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform22));

	auto ladderPlatform23 = std::make_unique<dae::GameObject>();
	ladderPlatform23->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform23->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform23->SetLocalPosition({ 126.f, 302.f, 0.f });
	ladderPlatform23->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform23->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform23->SetCanCollide(true);
	ladderPlatform23->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform23));

	auto ladderPlatform24 = std::make_unique<dae::GameObject>();
	ladderPlatform24->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform24->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform24->SetLocalPosition({ 222.f, 302.f, 0.f });
	ladderPlatform24->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform24->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform24->SetCanCollide(true);
	ladderPlatform24->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform24));

	auto ladderPlatform25 = std::make_unique<dae::GameObject>();
	ladderPlatform25->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform25->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform25->SetLocalPosition({ 318.f, 302.f, 0.f });
	ladderPlatform25->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform25->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform25->SetCanCollide(true);
	ladderPlatform25->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform25));

	auto ladderPlatform26 = std::make_unique<dae::GameObject>();
	ladderPlatform26->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform26->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform26->SetLocalPosition({ 30.f, 366.f, 0.f });
	ladderPlatform26->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform26->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform26->SetCanCollide(true);
	ladderPlatform26->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform26));

	auto ladderPlatform27 = std::make_unique<dae::GameObject>();
	ladderPlatform27->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform27->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform27->SetLocalPosition({ 126.f, 366.f, 0.f });
	ladderPlatform27->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform27->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform27->SetCanCollide(true);
	ladderPlatform27->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform27));

	auto ladderPlatform28 = std::make_unique<dae::GameObject>();
	ladderPlatform28->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform28->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform28->SetLocalPosition({ 222.f, 366.f, 0.f });
	ladderPlatform28->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform28->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform28->SetCanCollide(true);
	ladderPlatform28->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform28));

	auto ladderPlatform29 = std::make_unique<dae::GameObject>();
	ladderPlatform29->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform29->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform29->SetLocalPosition({ 318.f, 366.f, 0.f });
	ladderPlatform29->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform29->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform29->SetCanCollide(true);
	ladderPlatform29->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform29));

	auto ladderPlatform30 = std::make_unique<dae::GameObject>();
	ladderPlatform30->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform30->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform30->SetLocalPosition({ 414.f, 366.f, 0.f });
	ladderPlatform30->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform30->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform30->SetCanCollide(true);
	ladderPlatform30->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform30));

	auto ladder2 = std::make_unique<dae::GameObject>();
	ladder2->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder2->SetSourceRectTexture(0, 6, 10, 34);
	ladder2->SetLocalPosition({ 84.f, 140.f, 0.f });
	ladder2->SetCanCollide(true);
	ladder2->SetScaling(2.f, 2.f, 2.f);
	ladder2->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder2->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder2));

	auto burgerPlatform1 = std::make_unique<dae::GameObject>();
	burgerPlatform1->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform1->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform1->SetLocalPosition({ 62.f, 78.f, 0.f });
	burgerPlatform1->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform1->SetCanCollide(true);
	burgerPlatform1->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform1->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform1));

	auto burgerPlatform2 = std::make_unique<dae::GameObject>();
	burgerPlatform2->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform2->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform2->SetLocalPosition({ 62.f, 142.f, 0.f });
	burgerPlatform2->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform2->SetCanCollide(true);
	burgerPlatform2->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform2->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform2->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform2));

	auto burgerPlatform3 = std::make_unique<dae::GameObject>();
	burgerPlatform3->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform3->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform3->SetLocalPosition({ 62.f, 206.f, 0.f });
	burgerPlatform3->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform3->SetCanCollide(true);
	burgerPlatform3->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform3->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform3->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform3));

	auto burgerPlatform4 = std::make_unique<dae::GameObject>();
	burgerPlatform4->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform4->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform4->SetLocalPosition({ 62.f, 303.f, 0.f });
	burgerPlatform4->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform4->SetCanCollide(true);
	burgerPlatform4->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform4->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform4->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform4));

	auto burgerPlatform5 = std::make_unique<dae::GameObject>();
	burgerPlatform5->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform5->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform5->SetLocalPosition({ 158.f, 78.f, 0.f });
	burgerPlatform5->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform5->SetCanCollide(true);
	burgerPlatform5->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform5->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform5->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform5));

	auto burgerPlatform6 = std::make_unique<dae::GameObject>();
	burgerPlatform6->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform6->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform6->SetLocalPosition({ 254.f, 78.f, 0.f });
	burgerPlatform6->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform6->SetCanCollide(true);
	burgerPlatform6->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform6->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform6->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform6));

	auto burgerPlatform7 = std::make_unique<dae::GameObject>();
	burgerPlatform7->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform7->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform7->SetLocalPosition({ 350.f, 78.f, 0.f });
	burgerPlatform7->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform7->SetCanCollide(true);
	burgerPlatform7->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform7->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform7->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform7));

	auto burgerPlatform8 = std::make_unique<dae::GameObject>();
	burgerPlatform8->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform8->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform8->SetLocalPosition({ 254.f, 142.f, 0.f });
	burgerPlatform8->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform8->SetCanCollide(true);
	burgerPlatform8->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform8->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform8->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform8));

	auto burgerPlatform9 = std::make_unique<dae::GameObject>();
	burgerPlatform9->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform9->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform9->SetLocalPosition({ 350.f, 142.f, 0.f });
	burgerPlatform9->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform9->SetCanCollide(true);
	burgerPlatform9->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform9->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform9->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform9));

	auto burgerPlatform10 = std::make_unique<dae::GameObject>();
	burgerPlatform10->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform10->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform10->SetLocalPosition({ 158.f, 174.f, 0.f });
	burgerPlatform10->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform10->SetCanCollide(true);
	burgerPlatform10->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform10->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform10->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform10));

	auto burgerPlatform11 = std::make_unique<dae::GameObject>();
	burgerPlatform11->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform11->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform11->SetLocalPosition({ 350.f, 206.f, 0.f });
	burgerPlatform11->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform11->SetCanCollide(true);
	burgerPlatform11->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform11->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform11->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform11));

	auto burgerPlatform12 = std::make_unique<dae::GameObject>();
	burgerPlatform12->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform12->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform12->SetLocalPosition({ 158.f, 238.f, 0.f });
	burgerPlatform12->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform12->SetCanCollide(true);
	burgerPlatform12->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform12->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform12->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform12));

	auto burgerPlatform13 = std::make_unique<dae::GameObject>();
	burgerPlatform13->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform13->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform13->SetLocalPosition({ 158.f, 238.f, 0.f });
	burgerPlatform13->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform13->SetCanCollide(true);
	burgerPlatform13->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform13->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform13->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform13));

	auto forgottenBourgirPlat = std::make_unique<dae::GameObject>();
	forgottenBourgirPlat->SetTexture("BackgroundSheet.tga", 32, 3);
	forgottenBourgirPlat->SetSourceRectTexture(0, 0, 32, 3);
	forgottenBourgirPlat->SetLocalPosition({ 254.f, 238.f, 0.f });
	forgottenBourgirPlat->SetScaling(2.f, 2.f, 2.f);
	forgottenBourgirPlat->SetCanCollide(true);
	forgottenBourgirPlat->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	forgottenBourgirPlat->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	forgottenBourgirPlat->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(forgottenBourgirPlat));

	auto burgerPlatform14 = std::make_unique<dae::GameObject>();
	burgerPlatform14->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform14->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform14->SetLocalPosition({ 350.f, 270.f, 0.f });
	burgerPlatform14->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform14->SetCanCollide(true);
	burgerPlatform14->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform14->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform14->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform14));

	auto burgerPlatform15 = std::make_unique<dae::GameObject>();
	burgerPlatform15->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform15->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform15->SetLocalPosition({ 158.f, 302.f, 0.f });
	burgerPlatform15->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform15->SetCanCollide(true);
	burgerPlatform15->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform15->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform15->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform15));

	auto burgerPlatform16 = std::make_unique<dae::GameObject>();
	burgerPlatform16->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform16->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform16->SetLocalPosition({ 254.f, 302.f, 0.f });
	burgerPlatform16->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform16->SetCanCollide(true);
	burgerPlatform16->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform16->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform16->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform16));

	auto burgerPlatform17 = std::make_unique<dae::GameObject>();
	burgerPlatform17->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform17->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform17->SetLocalPosition({ 62.f, 366.f, 0.f });
	burgerPlatform17->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform17->SetCanCollide(true);
	burgerPlatform17->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform17->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform17->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform17));

	auto burgerPlatform18 = std::make_unique<dae::GameObject>();
	burgerPlatform18->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform18->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform18->SetLocalPosition({ 158.f, 366.f, 0.f });
	burgerPlatform18->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform18->SetCanCollide(true);
	burgerPlatform18->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform18->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform18->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform18));

	auto burgerPlatform19 = std::make_unique<dae::GameObject>();
	burgerPlatform19->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform19->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform19->SetLocalPosition({ 254.f, 366.f, 0.f });
	burgerPlatform19->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform19->SetCanCollide(true);
	burgerPlatform19->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform19->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform19->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform19));

	auto burgerPlatform20 = std::make_unique<dae::GameObject>();
	burgerPlatform20->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform20->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform20->SetLocalPosition({ 350.f, 366.f, 0.f });
	burgerPlatform20->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform20->SetCanCollide(true);
	burgerPlatform20->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform20->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform20->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform20));

	auto plate1 = std::make_unique<dae::GameObject>();
	plate1->SetTexture("BackgroundSheet.tga", 38, 6);
	plate1->SetSourceRectTexture(0, 40, 38, 6);
	plate1->SetLocalPosition({ 56.f, 445.f, 0.f });
	plate1->SetScaling(2.f, 2.f, 2.f);
	plate1->SetCanCollide(true);
	plate1->AddTag(dae::make_sdbm_hash("Plate"));
	plate1->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate1));

	auto pScoreObserver = std::make_unique<dae::ScoreObserver>();
	auto scoreDisplay = std::make_unique<dae::GameObject>();
	scoreDisplay->AddComponent<dae::ScoreDisplayComponent>();

	auto burgerBun1 = std::make_unique<dae::GameObject>();
	burgerBun1->SetLocalPosition({ 63.f, 68.f, 0.f });
	burgerBun1->SetShouldRender(false);
	burgerBun1->SetCanCollide(true);
	burgerBun1->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBun1->SetScaling(2.f, 2.f, 2.f);

	auto burgerBun1Part1 = std::make_unique<dae::GameObject>();
	burgerBun1Part1->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part1->SetSourceRectTexture(112, 49, 8, 7);
	burgerBun1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	burgerBun1Part1->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part1->SetCanCollide(true);
	burgerBun1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	burgerBun1Part1->SetParent(burgerBun1.get());
	burgerBun1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(burgerBun1Part1));

	auto burgerBun1Part2 = std::make_unique<dae::GameObject>();
	burgerBun1Part2->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part2->SetSourceRectTexture(120, 49, 8, 7);
	burgerBun1Part2->SetLocalPosition({ 16.f, 0.f, 0.f });
	burgerBun1Part2->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part2->SetCanCollide(true);
	burgerBun1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	burgerBun1Part2->SetParent(burgerBun1.get());
	burgerBun1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(burgerBun1Part2));

	auto burgerBun1Part3 = std::make_unique<dae::GameObject>();
	burgerBun1Part3->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part3->SetSourceRectTexture(128, 49, 8, 7);
	burgerBun1Part3->SetLocalPosition({ 32.f, 0.f, 0.f });
	burgerBun1Part3->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part3->SetCanCollide(true);
	burgerBun1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	burgerBun1Part3->SetParent(burgerBun1.get());
	burgerBun1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(burgerBun1Part3));

	auto burgerBun1Part4 = std::make_unique<dae::GameObject>();
	burgerBun1Part4->SetTexture("BurgerTime.png", 8, 7);
	burgerBun1Part4->SetSourceRectTexture(136, 49, 8, 7);
	burgerBun1Part4->SetLocalPosition({ 48.f, 0.f, 0.f });
	burgerBun1Part4->SetScaling(2.f, 2.f, 2.f);
	burgerBun1Part4->SetCanCollide(true);
	burgerBun1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	burgerBun1Part4->SetParent(burgerBun1.get());
	burgerBun1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(burgerBun1Part4));

	burgerBun1->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBun1->AddComponent<dae::BurgerCollisionComponent>();
	burgerBun1->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*scoreDisplay->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(burgerBun1));

	auto lettuce1 = std::make_unique<dae::GameObject>();
	lettuce1->SetLocalPosition({ 63.f, 133.f, 0.f });
	lettuce1->SetShouldRender(false);
	lettuce1->SetCanCollide(true);
	lettuce1->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	lettuce1->SetScaling(2.f, 2.f, 2.f);

	auto lettuce1Part1 = std::make_unique<dae::GameObject>();
	lettuce1Part1->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part1->SetSourceRectTexture(112, 89, 8, 7);
	lettuce1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	lettuce1Part1->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part1->SetCanCollide(true);
	lettuce1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	lettuce1Part1->SetParent(lettuce1.get());
	lettuce1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(lettuce1Part1));

	auto lettuce1Part2 = std::make_unique<dae::GameObject>();
	lettuce1Part2->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part2->SetSourceRectTexture(120, 89, 8, 7);
	lettuce1Part2->SetLocalPosition({ 16.f, 0.f, 0.f });
	lettuce1Part2->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part2->SetCanCollide(true);
	lettuce1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	lettuce1Part2->SetParent(lettuce1.get());
	lettuce1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(lettuce1Part2));

	auto lettuce1Part3 = std::make_unique<dae::GameObject>();
	lettuce1Part3->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part3->SetSourceRectTexture(128, 89, 8, 7);
	lettuce1Part3->SetLocalPosition({ 32.f, 0.f, 0.f });
	lettuce1Part3->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part3->SetCanCollide(true);
	lettuce1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	lettuce1Part3->SetParent(lettuce1.get());
	lettuce1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(lettuce1Part3));

	auto lettuce1Part4 = std::make_unique<dae::GameObject>();
	lettuce1Part4->SetTexture("BurgerTime.png", 8, 7);
	lettuce1Part4->SetSourceRectTexture(136, 89, 8, 7);
	lettuce1Part4->SetLocalPosition({ 48.f, 0.f, 0.f });
	lettuce1Part4->SetScaling(2.f, 2.f, 2.f);
	lettuce1Part4->SetCanCollide(true);
	lettuce1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	lettuce1Part4->SetParent(lettuce1.get());
	lettuce1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(lettuce1Part4));

	lettuce1->AddComponent<dae::FoodFallingComponent>(0.2f);
	lettuce1->AddComponent<dae::BurgerCollisionComponent>();
	lettuce1->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*scoreDisplay->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(lettuce1));

	auto beef1 = std::make_unique<dae::GameObject>();
	beef1->SetLocalPosition({ 65.f, 195.f, 0.f });
	beef1->SetShouldRender(false);
	beef1->SetCanCollide(true);
	beef1->SetBoudingBoxDimensions(7.f * 4.f, 7.f);
	beef1->SetScaling(2.f, 2.f, 2.f);

	auto beef1Part1 = std::make_unique<dae::GameObject>();
	beef1Part1->SetTexture("BurgerTime.png", 7, 7);
	beef1Part1->SetSourceRectTexture(114, 73, 7, 7);
	beef1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	beef1Part1->SetScaling(2.f, 2.f, 2.f);
	beef1Part1->SetCanCollide(true);
	beef1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	beef1Part1->SetParent(beef1.get());
	beef1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(beef1Part1));

	auto beef1Part2 = std::make_unique<dae::GameObject>();
	beef1Part2->SetTexture("BurgerTime.png", 7, 7);
	beef1Part2->SetSourceRectTexture(120, 73, 7, 7);
	beef1Part2->SetLocalPosition({ 14.f, 0.f, 0.f });
	beef1Part2->SetScaling(2.f, 2.f, 2.f);
	beef1Part2->SetCanCollide(true);
	beef1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	beef1Part2->SetParent(beef1.get());
	beef1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(beef1Part2));

	auto beef1Part3 = std::make_unique<dae::GameObject>();
	beef1Part3->SetTexture("BurgerTime.png", 7, 7);
	beef1Part3->SetSourceRectTexture(127, 73, 7, 7);
	beef1Part3->SetLocalPosition({ 28.f, 0.f, 0.f });
	beef1Part3->SetScaling(2.f, 2.f, 2.f);
	beef1Part3->SetCanCollide(true);
	beef1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	beef1Part3->SetParent(beef1.get());
	beef1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(beef1Part3));

	auto beef1Part4 = std::make_unique<dae::GameObject>();
	beef1Part4->SetTexture("BurgerTime.png", 8, 7);
	beef1Part4->SetSourceRectTexture(134, 73, 7, 7);
	beef1Part4->SetLocalPosition({ 42.f, 0.f, 0.f });
	beef1Part4->SetScaling(2.f, 2.f, 2.f);
	beef1Part4->SetCanCollide(true);
	beef1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	beef1Part4->SetParent(beef1.get());
	beef1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(beef1Part4));

	beef1->AddComponent<dae::FoodFallingComponent>(0.2f);
	beef1->AddComponent<dae::BurgerCollisionComponent>();
	beef1->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*scoreDisplay->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(beef1));

	auto topBun1 = std::make_unique<dae::GameObject>();
	topBun1->SetLocalPosition({ 62.f, 356.f, 0.f });
	topBun1->SetShouldRender(false);
	topBun1->SetCanCollide(true);
	topBun1->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	topBun1->SetScaling(2.f, 2.f, 2.f);

	auto topBun1Part1 = std::make_unique<dae::GameObject>();
	topBun1Part1->SetTexture("BurgerTime.png", 8, 7);
	topBun1Part1->SetSourceRectTexture(112, 57, 8, 7);
	topBun1Part1->SetLocalPosition({ 0.f, 0.f, 0.f });
	topBun1Part1->SetScaling(2.f, 2.f, 2.f);
	topBun1Part1->SetCanCollide(true);
	topBun1Part1->AddComponent<dae::BurgerPartsCollisionComponent>(0);
	topBun1Part1->SetParent(topBun1.get());
	topBun1Part1->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(topBun1Part1));

	auto topBun1Part2 = std::make_unique<dae::GameObject>();
	topBun1Part2->SetTexture("BurgerTime.png", 8, 7);
	topBun1Part2->SetSourceRectTexture(120, 57, 8, 7);
	topBun1Part2->SetLocalPosition({ 16.f, 0.f, 0.f });
	topBun1Part2->SetScaling(2.f, 2.f, 2.f);
	topBun1Part2->SetCanCollide(true);
	topBun1Part2->AddComponent<dae::BurgerPartsCollisionComponent>(1);
	topBun1Part2->SetParent(topBun1.get());
	topBun1Part2->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(topBun1Part2));

	auto topBun1Part3 = std::make_unique<dae::GameObject>();
	topBun1Part3->SetTexture("BurgerTime.png", 8, 7);
	topBun1Part3->SetSourceRectTexture(128, 57, 8, 7);
	topBun1Part3->SetLocalPosition({ 32.f, 0.f, 0.f });
	topBun1Part3->SetScaling(2.f, 2.f, 2.f);
	topBun1Part3->SetCanCollide(true);
	topBun1Part3->AddComponent<dae::BurgerPartsCollisionComponent>(2);
	topBun1Part3->SetParent(topBun1.get());
	topBun1Part3->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(topBun1Part3));

	auto topBun1Part4 = std::make_unique<dae::GameObject>();
	topBun1Part4->SetTexture("BurgerTime.png", 8, 7);
	topBun1Part4->SetSourceRectTexture(136, 57, 8, 7);
	topBun1Part4->SetLocalPosition({ 48.f, 0.f, 0.f });
	topBun1Part4->SetScaling(2.f, 2.f, 2.f);
	topBun1Part4->SetCanCollide(true);
	topBun1Part4->AddComponent<dae::BurgerPartsCollisionComponent>(3);
	topBun1Part4->SetParent(topBun1.get());
	topBun1Part4->AddTag(dae::make_sdbm_hash("Food"));
	scene.Add(std::move(topBun1Part4));

	topBun1->AddComponent<dae::FoodFallingComponent>(0.2f);
	topBun1->AddComponent<dae::BurgerCollisionComponent>();
	topBun1->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*scoreDisplay->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(topBun1));

	scene.Add(std::move(scoreDisplay));

	// Command exercise
	auto burgerGuy = std::make_unique<dae::GameObject>();
	burgerGuy->SetTexture("BurgerTime.png", 16.f, 16.f);
	burgerGuy->SetSourceRectTexture(0, 0, 16, 16);
	burgerGuy->SetLocalPosition({ 200.f, 46.f, 0.f });
	burgerGuy->SetSpeed(0.1f);
	burgerGuy->SetCanCollide(true);
	burgerGuy->SetScaling(2.f, 2.f, 2.f);
	burgerGuy->AddTag(dae::make_sdbm_hash("Player"));
	burgerGuy->AddComponent<dae::MoveDownLadderComponent>(0.1f);
	burgerGuy->AddComponent<dae::PlayerCollisionComponent>();


	auto burgerGuy2 = std::make_unique<dae::GameObject>();
	burgerGuy2->SetTexture("BurgerTime.png", 16.f, 16.f);
	burgerGuy2->SetSourceRectTexture(0, 0, 16, 16);
	burgerGuy2->SetLocalPosition({ 250.f, 46.f, 0.f });
	burgerGuy2->SetSpeed(0.1f);
	burgerGuy2->SetCanCollide(true);
	burgerGuy2->SetScaling(2.f, 2.f, 2.f);
	burgerGuy2->AddTag(dae::make_sdbm_hash("Player"));
	burgerGuy2->AddComponent<dae::MoveDownLadderComponent>(0.1f);
	burgerGuy2->AddComponent<dae::PlayerCollisionComponent>();

	auto mrHotDog = std::make_unique<dae::GameObject>();
	mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog->SetLocalPosition({ 100.f, 175.f, 0.f });
	mrHotDog->SetSpeed(0.1f);
	mrHotDog->SetCanCollide(true);
	mrHotDog->SetScaling(2.f, 2.f, 2.f);
	mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.1f);
	mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	scene.Add(std::move(mrHotDog));

	auto mrHotDog2 = std::make_unique<dae::GameObject>();
	mrHotDog2->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog2->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog2->SetLocalPosition({ 75.f, 175.f, 0.f });
	mrHotDog2->SetSpeed(0.1f);
	mrHotDog2->SetCanCollide(true);
	mrHotDog2->SetScaling(2.f, 2.f, 2.f);
	mrHotDog2->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog2->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog2->AddComponent<dae::MoveDownLadderComponent>(0.1f);
	mrHotDog2->AddComponent<dae::PlayerCollisionComponent>();
	scene.Add(std::move(mrHotDog2));

	auto smallerFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 17);

	auto healthDisplay = std::make_unique<dae::GameObject>();
	healthDisplay->SetTexture("BurgerTime.png", 7, 8);
	healthDisplay->SetSourceRectTexture(201, 0, 7, 8);
	healthDisplay->SetLocalPosition({ 20.f, 445.f, 0.f });
	healthDisplay->SetScaling(2.f, 2.f, 2.f);
	healthDisplay->AddComponent<dae::HealthDisplayComponent>();

	/*auto instructions = std::make_unique<dae::GameObject>();
	instructions->SetLocalPosition(glm::vec3{ 10.f, 150.f, 0.f });
	instructions->AddComponent<dae::TextComponent>();
	instructions->GetComponent<dae::TextComponent>()->SetText("Press Q to play a sound effect and E to start the music! Press P to pause/unpause the music!");
	instructions->GetComponent<dae::TextComponent>()->SetFont(smallerFont);
	scene.Add(instructions);*/

	auto moveLeft = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{0.f, -1.f, 0.f});
	auto moveDown = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 0.f, 1.f, 0.f });

	auto moveLeft2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 0.f, -1.f, 0.f });
	auto moveDown2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 0.f, 1.f, 0.f });

	auto playEnterSoundEffect = std::make_unique<dae::PlaySoundCommand>(*burgerGuy, dae::make_sdbm_hash("Enter"));
	auto playMusic = std::make_unique<dae::PlayMusicCommand>(*burgerGuy, dae::make_sdbm_hash("MainMusic"));
	auto pauseMusic = std::make_unique<dae::PauseMusicCommand>(*burgerGuy);
	auto muteCommand = std::make_unique<dae::MuteSoundCommand>(*burgerGuy, 50);
	auto decLivesCommand = std::make_unique<dae::DecreaseLivesCommand>(*burgerGuy);
	decLivesCommand->AddObserver(*healthDisplay->GetComponent<dae::HealthDisplayComponent>()->GetObserver());

	auto& input = dae::InputManager::GetInstance();
	input.BindInputKeyboard(SDL_SCANCODE_A, SDL_KEYDOWN, std::move(moveLeft));
	input.BindInputKeyboard(SDL_SCANCODE_D, SDL_KEYDOWN, std::move(moveRight));
	input.BindInputKeyboard(SDL_SCANCODE_W, SDL_KEYDOWN, std::move(moveUp));
	input.BindInputKeyboard(SDL_SCANCODE_S, SDL_KEYDOWN, std::move(moveDown));
	input.BindInputKeyboard(SDL_SCANCODE_Q, SDL_KEYUP, std::move(playEnterSoundEffect));
	input.BindInputKeyboard(SDL_SCANCODE_E, SDL_KEYDOWN, std::move(playMusic));
	input.BindInputKeyboard(SDL_SCANCODE_P, SDL_KEYDOWN, std::move(pauseMusic));
	input.BindInputKeyboard(SDL_SCANCODE_F2, SDL_KEYUP, std::move(muteCommand));
	input.BindInputKeyboard(SDL_SCANCODE_H, SDL_KEYUP, std::move(decLivesCommand));


	input.AddController();
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_LEFT, true, std::move(moveLeft2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_RIGHT, true, std::move(moveRight2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_UP, true, std::move(moveUp2));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_DOWN, true, std::move(moveDown2));

	scene.Add(std::move(burgerGuy));
	scene.Add(std::move(burgerGuy2));
	scene.Add(std::move(healthDisplay));
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