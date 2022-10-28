#include <iostream>
#include <vector>
#include "AvlTree.h"
#include <algorithm>
#include <random>
#include <set>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main()
{
		AvlTree<int> avl;
		int j,i ;
		
		for (j=20;j<=1000;j+=100)// j 为每次排序的数字的总数
		{
		  double time = 0;
		  clock_t start = clock();
		  cout << "运行前的数字: "<< endl;
		  for ( i = j-1; i >= 0; i-- )
		    {
		      avl.insert(i);
		      cout << i <<" ";
		     }
		   cout << "运行后的数字: "<< endl;
		  int k1 = 20;
		  int k2 = 100;
		  avl.Printelement( k1, k2 );
		  clock_t end = clock();
		  time = (double)(end-start)/CLOCKS_PER_SEC;

		  cout <<""<<endl;
		  cout << "下限K1: " << k1;
		  cout << "  上限K2: " << k2;
		  cout << "  运行时间: " << time << endl; 
	        }

		return 0;
}
