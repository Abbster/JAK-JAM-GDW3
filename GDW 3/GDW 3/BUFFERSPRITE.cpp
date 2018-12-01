#include "BUFFERSPRITE.h"
#include "Timer.h"
SPRITE::SPRITE()
{

}

SPRITE::SPRITE(const char * a_Characters, const unsigned int a_width, const unsigned int a_height)
{
	m_Buffer = new CHAR_INFO[a_width * a_height];
	for (unsigned int i = 0; i < a_height * a_width; i++) {
		m_Buffer[i].Char.AsciiChar = a_Characters[i];
	}
	m_Size = Vec2(a_width, a_height);
}

SPRITE::~SPRITE()
{
	if (m_Buffer != nullptr)
		delete[] m_Buffer;
}

void SPRITE::SetSprite(const char *a_Characters, const unsigned int a_width, const unsigned int a_height)
{
	if (m_Buffer != nullptr)
		delete[] m_Buffer;
	m_Buffer = new CHAR_INFO[a_width * a_height];
	for (unsigned int i = 0; i < a_height * a_width; i++) {
		m_Buffer[i].Char.AsciiChar = a_Characters[i];
	}
	m_Size = Vec2(a_width, a_height);
}

CHAR_INFO * SPRITE::GetBuffer()
{
	return m_Buffer;
}

COORD SPRITE::GetSize() const
{
	return m_Size;
}

COORD SPRITE::GetPosition() const
{
	return m_Position;
}

void SPRITE::SetPosition(const unsigned int a_X, const unsigned int a_Y)
{
	m_Position = Vec2(a_X, a_Y);
}
PixelSprite::PixelSprite(const unsigned int a_width, const unsigned int a_height,unsigned int a_Colour)
{
	// creat out ofn buffer
	char *l_Temp = new char[a_width * a_height];
	// assign each ascii to the block ascii 
	
	for (unsigned int i = 0; i < a_width * a_height; i++)
	{
		l_Temp[i] = 219;
	}
	// call the parent constructor 
	SetSprite(l_Temp, a_width, a_height);
	
	CHAR_INFO *ptr = GetBuffer();
	for (unsigned int i = 0; i < a_width * a_height; i++)
	{
		ptr[i].Attributes = a_Colour;
	}
	// delete our buffer
	delete[] l_Temp;
}

PixelSprite::PixelSprite(const PixelSprite & a_Sprite)
{
	
}

void AnimatedSprite::SetAnimationRate(const unsigned int a_Time)
{
	m_RateOfAnimation = (float)a_Time / 1000.0f;
}

void AnimatedSprite::SetAnimationRate(float a_Time)
{
	m_RateOfAnimation = a_Time;
}

SPRITE AnimatedSprite::GetAnimation()
{
	if (m_Current > m_RateOfAnimation + m_RateOfAnimation)
	{
		m_CurrentAnimation = 1;
		if (m_CurrentAnimation > m_AnimatedBuffer.size())
			m_CurrentAnimation = 0;
	}
	return m_AnimatedBuffer[m_CurrentAnimation];
}

void AnimatedSprite::AddSprite(PixelSprite a_Sprite)
{
	m_AnimatedBuffer.push_back(a_Sprite);
}