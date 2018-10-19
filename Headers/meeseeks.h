

#ifndef MEESEEKS_H
#define MEESEEKS_H

#include <cmath>
#include <figure.h>

const int GENE_AMOUNT = 4;

class Meeseeks {

	int genome[GENE_AMOUNT] = {12, 23, 5, 2};
	int energy;
	Figure* mortalBody;

public:
	Meeseeks();
	int getNextMove();
	Figure* getBody();
private:
	void produceGenes();

};
#endif

