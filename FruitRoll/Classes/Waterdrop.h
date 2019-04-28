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
	bool moving;											// �����̴� ������ üũ
	float width;											// ������� ���� ����
	float height;											// ������� ���� ����
	Size visibleSize;										// �ػ�

	void Remove();											// ������ҷ� �̵��ϱ�
	void Move();											// ������ �����̱�
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ��
};
