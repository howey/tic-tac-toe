#include "CApp.h"

bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		printf("error initializing SDL mixer: %s\n", Mix_GetError());
		return false;
	}

	Music = Mix_LoadMUS("music.mp3");
	Boink = Mix_LoadWAV("boink.wav");
	Chime = Mix_LoadWAV("chime.wav");

	Mix_PlayMusic(Music, -1);

	if((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	if((Surf_Grid = CSurface::OnLoad("grid.bmp")) == NULL) {
		return false;
	}

	if((Surf_NoGrid = CSurface::OnLoad("nogrid.bmp")) == NULL) {
		return false;
	}

	if((Surf_Win = CSurface::OnLoad("win.bmp")) == NULL) {
		return false;
	}

	if((Surf_Tie = CSurface::OnLoad("tie.bmp")) == NULL) {
		return false;
	}
	
	if((Surf_X = CSurface::OnLoad("x.bmp")) == NULL) {
		return false;
	}

	if((Surf_O = CSurface::OnLoad("o.bmp")) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Win, 255, 0, 0);
	CSurface::Transparent(Surf_Tie, 255, 0, 0);

	Reset();

	return true;
}
