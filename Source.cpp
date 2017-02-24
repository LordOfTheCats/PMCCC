#pragma once
#include <stdlib.h>

using namespace std;

struct node {
	float data;
	node* next;

	void append(float x) {
		if (next == NULL) {
			node* temp;
			temp = (node*)malloc(sizeof(node));
			temp->data = x;
			temp->next = NULL;
			next = temp;
		} else {
			next->append(x);
		}
	}

	float retrieve(int p) {
		node* anotherOne = this;
		for (int i = 0; i < p; i++) {
			if (anotherOne->next != NULL) {
				anotherOne = anotherOne->next;
			} else {
				throw "Shit";
			}
		}
		return anotherOne->data;
	}

	node() {
		data = 0;
		next = NULL;
	};
};
