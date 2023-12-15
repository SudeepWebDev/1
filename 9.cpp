void SLL::insert_at_loc(int num, int position)
{
    Node *newNode = new Node();
    newNode->data = num;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev = head;
    for (int i = 1; i < position - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}