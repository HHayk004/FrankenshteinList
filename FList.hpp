#ifndef FLIST_HPP
#define FLIST_HPP

#include <utility>
#include <initializer_list>

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
FrankList<T>::FrankList(size_type size) : FrankList()
{
    for (size_type i = 0; i < size; ++i)
    {
        push_back(value_type());
    }
}

template <typename T>
FrankList<T>::FrankList(size_type size, const_reference init) : FrankList()
{
    for (size_type i = 0; i < size; ++i)
    {
        push_back(init);
    }
}

template <typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init) : FrankList()
{
    for (auto elem : init)
    {
        push_back(elem);
    }
}

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
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(int)
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
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(int)
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
FrankList<T>::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv) {}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv) : const_iterator(std::move(rhv)) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::iterator::operator*()
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator->()
{
    return &(this->ptr->val);
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
    return iterator(base_iterator(head));
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end()
{
    return iterator(base_iterator(nullptr));
}

// Const Reverse Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv) {}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv))
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
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(int)
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
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(int)
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
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv) {}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(std::move(rhv)) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::reverse_iterator::operator*()
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::reverse_iterator::operator->()
{
    return &(this->ptr->val);
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
    return reverse_iterator(base_iterator(tail));
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend()
{
    return reverse_iterator(base_iterator(nullptr));
}

// Const asc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) : base_iterator(rhv) {}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv))
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
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(int)
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
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(int)
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
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv) : const_asc_iterator(rhv) {}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv) : const_asc_iterator(std::move(rhv)) {
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(const base_iterator& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
    }

    return *this;
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(FrankList<T>::base_iterator&& rhv)
{
    if(this != &rhv)
    {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }

    return *this;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::asc_iterator::operator*()
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::asc_iterator::operator->()
{
    return &(this->ptr->val);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin()
{
    return asc_iterator(base_iterator(ahead));
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend()
{
    return asc_iterator(base_iterator(nullptr));
}

// Const desc Iterator
//
//
//
//
//

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) : base_iterator(rhv) {}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) : base_iterator(std::move(rhv))
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
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(int)
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
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(int)
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
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv) : const_desc_iterator(rhv) {}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv) : const_desc_iterator(std::move(rhv)) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
{
    return this->ptr->val;
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
{
    return &(this->ptr->val);
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
    return desc_iterator(base_iterator(atail));
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend()
{
    return desc_iterator(base_iterator(nullptr));
}

// Main functionality
//
//
//
//
//

template <typename T>
FrankList<T>::size_type FrankList<T>::size() const
{
    size_type size = 0;

    Node* tmp_head = head;
    while (tmp_head)
    {
        ++size;
        tmp_head = tmp_head->next;
    }
    
    return size;
}

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
        put_in_sorted_order(tail->next);
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
        put_in_sorted_order(head->prev);
        head = head->prev;
    }
}

template <typename T>
void FrankList<T>::pop_back()
{
    if (head == nullptr)
    {
        std::cerr << "Error in pop_back:\n";
        exit(-1);
    }

    Node* del_node = tail;

    if (del_node == head)
    {
        head = nullptr;
        tail = nullptr;
        ahead = nullptr;
        atail = nullptr;
    }

    else
    {
        tail = tail->prev;
        tail->next = nullptr;

        if (del_node == ahead)
        {
            ahead = ahead->asc;
        }

        else if (del_node == atail)
        {
            atail = atail->desc;
        }
    }

    if (del_node->desc)
    {
        del_node->desc->asc = del_node->asc;
    }

    if (del_node->asc)
    {
        del_node->asc->desc = del_node->desc;
    }

    delete del_node;
}

template <typename T>
void FrankList<T>::pop_front()
{
    if (head == nullptr)
    {
        std::cerr << "Error in pop_back:\n";
        exit(-1);
    }

    Node* del_node = head;

    if (del_node == tail)
    {
        head = nullptr;
        tail = nullptr;
        ahead = nullptr;
        atail = nullptr;
    }

    else
    {
        head = head->next;
        head->prev = nullptr;

        if (del_node == ahead)
        {
            ahead = ahead->asc;
        }

        else if (del_node == atail)
        {
            atail = atail->desc;
        }
    }

    if (del_node->desc)
    {
        del_node->desc->asc = del_node->asc;
    }

    if (del_node->asc)
    {
        del_node->asc->desc = del_node->desc;
    }

    delete del_node;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter pos)
{
    if (pos.ptr == head)
    {
        ++pos;
        pop_front();
        return pos;
    }

    else if (pos.ptr == tail)
    {
        ++pos;
        pop_back();
    }

    else
    {
        Node* del_node = pos.ptr;
        
        del_node->next->prev = del_node->prev;
        del_node->prev->next = del_node->next;
    
        if (del_node->asc)
        {
            del_node->asc->desc = del_node->desc;
        }

        if (del_node->desc)
        {
            del_node->desc->asc = del_node->asc;
        }

        ++pos;
        delete del_node;
    }

    return pos;
}
template <typename T>
template <typename iter>
iter FrankList<T>::insert_def(iter pos, const_reference val)
{
    if (pos.ptr == head)
    {
        push_front(val);
    }

    else if (pos.ptr == tail)
    {
        push_back(val);
    }

    else
    {
        Node* next_node = pos.ptr;
        Node* prev_node = next_node->prev;

        Node* new_node = new Node(val);

        prev_node->next = new_node;

        new_node->next = next_node;
        new_node->prev = prev_node;

        next_node->prev = new_node;

        put_in_sorted_order(new_node);
    }

    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev(iter pos, const_reference val)
{
    insert_def(pos, val);
    ++pos;

    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter f, iter l)
{
    while (f != l)
    {
        iter tmp_f = f;
        ++f;
        erase(tmp_f);
    }

    return l;
}

template <typename T>
void FrankList<T>::reverse()
{
    std::swap(head, tail);

    Node* tmp_head = head;

    while (tmp_head)
    {
        std::swap(tmp_head->next, tmp_head->prev);
        tmp_head = tmp_head->next;
    }
}

template <typename T>
void FrankList<T>::sort(bool reversed)
{
    head = ahead;
    tail = atail;

    Node* tmp_head = head;

    while (tmp_head)
    {
        tmp_head->next = tmp_head->asc;
        tmp_head->prev = tmp_head->desc;

        tmp_head = tmp_head->next;
    }

    if (reversed)
    {
        reverse();
    }
}

template <typename T>
void FrankList<T>::put_in_sorted_order(Node* node)
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