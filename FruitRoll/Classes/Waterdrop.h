#pragma once
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Waterdrop
{
public:
	Waterdrop();
	~Waterdrop();

	Sprite* waterdropImage;									// ����� �̹���
	bool stopping;											// �����ϴ� ������ üũ
	bool needDelete;										// �����ؾ��ϴ���

	bool CollideCheck(float x, float y, float size);		// ���ϰ��� �浹 üũ
	void Move();											// ������ �����̱�
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
};

