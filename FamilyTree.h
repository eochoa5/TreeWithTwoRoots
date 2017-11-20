#ifndef FAMILYTREE
#define FAMILYTREE
#include "FamilyTreeNode.h"
#include <string>
#include <set>
#include <iostream>
#include <ostream>

using namespace std;

class FamilyTree {

public:
	FamilyTree(string familynameIn) :
		familyName(familynameIn) {};

	void setRoot(FamilyTreeNode *node) {
		if (root1 != NULL && root2 != NULL) {

			cout << "Error: roots are already defined \n" << endl;
			return;

		}
		if (root1 == NULL) {
			root1 = node;
			return;

		}
		else {
			root2 = node;
		}

	}

	void addNode(FamilyTreeNode *n);
	set<FamilyTreeNode *> getAllNodes();
	vector<FamilyTreeNode *> getDescendants(FamilyTreeNode *n);
	vector<FamilyTreeNode *> getAncestors(FamilyTreeNode *n);
	bool isAncestor(FamilyTreeNode *node1, FamilyTreeNode *node2);
	bool isDescendant(FamilyTreeNode *node1, FamilyTreeNode *node2);

	string getFamilyName() {
		return familyName;

	}

	friend ostream& operator<<(ostream& os, FamilyTree* f) {

		os << "all nodes in " << f->getFamilyName() << " tree: " << endl;

		set<FamilyTreeNode *> all = f->getAllNodes();
		while (!all.empty()) {
			os << ' ' << (*all.begin()) << endl;
			all.erase(all.begin());
		}

		return os;
	}


private:
	string familyName;
	FamilyTreeNode *root1 = NULL;
	FamilyTreeNode *root2 = NULL;
};

#endif

