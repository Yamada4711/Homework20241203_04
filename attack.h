#pragma once

class Attack
{
public:
	bool AttackPhysicsAndDead(int str, int vit, int* pHp);
	bool AttackMagicAndDead(int* pHp, int* pVit, int* pMp, int opponentAttribute, int myAttribute);
protected:

	enum Attribute
	{
	//�@ �@����						����
	//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
		NOMAL = 0,		// ���@���g���Ȃ����U���͂���ԍ���
		FIRE = 1,		// ���@�ϐ�������
		WATER = 2,		// �h��͂�����
		ROCK = 3,		// �U���͂���Ԗڂɍ���
		WIND = 4,		// ���@�ϐ�������
	};
};