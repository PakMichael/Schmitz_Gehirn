

#ifndef MEESEEKS_H
#define MEESEEKS_H

#include <cmath>
#include <figure.h>

const int GENE_AMOUNT = 4;

class Meeseeks {

	int genome[GENE_AMOUNT];
	int energy;
	Figure* mortalBody;

public:
	Meeseeks();
	int getNextMove();
	Figure* getBody();
	void setEnergy(int E);
	int getEnergy();
private:
	void produceGenes();

};
#endif

