#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "XInput.h"

#include <memory>

	class ControllerInput
	{
	private:
		class ControllerInputImpl;
		ControllerInputImpl* m_pImpl;

	public:
		ControllerInput();
		~ControllerInput();

		void Update();
		bool CheckButtonPressed(unsigned int button) const;
		bool CheckButtonReleased(unsigned int button) const;

	};
