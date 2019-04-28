#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace std;
using namespace ui;
USING_NS_CC;
 
class GameSceneUI
{
public:
	GameSceneUI();
	~GameSceneUI();

	Sprite* jumpButton;						// ���� ��ư
	Sprite* stopButton;						// ��ž ��ư
	MenuItemImage* pauseButton;				// �Ͻ����� �޴�������
	Label* healthLabel;						// ü��
	LoadingBar* healthBar;					// ü�� ������ 
	Label* waterdropLabel;					// ȹ���� �����
	Size visibleSize;						// �ػ�

	void MakeButton();						// ��ư ����
	void MakeInfo();						// ���� ȭ�� ����
	void UpdateInfo(int hp, int score);		// ���� ������Ʈ
};