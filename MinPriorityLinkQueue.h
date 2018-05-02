#ifndef MIN_PRIORITY_LINK_QUEUE_H
#define MIN_PRIORITY_LINK_QUEUE_H

#include "LinkQueue.h"

// 最小优先链队列类
template <class ElemType>
class MinPriorityLinkQueue : public LinkQueue<ElemType>
{
  public:
    // 重载入队操作声明：
    int InQueue(const ElemType &e); // 重载入队操作
};

// 最小优先链队列类的实现部分
template <class ElemType>
int MinPriorityLinkQueue<ElemType>::InQueue(const ElemType &e)
{
    // 操作结果：插入元素e为新的队尾，返回SUCCESS
    Node<ElemType> *curPtr = LinkQueue<ElemType>::front->next; // 指向当前结点
    Node<ElemType> *curPrePtr = LinkQueue<ElemType>::front;    // 指向当前结点的前驱结点

    while (curPtr != nullptr && curPtr->data <= e)
    {
        // curPtr与curPrePtr都指向下一元素
        curPrePtr = curPtr;
        curPtr = curPtr->next;
    }

    Node<ElemType> *tmpPtr = new Node<ElemType>(e, curPtr); // 生成新结点
    curPrePtr->next = tmpPtr;                               // 将tmpPtr插入在curPrePtr与curPtr之间

    if (curPrePtr == LinkQueue<ElemType>::rear)
    {
        // 新结点插在rear的后面
        LinkQueue<ElemType>::rear = tmpPtr; // rear指向新队尾
    }
    return SUCCESS;
}

#endif // MIN_PRIORITY_LINK_QUEUE_H