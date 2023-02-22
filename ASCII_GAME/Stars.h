
#ifndef _Stars_H
#define _Stars_H

#include "Star.h"
#include "Core/Maths/Vector2.h"



const int NUM_STARS_PER_ROW = 25;
const int NUM_ROWS_OF_STARS = 1;
const int TOP_OF_PLAY_SCREEN_STARS = 15;

class Game;
class ASCIIRenderer;


class Stars
{
public:
	Stars();
	~Stars();

	void Initialise(Game* pGame);
	void Update();
	void Render(ASCIIRenderer* pRenderer);

	void Approach();



private:
	bool m_bInitialised;
	bool m_Aproaching;
	float m_UpdateTimer;
	Game* m_pGame;
	Star m_Star[NUM_ROWS_OF_STARS][NUM_STARS_PER_ROW];


	float m_AnimationTimer;


};

#endif