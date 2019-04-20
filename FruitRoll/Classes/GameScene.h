#pragma once
#include "cocos2d.h"
#include "Fruit.h"
#include "Obstacle.h"
#include "Waterdrop.h"
#include "Board.h"

using namespace std;
USING_NS_CC;

class GameScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	int playTime;						// ���� �ð�
	int score;							// ����
	int money;							// ȹ���� �����
	string backgroundType;				// ����� ����
	Sprite* backgroundImage;			// ����� �̹���
	Fruit* fruit;						// ����
	list<Waterdrop*> waterdropList;		// ����� ����Ʈ
	list<Obstacle*> obstacleList;		// ��ֹ� ����Ʈ
	list<Board*> boardList;				// ������ ����Ʈ

	void makeBackground();				// ��� ����
	void MakeFruit();					// ���� ����
	void MakeObject(float f);			// ������Ʈ �ڵ�����
	void DeleteObject(float f);			// ������Ʈ ����
	void PrintInfo();					// ���� ���
	void RunAudio();					// ����� ����
	void MakeBoard();					// ������ ����


	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};