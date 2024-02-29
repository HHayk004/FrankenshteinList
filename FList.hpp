#ifndef FLIST_HPP
#define FLIST_HPP

template <typename T>
FrankList::Node::Node() : val(0), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

template <typename T>
FrankList::Node::Node(T val) : val(val), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr) {}

#endif