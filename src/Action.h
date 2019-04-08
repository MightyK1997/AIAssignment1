#pragma once
#include <functional>


class Action
{
public:
	Action() = default;
	Action(float i_ExpiryTime, float i_Priority) : m_ExpiryTime(i_ExpiryTime), m_Priority(i_Priority){}
	~Action() = default;
	bool CanInterrupt();
	bool CanInterrupt(Action* i_Action);
	bool CanDoBoth(Action* i_Action);
	bool IsComplete();
	void SetAction(std::function<void()> i_Function) { m_Function = i_Function; }
	void ExecuteAction();
	void IncrementQueuedTime(float i_DeltaTime);
	float GetPriority() const { return m_Priority; }
	float GetQueuedTime() const { return m_QueuedTime; }
	float GetExpiryTime() const { return m_ExpiryTime; }

private:
	float m_QueuedTime = 0.0f;
	float m_ExpiryTime = 0.0f;
	float m_Priority = 0.0f;
	std::function<void()> m_Function;
};
