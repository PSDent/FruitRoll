#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace std;
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
	ui::LoadingBar* healthBar;				// ü�� ������ 
	Sprite* healthBarBackground;			// ü�� ������ ��� 
	ui::Text* scoreText;					// ȹ���� �����
	Size visibleSize;						// �ػ�

	void MakeButton();						// ��ư ����
	void MakeInfo();						// ���� ȭ�� ����
	void UpdateInfo(int hp, int score);		// ���� ������Ʈ
};