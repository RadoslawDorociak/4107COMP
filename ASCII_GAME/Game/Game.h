#ifndef _GAME_H_
#define _GAME_H

#include "GameStates.h"
#include "../PlayerShip.h"
#include "../Menu.h"
#include "../EndGameMenu.h"
#include "../UpperBar.h"
#include "../Background.h"
#include "../Missile.h"
#include "../Stars.h"
#include "../Star.h"
#include "../EnemyArmy.h"
#include "../Core/Renderer/Sprite.h"
#include "GameObjects\ScoreDisplay.h"
#include <vector>

class ASCIIRenderer;

class Game
{
public:
	Game();
	~Game();

	void Initialise();
	void Run();
	

private:

	//Functions
	void InitialiseRenderer();
	void InitialiseGame();
	void UpdateScoreDisplay();
	void InitialiseMainMenu();
	void InitialiseEndMenu();
	void UpdateMainMenu();
	void UpdateEndMenu();
	void RenderMainMenu();
	void RenderEndMenu();
	void Update();
	void UpdateGame();
	void CheckWinConditions();
	void UpdateMissile();
	void FireMissile();
	void Render();
	void RenderGame();
	void RenderScore();
	//Variables
	ASCIIRenderer* m_pRenderer;

	E_GAME_STATE m_GameState; // add the state of the game
	int lives = 3;
	bool m_bInitialised;
	bool m_bExitApp;
	int m_Score;
	float Missed = 0;
	float Hit = 0;
	int m_Accuracy;
	PlayerShip m_PlayerShip;
	Missile m_Missile;
	MenuIcon m_Title;
	MenuIcon m_PlayIcon;
	MenuIcon m_ExitIcon;
	Pointer  m_Pointer;
	EndMenuIcon m_EndLose;
	EndMenuIcon m_EndWin;
	EndMenuIcon m_EndBackground;
	EndMenuIcon m_EndExitIcon;
	EnemyArmy m_Army;
	Stars m_Stars;
	Star m_Star;
	EnemyShip m_EnemyShip;
	UpperBar m_UpperBar;
	Background m_Background;
	ScoreDisplay m_ScoreDigit[5];
	ScoreDisplay m_AccuracyDigit[3];
	ScoreDisplay m_Life;
	int m_MainMenuCounter = 0;
};


#endif
