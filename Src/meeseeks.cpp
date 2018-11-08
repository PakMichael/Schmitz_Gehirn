#include <meeseeks.h>

Meeseeks::Meeseeks() {
	mortalBody = new Figure(0.05, 0.05);
	produceGenes();
	id = rand() % 1000;

}
int Meeseeks::getNextMove() {



	int temp = rand() % probabilityDistribution.size();
	switch (temp) {
	case 0: // gene responsible for looking
		energy += 1;
		break;
	case 1:
		energy += 2;
		break;
	case 2:
		energy += 3;
		break;
	}
	return probabilityDistribution[temp];


}


void Meeseeks::produceGenes() {
	for (int a = 0; a < GENE_AMOUNT; ++a) {
		int geneValue = rand() % 100;
		genome[a] = geneValue;
		for (int b = 0; b < geneValue; ++b) {
			probabilityDistribution.push_back(a);
		}
	}


}

Figure* Meeseeks::getBody() {
	return mortalBody;
}


void Meeseeks::setEnergy(int E) {
	energy = E;
}
int Meeseeks::getEnergy() {
	return energy;
}