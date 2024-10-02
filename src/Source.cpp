#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	game->initialise();
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
		game->levels();
	}
	game->clean();
	return 0;
}