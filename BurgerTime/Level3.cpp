#include "Level3.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Utils.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "BurgerPartsCollisionComponent.h"
#include "FoodFallingComponent.h"
#include "BurgerCollisionComponent.h"
#include "TopBurgerComponent.h"
#include "EndLevelComponent.h"
#include "GameManager.h"
#include "ScoreDisplayComponent.h"
#include "Components/MoveDownLadderComponent.h"
#include "Components/PlayerCollisionComponent.h"
#include "EnemyStateComponent.h"
#include "EnemyComponent.h"

dae::Level3::Level3()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene(make_sdbm_hash("Level3"));
	auto font = dae::ResourceManager::GetInstance().LoadFont("PressStart2P-Regular.ttf", 12);

	float xOffset{ 96.f };
	float yOffset{ 32.f };
	auto ladder = std::make_unique<dae::GameObject>();
	for (int i{}; i < 5; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 36.f + xOffset * i, 75.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 84.f + xOffset * i, 107.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 2; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 36.f + xOffset * i, 139.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 2; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 324.f + xOffset * i, 139.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 84.f + xOffset * i, 172.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	xOffset = 192.f;
	for (int i{}; i < 2; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 132.f + xOffset * i, 139.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 2; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 132.f + xOffset * i, 203.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	xOffset = 96.f;
	for (int i{}; i < 4; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 84.f + xOffset * i, 236.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	for (int i{}; i < 3; ++i)
	{
		ladder->SetTexture("BackgroundSheet.tga", 10, 18);
		ladder->SetSourceRectTexture(0, 96, 10, 18);
		ladder->SetLocalPosition({ 132.f + xOffset * i, 268.f, 0.f });
		ladder->SetCanCollide(true);
		ladder->SetScaling(2.f, 2.f, 2.f);
		ladder->AddTag(dae::make_sdbm_hash("Ladder"));
		ladder->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(ladder));

		ladder.reset(new dae::GameObject);
	}

	ladder->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder->SetSourceRectTexture(0, 46, 10, 50);
	ladder->SetLocalPosition({ 228.f, 139.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder));

	ladder.reset(new dae::GameObject);

	ladder->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder->SetSourceRectTexture(0, 46, 10, 50);
	ladder->SetLocalPosition({ 36.f, 204.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder));

	ladder.reset(new dae::GameObject);

	ladder->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder->SetSourceRectTexture(0, 46, 10, 50);
	ladder->SetLocalPosition({ 420.f, 204.f, 0.f });
	ladder->SetCanCollide(true);
	ladder->SetScaling(2.f, 2.f, 2.f);
	ladder->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder));

	ladder.reset(new dae::GameObject);

	auto burgerPlatform = std::make_unique<dae::GameObject>();
	for (int x{}; x < 4; ++x)
	{
		for (int y{}; y < 8; ++y)
		{
			burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
			burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
			burgerPlatform->SetLocalPosition({ 62.f + x * xOffset, 78.f + y * yOffset, 0.f });
			burgerPlatform->SetScaling(2.f, 2.f, 2.f);
			burgerPlatform->SetCanCollide(true);
			burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
			burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
			burgerPlatform->AddComponent<dae::CollisionComponent>();
			scene.Add(std::move(burgerPlatform));

			burgerPlatform.reset(new dae::GameObject);
		}
	}

	auto ladderPlatform = std::make_unique<dae::GameObject>();
	for (int x{}; x < 5; ++x)
	{
		for (int y{}; y < 8; ++y)
		{
			ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
			ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
			ladderPlatform->SetLocalPosition({ 30.f + x * xOffset, 78.f + y * yOffset, 0.f });
			ladderPlatform->SetScaling(2.f, 2.f, 2.f);
			ladderPlatform->SetCanCollide(true);
			ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
			ladderPlatform->AddComponent<dae::CollisionComponent>();
			scene.Add(std::move(ladderPlatform));

			ladderPlatform.reset(new dae::GameObject);
		}
	}

	auto plate = std::make_unique<dae::GameObject>();
	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 56.f, 445.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 154.f, 445.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 250.f, 445.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 346.f, 445.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	auto endLevel = std::make_unique<dae::GameObject>();
	endLevel->SetLocalPosition({ 100.f, 0.f, 0.f });
	endLevel->SetBoudingBoxDimensions(100.f, 100.f);
	endLevel->SetScaling(1.f, 1.f, 1.f);
	endLevel->AddComponent<dae::EndLevelComponent>();

	int offset = 8;

	auto burgerPart = std::make_unique<dae::GameObject>();
	int offsetBurgerBun{ 96 };
	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 67.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(offset, 49, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		burgerPart->AddComponent<dae::TopBurgerComponent>();
		burgerPart->GetComponent<dae::TopBurgerComponent>()->AddObserver(*endLevel->GetComponent<dae::EndLevelComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 98.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(offset, 89, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 163.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(7, 73, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 197.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(8, 81, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 226.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(7, 65, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	for (int i{}; i < 4; ++i)
	{
		burgerPart->SetLocalPosition({ 63.f + offsetBurgerBun * i, 293.f, 0.f });
		burgerPart->SetShouldRender(false);
		burgerPart->SetCanCollide(true);
		burgerPart->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerPart->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(offset, 57, burgerPart.get(), scene);

		burgerPart->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerPart->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerPart->AddComponent<dae::BurgerCollisionComponent>();
		burgerPart->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerPart));

		burgerPart.reset(new GameObject);
	}

	auto mrHotDog = std::make_unique<dae::GameObject>();
	mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog->SetLocalPosition({ 30.f, 48.f, 0.f });
	mrHotDog->SetSpeed(0.1f);
	mrHotDog->SetCanCollide(true);
	mrHotDog->SetScaling(2.f, 2.f, 2.f);
	mrHotDog->SetAmountFrames(2);
	mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	mrHotDog->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrHotDog->AddComponent<dae::EnemyComponent>(glm::vec3{ 30.f, 48.f, 0.f });
	scene.Add(std::move(mrHotDog));

	mrHotDog.reset(new GameObject);

	mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog->SetLocalPosition({ 415.f, 48.f, 0.f });
	mrHotDog->SetSpeed(0.1f);
	mrHotDog->SetCanCollide(true);
	mrHotDog->SetScaling(2.f, 2.f, 2.f);
	mrHotDog->SetAmountFrames(2);
	mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	mrHotDog->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrHotDog->AddComponent<dae::EnemyComponent>(glm::vec3{ 415.f, 48.f, 0.f });
	scene.Add(std::move(mrHotDog));

	mrHotDog.reset(new GameObject);

	mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog->SetLocalPosition({ 30.f, 177.f, 0.f });
	mrHotDog->SetSpeed(0.1f);
	mrHotDog->SetCanCollide(true);
	mrHotDog->SetScaling(2.f, 2.f, 2.f);
	mrHotDog->SetAmountFrames(2);
	mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	mrHotDog->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrHotDog->AddComponent<dae::EnemyComponent>(glm::vec3{ 30.f, 177.f, 0.f });
	scene.Add(std::move(mrHotDog));
	mrHotDog.reset(new GameObject);

	mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	mrHotDog->SetLocalPosition({ 415.f, 177.f, 0.f });
	mrHotDog->SetSpeed(0.1f);
	mrHotDog->SetCanCollide(true);
	mrHotDog->SetScaling(2.f, 2.f, 2.f);
	mrHotDog->SetAmountFrames(2);
	mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	mrHotDog->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrHotDog->AddComponent<dae::EnemyComponent>(glm::vec3{ 415.f, 177.f, 0.f });
	scene.Add(std::move(mrHotDog));
	mrHotDog.reset(new GameObject);

	auto mrEgg = std::make_unique<dae::GameObject>();
	mrEgg->SetTexture("BurgerTime.png", 16.f, 16.f);
	mrEgg->SetSourceRectTexture(0, 96, 16, 16);
	mrEgg->SetLocalPosition({ 125.f, 240.f, 0.f });
	mrEgg->SetSpeed(0.1f);
	mrEgg->SetCanCollide(true);
	mrEgg->SetScaling(2.f, 2.f, 2.f);
	mrEgg->SetAmountFrames(2);
	mrEgg->AddTag(dae::make_sdbm_hash("Enemy"));
	mrEgg->AddTag(dae::make_sdbm_hash("MrEgg"));
	mrEgg->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrEgg->AddComponent<dae::PlayerCollisionComponent>();
	mrEgg->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrEgg->AddComponent<dae::EnemyComponent>(glm::vec3{ 125.f, 240.f, 0.f });
	scene.Add(std::move(mrEgg));

	auto mrPickle = std::make_unique<dae::GameObject>();
	mrPickle->SetTexture("BurgerTime.png", 16.f, 16.f);
	mrPickle->SetSourceRectTexture(0, 64, 16, 16);
	mrPickle->SetLocalPosition({ 317.f, 112.f, 0.f });
	mrPickle->SetSpeed(0.1f);
	mrPickle->SetCanCollide(true);
	mrPickle->SetScaling(2.f, 2.f, 2.f);
	mrPickle->SetAmountFrames(2);
	mrPickle->AddTag(dae::make_sdbm_hash("Enemy"));
	mrPickle->AddTag(dae::make_sdbm_hash("MrPickle"));
	mrPickle->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	mrPickle->AddComponent<dae::PlayerCollisionComponent>();
	mrPickle->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	mrPickle->AddComponent<dae::EnemyComponent>(glm::vec3{ 317.f, 112.f, 0.f });
	scene.Add(std::move(mrPickle));

	scene.Add(std::move(endLevel));
}

void dae::Level3::MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene)
{
	auto burgerBunPart = std::make_unique<GameObject>();
	for (int i{}; i < 4; ++i)
	{
		burgerBunPart->SetTexture("BurgerTime.png", static_cast<float>(xOffset), 7.f);
		burgerBunPart->SetSourceRectTexture(112 + xOffset * i, yOffset, xOffset, 7);
		burgerBunPart->SetScaling(2.f, 2.f, 2.f);
		burgerBunPart->SetLocalPosition({ 0.f + burgerBunPart->GetBoundingBox()->w * i, 0.f, 0.f });
		burgerBunPart->SetCanCollide(true);
		burgerBunPart->AddComponent<dae::BurgerPartsCollisionComponent>(i);
		burgerBunPart->SetParent(parent);
		burgerBunPart->AddTag(dae::make_sdbm_hash("Food"));
		scene.Add(std::move(burgerBunPart));

		burgerBunPart.reset(new GameObject);
	}
}
