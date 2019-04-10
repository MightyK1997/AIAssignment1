#pragma once
#include "DecisionTreeNode.h"


class DecisionNode: public DecisionTreeNode
{
public:
	virtual DecisionTreeNode* MakeDecision() override;
	virtual Action* GetAction() override { return nullptr; }
	void SetDecisionFunction(std::function<bool()> i_Function) { m_DecisionFunction = i_Function; }
	void SetNodes(DecisionTreeNode* i_TrueNode, DecisionTreeNode* i_FalseNode)
	{
		m_TrueNode = i_TrueNode;
		m_FalseNode = i_FalseNode;
	}
	virtual ~DecisionNode() = default;

private:
	bool IsTrue();
	DecisionTreeNode* GetBranch();
	DecisionTreeNode* m_TrueNode = nullptr;
	DecisionTreeNode* m_FalseNode = nullptr;
	std::function<bool()> m_DecisionFunction;
};
