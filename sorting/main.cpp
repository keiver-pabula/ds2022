#include <iostream>
#include <functional>
#include "sorting.h"
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;
int main(int argc, char* argv[])
{
  vector<int> v; //v为存放数据的数组
  int n;//数组n
  int i,j,k;//i,j,k为for内的元素
  clock_t begin;//时间
  clock_t end;//时间
  double p,sum;//p为从第几个数开始无序，sum为时间的总数

  /**
 * @brief 测试前1%输入有序的Heapsort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.01;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   heapsort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前1%有序Heapsort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }


  /**
 * @brief 测试前1%输入有序的Quicksort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.01;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   quicksort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前1%有序Quicksort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }

/**
 * @brief 测试前10%输入有序的Heapsort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.1;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   heapsort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前10%有序Heapsort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }


  /**
 * @brief 测试前10%输入有序的Quicksort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.1;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   quicksort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前10%有序Quicksort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }

  /**
 * @brief 测试前90%输入有序的Heapsort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.9;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   heapsort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前90%有序Heapsort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }


  /**
 * @brief 测试前90%输入有序的Quicksort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.9;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   quicksort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前90%有序Quicksort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }

  /**
 * @brief 测试前99%输入有序的Heapsort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.99;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   heapsort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前99%有序Heapsort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }


  /**
 * @brief 测试前99%输入有序的Quicksort排序效率
 *
 * i是为了多组数据测试，k是为了反复测试
 * n+=10000是为了每次数组的数据都不一样
 */
  n=10000;
  for(i=0;i<5;i++)
  {
   sum=0;
   p=n*0.99;
   for(k=0;k<10;k++)
   {
   for(j=1;j<=p+1;j++)
    v.push_back(j);
   for(j=n;j>=p+1;j--)
    v.push_back(j);
   begin=clock();
   quicksort(v);
   end=clock();
   sum+=double(end-begin)/CLOCKS_PER_SEC;
   v.clear();
   }
  cout<<" 对于n = "<<n<<"前99%有序Quicksort花费了 :"<<sum/k<<"s"<<endl;
  n+=10000;
  }
  
  return 0;
}
