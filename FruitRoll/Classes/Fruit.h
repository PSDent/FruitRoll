#pragma once
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Fruit
{
public:
	Fruit(string type);
	~Fruit();

	string fruitType;			// ������ ����
	bool jumping;				// �����ϴ� ������ üũ
	bool stopping;				// �����ϴ� ������ üũ
	Sprite* fruitImage;			// ������ �̹���
	Animation* fruitAnimation;	// ���Ͼִϸ��̼�

	void MakeSprite();			// �ִϸ���Ʈ ����
	void Jump();				// �����ϱ�
	void JumpEnd();				// ���� ������
	void Stop();				// �����ϱ�
	void StopEnd();				// ���� ������
	void Rotate();				// ������
	void PlayAnimation();				// �浹 �� �ִϸ��̼� ����
};