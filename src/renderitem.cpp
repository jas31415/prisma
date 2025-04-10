/*

RenderItem is a wrapper class for the raylib Texture, because it really needs it

*/

// raylib
#include "raylib.h"

// prisma
#include "renderitem.h"

RenderItem::RenderItem(const Texture2D& raylibTexture, const Vector2& position)
	: c_RaylibTexture{ raylibTexture }
	, m_Position{ position }
{
}

RenderItem::~RenderItem()
{
	UnloadTexture(c_RaylibTexture);
}

Texture2D RenderItem::GetRaylibTexture() const
{
	return c_RaylibTexture;
}

void RenderItem::SetPosition(const Vector2& newPosition)
{
	m_Position = newPosition;
}

void RenderItem::SetPosition(float newX, float newY)
{
	SetPosition(Vector2{ newX, newY });
}

void RenderItem::SetX(float newX)
{
	m_Position.x = newX;
}

void RenderItem::SetY(float newY)
{
	m_Position.y = newY;
}