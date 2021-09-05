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

void deepCopy(Node* a, Node* b) {
    a->data = b->data;
    a->next = b->next;
}

void printList(Node* head) {
    std::cout << "List: ";
    while (head != NULL) {
        std::cout << head->data << ", ";
        head = head->next;
    }
    std::cout << "\n";
}

int listLen(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* reverseList(Node* head) {
    if (head->next == NULL) {
        return head;
    }
    Node* node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

void addEasy(Node* head1, Node* head2, int carry) {
    if (head2 != NULL) {
        head1->data = head1->data + head2->data + carry;
        carry = head1->data / 10;
        head1->data %= 10;

        if (head2->next != NULL) {
            addEasy(head1->next, head2->next, carry);
        }
    }

    if ((head2 == NULL || (head2 != NULL && head2->next == NULL)) && carry > 0) {
        if (head1->next == NULL) {
            head1->next = new Node(carry % 10);
            carry /= 10;
        } else {
            head1->data = head1->data + carry;
            carry = head1->data / 10;
            head1->data %= 10;
        }
        addEasy(head1->next, NULL, carry);
    }
}

Node* addSuperHard(Node* head1, Node* head2) {
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    bool swapping = listLen(head2) > listLen(head1);
    swapping? addEasy(head2, head1, 0) : addEasy(head1, head2, 0);
    if (swapping) {
        deepCopy(head1, head2);
    }

    return reverseList(head1);
}

int main()
{
    Node* n1 = createList(3); // [3, 2, 1]
    Node* n2 = createList(6); // [2, 1]

    // addHard(n2, n1);
    printList(n1);
    printList(n2);

    Node* n3 = addSuperHard(n1, n2);
    printList(n3);
}
