#include "game.h"

using namespace std;
void Game::init() {
	initializeRemarks();
	int heightPX = 600;
	int widthPX = 1000;
	relativeCellSizeX = 0.025; //0.0833;
	relativeCellSizeY = 0.05;
	makeRemark("init", new Point2D(widthPX, heightPX));
	srand(std::time(0));
	gameField = new Backstage();
	gameField->setScreenSize(widthPX, heightPX);
	gameField->setCellSize(relativeCellSizeX, relativeCellSizeY);
	makeRemark("updBackstage", gameField);
	gameField->addSupervisor(this);
	gameField->seedPopulation();
	t = std::thread(&Game::initSimulation, this);
	makeRemark("start", 0);
	t.join();
}


void Game::createFigure() {
	//deprecated
	Figure* tmp = new Figure(relativeCellSizeY, relativeCellSizeX);
	tmp->addSupervisor(this);
	figureFlying = tmp;
	makeRemark("updPlayerFigure", figureFlying);
	tmp->init();

}
void Game::initSimulation() {
	setFlag("nudgeBackstage", true);
	setFlag("redrawAll", true);
	for (int a = 0; a < 1; ++a) {
		clock_t now = clock() / CLOCKS_PER_SEC;
		while (clock() / CLOCKS_PER_SEC - now < 0.1);
		gameField->startEvolution();
		setFlag("nudgeBackstage", true);
		setFlag("redrawAll", true);

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
		changeFlag("redrawAll", true);
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
void Game::initializeRemarks() {
	declareRemark("moveTo", [this](void* ptr)
	{
		induceMovement();
	});
	declareRemark("immovable", [this](void* ptr)
	{
		gameField->reconstructBackstage();
		createFigure();
	});
	declareRemark("immovable", [this](void* ptr)
	{
		gameField->reconstructBackstage();
		createFigure();
	});
	declareRemark("drop", [this](void* ptr)
	{
		changeFlag("drop", true);
	});
	declareRemark("redraw", [this](void* ptr)
	{
		changeFlag("redraw", true);
	});
}
