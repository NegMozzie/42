/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:48:27 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 12:48:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default Constructor Called" << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const &src)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

ScavTrap::ScavTrap(const std::string str) : name(str)
{
    std::cout << "String Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->MaxHitPoint = 100;
    this->EnergyPoint = 50;
    this->MaxEnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorAttackReduction = 3;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor Called" << std::endl;

}

void ScavTrap::rangedAttack(const std::string &target)
{
    std::cout << "SG4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target)
{
    std::cout << "SG4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->getHitPoint() >= this->getMaxHitPoint())
        std::cout << "The unit is already at Max Hit Point" << std::endl;
    else
    {
        if (this->getHitPoint() == 0)
            std::cout << "SG4G-TP <" << this->getName() << "> has been resurected" << std::endl;
        std::cout << "SG4G-TP <" << this->getName() << "> is heal by " << amount << "> Hit points" << std::endl;
        this->HitPoint += amount;
        this->HitPoint =  (this->getHitPoint() > this->getMaxHitPoint()) ? this->getMaxHitPoint() : this->HitPoint;
    }   
}

void ScavTrap::challengeNewcomer(const std::string &target) const
{
    std::string randomChallenge[7];

    randomChallenge[0] = "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!";
    randomChallenge[1] = "Wanna hear a new dubstep song I wrote? Wub! Wub";
    randomChallenge[2] = "Good as new, I think. Am I leaking?";
    randomChallenge[3] = "Please open the box";
    randomChallenge[4] = "I can see through time...";
    randomChallenge[5] = "Please don't shoot me, please don't shoot me, please don't shoot me!";
    randomChallenge[6] = "Turning off the optics... they can't see me...";

    std::cout << "<ScavTrap> Hey <" << target << ">" << randomChallenge[std::rand() % 6] << std::endl;

}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->HitPoint -= (amount -= this->getArmorAttackReduction());
    this->HitPoint =  (this->getHitPoint() < 0) ? 0 : this->HitPoint;
    if (this->getHitPoint() <= 0)
        std::cout << "this unit is destroyed" << std::endl;
    else
        std::cout << "SG4G-TP <" << this->getName() << "> is hit by <" << amount + this->getArmorAttackReduction() << "> Hit points " << "(reduced to " << amount << ")" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}

int ScavTrap::getHitPoint() const
{
    return HitPoint;
}

int ScavTrap::getMaxHitPoint() const
{
    return MaxHitPoint;
}

int ScavTrap::getEnergyPoint() const
{
    return EnergyPoint;
}

int ScavTrap::getMaxEnergyPoint() const
{
    return MaxEnergyPoint;
}

int ScavTrap::getLevel() const
{
    return level;
}

std::string ScavTrap::getName() const
{
    return name;
}

int ScavTrap::getMeleeAttackDamage() const
{
    return meleeAttackDamage;
}

int ScavTrap::getRangedAttackDamage() const
{
    return rangedAttackDamage;
}

int ScavTrap::getArmorAttackReduction() const
{
    return ArmorAttackReduction;
}