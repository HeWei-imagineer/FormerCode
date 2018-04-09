#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int main(){
	cout<<"Please put in the codes:"<<endl;
	string s;
	getline(cin,s);
	queue<char>tQueue;//��Ų�ͬ������
	//��ΪE,e,T,t,F,#,id,*,+,(,)�ĸ���char
	stack<char> mStack;
	mStack.push('#');//�Ȱ�#��ջ
	mStack.push('E');//����E
	//���S�������������ļ�����С������ϵı���
	int i;
	for(i = 0; s[i] != NULL;i++){//��ͷ��β
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
		return 0;//ֱ������س�ʱi=0,��������
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
				cout<<"E'->e'"<<endl;//e'��ʾ�մ�
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
			//Ϊidʱ
			if(tQueue.front() == 'i'){
				tQueue.pop();
				cout<<"���봮�����Ǻ�'id'���û���������һ��id."<<endl;
			}
			// * +
			else if((tQueue.front() == '+'||tQueue.front() == '*')&&mStack.top() == 'F'){//*+  **
				mStack.pop();
				cout<<"��ջ���������ս��'F'���û���������һ��id"<<endl;
			}
			else if(tQueue.front() == '*'&&mStack.top() == 'T'){
				cout<<"���봮�����Ǻ�'"<<tQueue.front()<<"',�û���������һ��id"<<endl;
				tQueue.pop();
			}
			else if(tQueue.front() == '+'&&mStack.top() == 'T'){
				mStack.pop();
				cout<<"��ջ���������ս��'F'���û���������һ��id"<<endl;
			}
			else if((tQueue.front() == '+'||tQueue.front() == '*')&&(mStack.top() == 'E'||mStack.top() == '#')){//��һ������*+
				cout<<"���봮�����Ǻ�'"<<tQueue.front()<<"',�û���������һ��id"<<endl;
				tQueue.pop();
			}
			else if(tQueue.front() == '*'&&mStack.top() == 'e'){
				tQueue.pop();
				cout<<"���봮�����Ǻ�'*',�û���������һ��id"<<endl;
			}
			//	)	(
			else if(tQueue.front() == '('){
				tQueue.pop();
				cout<<"���봮�����Ǻ�'(',�û���������һ��������"<<endl;
			}
			else if(mStack.top() == ')'){
				mStack.pop();
				cout<<"��ջ,�����ս��')',�û���������һ��������"<<endl;
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
		//�ɹ�ƥ��
		else {//if(){//id
			mStack.pop();
			tQueue.pop();
		}
		if(mStack.top() == '#'&& tQueue.front()=='#')break;
	}
	return 0;
}


