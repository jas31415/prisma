#pragma once
#include <string>

class Settings final
{
public:
	explicit Settings() = default;
	Settings(const Settings& other) = default;
	Settings& operator=(const Settings& other) = default;
	Settings(Settings&& other) = default;
	Settings& operator=(Settings&& other) = default;
	~Settings() = default;

	void SetTitle(const std::string& newTitle);
	std::string GetTitle() const;
	void SetTargetFPS(int newTargetFPS);
	int GetTargetFPS() const;
	float GetFPS() const;
	void SetVSync(bool enable);
	bool IsVSyncEnabled() const;

private:
	std::string m_Title;
	int m_TargetFPS;
};