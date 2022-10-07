#include<iostream>
#include"DoubleLinkedList.h"

template <typename Object>
typename List<Object>::iterator find(List<Object>& _list, const Object& _val)
{
  typename List<Object>::iterator beg = _list.begin();
  typename List<Object>::iterator en = _list.end();
  int i = 1;
  for(beg;*beg!=_val;beg++)//遍历所有链表节点直到找到对应的值
    {
      if(beg == en)//没有找到对应的值
	{
	  std::cout << "Not Found " <<_val << " in the List" <<std::endl;
	  i++;
	  return en;
	  break;
	}
      i++;
    }
  std::cout << "Found " << _val << "at position: " << i  <<std::endl;
    return beg;
}

int main()
{
  int k;
  List<int> list;
  List<int>::iterator iter;
  for(k=1;k<=5;k++)
    {
      list.push_back(k);
    }
  list.PrintList();
  iter = find(list,3);
  list.erase(iter);
  list.PrintList();
  iter = find(list,3);
  return 0;
}
