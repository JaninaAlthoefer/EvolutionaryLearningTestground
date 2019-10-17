#pragma once

#include "AIManager.h"
#include "AICharacter.h"

AIManager::AIManager(int size, bool init)
{
	for (int i = 0; i < size; i++)
	{
		AICharacter *newAIChar = new AICharacter();
		
		if (init)
		{
			newAIChar->generateCharacter();
		}
		
		this->chars.push_back(newAIChar);
	}
	
}

AIManager::~AIManager()
{
	for (int i = 0; i < chars.size(); i++)
	{
		delete chars.at(i);
	}

	chars.clear();
}

AICharacter* AIManager::getChar(int idx)
{
	return chars.at(idx);
}

AICharacter* AIManager::getFittest()
{
	AICharacter *fittest = chars.at(0);

	for each (AICharacter *c in chars)
	{
		int fitnessNewAI = c->getFitness();

		if (fittest->getFitness() > fitnessNewAI)
		{
			fittest = c;
		}

	}

	return fittest;
}

int AIManager::getSize()
{
	return chars.size();
}

void AIManager::saveChar(int idx, AICharacter* character)
{
	delete chars[idx];

	chars[idx] = character;
}

std::vector<AICharacter*>* AIManager::getVector()
{
	return &this->chars;
}

/*void AIManager::getVector(std::vector<AICharacter*> *result)
{
	*result = this->chars;

	int i = 0;
	i++;
}*/

void AIManager::setVector(std::vector<AICharacter*> vector)
{
	this->chars = vector;
}

void AIManager::clearOldChars()
{
	for each (AICharacter* c in chars)
	{
		delete c;
	}
	chars.clear();
}