/*

settings.cpp is where the engine's configurations are managed

*/

#include "raylib.h"
#include "settings.h"

int Settings::GetFPS(bool getTarget) const
{
	if (getTarget)
	{
		return (m_DoVSync) ? GetMonitorRefreshRate(GetCurrentMonitor()) : c_TargetFPS;
	}
	return 1.0f / GetFrameTime();
}

bool Settings::IsVSyncEnabled() const
{
	return m_DoVSync;
}

void Settings::SetVSync(bool newTruth)
{
	m_DoVSync = newTruth;
}