#ifndef FAMILYTREENODE
#define FAMILYTREENODE
#include <string>
#include <iostream>
#include "person.h"
#include <vector>

using namespace std;

class FamilyTreeNode: public Person {

public:
	FamilyTreeNode(string firstIn, string lastIn, FamilyTreeNode *p1, FamilyTreeNode *p2, int yearIn, int monthIn, int dayIn, 
		char genderIn) : Person(firstIn, lastIn, monthIn, dayIn, yearIn, genderIn),  parent1(p1), parent2(p2){};

	void addAsChild() {
		if (this->parent1 != NULL) {
			this->parent1->children.push_back(this);
		}
		if (this->parent2 != NULL) {
			this->parent2->children.push_back(this);
		}
		
	}

	vector <FamilyTreeNode*> getChildren() {
		return children;

	}

	FamilyTreeNode* getParent1() {
		return parent1;

	}

	FamilyTreeNode* getParent2() {
		return parent2;

	}

	friend ostream& operator<<(ostream& os, FamilyTreeNode* f) {

		string parent1 = "n/a";
		string parent2 = "n/a";

		if (f->getParent1() != NULL) {
			parent1 = f->getParent1()->getFullName();
		}
		if (f->getParent2() != NULL) {
			parent2 = f->getParent2()->getFullName();
		}


		os << f->getFullName() << ", Gender: " << f->getGender() << ", Born: " << f->getDOB() << " Parent 1: " << parent1
			<< ", Parent 2: " << parent2 << endl;

		return os;
	}

	
	vector<FamilyTreeNode*> getParents() {
		
		vector<FamilyTreeNode*> p;
		
		if (parent1 != NULL) {
			p.push_back(parent1);
		}
		if (parent2 != NULL) {
			p.push_back(parent2);
		}

		return p;

	}

	
private:
	vector <FamilyTreeNode*> children;
	FamilyTreeNode *parent1 = NULL;
	FamilyTreeNode *parent2 = NULL;

};

#endif


