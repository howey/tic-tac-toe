all: CApp

CApp: CEvent.cpp CSurface.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CApp.cpp
	g++ -lSDL -lSDL_mixer CEvent.cpp CSurface.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CApp.cpp -o CApp

clean:
	rm -f CApp
