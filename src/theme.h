#pragma once
#include <string>

class Theme final
{
public:
	explicit Theme(
		const std::string& windowIconPath,
		const Color& backgroundColor
		);
	Theme(const Theme& other) = default;
	Theme& operator=(const Theme& other) = default;
	Theme(Theme&& other) = default;
	Theme& operator=(Theme&& other) = default;
	~Theme() = default;

	void SetWindowIcon(const std::string& iconPath);
	std::string GetWindowIconPath() const;
	Image GetWindowIcon() const;
	void SetBackgroundColor(const Color& newColor);
	Color GetBackgroundColor() const;

private:
	std::string m_WindowIconPath;
	Color m_BackgroundColor;
};