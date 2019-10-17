#pragma once
#ifndef AICHARACTER_H
#define AICHARACTER_H

#include "GlobalValues.h"


class AICharacter
{
private:
	int fOVRadius;
	int gullibility;
	int dutifulness;
	int walkSpeed;


public:
	AICharacter();
	AICharacter(AICharacter* copy);
	~AICharacter();
	void generateCharacter();
	int getFitness();

	int getFOVRadius();
	int getGullibility();
	int getDutifulness();
	int getWalkSpeed();

	void setFOVRadius(int val);
	void setGullibility(int val);
	void setDutifulness(int val);
	void setWalkSpeed(int val);

};
#endif