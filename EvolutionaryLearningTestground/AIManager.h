#pragma once
#ifndef AIMANAGER_H
#define AIMANAGER_H

#include <vector>

class AICharacter;

class AIManager
{
private:
	std::vector<AICharacter*> chars;
	
public:
	AIManager(int size, bool init);
	~AIManager();
	AICharacter* getChar(int idx);
	AICharacter* getFittest();
	int getSize();
	void saveChar(int idx, AICharacter* character);
	std::vector<AICharacter*>* getVector();
	//void getVector(std::vector<AICharacter*> *result);
	void setVector(std::vector<AICharacter*> vector);
	void clearOldChars();

};
#endif