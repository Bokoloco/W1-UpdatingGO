#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "XInput.h"

namespace dae
{
	class ControllerInput
	{
	public:
		ControllerInput() = default;
		~ControllerInput() = default;

		void Update();
		bool CheckButtonPressed(unsigned int button) const;

	private:
		XINPUT_STATE m_CurrentState{};
		int m_ButtonsPressedThisFrame{};
		int m_ButtonsReleasedThisFrame{};

		DWORD m_ConreollerIndex{0};
	};
}