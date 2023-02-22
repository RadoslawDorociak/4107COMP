#include "Menu.h"

#include "Core/Renderer/ConsoleColours.h"

CHAR_INFO exitSprite[] =
{
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
};

CHAR_INFO playSprite[] =
{
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE}, {' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ',BACKGROUND_WHITE},{' ', BACKGROUND_WHITE},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},

};

CHAR_INFO TitleSprite[] =
{
	{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},
	{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_YELLOW},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
	{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_MUSTARD},{' ', BACKGROUND_BLACK},{' ', BACKGROUND_BLACK},
};

//CONSTRUCTOR 
MenuIcon::MenuIcon()
	: m_bInitialised(false)
{
}

// DESTRUCTOR
MenuIcon::~MenuIcon()
{
}

void MenuIcon::SetPosition(Vector2 position)
{
	m_position.x = position.x;
	m_position.y = position.y;
}

Vector2 MenuIcon::GetPosition()
{
	return m_position;
}

void MenuIcon::Initialise(Vector2& position)
{
	switch (GetSpriteID()) {
	case 0:Sprite::Initialise(TitleSprite, Vector2(34 ,5)); break;
	case 1:Sprite::Initialise(playSprite, Vector2(25, 5)); break;
	case 2:Sprite::Initialise(exitSprite, Vector2(25, 5)); break;
	}

	Vector2 startPosition(position.x - (Sprite::GetSize().x / 2),
		position.y - (Sprite::GetSize().y / 2));
	Sprite::SetPosition(startPosition);
	m_bInitialised = true;
}
void MenuIcon::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;
	Sprite::Render(pRenderer);
}
void MenuIcon::Update()
{
	if (!m_bInitialised || !m_Active)
		return;
}

CHAR_INFO pointerSprite[] =
{
	{0, BACKGROUND_BLACK}, {0, BACKGROUND_BLACK},{0, BACKGROUND_YELLOW},
	{0, BACKGROUND_BLACK}, {0, BACKGROUND_YELLOW},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_YELLOW}, {0, BACKGROUND_BLACK},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK}, {0, BACKGROUND_YELLOW},{0, BACKGROUND_BLACK},
	{0, BACKGROUND_BLACK}, {0, BACKGROUND_BLACK},{0, BACKGROUND_YELLOW},

};


Pointer::Pointer()
	:m_upKey(0)
	, m_downKey(0)
	, m_bInitialised(false)
{
}

Pointer::~Pointer()
{
}

void Pointer::Initialise(Vector2& position, int upKey, int downKey)
{
	m_upKey = upKey;
	m_downKey = downKey;

	Sprite::Initialise(pointerSprite, Vector2(3, 5));
	Vector2 startPosition(position.x - (Sprite::GetSize().x / 2),
		position.y - (Sprite::GetSize().y / 2));
	SetPosition(startPosition);
	m_bInitialised = true;
}

//if UP key is pressed, move the pointer up so its next to 'play'. if the down key is pressed, move it down so its next to 'exit'
void Pointer::Update()
{
	if (!m_bInitialised)
		return;

	if (GetKeyState(m_upKey) < 0)
	{
		MoveUp();
	}
	if (GetKeyState(m_downKey) < 0)
	{
		MoveDown();
	}


}
void Pointer::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	Sprite::Render(pRenderer);
}
// sets y coordinate to same as play icon
void Pointer::MoveUp()
{
	SetPosition(Vector2(SCREEN_WIDTH / 2 + 20, (SCREEN_HEIGHT / 2) - 2));
	
}
//sets y coordinate so its next to exit icon
void Pointer::MoveDown()
{
	SetPosition(Vector2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 + 4));
}