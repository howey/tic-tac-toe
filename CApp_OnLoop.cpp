#include "CApp.h"

void CApp::OnLoop() {
	if(!Winner) {
		if( ((Grid[0] == GRID_TYPE_X) && (Grid[1] == GRID_TYPE_X) && (Grid[2] == GRID_TYPE_X)) ||
			((Grid[3] == GRID_TYPE_X) && (Grid[4] == GRID_TYPE_X) && (Grid[5] == GRID_TYPE_X)) ||
			((Grid[6] == GRID_TYPE_X) && (Grid[7] == GRID_TYPE_X) && (Grid[8] == GRID_TYPE_X)) ||
			((Grid[0] == GRID_TYPE_X) && (Grid[3] == GRID_TYPE_X) && (Grid[6] == GRID_TYPE_X)) ||
			((Grid[1] == GRID_TYPE_X) && (Grid[4] == GRID_TYPE_X) && (Grid[7] == GRID_TYPE_X)) ||
			((Grid[2] == GRID_TYPE_X) && (Grid[5] == GRID_TYPE_X) && (Grid[8] == GRID_TYPE_X)) ||
			((Grid[0] == GRID_TYPE_X) && (Grid[4] == GRID_TYPE_X) && (Grid[8] == GRID_TYPE_X)) ||
			((Grid[2] == GRID_TYPE_X) && (Grid[4] == GRID_TYPE_X) && (Grid[6] == GRID_TYPE_X))) {
			//X wins
			Winner = true;
			Mix_PlayChannel(-1, Chime, 0);
		}


		if( ((Grid[0] == GRID_TYPE_O) && (Grid[1] == GRID_TYPE_O) && (Grid[2] == GRID_TYPE_O)) ||
			((Grid[3] == GRID_TYPE_O) && (Grid[4] == GRID_TYPE_O) && (Grid[5] == GRID_TYPE_O)) ||
			((Grid[6] == GRID_TYPE_O) && (Grid[7] == GRID_TYPE_O) && (Grid[8] == GRID_TYPE_O)) ||
			((Grid[0] == GRID_TYPE_O) && (Grid[3] == GRID_TYPE_O) && (Grid[6] == GRID_TYPE_O)) ||
			((Grid[1] == GRID_TYPE_O) && (Grid[4] == GRID_TYPE_O) && (Grid[7] == GRID_TYPE_O)) ||
			((Grid[2] == GRID_TYPE_O) && (Grid[5] == GRID_TYPE_O) && (Grid[8] == GRID_TYPE_O)) ||
			((Grid[0] == GRID_TYPE_O) && (Grid[4] == GRID_TYPE_O) && (Grid[8] == GRID_TYPE_O)) ||
			((Grid[2] == GRID_TYPE_O) && (Grid[4] == GRID_TYPE_O) && (Grid[6] == GRID_TYPE_O))) {
			//O wins
			Winner = true;
			Mix_PlayChannel(-1, Chime, 0);
		}

		if( ((Grid[0] != GRID_TYPE_NONE) && (Grid[1] != GRID_TYPE_NONE) && (Grid[2] != GRID_TYPE_NONE) && 
			(Grid[3] != GRID_TYPE_NONE) && (Grid[4] != GRID_TYPE_NONE) && (Grid[5] != GRID_TYPE_NONE) && 
			(Grid[6] != GRID_TYPE_NONE) && (Grid[7] != GRID_TYPE_NONE) && (Grid[8] != GRID_TYPE_NONE)) && (Winner == false) ) {
		       //Tie
		       Tie = true;
	       		Winner = true;		       
		}
	}
	
	
}
