/*

main.cpp is the entry point for Prisma
it configured raylib
from here, the editor does five things:
	launch,
	handle input,
	update,
	render, and
	terminate

*/

// libraries
#include <string>
#include <memory>
#include "raylib.h"

// prisma
#include "macros.cpp"
#include "editor.h"

int main()
{
	// initialize the editor in its default state
	Editor& editor{ Editor::GetSingleton() };
	editor.Launch();

	while (!WindowShouldClose())
	{
		editor.HandleInput();
		editor.Update();
		editor.Render();
	}

	CloseWindow();

    return 0;
}