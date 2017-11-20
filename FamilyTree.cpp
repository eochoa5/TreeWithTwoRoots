#include "FamilyTree.h"
#include <algorithm>

void FamilyTree::addNode(FamilyTreeNode * n){
	n->addAsChild();
}

static void traverse(FamilyTreeNode* node, set<FamilyTreeNode*>& s) {
	
	if (node->getParent1() != NULL){
		s.insert(node->getParent1());
	}
	if (node->getParent2() != NULL) {
		s.insert(node->getParent2());
	}

	s.insert(node);

	for (FamilyTreeNode* each : node->getChildren()) {
		traverse(each, s);
	}
}

set<FamilyTreeNode*> FamilyTree::getAllNodes(){
	
	set<FamilyTreeNode*> setOfNodes;

	vector<FamilyTreeNode*> vec = root1->getChildren();
	vector<FamilyTreeNode*> vec2 = root2->getChildren();
	vec.insert(vec.end(), vec2.begin(), vec2.end());
	set<FamilyTreeNode*> uniqueChildrenOfRoots(vec.begin(), vec.end());

	for (FamilyTreeNode* each : uniqueChildrenOfRoots) {
		traverse(each, setOfNodes);
	}
	
	return setOfNodes;
}


vector<FamilyTreeNode*> FamilyTree::getDescendants(FamilyTreeNode * n){
	 vector<FamilyTreeNode*> vec;

		 vec.push_back(n);
		 for (int i = 0; i < (int) vec.size(); ++i) {
			 FamilyTreeNode *curr = vec[i];
			 vector<FamilyTreeNode*> children = curr->getChildren();
			 if (children.size() > 0) {
				 for (FamilyTreeNode* child : children) {
					 if (!(std::find(vec.begin(), vec.end(), child) != vec.end())) {
						 vec.push_back(child);
					 }
				 }
			 }
		 }
	 
		 vec.erase(vec.begin());
	 
	 return vec;
}

static void getAncestorsHelper(FamilyTreeNode* node, vector<FamilyTreeNode*>& v) {
	
	FamilyTreeNode *p1 = node->getParent1();
	FamilyTreeNode *p2 = node->getParent2();

	if (p1 != NULL) { v.push_back(p1); }

	if (p2 != NULL) { v.push_back(p2); }

	for (FamilyTreeNode* f : node->getParents()) {
		getAncestorsHelper(f, v);

	}

}


vector<FamilyTreeNode*> FamilyTree::getAncestors(FamilyTreeNode * n){
	vector<FamilyTreeNode*> vec;

	for (FamilyTreeNode* f: n->getParents()) {
		vec.push_back(f);
		getAncestorsHelper(f, vec);

	}

	return vec;
}

bool FamilyTree::isAncestor(FamilyTreeNode * node1, FamilyTreeNode * node2){
	vector<FamilyTreeNode*> node2Ancestors = getAncestors(node2);
	return (std::find(node2Ancestors.begin(), node2Ancestors.end(), node1) != node2Ancestors.end());
}

bool FamilyTree::isDescendant(FamilyTreeNode * node1, FamilyTreeNode * node2){
	vector<FamilyTreeNode*> node2Descendants = getDescendants(node2);
	return (std::find(node2Descendants.begin(), node2Descendants.end(), node1) != node2Descendants.end());			
}
