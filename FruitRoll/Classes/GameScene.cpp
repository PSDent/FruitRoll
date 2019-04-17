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

	makeBackground();
	MakeFruit();
	this->schedule(schedule_selector(GameScene::MakeObject), 3);
	this->schedule(schedule_selector(GameScene::DeleteObject));

	return true;
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
}

// ���� �߰�
void GameScene::MakeFruit() {
	fruit = new Fruit("Apple");
	this->addChild(fruit->fruitImage, 10);
	fruit->Rotate();
	fruit->Jump();
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
		this->addChild(waterdrop->waterdropImage, 1);
		waterdropList.push_back(waterdrop);
		break;
	case 1:
		obstacle = new Obstacle("Fixed");
		this->addChild(obstacle->obstacleImage, 1);
		obstacleList.push_back(obstacle);
		break;
	case 2:
		obstacle = new Obstacle("Falling");
		this->addChild(obstacle->obstacleImage, 1);
		obstacleList.push_back(obstacle);
		break;
	}
}

// ������Ʈ �ڵ�����
// ��ǥ ������ �������� �� ����
void GameScene::DeleteObject(float f) {
	if (!obstacleList.empty() && obstacleList.front()->needDelete) {
		this->removeChild(obstacleList.front()->obstacleImage);
		delete obstacleList.front();
		obstacleList.pop_front();
	}
	if (!waterdropList.empty() &&waterdropList.front()->needDelete) {
		this->removeChild(waterdropList.front()->waterdropImage);
		delete waterdropList.front();
		waterdropList.pop_front();
	}
}