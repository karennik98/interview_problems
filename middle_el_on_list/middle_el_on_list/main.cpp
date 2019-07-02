#include "list.h"

#include <iostream>

template<typename T>
list_node<T>* find_middle(list_node<T>* head)
{
	if (nullptr == head)
		return nullptr;

	list_node<T>* fast_ptr = head;
	list_node<T>* slow_ptr = head;
	while (fast_ptr != nullptr && fast_ptr->next != nullptr)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	return slow_ptr;
}


int main(int argc, char* argv[])
{
	list_node<int>* head = new list_node<int>(1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 1);
	insert(&head, 3);

	show_list(head);

	auto el = find_middle(head);

	std::cout << el->data << std::endl;

	system("pause");
	return 0;
}