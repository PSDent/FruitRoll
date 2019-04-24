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

	void Remove();											// ������ҷ� �̵��ϱ�
	void Move();											// ������ �����̱�
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ��
};
