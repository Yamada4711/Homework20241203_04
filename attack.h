#pragma once

class Character;

class Attack
{
public:
	static bool AttackPhysicsAndDead(Character* pCA, Character* pCB);
	static bool AttackMagicAndDead(Character* pCA, Character* pCB);
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