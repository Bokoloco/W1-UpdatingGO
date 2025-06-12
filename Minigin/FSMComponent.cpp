#include "FSMComponent.h"
#include <iostream>
#include "FSMStateAndCondition.h"

dae::FSMComponent::FSMComponent(GameObject& go)
	: BaseComponent(go)
{
}

void dae::FSMComponent::AddTransition(unsigned int startState, unsigned int toState, unsigned int condition)
{
	if (m_States.find(startState) == m_States.end()) std::cerr << "Start state not in map" << std::endl;
	if (m_States.find(toState) == m_States.end()) std::cerr << "To state not in map" << std::endl;
	if (m_Conditions.find(condition) == m_Conditions.end()) std::cerr << "Condition not in map" << std::endl;

	auto pStartState = m_States[startState].get();
	auto pToState = m_States[toState].get();
	auto pCondition = m_Conditions[condition].get();

	auto it = m_Transitions.find(pStartState);
	if (it == m_Transitions.end())
	{
		m_Transitions[pStartState] = std::vector<std::pair<FSMCondition*, FSMState*>>();
	}

	m_Transitions[pStartState].push_back(std::make_pair(pCondition, pToState));
}

void dae::FSMComponent::Update()
{
    if (m_pCurrentState)
        m_pCurrentState->Update();

    if (m_Transitions.find(m_pCurrentState) != m_Transitions.end())
    {
        auto transitions = m_Transitions.find(m_pCurrentState)->second;
        if (transitions.size() >= 1)
        {
            for (auto pair : transitions)
            {
                if (pair.first->Evaluate())
                {
                    m_pCurrentState = pair.second;
                    m_pCurrentState->OnEnter();
                }
            }
        }
    }
}
