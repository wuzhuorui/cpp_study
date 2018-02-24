class BaseClass
{
public:
	int public_int;
private:
	int private_int;
protected:
	int protected_int;
};

class DerivedClass :public BaseClass {
public:
	void UsePublicInt()
	{
		public_int = 1; //正确
	}
	void UserPrivateInt()
	{
		private_int = 1;//错误:成员 BaseClass::private_int不可访问
	}
	void UserProtectedInt()
	{
		protected_int = 1; //正确 
	}
};

//protected 对ProtectedDerivedClass的派生类和用户和友元函数产生影响,对ProtectedDerivedClass自身的成员函数无影响
class ProtectedDerivedClass :protected BaseClass {
public:
	void UsePublicInt()
	{
		public_int = 1; //正确 BaseClass::public_int是公有的
	}
	void UserPrivateInt()
	{
		private_int = 1;//错误:成员 BaseClass::private_int不可访问
	}
	void UserProtectedInt()
	{
		protected_int = 1; //正确 
	}
};

int main()
{
	BaseClass baseclass;
	baseclass.public_int; //正确
	baseclass.protected_int; //错误:成员 BaseClass::protected_int不可访问
	baseclass.private_int; //错误:成员 BaseClass::private_int不可访问

	DerivedClass derivedclass;
	derivedclass.public_int;   //正确
	derivedclass.protected_int; //错误:成员 BaseClass::protected_int不可访问
	derivedclass.private_int; //错误:成员 BaseClass::private_int不可访问 

	ProtectedDerivedClass protectedderivedclass;
	protectedderivedclass.public_int = 1;//错误:成员 BaseClass::public_int不可访问 原因 ProtectedDerivedClass :protected DerivedClass,对ProtectedDerivedClass的用户而言public_int是protectd,所以无法访问
	protectedderivedclass.protected_int; //错误:成员 BaseClass::protected_int不可访问
	protectedderivedclass.private_int; //错误:成员 BaseClass::private_int不可访问 
}