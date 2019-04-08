#include "DecisionNode.h"

DecisionTreeNode* DecisionNode::MakeDecision()
{
	return (GetBranch()->MakeDecision());
}

bool DecisionNode::IsTrue()
{
	return true;
}

DecisionTreeNode* DecisionNode::GetBranch()
{
	return (IsTrue() ? m_TrueNode: m_FalseNode);
}