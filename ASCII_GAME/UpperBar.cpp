#include "UpperBar.h"
#include "../ASCII_GAME/Core/Maths/Vector2.h"
#include "../ASCII_GAME/Core/Renderer/ConsoleColours.h"
#include <Windows.h>

//sprite design
CHAR_INFO BarSprite[3584];

UpperBar::UpperBar()
	:m_bInitialised(false)
{
}

UpperBar::~UpperBar()
{
}


void UpperBar::Initialise(Vector2& position)
{
	for (int i = 0; i < 3584; i++) {
		if( i % 64 == 0 || i > 3328) BarSprite[i] = { 0, BACKGROUND_WHITE };
		else BarSprite[i] = { 0, BACKGROUND_SKYBLUE };
	}
	Sprite::Initialise(BarSprite, Vector2(SCREEN_WIDTH, 14));

	Vector2 startPosition(0, 0);
	SetPosition(startPosition);

	m_bInitialised = true;
}
//render sprite on screen
void UpperBar::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	Sprite::Render(pRenderer);
}

