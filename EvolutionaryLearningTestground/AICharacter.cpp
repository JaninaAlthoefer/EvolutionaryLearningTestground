#pragma once

#include <stdlib.h>
#include "AICharacter.h"

AICharacter::AICharacter()
{
	
}

AICharacter::AICharacter(AICharacter* copy)
{
	this->dutifulness = copy->dutifulness;
	this->gullibility = copy->gullibility;
	this->walkSpeed = copy->walkSpeed;
	this->fOVRadius = copy->fOVRadius;
}

AICharacter::~AICharacter()
{

}

void AICharacter::generateCharacter()
{
	this->dutifulness = rand() % 100;
	this->gullibility = rand() % 100;
	this->walkSpeed = rand() % 100;
	this->fOVRadius = rand() % 25;
}

int AICharacter::getFitness()
{
	int result;

	result = (this->dutifulness - targetDutifulness) * (this->dutifulness - targetDutifulness);
	result += (this->gullibility - targetGullibility) * (this->gullibility - targetGullibility);
	result += (this->fOVRadius - targetFOVRadius) * (this->fOVRadius - targetFOVRadius);
	result += (this->walkSpeed - targetWalkSpeed) * (this->walkSpeed - targetWalkSpeed);

	return result;
}

int AICharacter::getFOVRadius()
{
	return this->fOVRadius;
}

int AICharacter::getGullibility()
{
	return this->gullibility;
}

int AICharacter::getDutifulness()
{
	return this->dutifulness;
}

int AICharacter::getWalkSpeed()
{
	return this->walkSpeed;
}

void AICharacter::setFOVRadius(int val)
{
	this->fOVRadius = val;

	if (val > 25)
		this->fOVRadius = 25;
}

void AICharacter::setGullibility(int val)
{
	this->gullibility = val;

	if (val > 100)
		this->gullibility = 100;
}

void AICharacter::setDutifulness(int val)
{
	this->dutifulness = val;

	if (val > 100)
		this->dutifulness = 100;
}

void AICharacter::setWalkSpeed(int val)
{
	this->walkSpeed = val;

	if (val > 100)
		this->walkSpeed = 100;
}