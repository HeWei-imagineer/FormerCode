// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "(F)��ջ���������ս��F,�û���������һ��id" << endl;
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
		cout << "(T1)���봮�����Ǻ�id���û���������һ��id" << endl;
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
		cout << "(T)��ջ���������ս��T���û���������һ��id" << endl;
	}

}
void E1()//Ϊʲô��������elseƥ�䲻�ɹ�
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
		cout << "ƥ��ɹ�" << endl;
		cout << lookahead << endl;
		return;
	}
	else if (lookahead == 'i') {
		cout << "���봮�����Ǻ�id���û���������һ��id" << endl;
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
		cout << "(E)��ջ���������ս��E���û���������һ��id" << endl;
	}

}
int main()
{
	E();
	cout << top;
	return 0;
}


