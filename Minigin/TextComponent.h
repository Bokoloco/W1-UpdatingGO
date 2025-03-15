#pragma once
#include <string>
#include <memory>
#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class GameObject;
	class TextComponent final : public BaseComponent
	{
	public:
		TextComponent(GameObject& go);

		void Update() override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetFont(std::shared_ptr<Font> font);

	private:
		bool m_NeedsUpdate{};
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_TextTexture;
	};
}