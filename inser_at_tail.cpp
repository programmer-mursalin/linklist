#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(node *&head, int v)
{
    node *nd = new node(v);
    if (head == NULL)
    {
        head = nd;
    }
    else
    {
        node *temp = head;
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nd;
    }
}
void print_at_link(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}
void insert_at_any_position(node *head, int pos, int val)
{
    node *nde = new node(val);
    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "invalid index" << endl;
            return;
        }
    }
    nde->next = temp->next;
    temp->next = nde;
}
void insert_at_head(node *head, int val)
{
    if (head == NULL)
    {
        cout << "head is not available" << endl;
        return;
    }
    node *nodi = new node(val);
    node *temp = head;
    nodi->next = head;
    head = nodi;
}
void delete_at_node(node *head, int pos)
{
    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "invalid index" << endl;
            return;
        }
    }
    if (temp->next == NULL)
    {
        cout << "invalid index" << endl;
        return;
    }
    node *delete_node = temp->next;
    temp->next = temp->next->next;
    delete delete_node;
}
void delete_at_head(node *&head)
{
    if (head == NULL)
    {
        cout << "head is not available" << endl;
        return;
    }
    node *delete_node = head;
    head = head->next;
    delete delete_node;
}

int main()
{
    node *head = NULL;
    while (true)
    {
        {
            /* code */
        }

        cout << "option1:insert at tail" << endl;
        cout << "option2:print at tail;" << endl;
        cout << "option3:insert at any position" << endl;
        cout << "option:4  insert head" << endl;
        cout << "option:5  delete" << endl;
        cout << "option:6  delete  at head" << endl;
        cout << "option:7  terminate" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {
            print_at_link(head);
        }
        else if (op == 3)
        {
            int q;
            cin >> q;
            while (q--)
            {
                int pos;
                cin >> pos;
                int val;
                cin >> val;
                if (pos == 0)
                {
                    insert_at_head(head, val);
                }
                else
                {
                    insert_at_any_position(head, pos, val);
                }
            }
        }
        else if (op == 4)
        {
            int val;
            cin >> val;
            insert_at_head(head, val);
        }
        else if (op == 5)
        {
            int pos;
            cin >> pos;
            if (pos == 0)
            {
                delete_at_head(head);
            }
            else
            {
                delete_at_node(head, pos);
            }
        }
        else if (op == 6)
        {
            delete_at_head(head);
        }

        else if (op == 7)
        {
            break;
        }
    }

    return 0;
}