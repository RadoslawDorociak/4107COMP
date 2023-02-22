#pragma once

#ifndef _Star_H
#define _Star_H
#include "Core/Renderer/AnimatedSprite.h"

//class ASCIIRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

const int STAR_SPRITE_ANIMATION_FRAMES = 4;

class Star : public AnimatedSprite
{
public:
	Star();
	~Star();

	void Initialise(Vector2& position, int fireRate, int sprite, int scoreValue, float initialTime = 0.0f);
	bool Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);


	bool Active() { return m_Active; }
	void Approach(float deltaTime); //move towards player
	bool AnimationRandomize = true;
	bool m_Active;
	float m_AnimationTimer;
private:
	bool m_bInitialised;
	



};
#endif

