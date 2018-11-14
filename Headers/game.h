#ifndef GAME_H
#define GAME_H

#include "supervisor.h"
#include "subordinate.h"
#include "figure.h"
#include "backstage.h"
#include <vector>
#include <string>
#include <thread>


class Game : public Supervisor, public Subordinate {
	Figure* figureFlying;
	Backstage* gameField;
	float relativeCellSizeX = 0.05f;
	float relativeCellSizeY = 0.05f;
	std::thread t;
public:
	void init();
	void createFigure();
	void induceMovement();
	void initSimulation();



private:
	void initializeRemarks();






};






#endif 