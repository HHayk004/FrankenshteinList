#ifndef FLIST_HPP
#define FLIST_HPP

#include <utility>

namespace hayk {

//Constructor, Destructor
//
//
//
//
//

template <typename T>
FrankList<T>::FrankList() : head(nullptr), tail(nullptr), ahead(nullptr), atail(nullptr) {}

template <typename T>
FrankList<T>::~FrankList()
{
    clear();
}

// Base Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr) : ptr(ptr) {}

template <typename T>
FrankList<T>::base_iterator::~base_iterator()
{
    this->ptr = nullptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const
{
    if (rhv.ptr)
    {
        return this->ptr->val == rhv.ptr->val;
    }

    return !(this->ptr);
}

template <typename T>
bool FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const
{
    if (rhv.ptr)
    {
        return this->ptr->val != rhv.ptr->val;
    }

    return this->ptr;
}

// Const Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv.ptr))
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(FrankList<T>::base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_iterator::operator*() const
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_iterator::operator->() const
{
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++()
{
    this->ptr = this->ptr->next;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(T)
{
    const_iterator tmp = *this;
    this->ptr = this->ptr->next;
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    this->ptr = this->ptr->prev;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(T)
{
    const_iterator tmp = *this;
    this->ptr = this->ptr->prev;
    return tmp;
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
    return const_iterator(base_iterator(head));
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const
{
    return const_iterator(base_iterator(nullptr));
}

// Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::iterator::iterator(Node* ptr) : const_iterator(ptr) {}

template <typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv) : const_iterator(std::move(rhv.ptr)) {
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin()
{
    return iterator(head);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end()
{
    return iterator(nullptr);
}

// Const Reverse Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv.ptr))
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(FrankList<T>::base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator*() const
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator->() const
{
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
{
    this->ptr = this->ptr->prev;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(T)
{
    const_reverse_iterator tmp = *this;
    this->ptr = this->ptr->prev;
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
{
    this->ptr = this->ptr->next;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(T)
{
    const_reverse_iterator tmp = *this;
    this->ptr = this->ptr->next;
    return tmp;
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
    return const_reverse_iterator(base_iterator(tail));
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
    return const_reverse_iterator(base_iterator(nullptr));
}

// Reverse Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr) : const_reverse_iterator(ptr) {}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(std::move(rhv.ptr)) {
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
{
    return reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend()
{
    return reverse_iterator(nullptr);
}

// Const asc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv.ptr))
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(FrankList<T>::base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
{
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{
    this->ptr = this->ptr->asc;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(T)
{
    const_asc_iterator tmp = *this;
    this->ptr = this->ptr->asc;
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
    this->ptr = this->ptr->desc;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(T)
{
    const_asc_iterator tmp = *this;
    this->ptr = this->ptr->desc;
    return tmp;
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
    return const_asc_iterator(base_iterator(ahead));
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
    return const_asc_iterator(base_iterator(nullptr));
}

// asc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(Node* ptr) : const_asc_iterator(ptr) {}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv) : const_asc_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv) : const_asc_iterator(std::move(rhv.ptr)) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin()
{
    return asc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend()
{
    return asc_iterator(nullptr);
}

// Const desc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) : base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv.ptr))
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(FrankList<T>::base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_desc_iterator::operator*() const
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_desc_iterator::operator->() const
{
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
{
    this->ptr = this->ptr->desc;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(T)
{
    const_desc_iterator tmp = *this;
    this->ptr = this->ptr->desc;
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
{
    this->ptr = this->ptr->asc;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(T)
{
    const_desc_iterator tmp = *this;
    this->ptr = this->ptr->asc;
    return tmp;
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
    return const_desc_iterator(base_iterator(atail));
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{
    return const_desc_iterator(base_iterator(nullptr));
}

// desc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* ptr) : const_desc_iterator(ptr) {}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv) : const_desc_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv) : const_desc_iterator(std::move(rhv.ptr)) {
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
{
    return desc_iterator(atail);
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend()
{
    return desc_iterator(nullptr);
}

// Main functionality
//
//
//
//
//

template <typename T>
void FrankList<T>::clear() noexcept
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

        head_tmp = next_tmp;
    }
}

template <typename T>
FrankList<T>::Node::Node() : val(0), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

template <typename T>
FrankList<T>::Node::Node(T val) : val(val), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

template <typename T>
void FrankList<T>::push_back(const_reference elem)
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
        tail->next->prev = tail;
        ascDescDefinition(tail->next);
        tail = tail->next;
    }
}

template <typename T>
void FrankList<T>::push_front(const_reference elem)
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
        head->prev = new Node (elem);
        head->prev->next = head;
        ascDescDefinition(head->prev);
        head = head->prev;
    }
}

template <typename T>
void FrankList<T>::ascDescDefinition(Node*& node)
{
    Node* prev_tmp = ahead;
    if (prev_tmp->val > node->val)
    {
        node->asc = ahead;
        ahead->desc = node;
        ahead = node;
        return;
    }

    while (prev_tmp->asc && prev_tmp->asc->val < node->val)
    {
        prev_tmp = prev_tmp->asc;
    }

    Node* next_tmp = prev_tmp->asc;

    if (next_tmp)
    {
        next_tmp->desc = node;
        node->asc = next_tmp;
    }

    else
    {
        atail = node;
    }

    prev_tmp->asc = node;
    node->desc = prev_tmp;
}

template <typename T>
void FrankList<T>::print(bool sorted, bool reversed) const
{
    if (sorted)
    {
        if (reversed)
        {
            for (auto it = cdbegin(); it != cdend(); ++it)
            {
                std::cout << *it << ' ';
            }
            std::cout << std::endl;
        }

        else
        {
            for (auto it = cabegin(); it != caend(); ++it)
            {
                std::cout << *it << ' ';
            }
            std::cout << std::endl;
        }
    }

    else
    {
        if (reversed)
        {
            for (auto it = crbegin(); it != crend(); ++it)
            {
                std::cout << *it << ' ';
            }
            std::cout << std::endl;
        }

        else
        {
            for (auto it = cbegin(); it != cend(); ++it)
            {
                std::cout << *it << ' ';
            } 
            std::cout << std::endl;
        }
    }
}

}

#endif