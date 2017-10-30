#ifndef __INPUT_H__
#define __INPUT_H__

#include "SSingleton.h"
#include "SDL.h"
#include "SVec2.h"
#include <vector>

enum SButton_State
{
	LEFT = 0,
	MIDDLE = 1, 
	RIGHT = 2
};

class SInput : public SSingleton<SInput>
{
	friend class SSingleton<SInput>;

public:
	void update();
private:
	SInput()
	{
		for (int i = 0; i < 3; i++)
			m_mouseButtonStates.push_back(false);
		m_mousePosition = new SVec2(0, 0);
	}
	~SInput(){}
	void onKeyDown();
	void onKeyUp();
	void onButtonDown(SDL_Event& event);
	void onButtonUp(SDL_Event& event);
	void onMouseMove(SDL_Event& event);

	std::vector<bool> m_mouseButtonStates;
	SVec2* m_mousePosition;
	const uint8_t* m_keystates;
};

#define SINPUT SInput::getInstance()

#endif // !__INPUT_H__
