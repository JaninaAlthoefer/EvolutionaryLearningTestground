#pragma

#include <stdlib.h>

#include "AICharacter.h"
#include "AIManager.h"
#include "Evolution.h"

void Evolution::evolveCharacters(AIManager *manager)
{
	int elite = 0;
	int incr = 0;
	m_pointer = manager->getVector();
	//manager->getVector(m_pointer);
	m_size = manager->getSize();

	if (keepBestChar)
	{
		elite = 1;
		//this gives nullptr after first iteration since it's deleted afterwards!!
		AICharacter *elite = manager->getFittest();
		result.push_back(new AICharacter(elite));
	}

	for (int i = elite; i < m_size; i++)
	{
		AICharacter *par1 = getParent();
		AICharacter *par2 = getParent();

		AICharacter *child = breed(par1, par2);
		result.push_back(child);
	}

	for (int i = elite; i < m_size; i++)
	{
		mutate(result[i]);
	}

	//clear other vector!! delete m_pointer;
	manager->clearOldChars();
	m_pointer = nullptr;
	m_size = NULL;
	manager->setVector(result);
	result.clear();//clearMaternityWard();

	incr++;
}

AICharacter* Evolution::breed(AICharacter *parent1, AICharacter *parent2)
{
	AICharacter *result = new AICharacter();
	int rng = rand() % 100 + 1;
	
	if (rng < uniformRate)
		result->setDutifulness(parent1->getDutifulness());
	else
		result->setDutifulness(parent2->getDutifulness());

	rng = rand() % 100 + 1;

	if (rng < uniformRate)
		result->setGullibility(parent1->getGullibility());
	else
		result->setGullibility(parent2->getGullibility());

	rng = rand() % 100 + 1;

	if (rng < uniformRate)
		result->setFOVRadius(parent1->getFOVRadius());
	else
		result->setFOVRadius(parent2->getFOVRadius());

	rng = rand() % 100 + 1;

	if (rng < uniformRate)
		result->setWalkSpeed(parent1->getWalkSpeed());
	else
		result->setWalkSpeed(parent2->getWalkSpeed());

	return result;
}

void Evolution::mutate(AICharacter* child)
{
	int rng = rand() % 100 + 1;

	if (rng < mutationRate)
		child->setDutifulness((rand() % 100));

	rng = rand() % 100 + 1;

	if (rng < mutationRate)
		child->setGullibility((rand() % 100));

	rng = rand() % 100 + 1;

	if (rng < mutationRate)
		child->setFOVRadius((rand() % 25));

	rng = rand() % 100 + 1;

	if (rng < mutationRate)
		child->setWalkSpeed((rand() % 100));
	
}

AICharacter* Evolution::getParent()
{
	int rng = rand() % m_size;

	return m_pointer->at(rng);
}

void Evolution::clearMaternityWard()
{
	for each (AICharacter* c in result)
	{
		delete c;
	}

	result.clear();
}