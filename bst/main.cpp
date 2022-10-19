#include <iostream>
#include <ctime>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;
/**
  * @brief 数组 _arr 排序
  *
  * Comparable 比较大小的类型
  * _arr 所引用于排序的数组
  * _mode 是排序的模式分为：1 要先打乱; 2 直接排序
  */
template <typename Comparable>
void BSTSorting(vector<Comparable> &_arr, int _mode = 0)
{
  clock_t start,end;
  double time =0;
  start = clock();
  if (_mode == 1)
    random_shuffle(_arr.begin(),_arr.end()); //用于乱序
  else if (_arr.size() == 0)
    {
      std:: cout<< "Wrong input" <<std::endl;
    exit(0);
    }
  else if (_mode !=0)
    {
      std::cout<< "Wrong input, please enter 0 or 1" <<std::endl;
    exit(0);
    }
   BinarySearchTree<Comparable> tree;
    for (int i=0; i<_arr.size(); i++)
    {
        tree.insert(_arr[i]);   //生成树
    }
    /*
      std::cout << "原来的的数组: ";
    for (typename vector<Comparable>::iterator p_arr = _arr.begin(); p_arr != _arr.end(); p_arr++)
    {
        cout << *p_arr << " ";
    }
    std::cout << endl;*/
    tree.sortTree(_arr); //排序
    /*std::cout << "排序后的数组: ";
    for (typename vector<Comparable>::iterator p_arr = _arr.begin(); p_arr != _arr.end(); p_arr++)
    {
        cout << *p_arr << " ";
    }
    std::cout << endl;*/
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout<<"The sorting process spent: " << time << std::endl;//计算时间
    
}

int main( )
{
    int testsize;
    int size;
    int _mode;
    while (std::cin >> testsize)//几次测试
    {
        for (int i = 0;i < testsize;i++)
        {
	  std::cin >> size >> _mode;//tree中有多少个数（0-size）& 模式
           
            std::vector<int> _arr={};
            for(int i = 0; i< size; i++)//输入进数字
            {
                _arr.push_back(i);
            }
            BSTSorting(_arr,_mode);//排序
        }
        return 0;
    }
};
