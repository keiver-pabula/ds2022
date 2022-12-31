#include<iostream>
#include<cmath>
#include <stack>
#include <vector>
#include <string>
#include"calculator.h"
using namespace std;

int main()
{
	cout << "五则运算器" << endl;
	string infix;
	cout << "请输入中缀表达式:" << endl;
	getline(cin, infix);
	cout << infix << "=" << Caculator(infix) << endl;
	
	return 0;
}
