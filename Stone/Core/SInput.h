#ifndef __INPUT_H__
#define __INPUT_H__

#include "SSingleton.h"
#include "SDL.h"
#include "SVec2.h"
#include <vector>

enum SButton_State
{
	SBUTTON_LEFT = 0,
	SBUTTON_MIDDLE = 1, 
	SBUTTON_RIGHT = 2
};

class SInput : public SSingleton<SInput>
{
	friend class SSingleton<SInput>;
public:
	void update();
	bool getMouseButtonState(int buttonNumber);
	SVec2 getMousePosition();
	bool isKeyDown(SDL_Scancode key);
private:
	SInput()
	{
		for (int i = 0; i < 3; i++)
			m_mouseButtonStates.push_back(false);
	}
	~SInput(){}
	void onKeyDown();
	void onKeyUp();
	void onButtonDown(SDL_Event& event);
	void onButtonUp(SDL_Event& event);
	void onMouseMove(SDL_Event& event);

	std::vector<bool> m_mouseButtonStates;
	SVec2 m_mousePosition;
	const uint8_t* m_keystates;
};

#define SINPUT SInput::getInstance()

#endif // !__INPUT_H__
