#pragma once
#include "Node.h"
class CompareNodesOther
{
public:
	CompareNodesOther();
	~CompareNodesOther();
	bool operator () (Node* pn1, Node* pn2)
	{
		return pn1->getF() < pn2->getF();
	}
};