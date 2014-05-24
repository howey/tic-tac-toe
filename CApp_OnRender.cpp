#include "CApp.h"

void CApp::OnRender() {
	if(Winner) {
		CSurface::OnDraw(Surf_Display, Surf_NoGrid, 0, 0);
		if(!Tie)
			CSurface::OnDraw(Surf_Display, Surf_Win, 275, 200);
		else
			CSurface::OnDraw(Surf_Display, Surf_Tie, 275, 200);

		//The winner is the previous player
		if(CurrentPlayer == 1) {
			CSurface::OnDraw(Surf_Display, Surf_X, 50, 200);
		}
		else {
			CSurface::OnDraw(Surf_Display, Surf_O, 50, 200);
		}
	}

	else {
		CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);

		for(int i = 0; i < 9; i++) {
			int X = (i % 3) * 200;
			int Y = (i / 3) * 200;

			if(Grid[i] == GRID_TYPE_X) {
				CSurface::OnDraw(Surf_Display, Surf_X, X, Y);
			}
			else if(Grid[i] == GRID_TYPE_O) {
				CSurface::OnDraw(Surf_Display, Surf_O, X, Y);
			}
		}
	}
	SDL_Flip(Surf_Display);
}
