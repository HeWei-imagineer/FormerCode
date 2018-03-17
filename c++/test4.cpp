#include<iostream>
#include<math.h>
using namespace std;
const double uZero = 1e-6;//避免浮点数误差

class Vector3{
private:
    float x, y, z;
public:
    Vector3(float xx=0,float yy=0,float zz=0):x(xx),y(yy),z(zz){}
    Vector3(float zz=1):z(zz){x=0;y=0;}// 构造函数 默认为 [0;0;0]  如果只有x,y, z默认1;

    Vector3(const Vector3&a){x=a.x;y=a.y;z=a.z;}//复制构造函数，常量引用参数，否则编译可能不通过
	//补全
    ~Vector3();
    // 向量运算
    void operator =(const Vector3 &v);
    // 重载加减运算符
    Vector3 operator +(const Vector3 &v){Vector3 a; a.x=x+v.x;a.y=y+v.y;a.z=z+v.z;return a;}
    Vector3 operator -(const Vector3 &v){Vector3 a; a.x=x-v.x;a.y=y-v.y;a.z=z-v.z;return a;}

    // 重载标量乘、除法运算符 对应元素乘除。
    Vector3 operator /(const Vector3 &v){Vector3 a;
    if(v.x!=0&&v.y!=0&&v.z!=0){a.x=x/v.x;a.y=y/v.y;a.z=z/v.z;  return a;}
    else{cout<<"wrong number"<<endl;}
    }
    Vector3 operator*(const Vector3 &v){Vector3 a; a.x=x*v.x;a.y=y*v.y;a.z=z*v.z;return a;}
    // 向量数值操作 相当于对每个元素分别操作
    Vector3 operator+(float f){Vector3 a; a.x=x+f;a.y=y+f;a.z=z+f;return a;}
    Vector3 operator-(float f){Vector3 a; a.x=x-f;a.y=y-f;a.z=z-f;return a;}
    Vector3 operator/(float f){Vector3 a;
    if(f!=0){ a.x=x/f;a.y=y/f;a.z=z/f;  return a;}
    else{cout<<"wrong number"<<endl;}
    }
    Vector3 operator*(float f){Vector3 a; a.x=f;a.y=y*f;a.z=z*f;return a;}
    // 向量长度
    float length(){float b=sqrt(x*x+y*y+z*z);return b;}
    // 向量标准化
    void normalize(){x=x/length();y=y/length();z=z/length(); }
    // 向量点乘，重载乘法运算符 计算向量的长度时可以使用
    float dot(const Vector3 &v){return (x*v.x+y*v.y+z*v.z);}
//Cross Product叉乘公式
   // aXb = | i,  j,  k  |
          //| a.x a.y a.z|
         // | b.x b.y b.z| =
    Vector3 crossProduct(const Vector3 &v){ x= (x*v.z -z*v.y);
    y=(z*v.x - x*v.z);z=(x+v.y - y*v.x); return *this;
    }
    // 重载输出流运算符
    friend ostream& operator << (ostream& out, const Vector3& V3){out<<"["<<x<<";"<<y<<";"<<z<<"]";return out;}//运算符“<<”重载为友元函数
    void printVec3();
};


int main(){
    Vector3 v[3]={Vector3(1,2),Vector3(2.0f,3.0f,4.0f)};
    cout<<"We have original Vector3s:\n";
    cout<<"v[3]:\n"<<v[0]<<"\t"<<v[1]<<"\t"<<v[2]<<endl;
    Vector3 v31;
    Vector3 v32=v[1];
    Vector3 v33(v32 + 1.0f);
    cout<<"v31:"<<v31<<"\tv32:"<<v32<<"\tv33:"<<v33<<endl<<endl;

    cout<<"Calculate Example:\n";
    cout<<"v32+v33="<<v32+v33<<endl;
    cout<<"v32-v33="<<v32-v33<<endl;
    cout<<"v32*v33="<<v32*v33<<endl;
    cout<<"v32/v33="<<v32/v33<<endl;
    //除数为零
    cout<<"v32/v31(Divisor contents 0):";
    cout<<v32/v31<<endl<<endl;
    cout<<"v32 crossproduct v33 is:\n";
    Vector3 v3233 = v32.crossProduct(v33);
    cout<<v3233<<endl<<endl;

    cout<<"Now we normalize them:\n";
    v31.normalize();
    v32.normalize();
    v33.normalize();
    v3233.normalize();
    cout<<"v31:"<<v31<<"\tv32:"<<v32<<"\tv33:"<<v33<<endl;
    cout<<"v3233:"<<v3233<<endl;
    return 0;
}
