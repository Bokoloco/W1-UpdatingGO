#include "ControllerInput.h"
#include <iostream>

#pragma comment(lib, "xinput.lib")

void dae::ControllerInput::Update()
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	// Simply get the state of the controller from XInput.
	DWORD dwResult = XInputGetState(m_ConreollerIndex, &state);

	if (dwResult == ERROR_SUCCESS)
	{
		XINPUT_STATE previousState;
		CopyMemory(&previousState, &m_CurrentState, sizeof(XINPUT_STATE));
		ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		XInputGetState(m_ConreollerIndex, &m_CurrentState);

		auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
		m_ButtonsPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
		m_ButtonsReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);
	}
}

bool dae::ControllerInput::CheckButtonPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}
