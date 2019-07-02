#include "list.h"

#include <iostream>

void remove_duplicate(list_node* head)
{
	assert(nullptr != head);

	/*list_node* first = head;
	list_node* second = head->next;*/
	list_node* tmp = head;
	while (tmp->next != nullptr)
	{
		if (tmp->data == tmp->next->data)
		{
			list_node* double_next = tmp->next->next;
			delete tmp->next;
			tmp->next = double_next;
			tmp = double_next;
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

int main()
{
	list_node* head = new list_node(1);
	insert(&head, 2);
	insert(&head, 2);
	insert(&head, 2);
	insert(&head, 3);
	show_list(head);
	remove_duplicate(head);
	show_list(head);
	system("pause");
}