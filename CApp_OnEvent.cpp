#include "CApp.h"

void CApp::OnEvent(SDL_Event * Event) {
	CEvent::OnEvent(Event);
}

void CApp::OnExit() {
	Running = false;
}

void CApp::OnLButtonDown(int mX, int mY) {
	if(Winner) {
		CApp::Reset();
		return;
	}

	int ID = mX / 200;
	ID = ID + ((mY / 200) * 3);

	if(Grid[ID] != GRID_TYPE_NONE) {
		return;
	}

	Mix_PlayChannel(-1, Boink, 0);

	if(CurrentPlayer == 0) {
		SetCell(ID, GRID_TYPE_X);
		CurrentPlayer = 1;
	}
	else {
		SetCell(ID, GRID_TYPE_O);
		CurrentPlayer = 0;
	}
}
