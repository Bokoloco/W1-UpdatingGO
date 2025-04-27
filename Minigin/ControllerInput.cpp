#include "ControllerInput.h"
#include <iostream>

#pragma comment(lib, "xinput.lib")


class ControllerInput::ControllerInputImpl
{
public:
	ControllerInputImpl(DWORD controllerIndex);
	~ControllerInputImpl() {};

	void Update();
	bool CheckButtonPressed(unsigned int button) const;
	bool CheckButtonReleased(unsigned int button) const;

private:
	XINPUT_STATE m_CurrentState{};
	int m_ButtonsPressedThisFrame{};
	int m_ButtonsReleasedThisFrame{};

	DWORD m_ControllerIndex{ 0 };
};

ControllerInput::ControllerInputImpl::ControllerInputImpl(DWORD controllerIndex)
	: m_ControllerIndex{controllerIndex}
{}

void ControllerInput::ControllerInputImpl::Update()
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	// Simply get the state of the controller from XInput.
	DWORD dwResult = XInputGetState(m_ControllerIndex, &state);

	if (dwResult == ERROR_SUCCESS)
	{
		XINPUT_STATE previousState;
		CopyMemory(&previousState, &m_CurrentState, sizeof(XINPUT_STATE));
		ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		XInputGetState(m_ControllerIndex, &m_CurrentState);

		auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
		m_ButtonsPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
		m_ButtonsReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);
	}
}

bool ControllerInput::ControllerInputImpl::CheckButtonPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}

bool ControllerInput::ControllerInputImpl::CheckButtonReleased(unsigned int button) const
{
	return m_ButtonsReleasedThisFrame & button ;
}


ControllerInput::ControllerInput(DWORD controllerIndex)
	: m_pImpl{new ControllerInput::ControllerInputImpl(controllerIndex)}
{}

ControllerInput::~ControllerInput()
{
	delete m_pImpl; 
}

void ControllerInput::Update()
{
	m_pImpl->Update();
}

bool ControllerInput::CheckButtonPressed(unsigned int button) const
{
	return m_pImpl->CheckButtonPressed(button);
}

bool ControllerInput::CheckButtonReleased(unsigned int button) const
{
	return m_pImpl->CheckButtonReleased(button);
}
