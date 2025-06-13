#include "Level2.h"
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

dae::Level2::Level2()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene(make_sdbm_hash("Level2"));
	auto font = dae::ResourceManager::GetInstance().LoadFont("PressStart2P-Regular.ttf", 12);

	auto ladder24 = std::make_unique<dae::GameObject>();
	ladder24->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder24->SetSourceRectTexture(0, 6, 10, 34);
	ladder24->SetLocalPosition({ 228.f, 331.f, 0.f });
	ladder24->SetCanCollide(true);
	ladder24->SetScaling(2.f, 2.f, 2.f);
	ladder24->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder24->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder24));

	auto ladder23 = std::make_unique<dae::GameObject>();
	ladder23->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder23->SetSourceRectTexture(0, 6, 10, 34);
	ladder23->SetLocalPosition({ 228.f, 267.f, 0.f });
	ladder23->SetCanCollide(true);
	ladder23->SetScaling(2.f, 2.f, 2.f);
	ladder23->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder23->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder23));

	auto ladder22 = std::make_unique<dae::GameObject>();
	ladder22->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder22->SetSourceRectTexture(0, 6, 10, 34);
	ladder22->SetLocalPosition({ 180.f, 267.f, 0.f });
	ladder22->SetCanCollide(true);
	ladder22->SetScaling(2.f, 2.f, 2.f);
	ladder22->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder22->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder22));

	auto ladder21 = std::make_unique<dae::GameObject>();
	ladder21->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder21->SetSourceRectTexture(0, 46, 10, 50);
	ladder21->SetLocalPosition({ 276.f, 235.f, 0.f });
	ladder21->SetCanCollide(true);
	ladder21->SetScaling(2.f, 2.f, 2.f);
	ladder21->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder21->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder21));

	auto ladder20 = std::make_unique<dae::GameObject>();
	ladder20->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder20->SetSourceRectTexture(0, 6, 10, 34);
	ladder20->SetLocalPosition({ 228.f, 203.f, 0.f });
	ladder20->SetCanCollide(true);
	ladder20->SetScaling(2.f, 2.f, 2.f);
	ladder20->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder20->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder20));

	auto ladder19 = std::make_unique<dae::GameObject>();
	ladder19->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder19->SetSourceRectTexture(0, 6, 10, 34);
	ladder19->SetLocalPosition({ 228.f, 203.f, 0.f });
	ladder19->SetCanCollide(true);
	ladder19->SetScaling(2.f, 2.f, 2.f);
	ladder19->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder19->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder19));

	auto ladder18 = std::make_unique<dae::GameObject>();
	ladder18->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder18->SetSourceRectTexture(0, 46, 10, 50);
	ladder18->SetLocalPosition({ 180.f, 171.f, 0.f });
	ladder18->SetCanCollide(true);
	ladder18->SetScaling(2.f, 2.f, 2.f);
	ladder18->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder18->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder18));

	auto ladder17 = std::make_unique<dae::GameObject>();
	ladder17->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder17->SetSourceRectTexture(0, 6, 10, 34);
	ladder17->SetLocalPosition({ 420.f, 139.f, 0.f });
	ladder17->SetCanCollide(true);
	ladder17->SetScaling(2.f, 2.f, 2.f);
	ladder17->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder17->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder17));

	auto ladder16 = std::make_unique<dae::GameObject>();
	ladder16->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder16->SetSourceRectTexture(0, 6, 10, 34);
	ladder16->SetLocalPosition({ 372.f, 139.f, 0.f });
	ladder16->SetCanCollide(true);
	ladder16->SetScaling(2.f, 2.f, 2.f);
	ladder16->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder16->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder16));

	auto ladder15 = std::make_unique<dae::GameObject>();
	ladder15->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder15->SetSourceRectTexture(0, 6, 10, 34);
	ladder15->SetLocalPosition({ 324.f, 139.f, 0.f });
	ladder15->SetCanCollide(true);
	ladder15->SetScaling(2.f, 2.f, 2.f);
	ladder15->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder15->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder15));

	auto ladder14 = std::make_unique<dae::GameObject>();
	ladder14->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder14->SetSourceRectTexture(0, 46, 10, 50);
	ladder14->SetLocalPosition({ 276.f, 139.f, 0.f });
	ladder14->SetCanCollide(true);
	ladder14->SetScaling(2.f, 2.f, 2.f);
	ladder14->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder14->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder14));

	auto ladder13 = std::make_unique<dae::GameObject>();
	ladder13->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder13->SetSourceRectTexture(0, 6, 10, 34);
	ladder13->SetLocalPosition({ 228.f, 139.f, 0.f });
	ladder13->SetCanCollide(true);
	ladder13->SetScaling(2.f, 2.f, 2.f);
	ladder13->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder13->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder13));

	auto ladder12 = std::make_unique<dae::GameObject>();
	ladder12->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder12->SetSourceRectTexture(0, 6, 10, 34);
	ladder12->SetLocalPosition({ 132.f, 139.f, 0.f });
	ladder12->SetCanCollide(true);
	ladder12->SetScaling(2.f, 2.f, 2.f);
	ladder12->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder12->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder12));

	auto ladder11 = std::make_unique<dae::GameObject>();
	ladder11->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder11->SetSourceRectTexture(0, 6, 10, 34);
	ladder11->SetLocalPosition({ 84.f, 139.f, 0.f });
	ladder11->SetCanCollide(true);
	ladder11->SetScaling(2.f, 2.f, 2.f);
	ladder11->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder11->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder11));

	auto ladder10 = std::make_unique<dae::GameObject>();
	ladder10->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder10->SetSourceRectTexture(0, 6, 10, 34);
	ladder10->SetLocalPosition({ 36.f, 139.f, 0.f });
	ladder10->SetCanCollide(true);
	ladder10->SetScaling(2.f, 2.f, 2.f);
	ladder10->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder10->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder10));

	auto ladder9 = std::make_unique<dae::GameObject>();
	ladder9->SetTexture("BackgroundSheet.tga", 10, 50);
	ladder9->SetSourceRectTexture(0, 46, 10, 50);
	ladder9->SetLocalPosition({ 180.f, 75.f, 0.f });
	ladder9->SetCanCollide(true);
	ladder9->SetScaling(2.f, 2.f, 2.f);
	ladder9->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder9->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder9));

	auto ladder8 = std::make_unique<dae::GameObject>();
	ladder8->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder8->SetSourceRectTexture(0, 6, 10, 34);
	ladder8->SetLocalPosition({ 420.f, 75.f, 0.f });
	ladder8->SetCanCollide(true);
	ladder8->SetScaling(2.f, 2.f, 2.f);
	ladder8->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder8->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder8));

	auto ladder7 = std::make_unique<dae::GameObject>();
	ladder7->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder7->SetSourceRectTexture(0, 6, 10, 34);
	ladder7->SetLocalPosition({ 372.f, 75.f, 0.f });
	ladder7->SetCanCollide(true);
	ladder7->SetScaling(2.f, 2.f, 2.f);
	ladder7->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder7->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder7));

	auto ladder6 = std::make_unique<dae::GameObject>();
	ladder6->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder6->SetSourceRectTexture(0, 6, 10, 34);
	ladder6->SetLocalPosition({ 324.f, 75.f, 0.f });
	ladder6->SetCanCollide(true);
	ladder6->SetScaling(2.f, 2.f, 2.f);
	ladder6->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder6->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder6));

	auto ladder5 = std::make_unique<dae::GameObject>();
	ladder5->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder5->SetSourceRectTexture(0, 6, 10, 34);
	ladder5->SetLocalPosition({ 276.f, 75.f, 0.f });
	ladder5->SetCanCollide(true);
	ladder5->SetScaling(2.f, 2.f, 2.f);
	ladder5->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder5->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder5));

	auto ladder4 = std::make_unique<dae::GameObject>();
	ladder4->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder4->SetSourceRectTexture(0, 6, 10, 34);
	ladder4->SetLocalPosition({ 228.f, 75.f, 0.f });
	ladder4->SetCanCollide(true);
	ladder4->SetScaling(2.f, 2.f, 2.f);
	ladder4->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder4->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder4));

	auto ladder3 = std::make_unique<dae::GameObject>();
	ladder3->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder3->SetSourceRectTexture(0, 6, 10, 34);
	ladder3->SetLocalPosition({ 132.f, 75.f, 0.f });
	ladder3->SetCanCollide(true);
	ladder3->SetScaling(2.f, 2.f, 2.f);
	ladder3->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder3->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder3));

	auto ladder2 = std::make_unique<dae::GameObject>();
	ladder2->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder2->SetSourceRectTexture(0, 6, 10, 34);
	ladder2->SetLocalPosition({ 84.f, 75.f, 0.f });
	ladder2->SetCanCollide(true);
	ladder2->SetScaling(2.f, 2.f, 2.f);
	ladder2->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder2->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder2));

	auto ladder1 = std::make_unique<dae::GameObject>();
	ladder1->SetTexture("BackgroundSheet.tga", 10, 34);
	ladder1->SetSourceRectTexture(0, 6, 10, 34);
	ladder1->SetLocalPosition({ 36.f, 75.f, 0.f });
	ladder1->SetCanCollide(true);
	ladder1->SetScaling(2.f, 2.f, 2.f);
	ladder1->AddTag(dae::make_sdbm_hash("Ladder"));
	ladder1->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladder1));

	auto ladderPlatform = std::make_unique<dae::GameObject>();
	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 30.f, 78.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 78.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 78.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 78.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 414.f, 78.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 30.f, 108.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 108.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 108.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 30.f, 142.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 142.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 142.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 142.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 414.f, 142.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 174.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 174.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 174.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 414.f, 174.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 30.f, 206.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 206.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 206.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 206.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 414.f, 206.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 238.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 238.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 270.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 270.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 302.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 302.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 126.f, 334.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 334.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 318.f, 334.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	ladderPlatform->SetTexture("BackgroundSheet.tga", 16, 3);
	ladderPlatform->SetSourceRectTexture(0, 3, 16, 3);
	ladderPlatform->SetLocalPosition({ 222.f, 398.f, 0.f });
	ladderPlatform->SetScaling(2.f, 2.f, 2.f);
	ladderPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	ladderPlatform->SetCanCollide(true);
	ladderPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(ladderPlatform));

	ladderPlatform.reset(std::make_unique<dae::GameObject>().release());

	auto burgerPlatform = std::make_unique<dae::GameObject>();
	float xOffset = 96.f;
	for (int i{}; i < 4; ++i)
	{
		burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
		burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
		burgerPlatform->SetLocalPosition({ 62.f + i * xOffset, 78.f, 0.f });
		burgerPlatform->SetScaling(2.f, 2.f, 2.f);
		burgerPlatform->SetCanCollide(true);
		burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
		burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
		burgerPlatform->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(burgerPlatform));

		burgerPlatform.reset(new dae::GameObject);
	}

	for (int i{}; i < 2; ++i)
	{
		burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
		burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
		burgerPlatform->SetLocalPosition({ 62.f + i * xOffset, 108.f, 0.f });
		burgerPlatform->SetScaling(2.f, 2.f, 2.f);
		burgerPlatform->SetCanCollide(true);
		burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
		burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
		burgerPlatform->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(burgerPlatform));

		burgerPlatform.reset(new dae::GameObject);
	}

	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 62.f, 142.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);

	for (int i{}; i < 2; ++i)
	{
		burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
		burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
		burgerPlatform->SetLocalPosition({ 254.f + i * xOffset, 142.f, 0.f });
		burgerPlatform->SetScaling(2.f, 2.f, 2.f);
		burgerPlatform->SetCanCollide(true);
		burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
		burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
		burgerPlatform->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(burgerPlatform));

		burgerPlatform.reset(new dae::GameObject);
	}

	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 158.f, 174.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);


	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 350.f, 174.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);

	for (int i{}; i < 4; ++i)
	{
		burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
		burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
		burgerPlatform->SetLocalPosition({ 62.f + i * xOffset, 206.f, 0.f });
		burgerPlatform->SetScaling(2.f, 2.f, 2.f);
		burgerPlatform->SetCanCollide(true);
		burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
		burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
		burgerPlatform->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(burgerPlatform));

		burgerPlatform.reset(new dae::GameObject);
	}

	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 254.f, 238.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);

	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 158.f, 270.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);

	burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
	burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
	burgerPlatform->SetLocalPosition({ 254.f, 302.f, 0.f });
	burgerPlatform->SetScaling(2.f, 2.f, 2.f);
	burgerPlatform->SetCanCollide(true);
	burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
	burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
	burgerPlatform->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(burgerPlatform));

	burgerPlatform.reset(new dae::GameObject);

	for (int i{}; i < 2; ++i)
	{
		burgerPlatform->SetTexture("BackgroundSheet.tga", 32, 3);
		burgerPlatform->SetSourceRectTexture(0, 0, 32, 3);
		burgerPlatform->SetLocalPosition({ 158.f + i * xOffset, 334.f, 0.f });
		burgerPlatform->SetScaling(2.f, 2.f, 2.f);
		burgerPlatform->SetCanCollide(true);
		burgerPlatform->AddTag(dae::make_sdbm_hash("BurgerPlatform"));
		burgerPlatform->AddTag(dae::make_sdbm_hash("LadderPlatform"));
		burgerPlatform->AddComponent<dae::CollisionComponent>();
		scene.Add(std::move(burgerPlatform));

		burgerPlatform.reset(new dae::GameObject);
	}

	auto plate = std::make_unique<dae::GameObject>();
	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 59.f, 409.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 154.f, 441.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 250.f, 441.f, 0.f });
	plate->SetScaling(2.f, 2.f, 2.f);
	plate->SetCanCollide(true);
	plate->AddTag(dae::make_sdbm_hash("Plate"));
	plate->AddComponent<dae::CollisionComponent>();
	scene.Add(std::move(plate));

	plate.reset(new dae::GameObject);

	plate->SetTexture("BackgroundSheet.tga", 38, 6);
	plate->SetSourceRectTexture(0, 40, 38, 6);
	plate->SetLocalPosition({ 346.f, 409.f, 0.f });
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

	auto burgerBunTop = std::make_unique<dae::GameObject>();
	burgerBunTop->SetLocalPosition({ 63.f, 68.f, 0.f });
	burgerBunTop->SetShouldRender(false);
	burgerBunTop->SetCanCollide(true);
	burgerBunTop->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBunTop->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 49, burgerBunTop.get(), scene);

	burgerBunTop->AddTag(dae::make_sdbm_hash("FoodParent"));
	burgerBunTop->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBunTop->AddComponent<dae::BurgerCollisionComponent>();
	burgerBunTop->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	burgerBunTop->AddComponent<dae::TopBurgerComponent>();
	burgerBunTop->GetComponent<dae::TopBurgerComponent>()->AddObserver(*endLevel->GetComponent<dae::EndLevelComponent>()->GetObserver());

	scene.Add(std::move(burgerBunTop));

	burgerBunTop.reset(new GameObject);



	auto lettuce = std::make_unique<dae::GameObject>();
	lettuce->SetLocalPosition({ 63.f, 133.f, 0.f });
	lettuce->SetShouldRender(false);
	lettuce->SetCanCollide(true);
	lettuce->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	lettuce->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 89, lettuce.get(), scene);

	lettuce->AddTag(dae::make_sdbm_hash("FoodParent"));
	lettuce->AddComponent<dae::FoodFallingComponent>(0.2f);
	lettuce->AddComponent<dae::BurgerCollisionComponent>();
	lettuce->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(lettuce));

	lettuce.reset(new GameObject);

	auto beef = std::make_unique<dae::GameObject>();
	beef->SetLocalPosition({ 65.f, 195.f, 0.f });
	beef->SetShouldRender(false);
	beef->SetCanCollide(true);
	beef->SetBoudingBoxDimensions(7.f * 4.f, 7.f);
	beef->SetScaling(2.f, 2.f, 2.f);
	beef->AddTag(dae::make_sdbm_hash("FoodParent"));

	MakeBurgerParts(7, 73, beef.get(), scene);

	beef->AddComponent<dae::FoodFallingComponent>(0.2f);
	beef->AddComponent<dae::BurgerCollisionComponent>();
	beef->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(beef));

	beef.reset(new GameObject);

	auto burgerBunBottom = std::make_unique<dae::GameObject>();
	int offsetBurgerBun{ 96 };
	for (int i{}; i < 4; ++i)
	{
		burgerBunBottom->SetLocalPosition({ 62.f + offsetBurgerBun * i, 356.f, 0.f });
		burgerBunBottom->SetShouldRender(false);
		burgerBunBottom->SetCanCollide(true);
		burgerBunBottom->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
		burgerBunBottom->SetScaling(2.f, 2.f, 2.f);

		MakeBurgerParts(offset, 57, burgerBunBottom.get(), scene);

		burgerBunBottom->AddTag(dae::make_sdbm_hash("FoodParent"));
		burgerBunBottom->AddComponent<dae::FoodFallingComponent>(0.2f);
		burgerBunBottom->AddComponent<dae::BurgerCollisionComponent>();
		burgerBunBottom->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
		scene.Add(std::move(burgerBunBottom));

		burgerBunBottom.reset(new GameObject);
	}

	// Second column
	burgerBunTop->SetLocalPosition({ 159.f, 68.f, 0.f });
	burgerBunTop->SetShouldRender(false);
	burgerBunTop->SetCanCollide(true);
	burgerBunTop->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBunTop->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 49, burgerBunTop.get(), scene);

	burgerBunTop->AddTag(dae::make_sdbm_hash("FoodParent"));
	burgerBunTop->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBunTop->AddComponent<dae::BurgerCollisionComponent>();
	burgerBunTop->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	burgerBunTop->AddComponent<dae::TopBurgerComponent>();
	burgerBunTop->GetComponent<dae::TopBurgerComponent>()->AddObserver(*endLevel->GetComponent<dae::EndLevelComponent>()->GetObserver());

	scene.Add(std::move(burgerBunTop));

	burgerBunTop.reset(new GameObject);

	lettuce->SetLocalPosition({ 159.f, 226.f, 0.f });
	lettuce->SetShouldRender(false);
	lettuce->SetCanCollide(true);
	lettuce->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	lettuce->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 89, lettuce.get(), scene);

	lettuce->AddTag(dae::make_sdbm_hash("FoodParent"));
	lettuce->AddComponent<dae::FoodFallingComponent>(0.2f);
	lettuce->AddComponent<dae::BurgerCollisionComponent>();
	lettuce->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(lettuce));

	lettuce.reset(new GameObject);

	beef->SetLocalPosition({ 159.f, 292.f, 0.f });
	beef->SetShouldRender(false);
	beef->SetCanCollide(true);
	beef->SetBoudingBoxDimensions(7.f * 4.f, 7.f);
	beef->SetScaling(2.f, 2.f, 2.f);
	beef->AddTag(dae::make_sdbm_hash("FoodParent"));

	MakeBurgerParts(7, 73, beef.get(), scene);

	beef->AddComponent<dae::FoodFallingComponent>(0.2f);
	beef->AddComponent<dae::BurgerCollisionComponent>();
	beef->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(beef));

	beef.reset(new GameObject);

	// Third column
	burgerBunTop->SetLocalPosition({ 255.f, 131.f, 0.f });
	burgerBunTop->SetShouldRender(false);
	burgerBunTop->SetCanCollide(true);
	burgerBunTop->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBunTop->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 49, burgerBunTop.get(), scene);

	burgerBunTop->AddTag(dae::make_sdbm_hash("FoodParent"));
	burgerBunTop->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBunTop->AddComponent<dae::BurgerCollisionComponent>();
	burgerBunTop->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	burgerBunTop->AddComponent<dae::TopBurgerComponent>();
	burgerBunTop->GetComponent<dae::TopBurgerComponent>()->AddObserver(*endLevel->GetComponent<dae::EndLevelComponent>()->GetObserver());

	scene.Add(std::move(burgerBunTop));

	burgerBunTop.reset(new GameObject);

	lettuce->SetLocalPosition({ 254.f, 228.f, 0.f });
	lettuce->SetShouldRender(false);
	lettuce->SetCanCollide(true);
	lettuce->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	lettuce->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 89, lettuce.get(), scene);

	lettuce->AddTag(dae::make_sdbm_hash("FoodParent"));
	lettuce->AddComponent<dae::FoodFallingComponent>(0.2f);
	lettuce->AddComponent<dae::BurgerCollisionComponent>();
	lettuce->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(lettuce));

	lettuce.reset(new GameObject);

	beef->SetLocalPosition({ 258.f, 292.f, 0.f });
	beef->SetShouldRender(false);
	beef->SetCanCollide(true);
	beef->SetBoudingBoxDimensions(7.f * 4.f, 7.f);
	beef->SetScaling(2.f, 2.f, 2.f);
	beef->AddTag(dae::make_sdbm_hash("FoodParent"));

	MakeBurgerParts(7, 73, beef.get(), scene);

	beef->AddComponent<dae::FoodFallingComponent>(0.2f);
	beef->AddComponent<dae::BurgerCollisionComponent>();
	beef->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(beef));

	beef.reset(new GameObject);

	// Fourth column
	burgerBunTop->SetLocalPosition({ 351.f, 131.f, 0.f });
	burgerBunTop->SetShouldRender(false);
	burgerBunTop->SetCanCollide(true);
	burgerBunTop->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	burgerBunTop->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 49, burgerBunTop.get(), scene);

	burgerBunTop->AddTag(dae::make_sdbm_hash("FoodParent"));
	burgerBunTop->AddComponent<dae::FoodFallingComponent>(0.2f);
	burgerBunTop->AddComponent<dae::BurgerCollisionComponent>();
	burgerBunTop->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	burgerBunTop->AddComponent<dae::TopBurgerComponent>();
	burgerBunTop->GetComponent<dae::TopBurgerComponent>()->AddObserver(*endLevel->GetComponent<dae::EndLevelComponent>()->GetObserver());

	scene.Add(std::move(burgerBunTop));

	burgerBunTop.reset(new GameObject);

	lettuce->SetLocalPosition({ 352.f, 196.f, 0.f });
	lettuce->SetShouldRender(false);
	lettuce->SetCanCollide(true);
	lettuce->SetBoudingBoxDimensions(8.f * 4.f, 7.f);
	lettuce->SetScaling(2.f, 2.f, 2.f);

	MakeBurgerParts(offset, 89, lettuce.get(), scene);

	lettuce->AddTag(dae::make_sdbm_hash("FoodParent"));
	lettuce->AddComponent<dae::FoodFallingComponent>(0.2f);
	lettuce->AddComponent<dae::BurgerCollisionComponent>();
	lettuce->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(lettuce));

	lettuce.reset(new GameObject);

	beef->SetLocalPosition({ 356.f, 260.f, 0.f });
	beef->SetShouldRender(false);
	beef->SetCanCollide(true);
	beef->SetBoudingBoxDimensions(7.f * 4.f, 7.f);
	beef->SetScaling(2.f, 2.f, 2.f);
	beef->AddTag(dae::make_sdbm_hash("FoodParent"));

	MakeBurgerParts(7, 73, beef.get(), scene);

	beef->AddComponent<dae::FoodFallingComponent>(0.2f);
	beef->AddComponent<dae::BurgerCollisionComponent>();
	beef->GetComponent<dae::BurgerCollisionComponent>()->AddObserver(*GameManager::GetInstance().ScoreObserverObject()->GetComponent<dae::ScoreDisplayComponent>()->GetObserver());
	scene.Add(std::move(beef));

	beef.reset(new GameObject);

	scene.Add(std::move(endLevel));
}

void dae::Level2::MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene)
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
