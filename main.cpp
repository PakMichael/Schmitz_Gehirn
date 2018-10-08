#include "logic.h"
#include "engine.h"




int main(){

	Engine engine;
	Logic logic;
	logic.addObserver(&engine);
	logic.init();
}