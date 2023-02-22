
#ifndef _EnemyArmy_H
#define _EnemyArmy_H

#include "EnemyShip.h"
#include "Core/Maths/Vector2.h"
#include "Missile.h"


const int NUM_INVADERS_PER_ROW = 20;
const int NUM_ROWS_OF_INVADERS = 1;
const int TOP_OF_PLAY_SCREEN = 15;

class Game;
class ASCIIRenderer;


class EnemyArmy
{
public:
	EnemyArmy();
	~EnemyArmy();
	
	void Initialise(Game* pGame);
	void Update();
	void Render(ASCIIRenderer* pRenderer);

	void Approach();

	bool Collides(Sprite& otherSprite);
	bool CollidesPlayer(Sprite& otherSprite);
	int GetScore() { int value = 100;  return value; }
	int EnemiesRemaining();
	void KillAll();
	void SetFalse();
	
	
	bool Landed();
	
private:
	bool m_bInitialised;
	bool m_Aproaching;
	float m_UpdateTimer;
	Game* m_pGame;
	EnemyShip m_EnemyShip[NUM_ROWS_OF_INVADERS][NUM_INVADERS_PER_ROW];
	int m_ScoreAdd;
	int EnemiesKilled;
	float m_AnimationTimer;
	bool m_Landed;
	
};

#endif