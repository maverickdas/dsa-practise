#include <iostream>

class Node
{
    public:
        Node* next;
        int data;

        Node()
        {
            this->data = NULL;
            this->next = NULL;
        }

        Node(Node* next, int data)
        {
            this->data = data;
            this->next = next;
        }

        Node(int data)
        {
            this->data = data;
        }
};

Node* createList(int size) {
    Node* head = new Node(1);
    for(int i=1; i < size; i++) {
        head = new Node(head, head->data + 1);
    }

    return head;
}


void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << ", ";
        head = head->next;
    }
    std::cout << "\n";
}

Node* addSameSize(Node* head1, Node* head2, int* carry) {
    if (head1->next == NULL) {
        Node* result = new Node(0);
        result->data = head1->data + head2->data + *carry;

        while (result->data > 9) {
            Node* tmp = new Node(result->data / 10);
            tmp->next = result;

            result->data = result->data % 10;
            result = tmp;
        }

        return result;
    }

    int c = (head1->next->data + head2->next->data) /10;
    Node* rem = addSameSize(head1->next, head2->next, &c);
    head1 = head1->next;
    head2 = head2->next;

    return NULL;
}

int main()
{
    Node* head1 = createList(1);
    Node* head2 = createList(1);
    int carry = 123;
    printList(addSameSize(head1, head2, &carry));
}
