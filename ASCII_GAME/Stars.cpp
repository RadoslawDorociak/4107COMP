#include "Stars.h"
#include "Core/Maths/Vector2.h"
float deltaTimeStars = 1.0f / 30.0f;
const int ENEMY_SPACING_X = 3; 

//constructor
Stars::Stars()
	:m_UpdateTimer(0.0f)
	, m_pGame(NULL)
	, m_AnimationTimer(0.0f)

{

}
//destructor
Stars::~Stars()
{
}
//script reuses most of the enemy army properties with some minor differences

void Stars::Initialise(Game* pGame)
{
	m_pGame = pGame;
	deltaTimeStars = 1.0f / 10.0f;
	m_Aproaching = true;
	for (int i = 0; i < NUM_ROWS_OF_STARS; i++)
	{
		for (int j = 0; j < NUM_STARS_PER_ROW; j++)
		{
			m_Star[i][j].m_Active = true;
			m_Star[i][j].SetAnimationFrame(1);
			int Rand = 0;
			while (Rand < 16) {
				Rand = rand() % (SCREEN_HEIGHT - 3);
			}
			
			m_Star[i][j].Initialise(Vector2(20 + (ENEMY_SPACING_X + j * (17 + ENEMY_SPACING_X)), Rand), 5, i, (NUM_ROWS_OF_STARS - i) * 200);
		}

	}
}

void Stars::Update()
{

	m_UpdateTimer += deltaTimeStars;
 
	if (m_UpdateTimer >= 1.0f)
	{
		for (int i = 0; i < NUM_ROWS_OF_STARS; i++)
		{
			for (int j = 0; j < NUM_STARS_PER_ROW; j++)
			{
				//Animaton timer starting state is randomized so different stars blink at different times
				if (m_Star[i][j].AnimationRandomize) {
					m_Star[i][j].m_AnimationTimer = rand() % (100);
					m_Star[i][j].AnimationRandomize = false;
				}
				
				m_Star[i][j].Approach(deltaTimeStars);
				//when star reaches left side of the screen, it teleports back to the right and randomizes y position
				if (m_Star[i][j].GetPosition().x < 0) m_Star[i][j].SetPosition((rand() % (30)) + SCREEN_WIDTH, (rand() % (SCREEN_HEIGHT)) + 15);
				
				
			}
		}


	}
}


void Stars::Render(ASCIIRenderer* pRenderer)
{

	for (int i = 0; i < NUM_ROWS_OF_STARS; i++)
	{
		for (int j = 0; j < NUM_STARS_PER_ROW; j++)
		{
			m_Star[i][j].Render(pRenderer);
		}
	}
}
