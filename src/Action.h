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
	void SetAction(std::function<void(void)> i_Function) { m_Function = i_Function; }
	void SetCompleteFunction(std::function<bool(void)> i_Function) { m_CheckCompleteFunction = i_Function; }
	void ExecuteAction();
	void IncrementQueuedTime(float i_DeltaTime);

	void SetQueuedTime(float i_QueuedTime) { m_QueuedTime = i_QueuedTime; }
	void SetExpiryTime(float i_ExpiryTime) { m_ExpiryTime = i_ExpiryTime; }
	void SetPriority(float i_Priority) { m_Priority = i_Priority; }

	float GetPriority() const { return m_Priority; }
	float GetQueuedTime() const { return m_QueuedTime; }
	float GetExpiryTime() const { return m_ExpiryTime; }
	void SetCanInterrupt(bool i_CanInterrupt) { m_CanInterrupt = i_CanInterrupt; }

private:
	float m_QueuedTime = 0.0f;
	float m_ExpiryTime = 1.0f;
	float m_Priority = 1.0f;
	bool m_CanInterrupt = false;
	std::function<void()> m_Function;
	std::function<bool()> m_CheckCompleteFunction;
};
