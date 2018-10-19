#include <meeseeks.h>

Meeseeks::Meeseeks() {
	mortalBody = new Figure(0.05, 0.05);
	produceGenes();


}
int Meeseeks::getNextMove() {
	//for (int a = 0; a < GENE_AMOUNT; ++a)
	//{
	//	if ((rand() % 100) <= genome[a])return a;
	//}
	return  rand() % GENE_AMOUNT;


}
 

void Meeseeks::produceGenes() {
	for (int a = 0; a < GENE_AMOUNT; ++a) {
		genome[a] = rand() % 100;
	}

}

Figure* Meeseeks::getBody() {
	return mortalBody;
}