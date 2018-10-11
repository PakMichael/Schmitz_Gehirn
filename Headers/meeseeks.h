

#ifndef MEESEEKS_H
#define MEESEEKS_H

#include <cmath>
#include <figure.h>

class Meeseeks {
	const int numberOfGenes=3;
	int randTable[100];  //100 percent
	int genome[3];
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

