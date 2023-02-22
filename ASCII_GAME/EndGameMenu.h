#ifndef _ENDMENU_H_
#define _ENDMENU_H_
#include "Core/Renderer/Sprite.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class EndMenuIcon : public Sprite
{
public:
	EndMenuIcon();
	~EndMenuIcon();

	void Initialise();
	void Update();
	void Render(ASCIIRenderer* pRenderer);

	void SetPosition(Vector2 position);
	Vector2 GetPosition();

	void SetSpriteID(int ID) { spriteID = ID; };
	int GetSpriteID() { return spriteID; };

private:
	bool m_bInitialised;
	bool m_Active;

	int  spriteID;
	Vector2 m_position;


};



#endif
