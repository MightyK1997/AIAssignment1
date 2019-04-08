#pragma once
#include "DecisionTreeNode.h"
#include "DecisionMakingBehavior.h"
#include "Action.h"

class DecisionTree : public DecisionMakingBehavior
{
public:
	DecisionTree() = default;
	DecisionTree(DecisionTreeNode* i_Root) : m_TreeRoot(i_Root) {}
	~DecisionTree() = default;

	Action* GetAction() override
	{
		auto node = m_TreeRoot->MakeDecision();
		return node->GetAction();
	}

	DecisionTreeNode* GetRoot() const;
	void SetRoot(DecisionTreeNode* i_Root) { m_TreeRoot = i_Root; }

private:
	DecisionTreeNode * m_TreeRoot;
};
