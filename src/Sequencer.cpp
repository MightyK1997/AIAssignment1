#pragma once
#include "Sequencer.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			TaskStatus Sequencer::OnEnter(Tick* i_tick)
			{
				return e_SUCCESS;
			}

			TaskStatus Sequencer::OnExit(Tick* i_tick)
			{
				return e_SUCCESS;
			}

			TaskStatus Sequencer::OnOpen(Tick* i_tick)
			{
				i_tick->GetBlackboard()->SetChild(0);
				return e_SUCCESS;
			}

			TaskStatus Sequencer::OnClose(Tick* i_tick)
			{
				return e_SUCCESS;
			}

			TaskStatus Sequencer::OnExecute(Tick* i_tick)
			{
				uint8_t runningChild = i_tick->GetBlackboard()->GetChild();
				for (int i = runningChild; i < m_ChildTasks.size(); i++)
				{
					Task* childTask = GetChildren()[i];
					TaskStatus childStatus = childTask->Run(i_tick);
					if (childStatus != e_SUCCESS)
					{
						if (childStatus == e_RUNNING)
						{
							i_tick->GetBlackboard()->SetChild(0);
						}
						return childStatus;
					}
				}
				return e_FAILURE;
			}

			Action* Sequencer::GetAction()
			{
				return nullptr;
			}

			TaskStatus Sequencer::Run(Tick* i_tick)
			{
				OnOpen(i_tick);
				return OnExecute(i_tick);
			}
		}
	}
}