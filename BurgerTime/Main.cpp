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
#include "FSMComponent.h"
#include "ScoreObserver.h"
#include "BurgerCollisionComponent.h"
#include "ScoreDisplayComponent.h"
#include "MuteSoundCommand.h"
#include "HealthDisplayComponent.h"
#include "DecreaseLivesCommand.h"
#include "EnemyStateComponent.h"
#include "StartGameCommand.h"
#include "GameManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

void load()
{
	auto testSound = std::make_unique<dae::SDLSoundSystem>();
	dae::ServiceLocator::RegisterSoundSystem(std::move(testSound));

	dae::ServiceLocator::GetSoundSystem().AddSound(dae::make_sdbm_hash("BurgerStep"), "../Data/Sounds/BurgerStep.wav");
	dae::ServiceLocator::GetSoundSystem().AddSound(dae::make_sdbm_hash("BurgerLand"), "../Data/Sounds/BurgerLand.wav");
	dae::ServiceLocator::GetSoundSystem().AddMusic(dae::make_sdbm_hash("Death"), "../Data/Sounds/Death.wav");
	dae::ServiceLocator::GetSoundSystem().AddMusic(dae::make_sdbm_hash("MainMusic"), "../Data/Sounds/BGM.mp3");
	dae::ServiceLocator::GetSoundSystem().ChangeMasterVolume(30);
	dae::ServiceLocator::GetSoundSystem().PlayMusic(dae::make_sdbm_hash("MainMusic"), -1);

	auto& mainMenuScene = dae::SceneManager::GetInstance().CreateScene(dae::make_sdbm_hash("MainMenu"));
	auto font = dae::ResourceManager::GetInstance().LoadFont("PressStart2P-Regular.ttf", 12);

	auto intro = std::make_unique<dae::GameObject>();
	intro->AddComponent<dae::TextComponent>();
	intro->GetComponent<dae::TextComponent>()->SetFont(font);
	intro->GetComponent<dae::TextComponent>()->SetText("Press 1 for single player");
	intro->SetWorldPosition(10, 20);

	auto intro1 = std::make_unique<dae::GameObject>();
	intro1->AddComponent<dae::TextComponent>();
	intro1->GetComponent<dae::TextComponent>()->SetFont(font);
	intro1->GetComponent<dae::TextComponent>()->SetText("Press 2 for coop player");
	intro1->SetWorldPosition(10, 50);

	auto intro2 = std::make_unique<dae::GameObject>();
	intro2->AddComponent<dae::TextComponent>();
	intro2->GetComponent<dae::TextComponent>()->SetFont(font);
	intro2->GetComponent<dae::TextComponent>()->SetText("Press 3 for coop player");
	intro2->SetWorldPosition(10, 80);

	// Command exercise
	auto burgerGuy = std::make_unique<dae::GameObject>();
	burgerGuy->SetTexture("BurgerTime.png", 16.f, 16.f);
	burgerGuy->SetSourceRectTexture(0, 0, 16, 16);
	burgerGuy->SetLocalPosition({ 222.f, 335.f , 0.f });
	burgerGuy->SetSpeed(0.1f);
	burgerGuy->SetCanCollide(true);
	burgerGuy->SetScaling(2.f, 2.f, 2.f);
	burgerGuy->AddTag(dae::make_sdbm_hash("Player"));
	burgerGuy->AddTag(dae::make_sdbm_hash("Player1"));
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
	burgerGuy2->AddTag(dae::make_sdbm_hash("Player2"));
	burgerGuy2->AddComponent<dae::MoveDownLadderComponent>(0.1f);
	burgerGuy2->AddComponent<dae::PlayerCollisionComponent>();

	auto smallerFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 17);

	auto healthDisplay = std::make_unique<dae::GameObject>();
	healthDisplay->SetTexture("BurgerTime.png", 7, 8);
	healthDisplay->SetSourceRectTexture(201, 0, 7, 8);
	healthDisplay->SetLocalPosition({ 20.f, 445.f, 0.f });
	healthDisplay->SetScaling(2.f, 2.f, 2.f);
	healthDisplay->AddTag(dae::make_sdbm_hash("HealthObComponent"));
	healthDisplay->AddComponent<dae::HealthDisplayComponent>();

	auto moveLeft = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{0.f, -1.f, 0.f});
	auto moveDown = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 0.f, 1.f, 0.f });

	auto moveLeftp1GP = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRightp1GP = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUpp1GP = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 0.f, -1.f, 0.f });
	auto moveDownp1GP = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy, glm::vec3{ 0.f, 1.f, 0.f });

	auto moveLeft2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ -1.f, 0.f, 0.f });
	auto moveRight2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 1.f, 0.f, 0.f });
	auto moveUp2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 0.f, -1.f, 0.f });
	auto moveDown2 = std::make_unique<dae::MoveOnLadderCommand>(*burgerGuy2, glm::vec3{ 0.f, 1.f, 0.f });

	auto playEnterSoundEffect = std::make_unique<dae::PlaySoundCommand>(*burgerGuy, dae::make_sdbm_hash("Enter"));
	auto playMusic = std::make_unique<dae::PlayMusicCommand>(*burgerGuy, dae::make_sdbm_hash("MainMusic"));
	auto pauseMusic = std::make_unique<dae::PauseMusicCommand>(*burgerGuy);
	auto muteCommand = std::make_unique<dae::MuteSoundCommand>(*burgerGuy, 30);
	auto decLivesCommand = std::make_unique<dae::DecreaseLivesCommand>(*burgerGuy);
	auto startSingleGame = std::make_unique<dae::StartSingleGameCommand>(*intro);
	auto startCoopGame = std::make_unique<dae::StartCoopGameCommand>(*intro1);
	auto startVersusGame = std::make_unique<dae::StartVersusGameCommand>(*intro2);
	auto mainMenuCommand = std::make_unique<dae::MainMenuCommand>(*burgerGuy);
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
	input.BindInputKeyboard(SDL_SCANCODE_1, SDL_KEYUP, std::move(startSingleGame));
	input.BindInputKeyboard(SDL_SCANCODE_2, SDL_KEYUP, std::move(startCoopGame));
	input.BindInputKeyboard(SDL_SCANCODE_3, SDL_KEYUP, std::move(startVersusGame));
	input.BindInputKeyboard(SDL_SCANCODE_M, SDL_KEYUP, std::move(mainMenuCommand));

	input.AddController();
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_LEFT, true, std::move(moveLeftp1GP));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_RIGHT, true, std::move(moveRightp1GP));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_UP, true, std::move(moveUpp1GP));
	input.BindInputController(0, XINPUT_GAMEPAD_DPAD_DOWN, true, std::move(moveDownp1GP));

	burgerGuy->GetComponent<dae::PlayerCollisionComponent>()->AddObserver(*healthDisplay->GetComponent<dae::HealthDisplayComponent>()->GetObserver());

	auto scoreDisplay = std::make_unique<dae::GameObject>();
	scoreDisplay->SetLocalPosition({ 100.f, 0.f, 0.f });
	scoreDisplay->SetBoudingBoxDimensions(100.f, 100.f);
	scoreDisplay->SetScaling(1.f, 1.f, 1.f);
	scoreDisplay->AddComponent<dae::TextComponent>();
	scoreDisplay->GetComponent<dae::TextComponent>()->SetFont(font);
	scoreDisplay->AddComponent<dae::ScoreDisplayComponent>();
	scoreDisplay->AddTag(dae::make_sdbm_hash("ScoreObComponent"));

	dae::GameManager::GetInstance().AddScoreObserver(std::move(scoreDisplay));
	dae::GameManager::GetInstance().AddPlayer1(std::move(burgerGuy));
	dae::GameManager::GetInstance().AddPlayer2(std::move(burgerGuy2));
	dae::GameManager::GetInstance().AddHealthObserver(std::move(healthDisplay));

	auto level1 = std::make_unique<dae::Level1>();
	//auto level2 = std::make_unique<dae::Level3>();

	mainMenuScene.Add(std::move(intro));
	mainMenuScene.Add(std::move(intro1));
	mainMenuScene.Add(std::move(intro2));

	dae::SceneManager::GetInstance().SetStartScene(dae::make_sdbm_hash("MainMenu"));
}

int main(int, char* []) 
{
	dae::Minigin engine("../Data/");
	engine.Run(load);

	return 0;
}