#include "AICharacter.h"
#include "AIManager.h"
#include "Evolution.h"

#include <iostream>
#include <ctime>

int main()
{
	int generation = 0;
	int minFitness = 10;
	srand((unsigned) time(0));

	AIManager *manager = new AIManager(50, true);
	Evolution evo;
	std::cout << "Start Test now?" << std::endl;

	char a;
	std::cin >> a;

	AICharacter *fittest = manager->getFittest();
	int currFitness = fittest->getFitness();

	std::cout << currFitness << std::endl;

	while (currFitness > minFitness)
	{
		evo.evolveCharacters(manager);

		fittest = manager->getFittest();
		currFitness = fittest->getFitness();
		generation++;

		//if ((generation % 10) == 0)
		//{
			std::cout << "Generation: " << generation;
			std::cout << " FittestFitness: " << currFitness << std::endl;
		//}
	}

	std::cout << "Done" << std::endl;

	delete manager; 

	std::cin >> a;

	return 0;
}
