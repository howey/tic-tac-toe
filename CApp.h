#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
	private:
		bool Running;
		bool Winner;
		bool Tie;
		SDL_Surface * Surf_Display;
		SDL_Surface * Surf_Grid;
		SDL_Surface * Surf_NoGrid;
		SDL_Surface * Surf_X;
		SDL_Surface * Surf_O;
		SDL_Surface * Surf_Win;
		SDL_Surface * Surf_Tie;
		Mix_Music * Music;
		Mix_Chunk * Boink;
		Mix_Chunk * Chime;
		int Grid[9];
		int CurrentPlayer;
		enum {
			GRID_TYPE_NONE = 0,
			GRID_TYPE_X,
			GRID_TYPE_O
		};
	public:
		CApp();
		int OnExecute();

	public:
		bool OnInit();
		void OnEvent(SDL_Event * Event);
		void OnExit();
		void OnLButtonDown(int mX, int mY);
		void OnLoop();
		void OnRender();
		void OnCleanup();
		void Reset();
		void SetCell(int ID, int Type);
};

#endif
