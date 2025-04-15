/*

Main is the entry point for Prisma
from here, the editor does its five key things:
	launch,
	handle input,
	update,
	render, and
	terminate

main function is defined at the bottom

*/

// c++
#include <iostream>

// raylib
#include "raylib.h"

// prisma
#include "main.h"
#include "editorproject.h"
#include "settings.h"
#include "theme.h"

Main::Main()
{
	m_Themes.insert(
		{"editor", new Theme(
			"../assets/logos/prisma-shatteredHierarchy-noGaps.png",
			ColorFromHSV(245.0f, 0.5f, 0.15f)
		)}
	);
}

Main::~Main()
{
	for (auto itr{ m_Themes.begin() }; itr != m_Themes.end(); itr++)
	{
		delete itr->second;
	}
}

Main& Main::GetSingleton()
{
	static Main singleton{ };
	return singleton;
}

Theme* Main::GetTheme(const std::string& name) const
{
	return m_Themes.at(name);
}

int main()
{
	InitWindow(1, 1, "");

	Main& main{ Main::GetSingleton() };

	EditorProject& project{ EditorProject::GetSingleton() };
	project.AssignTheme(main.GetTheme("editor"));

	Settings& projectSettings{ *project.GetSettings() };
	projectSettings.SetTitle("Prisma " + project.GetVersionString());
	
	project.Launch();

	while (!project.ShouldTerminate())
	{
		project.HandleInput();
		project.Update();
		project.Render();
	}

	CloseWindow();

    return 0;
}