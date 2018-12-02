#pragma once
#include <Windows.h>
#include <vector>

class SPRITE {
public:
	SPRITE();
	SPRITE(const char *a_Characters, const unsigned int a_width, const unsigned int a_height);
	~SPRITE();
	void SetSprite(const char *a_Characters, const unsigned int a_width, const unsigned int a_height);
	CHAR_INFO * GetBuffer();
	COORD GetSize() const;
	COORD GetPosition() const;
	void SetPosition(const unsigned int a_X, const unsigned int a_Y);

	void SetSize(COORD a) {
		m_Position = Vec2(a.X, a.Y);
	}
private:
	struct Vec2 : public _COORD {
		Vec2(unsigned int a_X, unsigned int a_Y) { X = a_X; Y = a_Y; }
		Vec2() {}
	};
	//contains characters to write to screen
	CHAR_INFO *m_Buffer;
	//size of sprite width and height
	COORD m_Size;
	//topleft corner of sprite
	COORD m_Position;
};

class PixelSprite : public SPRITE
{
public:
	PixelSprite(const unsigned int a_width, const unsigned int a_height, unsigned int a_Colour);
	PixelSprite(const PixelSprite &a_Sprite);
private:

};

class AnimatedSprite {
public:

	//time must be in miliseconds
	void SetAnimationRate(const unsigned int a_Time);
	void SetAnimationRate(float a_Time);
	SPRITE GetAnimation();
	void AddSprite(PixelSprite a_Sprite);
private:
	std::vector<PixelSprite> m_AnimatedBuffer;
	float m_Last;
	float m_Current;
	float m_RateOfAnimation;
	unsigned int m_CurrentAnimation = 0;
};