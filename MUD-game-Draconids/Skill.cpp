#include "Skill.h"

#include "Skill.h"
#include "Role.h"

Skill::Skill(const std::string& name, int damage, int mpCost, const std::string& description)
	: name(name), damage(damage), mpCost(mpCost), description(description)
{
}

const std::string& Skill::getName() const {
	return name;
}

int Skill::getDamage() const {
	return damage;
}

int Skill::getMPCost() const {
	return mpCost;
}

const std::string& Skill::getDescription() const {
	return description;
}

void Skill::useSkill(Role& attacker, Role& target) const {
	// ���ݼ�������ִ����Ӧ��Ч��
	if (name == "��֮��Ϣ") {
		// ��֮��Ϣ�Ե�������˺�
		int damage = getDamage(); // ��ȡ�����˺�
		target.takeDamage(damage);
		cout << attacker.getName() << " ʹ�� " << name << " �� " << target.getName() << " ��� " << damage << " �˺���" << endl;
	}
	else if (name == "���ۻ���") {
		// ���ۻ������ӽ�ɫ����
		int defenseIncrease = getDamage(); // ����ʹ���˺���������ʾ��������ֵ
		attacker.increaseDEF(defenseIncrease);
		cout << attacker.getName() << " ������ " << name << "�������� " << defenseIncrease << " ���������" << endl;
	}
	else if (name == "��������") {
		// �������ｵ�ͶԷ����������ܵ���0
		int defenseDecrease = getDamage(); // ����ʹ���˺���������ʾ��������ֵ
		int newDefense = max(target.getDEF() - defenseDecrease, 0); // �������͵����ܵ���0
		target.setDEF(newDefense); // �����µķ���ֵ
		cout << attacker.getName() << " ʹ�� " << name << " �� " << target.getName() << " �ͷ���������˶Է�������" << endl;
	}
}


/*Skill::Skill()
{
}

Skill::~Skill()
{
}

void Skill::show()
{
	cout << "�������ƣ�" << name << endl;
	cout << "���ܽ��ܣ�" << introduce << endl;
	cout << "����Ч����" << effect << endl;
}

void Skill::can()
{
	is_can = true;
}

bool Skill::get_is_can()
{
	return is_can;
}

GUI::GUI():Skill("���顤��ʤ", "��������100%(ֻ���ͷ�һ��)", "���������Ч��Χ���ͷ��������ͷ��������Լ���������ȫ������ʹ���Ӷ����ӳ����޵�����")
{
}

void GUI::Motor_skill_start(Role& role, Role& enemy)
{
	role.attack = role.attack * 2;
}

void GUI::Motor_skill_end(Role& role, Role& enemy)
{
	role.attack = role.attack / 2;
}



SHEN::SHEN():Skill("���顤��Ѫ","��������, ��۳��з�Ѫ��(���߽����乥��)","ʹ�Լ����ж���")
{
}

void SHEN::Motor_skill_start(Role& role, Role& enemy)
{
	role.HP -= 5;
	role.attack -= 5;
}

void SHEN::Motor_skill_end(Role& role, Role& enemy)
{
}

XI::XI():Skill("���顤��Ѫ��", "�ͷ�һ�ι���1.5���˺�, ���չ�����30% Ѫ��", "��tm�������� û��һ��Ѫ���Լ���")
{
}

void XI::Motor_skill_start(Role& role, Role& enemy)
{
	role.HP += static_cast<int>(role.attack * 0.3);
	if (role.HP > 100) {
		role.HP = 100;
	}
	atteck = role.attack;
	role.attack = static_cast<int>(role.attack * 1.5);
}

void XI::Motor_skill_end(Role& role, Role& enemy)
{
	role.attack = atteck;
}