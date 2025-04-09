#pragma once
#include <string>
#include <memory>

class Settings;
class Theme;

class Editor final
{
public:
	enum class State { LOADING, INTERFACE };

	Editor(const Editor& other) = delete;
	Editor& operator=(const Editor& other) = delete;
	Editor(Editor&& other) = delete;
	Editor& operator=(Editor&& other) = delete;

	void Launch();
	void HandleInput();
	void Update();
	void Render() const;
	void Terminate();

	static Editor& GetSingleton();
	
	std::string GetVersionString() const;
	void SetState(State newState);
	State GetState() const;
	Settings* GetSettings() const;
	void AssignTheme(Theme* theme);
	Theme* GetAssignedTheme() const;

private:
	const std::string c_VersionString;
	Settings* m_pSettings;
	Theme* m_pAssignedTheme;
	State m_State;

	explicit Editor();
	~Editor();
};