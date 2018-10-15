#ifndef BACKSTAGE_H
#define BACKSTAGE_H

#include "figure.h"
#include "primitive.h"
#include <vector>
#include "meeseeks.h"
#include "observable.h"

class Backstage : public Entity, public Observable {
private:
	bool cellsTaken[22][10];
	Meeseeks* population[100];
	std::vector<Rectangle*> map;
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
	void seedPopulation();
	void evolveOnce(Meeseeks* subj);
	void startEvolution();
	int  calculateEnergy();
};




#endif