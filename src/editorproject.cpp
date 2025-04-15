/*

EditorProject is the manager class of the engine's various game development components

*/

// c++
#include <string>

// raylib
#include "raylib.h"

// prisma
#include "main.h"
#include "editorproject.h"
#include "settings.h"
#include "theme.h"
#include "renderitem.h"

EditorProject::EditorProject()
	: c_VersionString	{ "1.0-libcandidate-raylib-c" }
	, m_pSettings		{ new Settings() }
	, m_State			{ State::LOADING }
	, m_pAssignedTheme	{ nullptr }
	, m_pRenderItem		{ nullptr }
	, m_ShouldTerminate { false }
{
}

EditorProject::~EditorProject()
{
	delete m_pSettings;
	delete m_pRenderItem;
}

void EditorProject::Launch()
{
	// initialize members
	
	// get necessary references
	const Texture2D& logoTexture{ LoadTextureFromImage(*m_pAssignedTheme->GetWindowIcon()) };
	const Image& windowIcon{ *m_pAssignedTheme->GetWindowIcon() };
	
	m_pRenderItem = new RenderItem{ logoTexture };
	// define required variables
	const Rectangle INITIAL_WINDOW_SPACE
	{ 
		(GetMonitorWidth(GetCurrentMonitor()) - windowIcon.width * 2.5f) / 2.0f,
		(GetMonitorHeight(GetCurrentMonitor()) - windowIcon.height * 1.5f) / 2.0f,
		windowIcon.width * 2.5f,	windowIcon.height * 1.5f
	};
	const Vector2 LOGO_POSITION
	{
		(INITIAL_WINDOW_SPACE.width - windowIcon.width) / 2.0f,
		(INITIAL_WINDOW_SPACE.height - windowIcon.height) / 2.0f,
	};

	// initialize the raylib windows
	ToggleBorderlessWindowed();
	SetWindowSize(INITIAL_WINDOW_SPACE.width, INITIAL_WINDOW_SPACE.height);
	SetWindowPosition(INITIAL_WINDOW_SPACE.x, INITIAL_WINDOW_SPACE.y);

	// initialize members
	m_pRenderItem->SetPosition(INITIAL_WINDOW_SPACE.x, INITIAL_WINDOW_SPACE.y);
}

void EditorProject::HandleInput()
{
	
}

void EditorProject::Update()
{
	const float delta{ GetFrameTime() };

	
}

void EditorProject::Render() const
{
	BeginDrawing();
	{
		ClearBackground(m_pAssignedTheme->GetBackgroundColor());
		m_pRenderItem->Render();
	}
	EndDrawing();
}

void EditorProject::Terminate()
{
	m_ShouldTerminate = true;
}

bool EditorProject::ShouldTerminate() const
{
	return m_ShouldTerminate;
}

EditorProject& EditorProject::GetSingleton()
{
	static EditorProject singleton{ };
	return singleton;
}

std::string EditorProject::GetVersionString() const
{
	return c_VersionString;
}

void EditorProject::SetState(EditorProject::State newState)
{
	m_State = newState;
}

EditorProject::State EditorProject::GetState() const
{
	return m_State;
}

Settings* EditorProject::GetSettings() const
{
	return m_pSettings;
}

void EditorProject::AssignTheme(Theme* theme)
{
	m_pAssignedTheme = theme;
}

Theme* EditorProject::GetAssignedTheme() const
{
	return m_pAssignedTheme;
}