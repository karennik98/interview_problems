#include <iostream>
#include "list.h"
#include <list>

template<typename T>
size_t list_size(list_node<T>* head)
{
	size_t size = 1;
	list_node<T>* node = head;
	while (node->next != nullptr)
	{
		size++;
		node = node->next;
	}
	return size;
}

template<typename T>
list_node<T>* search_last_k_node(list_node<T>* head, size_t k)
{
	size_t i = 0;
	size_t size = list_size(head);
	list_node<T>* node = head;
	while (i != size - k)
	{
		node = node->next;
		i++;
	}

	return node;
}

int main()
{
	list_node<int>* head = new list_node<int>(1);
	list_node<int>* node1 = new list_node<int>(2);
	list_node<int>* node2 = new list_node<int>(3);
	list_node<int>* node3 = new list_node<int>(4);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = nullptr;

	std::cout << search_last_k_node(head, 2)->value << std::endl;

	system("pause");
	return 0;
}