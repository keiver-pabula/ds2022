#include<iostream>
#include<cmath>
#include <stack>
#include <vector>
#include <string>
using namespace std;

vector<string> postfix;	//后缀表达式向量
stack<char> operaStack;	//符号栈
stack<double> numStack;	 //数字栈
string stdInfix; //输入表达式并换为字符串
double result; //最终结果


int priority(char c) //判断运算符号优先级
{
  if (c == '+' || c == '-') 
    {
      return 1;
    }
  if (c == '*' || c == '/') 
    {
      return 2;
    }
  if (c == '^') 
    {
      return 3;
    }
  return 0;
}

void transform(string infix) //中缀表达式转化为后缀表达式
{
  stdInfix = infix;
  for (int i = 0; i < stdInfix.size(); i++) 
    {
      //判断是否有错误的表达式
      if (stdInfix[0] == '*' || stdInfix[0] == '/' || stdInfix[0] == '^' || stdInfix[0] == '.')
	{
	  cout << "错误：输入的表达式错误，符号位置不正确" << endl;
	  abort();
	}
      if (stdInfix[i] == '-' || stdInfix[i] == '+') 
	{		
          //-x则在字符串中转换为为0-x，+x转化为0+x
	  //分为在括号后面的或者是在表达式开头，其余的都不用管因为是正常的数字
	  if (i == 0) 
	    {
	      stdInfix.insert(0, 1, '0');
	    }
	  else if (stdInfix[i - 1] == '(') 
	    {
	      stdInfix.insert(i, 1, '0');
	    }
	}
    }
  
  //后缀表达式  
     string a;
     for (int i = 0; i < stdInfix.size(); i++)
	{
	  a = "";
          switch (stdInfix[i])
	{
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
	    //以下五种操作都会执行
	    //如果栈为空或者栈顶=(则直接入栈
	    if (operaStack.empty() || operaStack.top() == '(')
	      operaStack.push(stdInfix[i]);
	    else
	      {
	    //如果栈不为空且栈顶元素优先级大于等于该运算符，则栈顶元素放入表达式向量，并删除栈顶元素；然后将该元素放入栈中
	    while (!operaStack.empty() && (priority(operaStack.top()) >= priority(stdInfix[i])))
	      {
		a += operaStack.top();
		postfix.push_back(a);  //后缀表达式向量末尾插入栈顶符号
		operaStack.pop();
		a = "";
	      }
	    operaStack.push(stdInfix[i]);
	      }
	    break;
	//当运算符为（时
	case '(':
	  if (!operaStack.empty() && operaStack.top() == '(')		//如果栈顶为'('，报错并退出
	    {
	      cout << "错误：括号不匹配" << endl;
	      abort();
	    }
	  operaStack.push(stdInfix[i]);
	  break;
	//当运算符为）时
	case ')':
	//一直将栈顶元素插入到表达式后方，直到栈顶为（
	  while (!operaStack.empty() && operaStack.top() != '(') 
	    {
	      a += operaStack.top();
	      postfix.push_back(a);
	      operaStack.pop();
	      a = "";
	    }
	  //如果为空就是括号不匹配
	  if (operaStack.empty()) 
	    {
	      cout << "错误：括号不匹配" << endl;
	      abort();
	    }
	  if (operaStack.top() == '(') 
	    {
	      operaStack.pop(); //将左括号出栈丢弃
	    }
	  break;
	  
	  //运算数的处理
	default:
	  if ((stdInfix[i] >= '0' && stdInfix[i] <= '9')) 
	    {
	      a += stdInfix[i];
	      //浮点数处理
	      while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.')) 
		{		
		  a += stdInfix[i + 1];			
		  //连续的数字则追加
		  i++;
		 }
	      if (a[a.length() - 1] == '.') 
		{
		  a += '0';					   
		  //将x.写成x.0
	  	 }
	      //放入后缀表达式的末尾
	      postfix.push_back(a);
	    }
	  break;
	}
	}
     // 把栈中所剩的运算符放入后缀表达式末尾    
     while (!operaStack.empty())	
       {
	 a = "";
	 a+= operaStack.top();
	 postfix.push_back(a);
	 operaStack.pop();
       }
}

//将符号和数字配在一起，将栈顶的两个数取出num1 num2，并在栈中删除
void op(double &num1, double &num2, stack<double> &numStack)
{
  if (!numStack.empty()) 
    {
      num2 = numStack.top();
      numStack.pop();
      num1 = numStack.top();
      numStack.pop();
    }
}

double Caculator(string infix)//计算后缀表达式 
{
  transform(infix);
  string a="";
  double number = 0;
  double num1 = 0;
  double num2 =0;
  

  for (int i = 0; i < postfix.size(); i++) 
    {
      a = postfix[i];
      if (a[0] >= '0' && a[0] <= '9') 
	{
	  number = atof(a.c_str());//将string型转变为浮点数型变量
	  numStack.push(number);//将数放入数字栈中
	}
      else if (postfix[i] == "+") 
	{
	  op(num1,num2,numStack);
	  numStack.push(num1 + num2);
	}
      else if (postfix[i] == "-") 
	{
	  op(num1,num2,numStack);
	  numStack.push(num1 - num2);
	}
      else if (postfix[i] == "*") 
	{
	  op(num1,num2,numStack);
	  numStack.push(num1* num2);
	}
      else if (postfix[i] == "/") 
	{
	  op(num1,num2,numStack);
	  if (num2 == 0) 
	    {
	      cout << "错误：除数为0" << endl;
	      abort();
	    }
	  numStack.push(num1 / num2);
	}
      else if (postfix[i] == "^") 
	{
	  {
	    num2 = numStack.top();
	  numStack.pop();
	  if (numStack.empty())
	    {
	      numStack.push(1);//第二个数没有则放入1到栈
	    }
	  num1 = numStack.top();
	  numStack.pop();
	  if(num1 == 0 && num2<=0)
	    {
	      cout << "错误：除数为0" << endl;
	      abort();
	    }
	  numStack.push(pow(num1, num2));
	  }
	}
    }
  result = numStack.top();
  return result;
}
