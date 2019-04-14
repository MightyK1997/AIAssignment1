#pragma once
#include "Example.h"
#include <vector>
#include "DecisionNode.h"


class Entropy
{
	float GetEntropy(std::vector<Example*> i_Examples);
	std::vector<std::vector<Example*>> SplitByAttribute(std::vector<Example*> i_Examples, std::string i_Attribute);
	float GetEntropyOfSets(std::vector<std::vector<Example*>> i_Sets, size_t i_ExampleCount);
	void MakeDecisionTree(std::vector<Example*> i_Examples, std::vector<std::string> i_Attributes, DecisionNode* i_RootNode);
};