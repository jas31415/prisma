/*

Theme is the class that contains all UI-related variables for a project
these also apply to the editor

[15:08 8-4-25] (jas31415)
	at some point i want to try and make the editor a project within this code-base itself
	kind of like how Godot is made in Godot

*/

// raylib
#include "raylib.h"

// prisma
#include "theme.h"

Theme::Theme(
	const std::string& iconPath,
	const Color& backgroundColor
)
	: m_WindowIcon{ LoadImage(iconPath.c_str()) }
	, m_WindowIconPath{ iconPath }
	, m_BackgroundColor{ backgroundColor }
{
}

// Adjusts both the window icon path stored by Prisma and the window icon path itself
// This function exists because raylib doesn't provide a way to access the window icon once it is set
// If you want to use raylib's version of this function, prefix the call with RAYLIB_H::
void Theme::SetWindowIcon(const std::string& newIconPath)
{
	m_WindowIconPath = newIconPath;
	UnloadImage(m_WindowIcon);
	m_WindowIcon = LoadImage(newIconPath.c_str());
	RAYLIB_H::SetWindowIcon(m_WindowIcon);
}

std::string Theme::GetWindowIconPath() const
{
	return m_WindowIconPath;
}

Image Theme::GetWindowIcon() const
{
	return m_WindowIcon;
}

void Theme::SetBackgroundColor(const Color& newColor)
{
	m_BackgroundColor = newColor;
}

Color Theme::GetBackgroundColor() const
{
	return m_BackgroundColor;
}