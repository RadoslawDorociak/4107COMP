#pragma once

#ifndef _ENEMYSHIP_H
#define _ENEMYSHIP_H
#include "Core/Renderer/AnimatedSprite.h"

//class ASCIIRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

const int ENEMY_SPRITE_ANIMATION_FRAMES = 4;

class EnemyShip : public AnimatedSprite
{
public:
	EnemyShip();
	~EnemyShip();

	void Initialise(Vector2& position, int fireRate, int sprite, float initialTime = 0.0f);
	bool Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);

	void Die(); //explode 
	bool Active() { return m_Active; }
	void Approach(float deltaTime); //move towards player


	bool m_Active;
private:
	bool m_bInitialised;
	float m_AnimationTimer;
	

	int m_FireRate;

};
#endif

