#pragma once

#include "FlowGraphNode.h"
#include <vector>


namespace WpfApplication2
{
	class FlowGraphWalker
	{

	public:
		FlowGraphWalker();
		std::vector<std::vector<FlowGraphNode*>> CalculateAllPathes(std::vector<FlowGraphNode*> nodes);
	};
}
