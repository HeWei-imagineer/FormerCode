// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include <stack>
#include<cstdio>
#include <iostream>
#include<cstring>
#include<string>

using namespace std;

int alist[12][9];//存表
char formula[6][20];//存产生式
char s[] = "i+i*i$";
int inter = 0;

stack<char> ss;//存活动记录



void action(int n,char c) {
	ss.push(c);
	ss.push(n);
	inter++;
	cout << "移进" << endl;

}
//根据状态数和输入符获取分析表中记录的数字
int getNum1(int n, char c) {
	int num;
	for (int i = 0; i < sizeof(s); i++) {
		if (s[i] == c) {
			num = i;
		}
		break;
	}
	return alist[n][num];
}
//获取输入符对应下标
int getNum2(char c) {
	int num;
	for (int i = 0; i < sizeof(s); i++) {
		if (s[i] == c) {
			num = i;
		}
		break;
	}
	return num;
}
void reduce(int n,char c) {
	ss.pop();
	int i = 1;
	char c1;
	while (formula[n][i]) {
		c1 = ss.top();
		if (formula[n][i] == c1) {
			i++;
		}
		ss.pop();
	}
	i = ss.top();
	int num;
	num = getNum1(i,formula[n][0]);
	ss.push(formula[n][0]);
	ss.push(num);
	cout << "归约" << formula[n][0] << "->";
	i = 1;
	while (formula[n][i]) {
		cout << formula[n][i];
	}

}




int main()
{
	memset(alist, 0, sizeof(alist));
	ss.push(0);

	formula[0][0] = 'E'; formula[0][1] = 'E'; formula[0][2] = '+'; formula[0][3] = 'T';
	formula[1][0] = 'E'; formula[1][1] = 'T';
	formula[2][0] = 'T'; formula[2][1] = 'T'; formula[2][2] = '*'; formula[2][3] = 'F';
	formula[3][0] = 'T'; formula[3][1] = 'F';
	formula[4][0] = 'F'; formula[4][1] = '('; formula[4][2] = 'E'; formula[4][3] = ')';
	formula[5][0] = 'F'; formula[5][1] = 'i';



	alist[0][0] = 15; alist[0][3] = 14; alist[0][0] = 15; alist[0][6] = 31; alist[0][7] = 32; alist[0][8] = 33;
	alist[1][1] = 16; alist[1][5] = -1;
	alist[2][1] = 22; alist[2][2] = 27; alist[2][4] = 22; alist[2][5] = 22;
	alist[3][1] = 22; alist[3][2] = 27; alist[3][4] = 22; alist[3][5] = 22;
	alist[4][0] = 15; alist[4][3] = 14; alist[0][6] = 38; alist[0][7] = 32; alist[0][8] = 33;
	alist[5][1] = 26; alist[5][2] = 26; alist[5][4] = 26; alist[5][5] = 26;
	alist[6][0] = 15; alist[6][3] = 14;
	alist[7][0] = 15; alist[7][3] = 14;
	alist[8][1] = 16; alist[8][4] = 111;
	alist[1][1] = 16; alist[1][5] = -1;

	char c = s[inter];
	cout<<c<<endl;
	int num1, num2;
	char s1[10];
	int length;
	while(s[inter]!=0) {
		memset(s1, 0, sizeof(s1));
		num2 = ss.top();
		num1 = getNum2(c);
		num1 = alist[num2][num1];
		itoa(num1, s1, 10);
		cout<<s1[0]<<endl;
		length = 1;
		num2 = 0;
		while (s1[length]!=0)
		{
		    cout<<s1[length]<<endl;
			num2 = (num2 * 10) + s1[length];
			cout<<num2<<endl;
			length++;
		}

		if (s1[0] == 0) {
			cout << "wrong";
		}
        else if (s1[0] < 2) {
			action(num2, c);
		}
		else if (s1[0] < 3) {
			reduce(num2, c);
		}
	}
	return 0;
}


