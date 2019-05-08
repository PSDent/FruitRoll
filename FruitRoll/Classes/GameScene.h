#pragma once
#include "cocos2d.h"
#include "Fruit.h"
#include "Obstacle.h"
#include "Waterdrop.h"
#include "Board.h"
#include "GameSceneUI.h"
#include "PausePopup.h"
#include "GameoverPopup.h"
#include "AudioEngine.h"
#include "MainScene.h"

using namespace std;
USING_NS_CC;

class GameScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	int score;										// ����
	int money;										// ȹ���� �����
	int fullHP;										// ���� ü��
	int health;										// ü��
	bool collided;									// �浹 ������ üũ
	bool end;										// ������ �������� üũ
	Fruit* fruit;									// ����
	Waterdrop* waterdrop;							// �����
	unordered_map<string, Obstacle*> obstacleMap;	// ��ֹ� 
	Board* board1;									// ��������1
	Board* board2;									// ��������2
	GameSceneUI* UI;								// ���Ӿ� UI
	EventListenerTouchOneByOne* listener;			// ��ġ ������

	void Tick(float f);								// �� �����Ӹ��� ȣ��
	void Jump();									// ������ư�� ������ ��
	void MakeBackground();							// ��� ����
	void MakeUI();									// UI ����
	void MakeFruit();								// ���� ����
	void MakeObject();								// ������Ʈ ����
	void MoveObject();								// ������Ʈ �̵�
	void DeleteObject();							// ������Ʈ ����
	void CheckCollide();							// �浹 üũ
	void OnClickPause();							// ���� �Ͻ� ����
	void GameOver();								// ���� ����
	void Restart();									// �ٽ� ����
	void Resume();									// ���ư���
	void GoMain();									// ����ȭ��

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event);
	virtual void onTouchEnded(Touch* touch, Event *unused_event);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};