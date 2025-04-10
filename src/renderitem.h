#pragma once

class RenderItem final
{
public:
	explicit RenderItem() = delete;
	RenderItem(const Texture2D& raylibTexture, const Vector2& position = {});
	RenderItem(const RenderItem& other) = delete;
	RenderItem& operator=(const RenderItem& other) = delete;
	RenderItem(RenderItem&& other) = delete;
	RenderItem& operator=(RenderItem&& other) = delete;
	~RenderItem();

	Texture2D GetRaylibTexture() const;
	void SetPosition(const Vector2& newPosition);
	void SetPosition(float newX, float newY);
	void SetX(float newX);
	void SetY(float newY);
	
private:
	const Texture2D& c_RaylibTexture;
	Vector2 m_Position;

};