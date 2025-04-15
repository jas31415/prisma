#pragma once

class Settings;
class Theme;
class RenderItem;

class EditorProject final
{
public:
	enum class State { LOADING, INTERFACE };

	EditorProject(const EditorProject& other) = delete;
	EditorProject& operator=(const EditorProject& other) = delete;
	EditorProject(EditorProject&& other) = delete;
	EditorProject& operator=(EditorProject&& other) = delete;

	void Launch();
	void HandleInput();
	void Update();
	void Render() const;
	void Terminate();
	bool ShouldTerminate() const;

	static EditorProject& GetSingleton();
	
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
	bool m_ShouldTerminate;
	
	RenderItem* m_pRenderItem;

	explicit EditorProject();
	~EditorProject();
};