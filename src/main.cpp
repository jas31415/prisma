/*

main.cpp is the entry point for Prisma
it configured raylib
from here, the editor does five things:
	launch,
	handle input,
	update,
	render, and
	terminate

main function is defined at the bottom

*/

// libraries
#include <iostream>
#include "raylib.h"

// prisma
#include "main.h"
#include "editor.h"
#include "settings.h"
#include "theme.h"

Main::Main()
{
	m_Themes.insert(
		{"editor", new Theme(
			"../assets/logos/prisma-shatteredHierarchy.png",
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
	std::cout << m_Themes.at("editor") << std::endl;
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

	Editor& editor{ Editor::GetSingleton() };
	editor.AssignTheme(main.GetTheme("editor"));

	Settings& editorSettings{ *editor.GetSettings() };
	editorSettings.SetTitle("Prisma " + editor.GetVersionString());
	
	editor.Launch();

	while (!WindowShouldClose())
	{
		editor.HandleInput();
		editor.Update();
		editor.Render();
	}

	editor.Terminate();

	CloseWindow();

    return 0;
}