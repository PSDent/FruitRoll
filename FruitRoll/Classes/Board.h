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
	bool madeBoard;											// ���� �������ڸ� ��������� üũ

	void Move();											// ������ �����̱�
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	bool CheckNeedMake();									// ���� �������ڸ� �������ϴ��� Ȯ���ϱ�
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ���ϱ�
};

