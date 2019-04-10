#include "DecisionNode.h"

DecisionTreeNode* DecisionNode::MakeDecision()
{
	return (GetBranch()->MakeDecision());
}

bool DecisionNode::IsTrue()
{
	return m_DecisionFunction();
}

DecisionTreeNode* DecisionNode::GetBranch()
{
	return (IsTrue() ? m_TrueNode: m_FalseNode);
}