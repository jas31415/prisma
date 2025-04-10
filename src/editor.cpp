/*

Editor is the manager class of the engine's various game development components

*/

// c++
#include <string>

// raylib
#include "raylib.h"

// prisma
#include "main.h"
#include "editor.h"
#include "settings.h"
#include "theme.h"
#include "renderitem.h"

Editor::Editor()
	: c_VersionString	{ "1.0-libcandidate-raylib-c" }
	, m_pSettings		{ new Settings() }
	, m_State			{ State::LOADING }
	, m_pAssignedTheme	{ nullptr }
	, m_pRenderItem		{ }
{
}

Editor::~Editor()
{
	delete m_pSettings;
	delete m_pRenderItem;
}

void Editor::Launch()
{
	m_pRenderItem = new RenderItem(LoadTextureFromImage(m_pAssignedTheme->GetWindowIcon()));
	const Image& windowIcon{ m_pAssignedTheme->GetWindowIcon() };
	SetWindowIcon(windowIcon);
	
	const Rectangle INITIAL_WINDOW_SPACE
	{ 
		(GetMonitorWidth(GetCurrentMonitor()) - windowIcon.width * 2.5f) / 2.0f,
		(GetMonitorHeight(GetCurrentMonitor()) - windowIcon.height * 1.5f) / 2.0f,
		windowIcon.width * 2.5f,	windowIcon.height * 1.5f
	};
	
	ToggleBorderlessWindowed();
	SetWindowSize(INITIAL_WINDOW_SPACE.width, INITIAL_WINDOW_SPACE.height);
	SetWindowPosition(INITIAL_WINDOW_SPACE.x, INITIAL_WINDOW_SPACE.y);
}

void Editor::HandleInput()
{
	
}

void Editor::Update()
{
	const float delta{ GetFrameTime() };

	
}

void Editor::Render() const
{
	const Texture2D& logo{ m_pRenderItem->GetRaylibTexture() };
	BeginDrawing();
	{
		ClearBackground(m_pAssignedTheme->GetBackgroundColor());
		const Vector2 LOGO_POSITION
		{
			(GetScreenWidth() - logo.width) / 2.0f,
			(GetScreenHeight() - logo.height) / 2.0f,
		};
		DrawTexture(logo, LOGO_POSITION.x, LOGO_POSITION.y, RAYWHITE);
	}
	EndDrawing();
}

void Editor::Terminate()
{
	
}

Editor& Editor::GetSingleton()
{
	static Editor singleton{ };
	return singleton;
}

std::string Editor::GetVersionString() const
{
	return c_VersionString;
}

void Editor::SetState(Editor::State newState)
{
	m_State = newState;
}

Editor::State Editor::GetState() const
{
	return m_State;
}

Settings* Editor::GetSettings() const
{
	return m_pSettings;
}

void Editor::AssignTheme(Theme* theme)
{
	m_pAssignedTheme = theme;
}

Theme* Editor::GetAssignedTheme() const
{
	return m_pAssignedTheme;
}