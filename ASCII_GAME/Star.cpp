#include "Star.h"
#include "Core/Renderer/ConsoleColours.h"
#include "Core/Maths/Vector2.h"
#include "Core/Renderer/AnimatedSprite.h"

//#include <Windows.h>

const int STAR_SPRITE_WIDTH = 6;
const int STAR_SPRITE_HEIGHT = 3;

CHAR_INFO StarSprite0[STAR_SPRITE_ANIMATION_FRAMES][STAR_SPRITE_WIDTH * STAR_SPRITE_HEIGHT] =
{
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLUE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		
	},
	
};

const int MOVEMENT_AMOUNT = 4;
//constructor
Star::Star()
	:m_bInitialised(false)
	, m_AnimationTimer(0.0f)
	, m_Active(true)

{
}
//destructor
Star::~Star()
{
}

void Star::Initialise(Vector2& position, int fireRate, int sprite, int scoreValue, float initialTime)
{
	m_AnimationTimer = initialTime;
	int SCREEN_HEIGHT = 96;

	AnimatedSprite::Initialise(&StarSprite0[0][0], Vector3(STAR_SPRITE_WIDTH, STAR_SPRITE_HEIGHT, STAR_SPRITE_ANIMATION_FRAMES));
	Vector2 startPosition(position.x - (AnimatedSprite::GetSize().x / 2), position.y - (AnimatedSprite::GetSize().y / 2));
	SetPosition(startPosition);

	m_bInitialised = true;

}

bool Star::Update(float deltaTime)
{
	if (!m_bInitialised || !m_Active)
		return false;
	m_AnimationTimer += deltaTime;
	if (m_AnimationTimer >= 1.0f)
	{
		//Move between two animation frames
			m_AnimationTimer -= 2.0f;
			SetAnimationFrame(GetAnimationFrame() == 0 ? 1 : 0);
		


	}
	//m_AnimationTimer += deltaTime;
	return false;
}

void Star::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised || !m_Active)
		return;

	AnimatedSprite::Render(pRenderer);
}






//decreases position on x axis causing it to move left towards playership
void Star::Approach(float deltaTime)
{
	SetPosition(Vector2(GetPosition().x - 5, GetPosition().y));
	Update(deltaTime);
}
