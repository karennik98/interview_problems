#pragma once
#include <assert.h>
#include <iostream>

struct list_node
{
	int data;
	list_node* next = nullptr;
	list_node(int data)
		: data(data)
	{
	}
};

void insert(list_node** head, int data)
{
	list_node* new_node = new list_node(data);
	new_node->next = *head;
	*head = new_node;
}

void show_list(list_node* head)
{
	assert(head != nullptr);

	list_node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->next != nullptr)
			std::cout << tmp->data << " ->" << std::ends;
		else
			std::cout << tmp->data;
		tmp = tmp->next;
	}
	std::cout << std::endl;
}