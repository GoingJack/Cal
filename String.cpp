#include<iostream>
#include<string.h>
using namespace std;

class String{
	friend bool operator == (const String &,const String &);
	friend bool operator != (const String &,const String &);
	friend bool operator <= (const String &,const String &);
	friend bool operator >= (const String &,const String &);
	friend bool operator  < (const String &,const String &);
	friend bool operator  > (const String &,const String &);
	friend String operator + (const String &lhs,const String &rhs);
	private:
		char *buffer;
	public:
		String()//无参数的构造函数 
		{
			buffer = new char[1];
		}
		String (const char *str)//有参数构造函数 
		{
			buffer = new char[strlen(str)+1];
			strcpy(buffer,str);
		}
		String (const String &rhs)//复制构造函数 
		{
			buffer = new char[strlen(rhs.buffer)+1];
			strcpy(buffer,rhs.buffer);
		}
		String &operator = (const String &rhs)//复制对象重载函数 
		{
			if (this != &rhs)
			{
				delete []buffer;
				buffer = new char[strlen(rhs.buffer)+1];
				strcpy(buffer,rhs.buffer);
			}
			return *this;
		}
		String & operator = (const char *str)//复制字符重载函数 
		{
			buffer = new char[strlen(str)+1];
			strcpy(buffer,str);
			return *this;
		}
		String & operator += (const String & rhs)
		{
			char *tmp;
			tmp = new char[strlen(buffer)+strlen(rhs.buffer)+1];
			strcpy(tmp,buffer);
			strcat(tmp,rhs.buffer);
			delete []buffer;
			buffer = tmp;
			return *this;
		}
		String & operator += (const char * str)
		{
			char *tmp;
			tmp = new char[strlen(str)+strlen(buffer)+1];
			strcpy(tmp,buffer);
			strcat(tmp,str);
			delete []buffer;
			buffer=tmp;
			return *this;
		}
		void print()
		{
			if (buffer==NULL)
			{
				cout<<""<<endl;	
			}	
			else 
			{
				cout<<"string:"<<buffer<<endl;
			}
		}	
		~String()
		{
			delete []buffer;
		}
}; 
bool operator == (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)==0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
bool operator != (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)!=0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
bool operator <= (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)<=0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
bool operator >= (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)>=0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
bool operator < (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)<0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
bool operator > (const String &lhs,const String &rhs)
	{
		if (strcmp(lhs.buffer,lhs.buffer)>0)
			{
				return 1;
			}
		else 
			{
				return 0;
			}
	}
String operator + (const String &lhs,const String &rhs)
{
	String tmp(lhs);
	tmp+=rhs;
	return tmp;
}
String operator + (const String &lhs,const char *str)
{
	String tmp(lhs);
	tmp+=str;
	return tmp;
}
String operator + (const char *str,const String &rhs)
{
	String tmp(str);
	tmp+=rhs;
	return tmp;
}
int main ()
{
	String s1="hello";
	s1.print();
	String s2("hello");
	s2.print();
	if (s1==s2)
		{
			cout<<"s1==s2"<<endl;
		}
	String s3="hell";
	if (s3<=s2)
	{
		cout<<"s3<=s2"<<endl;
	}
	s3+=s2;
	s3.print();
	s2+="world";
	s2.print();
	String s4="Hello";
	String s5="Jack";
	String s6;
	s6=s4+s5;
	s6.print();
	s6="Hello"+s5;
	s6.print();
	s6=s4+"Jack";
	s6.print();
	return 0;
}
