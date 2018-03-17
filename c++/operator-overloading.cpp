//Ch4_7 �ַ���������������
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;   //����assert()
//�����ַ�����
class String
{
 public:
    String( const char *s = 0);     	   //ת�����캯��
    String( const String & );           //�������캯��
    ~String( );                  	  //��������
    int getLength( ) { iLength=strlen(sPtr);return iLength; };  //���ش���
		//���س��������
    const String &operator=( const String & );
    const String &operator+( const String & );
    bool operator!( ) const;
    bool operator==( const String & ) const;
    bool operator<( const String & ) const;
    char &operator[ ]( int );
    //���������صĹ�ϵ�����ʵ���������������
    bool operator!=( const String & right ) const{
 return !( *this == right ); }
    bool operator>( const String &right ) const{
 return right < *this;   }
    bool operator<=( const String &right ) const{
 return !( right < *this ); }
    bool operator>=( const String &right ) const{
        return !( *this < right ); }
	friend ostream &operator << ( ostream &, const String & );
private:
     char *sPtr;          	     //�ַ���ָ��
     int iLength;                //����
     void setString( const char *s); //�����ַ����Ĺ��ߺ���
};

//ת�����캯������char* ת��Ϊstring����
String::String( const char *s ) {
   if(s==NULL){
	      sPtr=NULL;
		  iLength = 0 ;
	   }
	   else{
	       iLength = strlen( s ) ;
		   sPtr = new char[iLength + 1 ];  //Ϊ�ַ��������ڴ�
		   assert( sPtr != 0 );        	//��������ڴ治�ɹ���ֹ����
		   strcpy( sPtr, s );
	   }
}
//���ƹ��캯�������
String::String( const String &cop ){
    if(cop.iLength  ==NULL) {
	       sPtr=NULL;
		   iLength = 0 ;
	   }
else
	  {
	      iLength = cop.iLength ;
	      sPtr = new char[iLength + 1 ];  //Ϊ�ַ��������ڴ�
		  assert( sPtr != 0 );        	//��������ڴ治�ɹ���ֹ����
		  strcpy( sPtr, cop.sPtr );    //��this->sPtr�����ַ���string2
	  }
}
String::~String( ){
    if(sPtr)
delete [ ] sPtr;       	//�ͷ��ַ����ڴ�
}
void String::setString( const char *s){
	   if(s==NULL) {
	       sPtr=NULL;
		   iLength = 0 ;
	   }
	   else{
	       iLength = strlen( s ) ;
		   sPtr = new char[iLength + 1 ];  //Ϊ�ַ��������ڴ�
		   assert( sPtr != 0 );        	//��������ڴ治�ɹ���ֹ����
		   strcpy( sPtr, s );    //��this->sPtr�����ַ���string2
}
}
//����=, ʵ���ַ�����ֵ
const String &String::operator=( const String &right ){
     if ( &right != this )	{ //�ж����Ҳ������Ƿ���ͬ
        delete [ ] sPtr;
        iLength = right.iLength;
        setString( right.sPtr );
    }
    else{    	//�������Ҹ�ֵ����ڴ�й©
    		cout << "Attempted assignment of a String to itself\n";
	    }
    return *this;
}
//����+=, ʵ���ַ�������
const String& String::operator+( const String &right ){
    String a;
    char *tempPtr = sPtr;         	//���������������ԭָ��
    iLength += right.iLength;     	//�½��ڴ�ռ�
    a.sPtr = new char[iLength + 1 ]; 	//�����µ��ַ���
    assert( sPtr != 0 );       	     //���������ڴ治�ɹ�
    strcpy( sPtr, tempPtr );   		//������������Ƹ����ַ���
    strcat( sPtr, right.sPtr );  	//���Ҳ��������ӵ����ַ���
    delete [ ] tempPtr;       		//�ͷ��������ԭָ��
    return a;
}
//����!,�ж϶����Ƿ�Ϊ���ַ���
bool String::operator!( ) const{
return iLength == 0; }
//���ع�ϵ�����
bool String::operator==( const String &right ) const{
return strcmp( sPtr, right.sPtr ) == 0; }
bool String::operator<( const String &right ) const{
return strcmp( sPtr, right.sPtr ) < 0; }
//�����±������
char &String::operator[ ]( int subscript ){
    assert( subscript >= 0 && subscript <iLength ); //�ж��±��Ƿ�Խ��
    return sPtr[ subscript ];  //�����÷�ʽ�����ַ���������ֵ
}
//�������������ȡ�����
ostream& operator << ( ostream &output, const String &s ){
    if( s.sPtr)
		   output << s.sPtr;
    return output;
}


class edit_string:public String
{
private:
    int dex;
    char *str;
    void set_string(char*s,int i=0)
    {
       if(s==NULL)
       {
	       str=NULL;
		   dex=i ;
	   }
	   else
       {
           str = new char[strlen(s) + 1 ];  //Ϊ�ַ��������ڴ�
           assert( str != 0 );        	//��������ڴ治�ɹ���ֹ����
           strcpy( str, s );    //��this->sPtr�����ַ���string2
       }
    }
public:
    edit_string(const char*s,int i=0);
    ~edit_string(){delete[]str;}
    edit_string& add(int i,const char* n);//����ַ���
    edit_string& rep(const char n,const char m);//�滻�ַ�
    edit_string& del(int i);//ɾ�������ַ���
    edit_string& fin(char *n);//�����Ӵ�λ��
};
edit_string:: edit_string(const char*s,int i)
{
    dex=i;
    if(s)
    {
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }
    else
    {
        str=new char[5];
        strcpy(str,"null");
    }
}
edit_string& edit_string::add(int i,const char* n)
{
    int k=strlen(n);
    char*p;
    char*s=new char[strlen(str+k+1)];
    for(int j=0;j<i;j++,s++,str++)
    {
        *s=*str;
    }
    p=s;
    for(int j=0;j<k;j++,s++,n++)
    {
        *s=*n;
    }
    strcat(s,p);
    for(int j=0;j<i;j++,p--);
    delete []p;
    for(int j=0;j<i+k;j++,s--);
    str=s;
    return *this;
}
edit_string& edit_string::del(int i)
{
char*p=new char[i+1];
for(int j=0;j<i;j++,str++);
str++;
*str=0;
for(int j=0;j<i;j++,str--);
strcpy(p,str);
delete[]str;
str=p;
return *this;
}
edit_string& edit_string::rep(const char n,const char m)
{
    char*p=new char[strlen(str+1)];
    strcpy(p,str);
    for(;*p!=0;p++)
    {
      if(*p='n')
        *p='m';
    }
    for(int j=0;j<strlen(str+1);p--);
    str=p;
    return *this;
}
int main( )
{

String s1( "dalianligong" ), s2( " ruanjianxueyuan" ),s3;
    cout << s1.getLength()<<endl;
    //���������!
s3=s1+s2;
    cout << s3<< endl;

    cout << "s1>s2 " << (s1<s2?"ture":"false") <<endl;
    for(int i=12;i<19;i++)
    {
        cout<<s3[i];
    }

edit_string ps1( "dalianligong" ), ps2( "ruanjianxueyuan" );
cout<<ps1<<endl;;
cout<<ps2<<endl;
ps1.rep('a','z');
ps2.add(11,"daxue");
cout<<ps1<<endl;
cout<<ps2<<endl;
return 0;
}

