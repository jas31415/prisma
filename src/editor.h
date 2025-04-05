#pragma once
#include <string>
#include <memory>

class Settings;

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

	static Editor& GetSingleton();

	State GetState() const;
	void SetState(State newState);
	const std::string& GetTitle() const;

private:
	Settings* m_pSettings;
	State m_State;
	const std::string m_Title;

	static std::string s_PathToLogo;
	static Texture2D s_LogoTexture;

	explicit Editor();
	~Editor() = default;
};