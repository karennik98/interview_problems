#include <iostream>
#include <memory>
#include <assert.h>
#include <forward_list>

template <typename T>
struct list_node
{
	T data;
	list_node* next = nullptr;

	list_node(T data)
		: data(data)
	{
	}
};

template<typename T>
void insert(list_node<T>** head, T data)
{
	list_node<T>* new_node = new list_node<T>(data);
	new_node->next = *head;
	*head = new_node;
}

template<typename T>
void show_list(list_node<T>* head)
{
	assert(nullptr != head);
	list_node<T>* tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<typename T>
void reverse_list(list_node<T>* head)
{
	list_node<T>* prev = nullptr;
	list_node<T>* next = nullptr;
	list_node<T>* curr = head;
	while (next != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = curr;
}

int main()
{
	list_node<int>* head = new list_node<int>(1);
	insert(&head, 2);
	insert(&head, 3);
	show_list(head);
	reverse_list(head);
	show_list(head);
	system("pause");
	return 0;
}