/*

editor.cpp is the manager class of the engine's various components

*/

#include "macros.cpp"
#include "raylib.h"
#include "editor.h"
#include "settings.h"

Editor::Editor()
	: m_pSettings	{ nullptr }
	, m_State		{ State::LOADING }
	, m_Title 		{ "Prisma " + PRISMA_VERSION_STRING }
{
	InitWindow(1, 1, m_Title.c_str());
}

void Editor::Launch()
{
	const Rectangle INITIAL_WINDOW_SPACE
	{ 
		(GetMonitorWidth(GetCurrentMonitor()) - s_LogoTexture.width * 2.5f) / 2.0f,
		(GetMonitorHeight(GetCurrentMonitor()) - s_LogoTexture.height * 1.5f) / 2.0f,
		s_LogoTexture.width * 2.5f,	s_LogoTexture.height * 1.5f
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
		ClearBackground(BLACK);
		const Vector2 LOGO_POSITION
		{
			(GetScreenWidth() - s_LogoTexture.width) / 2.0f,
			(GetScreenHeight() - s_LogoTexture.height) / 2.0f,
		};
		DrawTexture(s_LogoTexture, LOGO_POSITION.x, LOGO_POSITION.y, Color(RAYWHITE));
	}
	EndDrawing();
}

std::string Editor::s_PathToLogo{ "../assets/logos/prisma-shatteredHierarchy-nogaps.png" };
Texture2D Editor::s_LogoTexture{ };

Editor& Editor::GetSingleton()
{
	static Editor singleton{ };
#if EDITOR_SINGLETON_CREATED == false
#undef EDITOR_SINGLETON_CREATED
#define EDITOR_SINGLETON_CREATED true
	s_LogoTexture = LoadTexture(s_PathToLogo.c_str());
#endif
	return singleton;
}

Editor::State Editor::GetState() const
{
	return m_State;
}

void Editor::SetState(Editor::State newState)
{
	m_State = newState;
}

const std::string& Editor::GetTitle() const
{
	return m_Title;
}