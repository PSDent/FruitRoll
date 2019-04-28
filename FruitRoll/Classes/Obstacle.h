#pragma once
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Obstacle
{
public:
	Obstacle(string type);
	~Obstacle();

	string name;											// ��ֹ��� ����
	Sprite* obstacleImage;									// ��ֹ��� �̹���
	bool stopping;											// �����ϴ� ������ üũ
	bool moving;											// �����̴� ������ üũ
	float width;											// ��ֹ��� ���� ����
	float height;											// ��ֹ��� ���� ����
	Size visibleSize;										// �ػ�

	void Stop();											// �����ϱ�
	void StopEnd();											// ���� ������
	void Remove();											// ������ҷ� �̵��ϱ�
	void Move();											// ������ �����̱�
	void Fall();											// �������� ��ֹ��� ��� ��������
	bool CheckNeedDelete();									// �����ؾ��ϴ��� Ȯ��
};