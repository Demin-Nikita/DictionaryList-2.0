#pragma once
class DictionaryList
{
private:
	struct Node {
		int item_;
		Node* next_;

		Node(int item, Node* next = nullptr) {
			item_ = item;
			next_ = next;
		}
	};

	Node* head_;
	Node* tail_;

	void insert(Node* x);
	void remove(Node* x);
	Node* head() const;
	Node* searchPtr(int item);

public:
	DictionaryList();
	DictionaryList(const DictionaryList& other);
	~DictionaryList();
	DictionaryList& operator= (const DictionaryList* other);
	DictionaryList* operator= (const DictionaryList& other);
	bool isEmpty();
	void print();
	void insert(int item);
	void remove(int item);
	bool search(int item);
	void merge(DictionaryList* subList);
	void remove(DictionaryList* subList);
	friend DictionaryList* getIntersection(DictionaryList* leftList, DictionaryList* rightList);
};