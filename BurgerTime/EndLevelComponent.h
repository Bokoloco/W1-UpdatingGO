#pragma once
#include "BaseComponent.h"
#include "EndLevelObserver.h"

namespace dae
{
	class Observer;
	class TextComponent;
	class EndLevelComponent final : public BaseComponent
	{
	public:
		EndLevelComponent(GameObject& go);
		~EndLevelComponent() = default;

		void Update() override {};
		void Render() const override {};

		EndLevelObserver* GetObserver() const;

	private:
		std::unique_ptr<EndLevelObserver> m_pEndLevelObserver{};
	};
}