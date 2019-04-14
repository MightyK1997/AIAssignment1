#include "Entropy.h"

float Entropy::GetEntropy(std::vector<Example*> i_Examples)
{
	if (i_Examples.empty()) return 0;
	std::map<std::string, int> actionCounts;
	for (auto example : i_Examples)
	{
		actionCounts[example->GetAction()]++;
	}
	auto actionCount = actionCounts.size();
	float entropy = 0;
	if (actionCount == 1) return 0;
	for (auto action : actionCounts)
	{
		auto proportion = action.second / i_Examples.size();
		entropy -= proportion * log2(proportion);
	}
	return entropy;
}

void Entropy::MakeDecisionTree(std::vector<Example*> i_Examples, std::vector<std::string> i_Attributes,
	DecisionNode* i_RootNode)
{
	auto initialEntropy = GetEntropy(i_Examples);
	if (initialEntropy <= 0) return;
	auto exampleCount = i_Examples.size();
	std::string bestAttribute = "";
	std::vector<std::vector<Example*>> bestSets;
	for (auto attribute : i_Attributes)
	{
		auto sets = SplitByAttribute(i_Examples, attribute);
		auto overallEntropy = GetEntropyOfSets(sets, i_Examples.size());
		auto infoGain = initialEntropy - overallEntropy;
	}
}

std::vector<std::vector<Example*>> Entropy::SplitByAttribute(std::vector<Example*> i_Examples, std::string i_Attribute)
{
	std::vector<std::vector<Example*>> sets;
	for (auto example : i_Examples)
	{

	}
	return sets;
}

float Entropy::GetEntropyOfSets(std::vector<std::vector<Example*>> i_Sets, size_t i_ExampleCount)
{
	float entropy = 0;
	for (auto set : i_Sets)
	{
		auto proportion = set.size() / i_ExampleCount;
		entropy -= proportion * GetEntropy(set);
	}
	return entropy;
}
