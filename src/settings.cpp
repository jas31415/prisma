/*

settings.cpp is where the engine's configurations are managed

[9:48 8-4-25] (jas31415)
	I did not singleton this because I expect to reuse it in the future for
	some kind of project-file class
*/

// raylib
#include "raylib.h"

// prisma
#include "settings.h"

Settings::Settings()
	: m_Title 		{ "" }
	, m_TargetFPS	{ 60 }
{
}

// Sets the title of the window
// This function exists because raylib offers no way to acquire the window's title
void Settings::SetTitle(const std::string& newTitle)
{
	m_Title = newTitle;
}

// Gets the title of the window
std::string Settings::GetTitle() const
{
	return m_Title;
}

// Sets the max FPS the project will try to achieve
// Disables V-Sync if it is enabled
// To use raylib's SetTargetFPS(), prefix it with the RAYLIB_H scope
// This function exists because raylib offers no way to acquire the target fps
void Settings::SetTargetFPS(int newTargetFPS)
{
	RAYLIB_H::SetTargetFPS(newTargetFPS);
	m_TargetFPS = newTargetFPS;
	ClearWindowState(FLAG_VSYNC_HINT);
}

// Returns the target FPS the project is trying to reach
int Settings::GetTargetFPS() const
{
	return m_TargetFPS;
}

// Returns the actual FPS the project is currently running at
float Settings::GetFPS() const
{
	return 1.0f / GetFrameTime();
}

void Settings::SetVSync(bool enable)
{
	(enable) ?
		SetWindowState(FLAG_VSYNC_HINT) // enabled
		: ClearWindowState(FLAG_VSYNC_HINT); // disabled
}

bool Settings::IsVSyncEnabled() const
{
	return IsWindowState(FLAG_VSYNC_HINT);
}