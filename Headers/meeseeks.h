

#ifndef MEESEEKS_H
#define MEESEEKS_H

#include <cmath>
#include <figure.h>

class Meeseeks {
	const int numberOfGenes=4;
	int randTable[100];  //100 percent
	int genome[4] = {12, 23, 4, 45};
	int energy;
	Figure* mortalBody;

public:
	Meeseeks();
	int getNextMove();
	Figure* getBody();
private:
	void seedRandTable();
	void produceGenes();

};
#endif

