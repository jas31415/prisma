/*

editor.cpp is the manager class of the engine's various components

*/

// raylib
#include "raylib.h"

// prisma
#include "editor.h"
#include "settings.h"
#include "main.h"
#include "theme.h"

Editor::Editor()
	: c_VersionString	{ "1.0-libcandidate-raylib-b" }
	, m_pSettings		{ new Settings() }
	, m_State			{ State::LOADING }
	, m_pAssignedTheme	{ nullptr }
{
}

Editor::~Editor()
{
	delete m_pSettings;
}

void Editor::Launch()
{
	const Image& windowIcon{ m_pAssignedTheme->GetWindowIcon() };

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
	BeginDrawing();
	{
		// !! FIX STATIC USAGE !!
		static Texture2D windowIconTexture{ LoadTexture(m_pAssignedTheme->GetWindowIconPath().c_str()) };
		ClearBackground(m_pAssignedTheme->GetBackgroundColor());
		const Vector2 LOGO_POSITION
		{
			(GetScreenWidth() - windowIconTexture.width) / 2.0f,
			(GetScreenHeight() - windowIconTexture.height) / 2.0f,
		};
		DrawTexture(windowIconTexture, LOGO_POSITION.x, LOGO_POSITION.y, RAYWHITE);
	}
	EndDrawing();
}

void Editor::Terminate()
{
	// prisma
	delete m_pSettings;
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