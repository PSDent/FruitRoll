#pragma once
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Board
{
public:
	Board();
	~Board();

	Sprite* boardImage;										// ����� �̹���
	bool stopping;											// �����ϴ� ������ üũ

	void Move();											// ������ �����̱�
	void Remove();											// ������ҷ� �̵��ϱ�
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ���ϱ�
};

