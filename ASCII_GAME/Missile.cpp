#include "Missile.h"
#include "../ASCII_GAME/Core/Renderer/ConsoleColours.h"

extern const int SCREEN_WIDTH;
CHAR_INFO MissileSprite[] =
{
	{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },

};

CHAR_INFO EnemyMissileSprite[] =
{
	{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },
	{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_YELLOW },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },
	{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_MUSTARD },{ ' ' , BACKGROUND_BLACK },{ ' ' , BACKGROUND_BLACK },

};

Missile::Missile()
	:m_bInitialised(false)
	, m_Active(true)
{

}

Missile::~Missile()
{

}

void Missile::Initialise(Vector2& position, Vector2& velocity)
{
	m_Velocity = velocity;

	Sprite::Initialise(m_Velocity.x < 0.0f ? MissileSprite : EnemyMissileSprite, Vector2(12, 6));

	Vector2 startPosition(position.x - (Sprite::GetSize().x / 2), position.y - (Sprite::GetSize().y / 2));
	SetPosition(startPosition);

	m_bInitialised = true;
}

void Missile::Update()
{
	if (!m_bInitialised || !m_Active)
		return;

	SetPosition(Vector2(GetPosition().x +10, GetPosition().y ));
	

}

void Missile::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised || !m_Active)
		return;

	Sprite::Render(pRenderer);
}

void Missile::Explode()
{
	m_Active = false;
}