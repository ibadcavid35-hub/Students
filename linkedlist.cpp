#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() :head(nullptr) {}

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			cout << current->data << " ";
			delete current;
			current = nextNode;
		}
		head = nullptr;
	}

	void add(int val) {
		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void print() const {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main() {
	LinkedList l1;
	l1.add(5);
	l1.add(7);
	l1.add(3);
	l1.print();

	return 0;
}