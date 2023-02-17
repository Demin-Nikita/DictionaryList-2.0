#include <iostream>
#include "DictionaryList.h"

int main() {
	DictionaryList l;
    std::cout << "l: ";
    l.print();
    std::cout << "Is l empty: " << l.isEmpty() << '\n';

    l.insert(5);
    l.insert(13);
    l.insert(13);
    l.insert(25);
    std::cout << "l: ";
    l.print();

    std::cout << "5 in l: " << l.search(5) << std::endl;
    std::cout << "6 in l: " << l.search(6) << std::endl;

    l.remove(5);
    l.remove(13);
    std::cout << "Removing 5 and 13 from l" << std::endl;
    std::cout << "l: ";
    l.print();

    
    DictionaryList l1;
    l1.insert(5);
    l1.insert(4);
    l1.insert(7);

    std::cout << "l1: ";
    l1.print();

    std::cout << "l merge with l1" << std::endl;
    l.merge(&l1);
    
    std::cout << "l: ";
    l.print();

    std::cout << "l1: ";
    l1.print();

    std::cout << "Inserting 25 and 4 in l1" << std::endl;
    l1.insert(25);
    l1.insert(4);

    std::cout << "Removing l1 from l" << std::endl;
    l.remove(&l1);

    std::cout << "l: ";
    l.print();

    std::cout << "l1: ";
    l1.print();
    std::cout << "Inserting 4 in l and 7 in l1" << std::endl;
    l.insert(4);
    l1.insert(7);

    std::cout << "l: ";
    l.print();

    std::cout << "l1: ";
    l1.print();

    std::cout << "Recording the intersection of l and l1 in l3" << std::endl;
    DictionaryList* l3;
    l3 = getIntersection(&l, &l1);
    std::cout << "l3: ";
    l3->print();

    return 0;
}