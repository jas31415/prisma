#pragma once
#include <string>
#include <map>
#define nameof(name) std::string(#name)

class Editor;
class Theme;

class Main final
{
public:
	Main(const Main& other) = delete;
	Main& operator=(const Main& other) = delete;
	Main(Main&& other) = delete;
	Main& operator=(Main&& other) = delete;

	static Main& GetSingleton();
	
	Theme* GetTheme(const std::string& name) const;

private:
	std::map<std::string, Theme*> m_Themes;

	explicit Main();
	~Main();
};