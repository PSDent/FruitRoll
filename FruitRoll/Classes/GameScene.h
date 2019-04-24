#pragma once
#include "cocos2d.h"
#include "Fruit.h"
#include "Obstacle.h"
#include "Waterdrop.h"
#include "Board.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;
USING_NS_CC;

class GameScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	int playTime;									// ���� �ð�
	int score;										// ����
	int money;										// ȹ���� �����
	int health;										// ü��
	bool collided;									// �浹 ������ üũ
	string backgroundType;							// ����� ����
	Sprite* backgroundImage;						// ����� �̹���
	Fruit* fruit;									// ����
	Waterdrop* waterdrop;							// �����
	unordered_map<string, Obstacle*> obstacleMap;	// ��ֹ� 
	Board* board1;									// ��������1
	Board* board2;									// ��������2

	void Tick(float f);								// �� �����Ӹ��� ȣ��
	void makeBackground();							// ��� ����
	void MakeFruit();								// ���� ����
	void MakeObject();								// ������Ʈ ����
	void MoveObject();								// ������Ʈ �̵�
	void DeleteObject();							// ������Ʈ ����
	void PrintInfo();								// ���� ���
	void CheckCollide();							// �浹 üũ

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};