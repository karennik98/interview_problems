#pragma once

template<typename T>
struct list_node
{
	list_node<T>* next = nullptr;
	T data = T();

	list_node(T data) : data(data)
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
	list_node<T>* tmp = head;
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