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

	bool CollideCheck(float x, float y, float size);		// ���ϰ��� �浹 üũ
	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	void Move();											// ������ �����̱�
	void Fall();											// �������� ��ֹ��� ��� ��������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ��
};