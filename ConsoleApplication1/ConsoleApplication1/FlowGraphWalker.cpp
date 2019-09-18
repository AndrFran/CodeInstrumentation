#include "pch.h"
#include "FlowGraphWalker.h"
#include "FlowGraphNode.h"

namespace WpfApplication2
{

	FlowGraphWalker::FlowGraphWalker()
	{

	}

	std::vector<std::vector<FlowGraphNode*>> FlowGraphWalker::CalculateAllPathes(std::vector<FlowGraphNode*> nodes)
	{
		std::vector<std::vector<FlowGraphNode*>> Pathes = std::vector<std::vector<FlowGraphNode*>>();

		for (auto node : nodes)
		{
		     switch (node->getNodeType())
			{
				case NodeType::E_FOR:
				{
						ForNode *whilenode = dynamic_cast<ForNode*>(node);
						if (Pathes.empty())
						{
							std::vector<FlowGraphNode*> tempVector4;
							tempVector4.push_back(whilenode);
							Pathes.push_back(tempVector4);
						}
						else
						{
							for (int i = 0; i < Pathes.size(); i++)
							{
								if (NodeType::E_RETURN != Pathes[i].back()->getNodeType())
								{
									Pathes[i].push_back(whilenode);
								}
							}
						}
						std::vector<std::vector<FlowGraphNode*>> dublicate = std::vector<std::vector<FlowGraphNode*>>();
						for (auto ls : Pathes)
						{
							if (NodeType::E_RETURN != ls.back()->getNodeType())
							{
								std::vector<FlowGraphNode*> tmp = std::vector<FlowGraphNode*>();
								tmp.insert(tmp.end(), std::begin(ls), std::end(ls));;
								dublicate.push_back(tmp);
							}
						}
						if (whilenode->getloop().size() > 0)
						{
							std::vector<std::vector<FlowGraphNode*>> recursive = CalculateAllPathes(whilenode->getloop());

							for (auto ls : recursive)
							{
								for (int j = 0; j < Pathes.size(); j++)
								{
									if (NodeType::E_RETURN != Pathes[j].back()->getNodeType())
									{
										Pathes[j].insert(Pathes[j].end(), std::begin(ls), std::end(ls));
									}
								}
							}
						}
						for (auto ls : dublicate)
						{

							Pathes.push_back(ls);
						}
						break;
				}
				case NodeType::E_WHILE:
				{
						WhileNode *whilenode = dynamic_cast<WhileNode*>(node);
						if (Pathes.empty())
						{
							std::vector<FlowGraphNode*> tempVector4;
							tempVector4.push_back(whilenode);
							Pathes.push_back(tempVector4);
						}
						else
						{
							for (int i = 0; i < Pathes.size(); i++)
							{
								if (NodeType::E_RETURN != Pathes[i].back()->getNodeType())
								{
									Pathes[i].push_back(whilenode);
								}
							}
						}
						std::vector<std::vector<FlowGraphNode*>> dublicate = std::vector<std::vector<FlowGraphNode*>>();
						for (auto ls : Pathes)
						{
							if (NodeType::E_RETURN != ls.back()->getNodeType())
							{
								std::vector<FlowGraphNode*> tmp = std::vector<FlowGraphNode*>();
								tmp.insert(tmp.end(), std::begin(ls), std::end(ls));;
								dublicate.push_back(tmp);
							}
						}
						if (whilenode->getloop().size() > 0)
						{
							std::vector<std::vector<FlowGraphNode*>> recursive = CalculateAllPathes(whilenode->getloop());

							for (auto ls : recursive)
							{
								for (int j = 0; j < Pathes.size(); j++)
								{
									if (NodeType::E_RETURN != Pathes[j].back()->getNodeType())
									{
										Pathes[j].insert(Pathes[j].end(), std::begin(ls), std::end(ls));
									}
								}
							}
						}
						for (auto ls : dublicate)
						{
							Pathes.push_back(ls);
						}
						break;
				}
				case NodeType::E_IF:
				{
							IfNode *ifnode = dynamic_cast<IfNode*>(node);
							if (Pathes.empty())
							{
								std::vector<FlowGraphNode*> tempVector4;
								tempVector4.push_back(ifnode);
								Pathes.push_back(tempVector4);
							}
							else
							{
								for (int i = 0; i < Pathes.size(); i++)
								{
								if (NodeType::E_RETURN != Pathes[i].back()->getNodeType())
								{
									Pathes[i].push_back(node);
								}
								}
							}
						std::vector<std::vector<FlowGraphNode*>> dublicate = std::vector<std::vector<FlowGraphNode*>>();
						for (auto ls : Pathes)
						{
							if (NodeType::E_RETURN != ls.back()->getNodeType())
							{
								std::vector<FlowGraphNode*> tmp = std::vector<FlowGraphNode*>();
								tmp.insert(tmp.end(), std::begin(ls), std::end(ls));;
								dublicate.push_back(tmp);
							}
						}
						if (ifnode->getleft().size() > 0)
						{
							std::vector<std::vector<FlowGraphNode*>> recursive = CalculateAllPathes(ifnode->getleft());

							for (auto ls : recursive)
							{
								for (int j = 0;j < Pathes.size();j++)
								{
									if (NodeType::E_RETURN != Pathes[j].back()->getNodeType())
									{
										Pathes[j].insert(Pathes[j].end(), std::begin(ls), std::end(ls));
									}
								}
							}
						}
						if (ifnode->getright().size() > 0)
						{
							std::vector<std::vector<FlowGraphNode*>> recursive = CalculateAllPathes(ifnode->getright());

							for (auto ls : recursive)
							{
								for (int j = 0; j < dublicate.size(); j++)
								{
									if (NodeType::E_RETURN != dublicate[j].back()->getNodeType())
									{
										dublicate[j].insert(dublicate[j].end(), std::begin(ls), std::end(ls));
									}
								}
							}
						}
						for (auto ls : dublicate)
						{
							Pathes.push_back(ls);
						}
						break;
				}

				default:
				{
						if (Pathes.empty())
						{
							std::vector<FlowGraphNode*> tempVector4;
							tempVector4.push_back(node);
							Pathes.push_back(tempVector4);
						}
						else
						{
							for (int i = 0;i < Pathes.size();i++)
							{
								if (NodeType::E_RETURN != Pathes[i].back()->getNodeType())
								{
									Pathes[i].push_back(node);
								}
							}
						}
						break;
				}
			}
		}

		return Pathes;
	}
}
