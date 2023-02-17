#include <iostream>
#include "DictionaryList.h"

//default constructor
DictionaryList::DictionaryList() {
	head_ = nullptr;
	tail_ = nullptr;
}

//move constructor
DictionaryList::DictionaryList(const DictionaryList& other) {
	head_ = other.head_;
	tail_ = other.tail_;
}

DictionaryList::~DictionaryList() {
	if (head_ != nullptr) {
		Node* next = head_;
		while (next) {
			next = next->next_;
			delete head_;
			head_ = next;
		}
	}
}

bool DictionaryList::isEmpty() {
	return head_ == nullptr;
}

DictionaryList::Node* DictionaryList::head() const {
	return head_;
}

void DictionaryList::print() {
	if (isEmpty()) {
		std::cout << std::endl;
		return;
	}

	Node* current = head_;
	while (current) {
		std::cout << current->item_ << " ";
		current = current->next_;
	}
	std::cout << std::endl;
}

void DictionaryList::insert(Node* x) {
	if (this->search(x->item_)) { return; }

	else if (this->isEmpty()) {
		head_ = x;
		tail_ = x;
		return;
	}

	else if (x->item_ < head_->item_) {
		x->next_ = head_;
		head_ = x;
	}

	else {
		Node* prev = head_;

		while (prev != tail_) {
			if (prev->next_->item_ > x->item_) {
				break;
			}
			prev = prev->next_;
		}

		if (prev == tail_) {
			x->next_ = nullptr;
			prev->next_ = x;
			tail_ = x;
		}
		else {
			x->next_ = prev->next_;
			prev->next_ = x;
		}
	}
}

void DictionaryList::insert(int item) {
	Node* newNode = new Node(item);
	this->insert(newNode);
}

void DictionaryList::remove(Node* x) {
	if (isEmpty()) return;
	Node* prev = head_;
	if (prev == x) {
		head_ = prev->next_;
		prev = prev->next_;
	}
	while (prev->next_) {
		if (prev->next_ == x) {
			if (prev->next_->next_) {
				prev->next_ = prev->next_->next_;
			}
			else {
				prev->next_ = nullptr;
			}
		}
		if (prev->next_) {
			prev = prev->next_;
		}
	}
	tail_ = prev;
}

void DictionaryList::remove(int item) {
	if (isEmpty()) return;
	Node* current = head_;
	if (head_->item_ == item) {
		head_ = head_->next_;
		return;
	}

	while (current->next_) {
		if (current->next_->item_ == item) {
			if (current->next_->next_) {
				current->next_ = current->next_->next_;
			}
			else {
				current->next_ = nullptr;
			}
		}
		if (current->next_) {
			current = current->next_;
		}
	}
	tail_ = current;
}

DictionaryList::Node* DictionaryList::searchPtr(int item) {
	if (isEmpty()) return nullptr;

	Node* current = head_;

	while (current) {
		if (current->item_ == item) {
			return current;
		}
		current = current->next_;
	}
	return nullptr;
}

bool DictionaryList::search(int item) {
	return this->searchPtr(item) ? true : false;
}

void DictionaryList::merge(DictionaryList* subList) {
	Node* xNode = subList->head();

	if (this->isEmpty()) {
		head_ = xNode;
		tail_ = xNode;
	}

	while (xNode) {
		Node* next = xNode->next_;
		
		if (xNode == subList->head_) {
			if (subList->head_->next_) { subList->head_ = subList->head_->next_; }
			else { subList->head_ = nullptr; }
		}
		this->insert(xNode);
		if (!subList->isEmpty()) {
			subList->remove(xNode);
		}
		if (next != nullptr) {
			xNode = next;
		}
		else { xNode = nullptr; }
	}
}

void DictionaryList::remove(DictionaryList* subList) {
	if (this->isEmpty()) return;
	
	Node* subHead = subList->head();

	while (subHead) {
		this->remove(subHead->item_);
		subHead = subHead->next_;
	}
}

DictionaryList* getIntersection(DictionaryList* leftList, DictionaryList* rightList) {
	DictionaryList* resList = new DictionaryList;
	
	DictionaryList::Node* subHead = leftList->head();

	while (subHead != nullptr) {
		if (rightList->search(subHead->item_)) {
			resList->insert(subHead->item_);
		}
		subHead = subHead->next_;
	}
	return resList;
}

//move operator
DictionaryList& DictionaryList::operator= (const DictionaryList* other) {

	this->head_ = other->head_;
	this->tail_ = other->tail_;
	return *this;
}

//copy operator
DictionaryList* DictionaryList::operator= (const DictionaryList& other) {
	Node* xNode = other.head_;

	while (xNode) {
		this->insert(xNode->item_);
		xNode = xNode->next_;
	}
	return this;
}