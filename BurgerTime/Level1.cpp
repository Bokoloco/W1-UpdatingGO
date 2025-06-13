#include "Level1.h"
#include "GameObject.h"
#include "Utils.h"
#include "CollisionComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "BurgerCollisionComponent.h"
#include "BurgerPartsCollisionComponent.h"
#include "ScoreObserver.h"
#include "./Components/TextComponent.h"
#include "ScoreDisplayComponent.h"
#include "FoodFallingComponent.h"
#include "Components/MoveDownLadderComponent.h"
#include "Components/PlayerCollisionComponent.h"
#include "EnemyStateComponent.h"
#include "GameManager.h"
#include "TopBurgerComponent.h"
#include "EndLevelObserver.h"
#include "EndLevelComponent.h"

dae::Level1::Level1(unsigned int sceneName)
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene(sceneName);
	auto font = dae::ResourceManager::GetInstance().LoadFont("PressStart2P-Regular.ttf", 12);

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
	ladder10->SetLocalPosition({ 228.f, 171.f, 0.f });
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

	//auto pEndLevelObserver = std::make_unique<dae::EndLevelObserver>();
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

	//auto mrHotDog = std::make_unique<dae::GameObject>();
	//mrHotDog->SetTexture("BurgerTime.png", 15.f, 16.f);
	//mrHotDog->SetSourceRectTexture(1, 32, 15, 16);
	//mrHotDog->SetLocalPosition({ 100.f, 175.f, 0.f });
	//mrHotDog->SetSpeed(0.1f);
	//mrHotDog->SetCanCollide(true);
	//mrHotDog->SetScaling(2.f, 2.f, 2.f);
	//mrHotDog->SetAmountFrames(2);
	//mrHotDog->AddTag(dae::make_sdbm_hash("Enemy"));
	//mrHotDog->AddTag(dae::make_sdbm_hash("MrHotDog"));
	//mrHotDog->AddComponent<dae::MoveDownLadderComponent>(0.07f);
	//mrHotDog->AddComponent<dae::PlayerCollisionComponent>();
	//mrHotDog->AddComponent<dae::EnemyStateComponent>(*dae::GameManager::GetInstance().Player1());
	//scene.Add(std::move(mrHotDog));

	scene.Add(std::move(endLevel));
}

void dae::Level1::MakeBurgerParts(int offset, int yOffset, GameObject* parent, Scene& scene)
{
	auto burgerBunPart = std::make_unique<GameObject>();
	for (int i{}; i < 4; ++i)
	{
		burgerBunPart->SetTexture("BurgerTime.png", static_cast<float>(offset), 7.f);
		burgerBunPart->SetSourceRectTexture(112 + offset * i, yOffset, offset, 7);
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
