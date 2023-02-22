#pragma once

#ifndef _Background_H_
#define _Background_H_

#include "../ASCII_GAME/Core/Renderer/Sprite.h"

class ASCIIRenderer;
//variable declaration
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class Background : public Sprite
{
public:

	Background();
	~Background();

	void Initialise(Vector2& position);
	void Render(ASCIIRenderer* pRenderer);

private:
	bool m_bInitialised;

};

#endif

