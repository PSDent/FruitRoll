#include "GameScene.h"

Scene* GameScene::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	backgroundType = "KitchenStage";
	health = 10;
	score = 0;
	MakeFruit();
	makeBackground();
	this->schedule(schedule_selector(GameScene::MakeObject), 3);
	this->schedule(schedule_selector(GameScene::Tick));
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/bgm.wav", true);
	
	return true;
}

void GameScene::Tick(float f) {
	DeleteObject();
	CheckCollide();
	for (auto board : boardList) {
		if (board->CheckNeedMake())
			MakeBoard();
	}
}

// ��� �߰�
void GameScene::makeBackground() {

	// sceneType ���ϱ�
	backgroundImage = Sprite::create("images\\" + backgroundType + ".png");
	backgroundImage->setAnchorPoint(Point::ZERO);

	// ȭ�鿡 ���缭 ����� ũ�� �����ϱ�
	auto visibleSize = Director::getInstance()->getVisibleSize();
	backgroundImage->setScale(visibleSize.width / backgroundImage->getContentSize().width, visibleSize.height / backgroundImage->getContentSize().height);

	this->addChild(backgroundImage, 0);

	MakeBoard();
	MakeBoard();
	boardList.front()->boardImage->setPosition(boardList.front()->boardImage->getContentSize().width / 2, 200);
	boardList.front()->madeBoard = true;
}

// ���� �߰�
void GameScene::MakeFruit() {
	fruit = new Fruit("Apple");
	this->addChild(fruit->fruitImage, 10);
	fruit->Rotate();
}

// ������Ʈ(��ֹ�, �����) �ڵ�����
void GameScene::MakeObject(float f) {
	// �������� ������Ʈ�� ���� ���� 1. ����� 2. �����̴� ��ֹ� 3. �������� ��ֹ�
	srand(time(NULL));
	int random = rand() % 3;

	Waterdrop* waterdrop;
	Obstacle* obstacle;

	switch (random) {
	case 0:
		waterdrop = new Waterdrop();
		this->addChild(waterdrop->waterdropImage, 2);
		waterdropList.push_back(waterdrop);
		break;
	case 1:
		obstacle = new Obstacle("Fixed");
		this->addChild(obstacle->obstacleImage, 2);
		obstacleList.push_back(obstacle);
		break;
	case 2:
		obstacle = new Obstacle("Falling");
		this->addChild(obstacle->obstacleImage, 2);
		obstacleList.push_back(obstacle);
		break;
	}
}

// ������Ʈ �ڵ�����
// ��ǥ ������ �������� �� ����
void GameScene::DeleteObject() {
	if (!waterdropList.empty() && waterdropList.front()->CheckNeedDelete()) {
		this->removeChild(waterdropList.front()->waterdropImage);
		delete waterdropList.front();
		waterdropList.pop_front();
	}
	if (!obstacleList.empty() && obstacleList.front()->CheckNeedDelete()) {
		this->removeChild(obstacleList.front()->obstacleImage);
		delete obstacleList.front();
		obstacleList.pop_front();
	}
	if (!boardList.empty() && boardList.front()->CheckNeedDelete()) {
		this->removeChild(boardList.front()->boardImage);
		delete boardList.front();
		boardList.pop_front();
	}
}

// �������� ����
// �������� ����Ʈ�� ù��° ��������Ʈ�� 0�� �������� �� ȣ��
void GameScene::MakeBoard() {
	Board* board = new Board();
	this->addChild(board->boardImage, 1);
	boardList.push_back(board);
}

// �浹 üũ
void GameScene::CheckCollide() {
	auto fruitBoundingbox = fruit->fruitImage->getBoundingBox();
	for (list<Waterdrop*>::iterator i = waterdropList.begin(); i != waterdropList.end();) {
		auto waterdropBoundingbox = (*i)->waterdropImage->getBoundingBox();
		if (fruitBoundingbox.intersectsRect(waterdropBoundingbox)) {
			SimpleAudioEngine::sharedEngine()->playEffect("sounds/waterdrop.wav");
			score++;
			this->removeChild((*i)->waterdropImage);
			delete *i;
			i = waterdropList.erase(i);
		}
		else
			i++;
	}

	for (Obstacle* obstacle : obstacleList) {
		auto obstacleBoundingbox = obstacle->obstacleImage->getBoundingBox();
		if (fruitBoundingbox.intersectsRect(obstacleBoundingbox)) {
			health--;
			fruit->PlayAnimation();
		}
	}
}