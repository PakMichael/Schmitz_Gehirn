#include "game.h"

using namespace std;
void Game::init() {
	int heightPX = 600;
	int widthPX = 1000;
	relativeCellSizeX = 0.025; //0.0833;
	relativeCellSizeY = 0.05;
	notify("init", new Point2D(widthPX, heightPX));
	srand(std::time(0));
	gameField = new Backstage();
	gameField->setScreenSize(widthPX, heightPX);
	gameField->setCellSize(relativeCellSizeX, relativeCellSizeY);
	notify("updBackstage", gameField);
	gameField->seedPopulation();
	  t = std::thread(&Game::initSimulation, this);
	notify("start");
	t.join();
}


void Game::createFigure() {
	//deprecated
	Figure* tmp = new Figure(relativeCellSizeY, relativeCellSizeX);
	tmp->addObserver(this);
	figureFlying = tmp;
	notify("updPlayerFigure", figureFlying);
	tmp->init();

}
void Game::initSimulation() {

	for (int a = 0; a < 5; ++a) {
		gameField->startEvolution();
		notify("nudgeBackstage");
		notify("redraw");
		clock_t now = clock() / CLOCKS_PER_SEC;
		while (clock() / CLOCKS_PER_SEC - now < 1);
	}
}


void Game::induceMovement() {

	switch (figureFlying->getDirection())
	{
	case ' ':
		figureFlying->rotate();
		break;
	case 'Q':
		figureFlying->boostDown();
		break;
	case 'A':
		figureFlying->moveLeft();
		break;
	case 'D':
		figureFlying->moveRight();
		break;
	case 'S':
		figureFlying->moveDown();
		break;
	case 'W':
		figureFlying->moveUp();
		break;
	case 'E':
		//figureFlying->setHitEarth();
		break;
	}

	if (!gameField->collisionOccured(figureFlying))
	{
		figureFlying->fulfilProphecy();

		notify("redraw");
		/*	float tmpx;
			float tmpy;
			figureFlying->getCoordinates(tmpx, tmpy);
			std::cout << gameField->scaledPositionToIndex(tmpy) << std::endl;*/
		return;
	}
	else
	{
		figureFlying->discardProphecy();
		/*gameField->consumeFigure(figureFlying);
		notify("immobilized");*/
	}

}

void Game::update(std::string msg, void* obj) {
	if (msg == "moveTo")induceMovement();
	if (msg == "immovable") {
		gameField->reconstructBackstage();
		createFigure();
	}
	if (msg == "drop")notify("drop");
	if (msg == "evolved")notify("redraw");
}
