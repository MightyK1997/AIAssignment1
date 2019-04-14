#pragma once
#include "Task.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Sequencer : protected Task
			{
			public:
				Sequencer(uint8_t i_id);
				~Sequencer();
				virtual TaskStatus OnEnter(Tick* i_tick) override;
				virtual TaskStatus OnExit(Tick* i_tick) override;
				virtual TaskStatus OnOpen(Tick* i_tick) override;
				virtual TaskStatus OnClose(Tick* i_tick) override;
				virtual TaskStatus OnExecute(Tick* i_tick) override;
				virtual Action* GetAction() override;
				virtual TaskStatus Run(Tick* i_tick) override;

				void AddChild(Task* i_task) { m_ChildTasks.push_back(i_task); }
			};
		}
	}
}