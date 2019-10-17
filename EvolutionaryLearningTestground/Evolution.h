#pragma once
#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <vector>

class AICharacter;
class AIManager;

static const int uniformRate = 50;
static const int mutationRate = 75;
static const int eliteSize = 5;
static const bool keepBestChar = true;

static std::vector<AICharacter*> *m_pointer;
static std::vector<AICharacter*> result;
static int m_size;

class Evolution 
{
private:
	//static AICharacter elites[eliteSize];
	static void clearMaternityWard();

public:
	static void evolveCharacters(AIManager* chars);
	static AICharacter* breed(AICharacter* parent1, AICharacter* parent2);
	static void mutate(AICharacter* child);
	static AICharacter* getParent();

};
#endif