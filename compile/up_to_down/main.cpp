#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int main(){
	cout<<"Please put in the codes:"<<endl;
	string s;
	getline(cin,s);
	queue<char>tQueue;//存放不同的输入
	//分为E,e,T,t,F,#,id,*,+,(,)的各种char
	stack<char> mStack;
	mStack.push('#');//先把#入栈
	mStack.push('E');//再是E
	//检查S，将符合条件的加入队列。不符合的报错
	int i;
	for(i = 0; s[i] != NULL;i++){//从头到尾
		while(s[i] == ' '||s[i] == '\t'||s[i] == '\n')i++;//

		if(s[i] =='#'){
			tQueue.push('#');
			i++;
			break;
		}
		else if(s[i] == '+'||s[i] =='*'||s[i] =='('||s[i] ==')')
			tQueue.push(s[i]);
		else if(s[i] == 'i'&&s[i+1] == 'd'){
			tQueue.push('i');
			i++;
		}
		else {
			cout<<"error!"<<endl;
			return 0;
		}
	}
	if(i<1){
		cout<<"No input!!!"<<endl;
		return 0;//直接输入回车时i=0,就跳出。
	}
	if(s[i - 1] != '#'){
		cout<<"Forgot to put in the '#'"<<endl;
		tQueue.push('#');
	}
	//int mark[8]={0};
	while(true){
		if(mStack.top() == 'E' && (tQueue.front() == 'i'||tQueue.front() == '(')){
			//if(mark[0] == 0)
				cout<<"E->TE'"<<endl;
			//mark[0] = 1;
			mStack.pop();
			mStack.push('e');
			mStack.push('T');
		}
		else if(mStack.top() == 'e'&&tQueue.front() == '+'){//||tQueue.front() == 28)
			//if(mark[1] == 0)
				cout<<"E'->+TE'"<<endl;
			//mark[1] = 1;
			mStack.pop();
			mStack.push('e');
			mStack.push('T');
			mStack.push('+');
		}
		else if(mStack.top() == 'e'&&(tQueue.front() == '#'||tQueue.front() == ')')){
			//if(mark[2] == 0)
				cout<<"E'->e'"<<endl;//e'表示空串
//			mark[2] = 1;
			mStack.pop();
		}
		else if(mStack.top() == 'T'&&(tQueue.front() == 'i'||tQueue.front() == '(')){
			//if(mark[3] == 0)
				cout<<"T->FT'"<<endl;
		//	mark[3] = 1;
			mStack.pop();
			mStack.push('t');
			mStack.push('F');
		}
		else if(mStack.top() == 't'&&tQueue.front() == '*'){
			//if(mark[4] == 0)
				cout<<"T'->*FT'"<<endl;
			//mark[4] = 1;
			mStack.pop();
			mStack.push('t');
			mStack.push('F');
			mStack.push('*');
		}
		else if(mStack.top() == 't'&&(tQueue.front() == '#'||tQueue.front() == ')'||tQueue.front() == '+')){
		//	if(mark[5] == 0)
				cout<<"T'->e'"<<endl;
		//	mark[5] = 1;
			mStack.pop();
		}
		else if(mStack.top() == 'F' && tQueue.front() == 'i'){
			//if(mark[6] == 0)
				cout<<"F->id"<<endl;
			//mark[6] = 1;
			mStack.pop();
			tQueue.pop();
		}
		else if(mStack.top() == 'F'&&tQueue.front() == '('){
			//if(mark[7] == 0)
				cout<<"F->(E)"<<endl;
			//mark[7] =1;
			mStack.pop();
			mStack.push(')');
			mStack.push('E');
			mStack.push('(');
		}
		else if(mStack.top() != tQueue.front()){
			//为id时
			if(tQueue.front() == 'i'){
				tQueue.pop();
				cout<<"输入串跳过记号'id'，用户多输入了一个id."<<endl;
			}
			// * +
			else if((tQueue.front() == '+'||tQueue.front() == '*')&&mStack.top() == 'F'){//*+  **
				mStack.pop();
				cout<<"弹栈，弹出非终结符'F'，用户少输入了一个id"<<endl;
			}
			else if(tQueue.front() == '*'&&mStack.top() == 'T'){
				cout<<"输入串跳过记号'"<<tQueue.front()<<"',用户少输入了一个id"<<endl;
				tQueue.pop();
			}
			else if(tQueue.front() == '+'&&mStack.top() == 'T'){
				mStack.pop();
				cout<<"弹栈，弹出非终结符'F'，用户少输入了一个id"<<endl;
			}
			else if((tQueue.front() == '+'||tQueue.front() == '*')&&(mStack.top() == 'E'||mStack.top() == '#')){//第一个就是*+
				cout<<"输入串跳过记号'"<<tQueue.front()<<"',用户少输入了一个id"<<endl;
				tQueue.pop();
			}
			else if(tQueue.front() == '*'&&mStack.top() == 'e'){
				tQueue.pop();
				cout<<"输入串跳过记号'*',用户少输入了一个id"<<endl;
			}
			//	)	(
			else if(tQueue.front() == '('){
				tQueue.pop();
				cout<<"输入串跳过记号'(',用户多输入了一个右括号"<<endl;
			}
			else if(mStack.top() == ')'){
				mStack.pop();
				cout<<"弹栈,弹出终结符')',用户少输入了一个右括号"<<endl;
			}
			else if(mStack.top() == '#'&&tQueue.front() != '#'){
				cout<<"Wrong'"<<tQueue.front()<<"'The Stack is already empty."<<endl;
				tQueue.pop();
			}
			else if(tQueue.front() == '#'&&mStack.top() != '#'){
				cout<<"Wrong'"<<mStack.top()<<"'The Queue is already empty."<<endl;
				mStack.pop();
			}
		}
		//成功匹配
		else {//if(){//id
			mStack.pop();
			tQueue.pop();
		}
		if(mStack.top() == '#'&& tQueue.front()=='#')break;
	}
	return 0;
}


