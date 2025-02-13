#pragma once
namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		virtual void Update() = 0;
		virtual void Render(const GameObject& gameObject) const = 0;
	};
}