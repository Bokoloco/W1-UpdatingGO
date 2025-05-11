#pragma once
#include "BaseComponent.h"
#include <vector>
#include <map>

namespace dae
{
	class GameObject;
	class FSMState;
	class FSMCondition;
	class FSMComponent : public BaseComponent
	{
	public:
		FSMComponent(GameObject& go);

		void Update() override;
		void Render() const override {};

		template<class StateType, typename... Args>
		void AddState(unsigned int id, Args&&... args);

		template<class ConditionType, typename... Args>
		void AddCondition(unsigned int id, Args&&... args);
		
		void AddTransition(unsigned int startState, unsigned int toState, unsigned int condition);

	private:
		std::map<unsigned int, std::unique_ptr<FSMState>> m_States{};
		std::map<unsigned int, std::unique_ptr<FSMCondition>> m_Conditions{};
		std::map<FSMState*, std::vector<std::pair<FSMCondition*, FSMState*>>> m_Transitions{};

		FSMState* m_pCurrentState{};
	};

	template<class StateType, typename ...Args>
	inline void FSMComponent::AddState(unsigned int id, Args && ...args)
	{
		m_States.emplace(id, std::make_unique<StateType>(std::forward<Args>(args)...));

		if (!m_pCurrentState) m_pCurrentState = m_States[id].get();
	}

	template<class ConditionType, typename ...Args>
	inline void FSMComponent::AddCondition(unsigned int id, Args && ...args)
	{
		m_Conditions.emplace(id, std::make_unique<ConditionType>(std::forward<Args>(args)...));
	}
}