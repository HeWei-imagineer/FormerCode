// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//




#include <iostream>

using namespace std;

char s[] = "i*(i+i)$";
int top = 0;
char lookahead = s[top];
int icount = 0;
void match(char c) {
	if (c != '#') {
		top++;
		lookahead = s[top];
	}
	cout << "match" << c << endl;
}

void E();

void F()
{
	if (lookahead == 'i') {
		match('i');
		cout << "F match i" << endl;
	}
	else if (lookahead == '(') {
		match('(');
		cout << "F match (" << endl;
		E();
	}
	else {
		cout << "(F)弹栈，弹出非终结符F,用户少输入了一个id" << endl;
	}

}

void T1()
{
	if (lookahead == '*') {
		match('*');
		cout << " t1 match *" << endl;
		F();
		T1();
	}
	else if (lookahead == 'i') {
		cout << top << "-------" << lookahead;
		cout << "(T1)输入串跳过记号id，用户多输入了一个id" << endl;
		F();
		T1();

	}


}
void T()
{
	if (lookahead == '(' || lookahead == 'i') {
		if (lookahead == '(') {
			//match('(');
			cout << "T match (" << endl;
		}
		else {
			//match('i');
			cout << "T match i" << endl;
		}

		F();
		T1();
	}
	else {
		cout << "(T)弹栈，弹出非终结符T，用户少输入了一个id" << endl;
	}

}
void E1()//为什么不加两个else匹配不成功
{
	if (lookahead == '+') {
		match('+');
		cout << "E1 match +" << endl;
		T(); E1();
	}
	else if (lookahead == ')') {
		match(')');
		cout << "E1 match )" << endl;
	}
	else if (lookahead == '$') {
		cout << "匹配成功" << endl;
		cout << lookahead << endl;
		return;
	}
	else if (lookahead == 'i') {
		cout << "输入串跳过记号id，用户多输入了一个id" << endl;
		E1();
	}

}

void E()
{

	if (lookahead == '(' || lookahead == 'i') {
		cout << "E match ( or i" << endl;
		T();
		E1();
	}
	else {
		cout << "(E)弹栈，弹出非终结符E，用户少输入了一个id" << endl;
	}

}
int main()
{
	E();
	cout << top;
	return 0;
}


