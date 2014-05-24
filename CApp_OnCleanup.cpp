#include "CApp.h"

void CApp::OnCleanup() {
	SDL_FreeSurface(Surf_Grid);
	SDL_FreeSurface(Surf_X);
	SDL_FreeSurface(Surf_O);
	SDL_FreeSurface(Surf_NoGrid);
	SDL_FreeSurface(Surf_Display);
	SDL_FreeSurface(Surf_Win);
	SDL_FreeSurface(Surf_Tie);
	Mix_HaltMusic();
	Mix_FreeMusic(Music);
	Mix_FreeChunk(Boink);
	Mix_FreeChunk(Chime);
	SDL_Quit();
}
