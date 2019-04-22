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

	int playTime;						// ���� �ð�
	int score;							// ����
	int money;							// ȹ���� �����
	int health;							// ü��
	string backgroundType;				// ����� ����
	Sprite* backgroundImage;			// ����� �̹���
	Fruit* fruit;						// ����
	list<Waterdrop*> waterdropList;		// ����� ����Ʈ
	list<Obstacle*> obstacleList;		// ��ֹ� ����Ʈ
	list<Board*> boardList;				// �������� ����Ʈ

	void Tick(float f);					// �� �����Ӹ��� ȣ��
	void makeBackground();				// ��� ����
	void MakeFruit();					// ���� ����
	void MakeObject(float f);			// ������Ʈ �ڵ�����
	void MakeBoard();					// �������� ����
	void DeleteObject();				// ������Ʈ ����
	void PrintInfo();					// ���� ���
	void RunAudio();					// ����� ����
	void CheckCollide();				// �浹 üũ

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};