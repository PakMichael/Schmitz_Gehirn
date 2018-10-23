#ifndef BACKSTAGE_H
#define BACKSTAGE_H

#include "figure.h"
#include "primitive.h"
#include <vector>
#include "meeseeks.h"
#include "subordinate.h"

const int POPULATION_COUNT = 1;

class Backstage : public Entity, public Subordinate{
private:
	bool cellsTaken[22][10];
	Meeseeks* population[POPULATION_COUNT];
	std::vector<Rectangle*> map;
	Figure* goal;
	int height;
	int width;
	float relativeCellSizeX;
	float relativeCellSizeY;

public:
	Backstage();
	bool collisionOccured(Figure* figureFlying);
	void consumeFigure(Figure* fig);
	void reconstructBackstage();
	void moveTo(int key);
	void removeFilledRow();


	int scaledPositionToIndex(float scale);
	void setScreenSize(int height, int width);
	void setCellSize(float relativeCellSizeX, float relativeCellSizeY);
	void nudge();
private:
	void createBorders();

public:
	void seedPopulation(int from=0);
	void evolveOnce(Meeseeks* subj);
	void startEvolution();
	int  calcCostFunction(Meeseeks* obj);
};




#endif