#ifndef FLIST_HPP
#define FLIST_HPP

namespace hayk {

template <typename T>
FrankList::FrankList() : head(), tail(), ahead, atail {}

template <typename T>
FrankList::~FrankList()
{
    clear();
}

template <typename T>
void FrankList::clear() noexcept
{
    Node* head_tmp = head;
    while (head_tmp)
    {
        Node* next_tmp = head_tmp->next;
        
        head_tmp->next = nullptr;
        head_tmp->prev = nullptr;
        head_tmp->asc = nullptr;
        head_tmp->desc = nullptr;

        delete head_tmp;

        head_tmp = next->tmp;
    }
}

template <typename T>
FrankList::Node::Node() : val(0), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

template <typename T>
FrankList::Node::Node(T val) : val(val), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

template <typename T>
FrankList::push_back(const_reference elem)
{
    if (head == nullptr)
    {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    }

    else
    {
        tail->next = new Node (elem);
        ascDescDefinition(tail->next);
    }
}

template <typename T>
FrankList::ascDescDefinition(Node*& node)
{
    Node* prev_tmp = head;
    while (head_tmp->asc->val <= node->val)
    {
        if (node->val - prev_tmp->asc->val <= node->val - prev_tmp->next->val ||
            prev_tmp->next->val > node->val)
        {
            prev_tmp = prev_tmp->asc;
        }

        else
        {
            prev_tmp = prev_tmp->next;
        }
    }

    next_tmp = prev_tmp->next;

    prev_tmp->asc = node;
    next_tmp->desc = node;

    node->desc = prev_tmp;
    node->asc = next_tmp;
}

template <typename T>
void FrankList::print(bool sorted = false, bool reversed = false) const
{
    // add implementation;
}

}

#endif