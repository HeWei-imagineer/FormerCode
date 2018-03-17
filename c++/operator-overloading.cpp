//Ch4_7 字符串类的运算符重载
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;   //断言assert()
//定义字符串类
class String
{
 public:
    String( const char *s = 0);     	   //转换构造函数
    String( const String & );           //拷贝构造函数
    ~String( );                  	  //析构函数
    int getLength( ) { iLength=strlen(sPtr);return iLength; };  //返回串长
		//重载常用运算符
    const String &operator=( const String & );
    const String &operator+( const String & );
    bool operator!( ) const;
    bool operator==( const String & ) const;
    bool operator<( const String & ) const;
    char &operator[ ]( int );
    //利用已重载的关系运算符实现重载其他运算符
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
     char *sPtr;          	     //字符串指针
     int iLength;                //串长
     void setString( const char *s); //设置字符串的工具函数
};

//转换构造函数，将char* 转换为string对象
String::String( const char *s ) {
   if(s==NULL){
	      sPtr=NULL;
		  iLength = 0 ;
	   }
	   else{
	       iLength = strlen( s ) ;
		   sPtr = new char[iLength + 1 ];  //为字符串分配内存
		   assert( sPtr != 0 );        	//如果分配内存不成功终止程序
		   strcpy( sPtr, s );
	   }
}
//复制构造函数，深复制
String::String( const String &cop ){
    if(cop.iLength  ==NULL) {
	       sPtr=NULL;
		   iLength = 0 ;
	   }
else
	  {
	      iLength = cop.iLength ;
	      sPtr = new char[iLength + 1 ];  //为字符串分配内存
		  assert( sPtr != 0 );        	//如果分配内存不成功终止程序
		  strcpy( sPtr, cop.sPtr );    //向this->sPtr拷贝字符串string2
	  }
}
String::~String( ){
    if(sPtr)
delete [ ] sPtr;       	//释放字符串内存
}
void String::setString( const char *s){
	   if(s==NULL) {
	       sPtr=NULL;
		   iLength = 0 ;
	   }
	   else{
	       iLength = strlen( s ) ;
		   sPtr = new char[iLength + 1 ];  //为字符串分配内存
		   assert( sPtr != 0 );        	//如果分配内存不成功终止程序
		   strcpy( sPtr, s );    //向this->sPtr拷贝字符串string2
}
}
//重载=, 实现字符串赋值
const String &String::operator=( const String &right ){
     if ( &right != this )	{ //判断左右操作数是否相同
        delete [ ] sPtr;
        iLength = right.iLength;
        setString( right.sPtr );
    }
    else{    	//避免自我赋值造成内存泄漏
    		cout << "Attempted assignment of a String to itself\n";
	    }
    return *this;
}
//重载+=, 实现字符串连接
const String& String::operator+( const String &right ){
    String a;
    char *tempPtr = sPtr;         	//保存左操作对象中原指针
    iLength += right.iLength;     	//新建内存空间
    a.sPtr = new char[iLength + 1 ]; 	//保存新的字符串
    assert( sPtr != 0 );       	     //避免申请内存不成功
    strcpy( sPtr, tempPtr );   		//将左操作数复制给新字符串
    strcat( sPtr, right.sPtr );  	//将右操作数连接到新字符串
    delete [ ] tempPtr;       		//释放左操作数原指针
    return a;
}
//重载!,判断对象是否为空字符串
bool String::operator!( ) const{
return iLength == 0; }
//重载关系运算符
bool String::operator==( const String &right ) const{
return strcmp( sPtr, right.sPtr ) == 0; }
bool String::operator<( const String &right ) const{
return strcmp( sPtr, right.sPtr ) < 0; }
//重载下标运算符
char &String::operator[ ]( int subscript ){
    assert( subscript >= 0 && subscript <iLength ); //判断下标是否越界
    return sPtr[ subscript ];  //按引用方式返回字符，可作左值
}
//重载流插入和提取运算符
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
           str = new char[strlen(s) + 1 ];  //为字符串分配内存
           assert( str != 0 );        	//如果分配内存不成功终止程序
           strcpy( str, s );    //向this->sPtr拷贝字符串string2
       }
    }
public:
    edit_string(const char*s,int i=0);
    ~edit_string(){delete[]str;}
    edit_string& add(int i,const char* n);//添加字符串
    edit_string& rep(const char n,const char m);//替换字符
    edit_string& del(int i);//删除后续字符串
    edit_string& fin(char *n);//查找子串位置
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
    //测试运算符!
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

