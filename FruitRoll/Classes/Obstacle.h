#pragma once
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Obstacle
{
public:
	Obstacle(string type);
	~Obstacle();

	string obstacleType;									// ��ֹ��� ����
	Sprite* obstacleImage;									// ��ֹ��� �̹���
	bool stopping;											// �����ϴ� ������ üũ

	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	void Remove(string name);								// ������ҷ� �̵��ϱ�
	void Move();											// ������ �����̱�
	void Fall();											// �������� ��ֹ��� ��� ��������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ��
};