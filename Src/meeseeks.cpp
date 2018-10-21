#include <meeseeks.h>

Meeseeks::Meeseeks() {
	mortalBody = new Figure(0.05, 0.05);
	produceGenes();


}
int Meeseeks::getNextMove() {
	int temp = rand() % GENE_AMOUNT;
	if (rand() % 100 <= genome[temp])
		return temp;
	return -1;


}


void Meeseeks::produceGenes() {
	for (int a = 0; a < GENE_AMOUNT; ++a) {
		genome[a] = rand() % 100;
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