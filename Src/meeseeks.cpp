#include <meeseeks.h>

Meeseeks::Meeseeks() {
	mortalBody = new Figure(0.05, 0.05);
	produceGenes();
	seedRandTable();

	
}
int Meeseeks::getNextMove() {

	int randIndex = rand() % 100;
	return randTable[randIndex];


}


void Meeseeks::seedRandTable() {
	int tempIndex = 0;
	for (int a = 0; a < numberOfGenes; ++a) {
		for (int b = 0; b < genome[a]; b++) {
			randTable[tempIndex++] = a;
		}
	}
}

void Meeseeks::produceGenes() {
	for (int a = 0; a < numberOfGenes; ++a) {
		genome[a] = rand() % 100;
	}

}

Figure* Meeseeks::getBody() {
	return mortalBody;
}