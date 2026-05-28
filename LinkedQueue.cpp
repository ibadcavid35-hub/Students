#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};

class LinkedQueue {
private:
	Node* _front;
	Node* _rear;
public:
	LinkedQueue() :_front(nullptr), _rear(nullptr) {}
	bool isEmpty() const {
		return _front == nullptr;
	}

	void addData(const int& val) {
		Node* newNode = new Node(val);
		if (isEmpty()) {
			_front = _rear = newNode;
			return;
		}
		_rear->next = newNode;
		_rear = newNode;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Empty!\n";
			return;
		}
		Node* temp = _front;
		_front = _front->next;
		delete temp;
	}

	int peek() {
		if (isEmpty()) {
			cout << "Empty\n";
			return 0;
		}
		return _front->data;
	}

	void print() const {
		Node* temp = _front;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	~LinkedQueue() {
		while (!isEmpty()) {
			pop();
		}
	}
};

int main() {
	LinkedQueue lq;
	lq.addData(12);
	lq.addData(66);
	lq.addData(45);
	lq.addData(23);
	lq.pop();
	lq.pop();
	cout << "Peek: " << lq.peek() << endl;
	cout << "Datas: "; lq.print(); cout << endl;

	return 0;
}