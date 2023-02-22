#include "Background.h"
#include "../ASCII_GAME/Core/Maths/Vector2.h"
#include "../ASCII_GAME/Core/Renderer/ConsoleColours.h"
#include <Windows.h>

//sprite design
CHAR_INFO BgSprite[24576];

Background::Background()
	:m_bInitialised(false)
{
}

Background::~Background()
{
}


void Background::Initialise(Vector2& position)
{
	for (int i = 0; i < 24576; i++) {
		if (i % 5 == 0 || i % 3 == 0) {
			BgSprite[i] = { 0, BACKGROUND_BLUE };
			
		}
		 else BgSprite[i] = { 0, BACKGROUND_BLACK };
	}
	Sprite::Initialise(BgSprite, Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));

	Vector2 startPosition(0, 0);
	SetPosition(startPosition);

	m_bInitialised = true;
}
//render sprite on screen
void Background::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	Sprite::Render(pRenderer);
}

