#pragma once

#include <string>
#include "Role.h"

class Skill {
public:
	Skill(const std::string& name, int damage, const std::string& description);

	const std::string& getName() const;
	int getDamage() const;
	const std::string& getDescription() const;

	void useSkill(Role& attacker, Role& target) const;

private:
	std::string name;
	int damage;
	std::string description;
};