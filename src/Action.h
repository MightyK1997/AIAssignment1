#pragma once


class Action
{
public:
	Action() = default;
	Action(float i_ExpiryTime, float i_Priority) : m_ExpiryTime(i_ExpiryTime), m_Priority(i_Priority){}
	~Action() = default;
	bool CanInterrupt();
	bool CanInterruptAction(Action* i_Action);
	bool CanDoBoth(Action* i_Action);
	bool IsComplete();
	void ExecuteAction();
	float GetPriority() { return m_Priority; }

private:
	float m_QueuedTime;
	float m_ExpiryTime;
	float m_Priority;
};