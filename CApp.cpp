#include "CApp.h"

CApp::CApp() {
	Surf_Display = NULL;
	Surf_Grid = NULL;
	Surf_X = NULL;
	Surf_O = NULL;
	Surf_Win = NULL;
	Surf_NoGrid = NULL;
	Surf_Tie = NULL;
	Music = NULL;
	Running = true;
	CurrentPlayer = 0;
	Tie = false;
	Winner = false;
}

int CApp::OnExecute() {
	if(OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

void CApp::Reset() {
	Winner = false;
	Tie = false;
	for(int i = 0; i < 9; i++) {
		Grid[i] = GRID_TYPE_NONE;
	}
}

void CApp::SetCell(int ID, int Type) {
	Grid[ID] = Type;
}

int main(int argc, char * argv[]) {
	CApp theApp;
	return theApp.OnExecute();
}
