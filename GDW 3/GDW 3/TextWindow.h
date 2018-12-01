#pragma once
#include "BUFFERSPRITE.h"
class TextWindow {
public:
	TextWindow();
	TextWindow(unsigned int a_width, unsigned int a_height);
	void Reize(unsigned int a_width, unsigned int a_height);
	void SwapBackBuffer();
	void RenderSprite(SPRITE &a_Sprite);

private:
	void ClearBackBuffer();
	HANDLE m_Buffers[2];//handle to the two buffers we're going to use to render
	bool m_CurrentBuffer = false;
	COORD m_Size;
};