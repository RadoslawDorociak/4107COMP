#pragma once

#ifndef _PlayerShip_H_
#define _PlayerShip_H_

#include "../ASCII_GAME/Core/Renderer/Sprite.h"

class ASCIIRenderer;
//variable declaration
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class PlayerShip : public Sprite
{
public:

	PlayerShip();
	~PlayerShip();

	void Initialise(Vector2& position, int leftKey, int rightKey);
	void Update();
	void Render(ASCIIRenderer* pRenderer);

private:
	//movement
	void MoveUp();
	void MoveDown();

	int m_UpKey;
	int m_DownKey;

	bool UpKeyPressed();
	bool DownKeyPressed();

	bool m_bInitialised;

};

#endif
