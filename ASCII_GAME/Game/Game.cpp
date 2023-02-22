#include "Game.h"
#include <windows.h>
#include <iostream>
#include "../Core/Utils.h"
#include "../Core/Renderer/ASCIIRenderer.h"
//define keys that are needed to controll the game, as well as screen size
const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 96;
#define VK_UP		0x26
#define VK_DOWN		0x28
#define VK_SPACE	0x20       
#define VK_QUIT 	0x51
Game::Game()
	:m_pRenderer(NULL)
	, m_GameState(E_GAME_STATE_MAIN_MENU) // add the state of the game
	, m_bInitialised(false)
	, m_Score(0)
	, m_bExitApp(false)
{
}

Game::~Game()
{
	SAFE_DELETE_PTR(m_pRenderer);
}

void Game::Initialise()
{
	InitialiseRenderer();

	InitialiseMainMenu();

	InitialiseGame();
	InitialiseEndMenu();
	m_bInitialised = true;
}

void Game::InitialiseRenderer()
{
	m_pRenderer = new ASCIIRenderer();

	m_pRenderer->Initialise(SCREEN_WIDTH, SCREEN_HEIGHT);
}
void Game::InitialiseMainMenu() 
{
	//Each sprite in the menu gets an unique ID, then has it's size set and finally is initialised at the proper position
	m_Title.SetSpriteID(0);
	m_Title.SetPosition(Vector2(39, 9));
	m_Title.Initialise(Vector2(SCREEN_WIDTH / 2, 30));

	m_PlayIcon.SetSpriteID(1);
	m_PlayIcon.SetPosition(Vector2(14, 6));
	m_PlayIcon.Initialise(Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	m_ExitIcon.SetSpriteID(2);
	m_ExitIcon.SetPosition(Vector2(14, 5));
	m_ExitIcon.Initialise(Vector2(SCREEN_WIDTH / 2, (m_PlayIcon.Sprite::GetPosition().y + m_PlayIcon.GetSize().y) + 3));

	m_Pointer.Initialise(Vector2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2), VK_UP, VK_DOWN);
}
void Game::InitialiseEndMenu() 
{
	//each sprite get an ID and is initialised, position and size are set within the initialise function
	m_EndLose.SetSpriteID(0);
	m_EndLose.Initialise();

	m_EndWin.SetSpriteID(1);
	m_EndWin.Initialise();

	m_EndBackground.SetSpriteID(2);
	m_EndBackground.Initialise();

	m_EndExitIcon.SetSpriteID(3);
	m_EndExitIcon.Initialise();


	
}
void Game::InitialiseGame()
{
	//all objets are initialised
	m_UpperBar.Initialise(Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_Background.Initialise(Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_PlayerShip.Initialise(Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 8), VK_UP, VK_DOWN);
	m_Army.Initialise(this);
	m_Stars.Initialise(this);
	m_Missile.Initialise(Vector2(m_PlayerShip.GetPosition().x + (m_PlayerShip.GetSize().x - 2), m_PlayerShip.GetPosition().y * 0.5f), Vector2(0, -MISSILE_SPEED));
	m_Missile.SetActive(false);
	for (int i = 0; i < 5; i++)
	{
		m_ScoreDigit[i].Initialise(Vector2(7 + (i * 10), 7));
	}
	for (int i = 0; i < 3; i++)
	{
		m_AccuracyDigit[i].Initialise(Vector2((i * 10) + SCREEN_WIDTH - 30, 7));
	}
	m_Life.Initialise(Vector2(136, 7));
}

void Game::Run()
{
	while (!m_bExitApp)
	{
		Update();

		Render();
		//This value changes the speed at which the game plays
		Sleep(30);
	}
}

void Game::Update()
{
	if (GetKeyState(VK_ESCAPE) < 0)
	{
		m_bExitApp = true;
		return;
	}
	//for as long as esc key isn not pressed, the game will update the appropriate screen
	switch (m_GameState)
	{

	case E_GAME_STATE_MAIN_MENU: // add 2
	{
		UpdateMainMenu();
	}
	break;

	case E_GAME_STATE_IN_GAME:
		UpdateGame();
		break;

	case E_GAME_STATE_LOSE_GAME:
	{
		UpdateEndMenu();
		break;
	}
	case E_GAME_STATE_WIN_GAME:
	{
		UpdateEndMenu();
		break;
	}
	default:
		break;
	}
}

void Game::UpdateGame()
{
	//when one of the ships lands, lives are substracted and script takes care of disposing of the landed enemy
	if (m_Army.Landed())
	{
		lives--;
		m_Army.SetFalse();
	}
	//every time an enemy ship collides with a missile, missile will explode, score will be added and multiplied by accuracy, accuracy value will also rise
	if (m_Missile.Active() && m_Army.Collides(m_Missile)) {
		m_Score += m_Army.GetScore() * m_Accuracy / 100;
		m_Missile.Explode();
		Hit++;
	}
	if (m_Army.CollidesPlayer(m_PlayerShip)) {
		lives--;
		
	}
	//if player misses, missile will explode, and accuracy value will be decreased
	else if (m_Missile.Active() && m_Missile.GetPosition().x > SCREEN_WIDTH) {
		m_Missile.Explode();
		Missed++;
	}
	//accuracy is calculated as a percantege of succesfull hits in the total amount of shots fired
	if (Missed + Hit != 0) {
		m_Accuracy = Hit / (Missed + Hit)  * 100;
	}
	//to avoid dividing by zero, if the total amount of shots is 0, the accuracy is automatically set to 100
	else {
		m_Accuracy = 100;
	}
	m_Army.Update();
	m_Stars.Update();
	if (GetKeyState(VK_SPACE) < 0)
	{
		if (!m_Missile.Active())
		{
			FireMissile();
		}
	}
	UpdateScoreDisplay();
	CheckWinConditions();
	m_Missile.Update();
	m_PlayerShip.Update();
}
void Game::FireMissile()
{
	m_Missile.SetPosition(m_PlayerShip.GetPosition().x, m_PlayerShip.GetPosition().y + 2);
	m_Missile.SetActive();
}

void Game::Render()
{
	//call this first
	m_pRenderer->ClearScreen();

	//render your game here
	switch (m_GameState)
	{
	case E_GAME_STATE_MAIN_MENU: // add 2
	{
		RenderMainMenu();
		break;
	}

	case E_GAME_STATE_IN_GAME:
	{
		RenderGame();
		break;
	}
	case E_GAME_STATE_LOSE_GAME:
	{
		RenderEndMenu();
		break;
	}
	case E_GAME_STATE_WIN_GAME:
	{
		RenderEndMenu();
		break;
	}
	default:
		break;
	}

	//call this last
	m_pRenderer->Render();
}

void Game::RenderGame()
{
	m_UpperBar.Render(m_pRenderer);
	m_Stars.Render(m_pRenderer);
	m_Army.Render(m_pRenderer);
	m_Missile.Render(m_pRenderer);
	m_PlayerShip.Render(m_pRenderer);
	RenderScore();
}

void Game::UpdateMainMenu()
{
	if (GetKeyState(VK_RETURN) < 0)
	{
		if (m_Pointer.GetPosition().y == SCREEN_HEIGHT / 2 - 2)  // if y position is same as play, start the game
		{
			//score position is set back to the top of the screen
			for (int i = 0; i < 5; i++)
			{
				m_ScoreDigit[i].SetPosition(Vector2(7 + (i * 10), 1));
			}
			for (int i = 0; i < 3; i++)
			{
				m_AccuracyDigit[i].SetPosition(Vector2((i * 10) + SCREEN_WIDTH - 30, 1));
			}
			m_Life.SetPosition(Vector2(136, 1));
			//enemy army is reset
			m_Army.KillAll();
			m_Army.Initialise(this);
			//score, lives and accuracy are reset as well
			lives = 3;
			m_Score = 0;
			m_Accuracy = 100;
			Hit = 0;
			Missed = 0;
			m_GameState = E_GAME_STATE_IN_GAME;
		}
		else // if not, close the game
		{
			m_bExitApp = true;
			return;
		}
	}
	m_Title.Update();
	m_PlayIcon.Update();
	m_ExitIcon.Update();
	m_Pointer.Update();
}
void Game::UpdateEndMenu()
{
	if (GetKeyState(VK_QUIT) < 0)
	{
		m_GameState = E_GAME_STATE_MAIN_MENU;
	}
	m_EndLose.Update();
	m_EndWin.Update();
	m_EndBackground.Update();
	m_EndExitIcon.Update();
	m_EndExitIcon.SetPosition(Vector2(SCREEN_WIDTH / 2, 20));
	UpdateScoreDisplay();
	
}
void Game::RenderScore()
{
	for (int i = 0; i < 5; i++)
	{
		m_ScoreDigit[i].Render(m_pRenderer);
	}
	for (int i = 0; i < 3; i++)
	{
		m_AccuracyDigit[i].Render(m_pRenderer);
	}
	m_Life.Render(m_pRenderer);
}
void Game::CheckWinConditions()
{
	//no enemies -> Player wins     no lives -> Player loses
	if (m_Army.EnemiesRemaining() <= 0)
	{
		m_GameState = E_GAME_STATE_WIN_GAME;
	}
	else if (lives == 0)
	{
		m_GameState = E_GAME_STATE_LOSE_GAME;
	}
}
void Game::UpdateScoreDisplay()
{
	for (int i = 0; i < 5; i++)
	{
		m_ScoreDigit[i].Update(0.0f);
	}
	for (int i = 0; i < 3; i++)
	{
		m_AccuracyDigit[i].Update(0.0f);
	}
	int ScoreValues[5];
	//score is set
	ScoreValues[4] = m_Score > 9999 ? 9 : m_Score % 10;
	ScoreValues[3] = m_Score > 9999 ? 9 : m_Score / 10 % 10;
	ScoreValues[2] = m_Score > 9999 ? 9 : m_Score / 100 % 10;
	ScoreValues[1] = m_Score > 9999 ? 9 : m_Score / 1000 % 10;
	ScoreValues[0] = m_Score > 9999 ? 9 : m_Score / 10000 % 10;
	m_ScoreDigit[0].SetDigitValue(ScoreValues[0]);
	m_ScoreDigit[1].SetDigitValue(ScoreValues[1]);
	m_ScoreDigit[2].SetDigitValue(ScoreValues[2]);
	m_ScoreDigit[3].SetDigitValue(ScoreValues[3]);
	m_ScoreDigit[4].SetDigitValue(ScoreValues[4]);
	//accuracy is set
	ScoreValues[4] = m_Accuracy > 9999 ? 9 : m_Accuracy % 10;
	ScoreValues[3] = m_Accuracy > 9999 ? 9 : m_Accuracy / 10 % 10;
	ScoreValues[2] = m_Accuracy > 9999 ? 9 : m_Accuracy / 100 % 10;
	m_AccuracyDigit[0].SetDigitValue(ScoreValues[2]);
	m_AccuracyDigit[1].SetDigitValue(ScoreValues[3]);
	m_AccuracyDigit[2].SetDigitValue(ScoreValues[4]);
	//lives are set
	m_Life.SetDigitValue(lives);
}
void Game::RenderMainMenu()
{
	m_Background.Render(m_pRenderer);
	m_Title.Render(m_pRenderer);
	m_PlayIcon.Render(m_pRenderer);
	m_ExitIcon.Render(m_pRenderer);
	m_Pointer.Render(m_pRenderer);
}
void Game::RenderEndMenu()
{
	
	m_EndBackground.Render(m_pRenderer);
	switch (m_GameState)
	{
		//if player has won, the victory text will be rendered
	case E_GAME_STATE_WIN_GAME: // add 2
	{
		m_EndWin.Render(m_pRenderer);
		break;
	}
	//otherwise if player loses only game over screen will render
	case E_GAME_STATE_LOSE_GAME:
	{
		m_EndLose.Render(m_pRenderer);
		break;
	}
	default:
		break;
	}

	
	m_EndExitIcon.Render(m_pRenderer);
	//the score and accuracy are still rendered, but their position is moved to the centre of the screen
	for (int i = 0; i < 5; i++)
	{
		m_ScoreDigit[i].SetPosition(Vector2((i * 10) + SCREEN_WIDTH / 2 - 25, 40));
	}
	for (int i = 0; i < 3; i++)
	{
		m_AccuracyDigit[i].SetPosition(Vector2((i * 10) + SCREEN_WIDTH /2 - 15, 55));
	}
	//life counter is moved off screen, since it always renders along the other counters but is not needed on the end menu
	m_Life.SetPosition(Vector2(-20, -20));
	RenderScore();
}
