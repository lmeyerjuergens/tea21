#include "linkedlist.h"

LinkedList::~LinkedList()
{
    for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext)
    {
        auto elem = tmp;
        delete elem;
    }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
    bool ret = false;
    if (nullptr == node)
    {
        return ret;
    }

    if (m_tail == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        m_tail->pNext = node;
        m_tail = node;
    }

    ret = true;
    return ret;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
    bool ret = false;
    if (nullptr == node)
    {
        return ret;
    }

    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->pNext = m_head;
        m_head = node;
    }

    ret = true;
    return ret;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
    bool ret = false;
    if ((nullptr == loc) || (nullptr == node))
    {
        return ret;
    }
    node->pNext = loc->pNext;
    loc->pNext = node;

    if (loc == m_tail)
    {
        m_tail = node;
    }

    ret = true;
    return ret;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
    bool ret = false;
    if ((nullptr == loc) || (nullptr == node))
    {
        return ret;
    }
    if (loc == m_head)
    {
        node->pNext = m_head;
        m_head = node;
    }
    else
    {
        auto tmp = m_head;
        while (tmp->pNext != loc)
        {
            tmp = tmp->pNext;
        }

        tmp->pNext = node;
        node->pNext = loc;
    }

    ret = true;
    return ret;
}

bool LinkedList::remove(LinkedListNode *node)
{
    bool ret = false;
    if (node == nullptr)
    {
        return ret;
    }

    if (node == m_head)
    {
        m_head = node->pNext;
        if (m_head == nullptr)
        {
            m_tail = nullptr;
        }
    }
    else
    {
        auto tmp = m_head;
        while (tmp->pNext != node)
        {
            tmp = tmp->pNext;
        }
        tmp->pNext = node->pNext;

        if (node == m_tail)
        {
            m_tail = tmp;
        }
    }

    delete node;
    ret = true;
    return ret;
}
