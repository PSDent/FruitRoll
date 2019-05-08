#pragma once
#pragma execution_character_set("UTF-8")
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"
#include "GameScene.h"

using namespace std;
USING_NS_CC;

class MainScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	int bestScore;									// �ְ�����
	int HP;											// ü��
	int waterdrop;									// ������ �����
	string fruitType;								// ���� Ÿ��
	ui::Text* HPText;								// ü�� �ؽ�Ʈ
	ui::Text* waterdropText;						// ������ ����� �ؽ�Ʈ
	ui::Text* needWaterdropText;					// ü�°�ȭ�� �ʿ��� ����� �ؽ�Ʈ
	Size visibleSize;								// ȭ�� ������
	Sprite* selectedSprite;							// ������ ������ ����Ű�� ��������Ʈ
	Menu* fruitMenu;								// ������ ���ϵ��� �ִ� �޴�

	void MakeBackground();							// ��� ����
	void MakeUI();									// UI ����
	void Start();									// ���� ����
	void SelectFruit(string type);					// ���� ����
	void UpgradeHP();								// ü�� ��ȭ

	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	// implement the "static create()" method manually
	CREATE_FUNC(MainScene);
};