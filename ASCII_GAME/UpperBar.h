#pragma once

#ifndef _UpperBar_H_
#define _UpperBar_H_

#include "../ASCII_GAME/Core/Renderer/Sprite.h"

class ASCIIRenderer;
//variable declaration
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class UpperBar : public Sprite
{
public:

	UpperBar();
	~UpperBar();

	void Initialise(Vector2& position);
	void Render(ASCIIRenderer* pRenderer);

private:
	bool m_bInitialised;

};

#endif

