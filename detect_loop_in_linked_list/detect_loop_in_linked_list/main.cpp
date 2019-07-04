#include <iostream>

struct list_node
{
	int data_;
	list_node* next_;

	list_node(int data, list_node* next = nullptr)
		: data_(data)
		, next_(next)
	{
	}
};

void insert(list_node** head, int data)
{
	list_node* new_node = new list_node(data);
	new_node->next_ = *head;
	*head = new_node;
}

list_node* detect_loop(list_node* head)
{
	list_node* fast = head;
	list_node* slow = head;

	while (fast != nullptr || fast->next_ != nullptr)
	{
		if (fast == slow)
			return fast;
		fast = fast->next_->next_;
		slow = slow->next_;
	}
	return nullptr;
}

void show_list(list_node* head)
{
	list_node* tmp = head;
	list_node* loop = detect_loop(head);
	while (tmp != nullptr && tmp != loop->next_)
	{
		std::cout << tmp->data_ << " ";
		tmp = tmp->next_;
	}
	std::cout << std::endl;
}

int main()
{
	list_node* head  = new list_node(1);
	list_node* node1 = new list_node(2);
	list_node* node2 = new list_node(3);
	list_node* node3 = new list_node(4);
	list_node* node4 = new list_node(5);
	head->next_ = node1;
	node1->next_ = node2;
	node2->next_ = node3;
	node3->next_ = node4;
	node4->next_ = head;
	show_list(head);
	list_node* loop = detect_loop(head);
	if (loop)
		std::cout << loop->data_ << std::endl;

	system("pause");
	return 0;
}




