#include "backstage.h"


Backstage::Backstage() {
	relativeCellSizeX = relativeCellSizeY = 0.05;
	goal = new Figure(0.1, 0.1f);
	goal->moveNTimesBy(5, 5);

	goal->fulfilProphecy();
	consumeFigure(goal);
	//for (int a = 0; a < 50; ++a)
	//	map.push_back(new Rectangle(a*0.05, 0, 0.05, 0.05));
	//	createBorders();
		//reconstructBackstage();
}


void Backstage::createBorders() {
	for (int a = 0; a < 50; ++a)
	{
		//horizontal
		map.push_back(new Rectangle(a*0.05 - 1, -1, 0.05, 0.05));
		map.push_back(new Rectangle(a*0.05 - 1, 1.05, 0.05, 0.05));
		//vertical
		map.push_back(new Rectangle(-1.05, a*0.05 - 1, 0.05, 0.05));
		map.push_back(new Rectangle(1.0, a*0.05 - 1, 0.05, 0.05));
	}
}
void Backstage::consumeFigure(Figure* fig) {
	for (int a = 0; a < 8; ++a) {
		if (fig->getDimensionsOfTile(a, fig->getAngle()) != 0) {
			Rectangle* tmp = new Rectangle(fig->getDimensionsOfTile(a, fig->getAngle())->getX(), fig->getDimensionsOfTile(a, fig->getAngle())->getY(), 0.05f, 0.05f);
			map.push_back(tmp);
		}

	}

}

void Backstage::reconstructBackstage() {
	std::vector<Primitive*> carcass;  //possibly huge overhead along with some voulnrabilities 
	for (Primitive* m : map)
	{
		if (m != NULL)
			carcass.push_back(new Rectangle(m->getX(), m->getY(), relativeCellSizeX, relativeCellSizeY));



	}
	assemble(carcass, 4);
}


bool Backstage::collisionOccured(Figure* figureFlying) {
	for (int a = 0; a < map.size(); a++) {
		if (figureFlying->intersects(map[a]))return true;
	}
	return false;
}




void Backstage::removeFilledRow() {/*
	for (int a = 0; a < rows.size(); ++a){
		if (rows[a] > 5)
		{
			for (int b = 0; b < map.size(); ++b){
				if (map[b]!=NULL)
				if (scaledPositionToIndex(map[b]->getY())==a){
					//map.erase(map.begin() + b);
					map[b] = NULL;
				}
			}
		}
	}*/
}

void Backstage::moveTo(int key) {

}


int Backstage::scaledPositionToIndex(float scale) {
	int res = ((scale + 1)*100.0f + 0.05) / 100.0f / 0.05f;

	return res;
}

void Backstage::setScreenSize(int height, int width) {
	this->height = height;
	this->width = width;
}

void Backstage::setCellSize(float relativeCellSizeX, float relativeCellSizeY) {
	this->relativeCellSizeX = relativeCellSizeX;
	this->relativeCellSizeY = relativeCellSizeY;

}

void Backstage::seedPopulation(int from) {

	for (int a = from; a < POPULATION_COUNT; ++a) {
		population.push_back(new Meeseeks());

	}

}

void Backstage::evolveOnce(Meeseeks* subj) {
	Figure* tmp = subj->getBody();
	switch (subj->getNextMove()) {
	case 0:
		tmp->moveDown();

		break;
	case 1:
		tmp->moveLeft();
		break;
	case 2:
		tmp->moveUp();
		break;
	case 3:
		tmp->moveRight();
		break;	
	}
}

bool cmp(  Meeseeks* a,   Meeseeks* b){
	if (a->getEnergy() > b->getEnergy()) return true;
return false;
}

void Backstage::startEvolution() {
	map.clear();
	consumeFigure(goal);
	/*for (int a = 0; a < 50; ++a)
		map.push_back(new Rectangle(a*0.05 , 0, 0.05, 0.05));*/
 
	for (int a = 0; a < population.size(); ++a) {
		evolveOnce(population[a]);
		population[a]->setEnergy(calcCostFunction(population[a]));
	}

 
	std::sort(population.begin(),population.end(),cmp);
	/*for (int a = 25; a < POPULATION_COUNT; ++a) {
		population[a] = 0;
	}*/

	population.erase(population.begin());
 
 
}

int Backstage::calcCostFunction(Meeseeks* obj) {
	int dist = sqrt(pow(goal->getX() - obj->getBody()->getX(), 2) + pow(goal->getY() - obj->getBody()->getY(), 2))*1000;
	return dist;
}


void Backstage::nudge() {
	for (int a = 0; a < population.size(); ++a) {
		population[a]->getBody()->fulfilProphecy();
		consumeFigure(population[a]->getBody());
		
	}
	reconstructBackstage();
}

