// Docking branch demo
#include <rlImGui.h>
#include <imgui.h>
#include "ImGuiCustomTheme.h"

int main()
{
	InitWindow(800, 600, "raylib + ImGui Docking Example");

	SetTargetFPS(60);
	rlImGuiSetup(true);

	// Enable docking
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGuiViewport *viewport = ImGui::GetMainViewport();

	ImCustomTheme();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		rlImGuiBegin();
		ImGui::DockSpaceOverViewport(viewport->ID);

		ImGui::Begin("C++ Performance Poem");
		ImGui::BeginChild("PoemScroll", ImVec2(0, 0), true, ImGuiWindowFlags_AlwaysVerticalScrollbar); 

		ImGui::TextWrapped
		(
			"No JVM to slow me down, no Python's sugar high,\n"
			"C++ runs like lightning - others just crawl by.\n"
			"\n"
			"With lambdas in hand and move semantics tight,\n"
			"Zero-cost abstractions make performance feel light.\n"
			"\n"
			"Python says, 'Hey, my code is clean and fun!'\n"
			"But C++ replies, 'I race jets, you barely run.'\n"
			"\n"
			"Java boasts, 'I've got a garbage collector to clean!'\n"
			"C++ grins, 'I have RAII - lean, fast, and mean.'\n"
			"\n"
			"Compile-time magic, with constexpr charm,\n"
			"Cache-friendly layout - no runtime harm.\n"
			"\n"
			"Want real performance? Need full control?\n"
			"C++ is the blade - the rest just scroll.\n"
			"\n"
			"So when building engines or launching to Mars,\n"
			"C++ drives the future - with STL and stars."
		);
		ImGui::EndChild();
		ImGui::End();

		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();
	return 0;
}
