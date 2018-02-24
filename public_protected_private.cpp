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
		public_int = 1; //��ȷ
	}
	void UserPrivateInt()
	{
		private_int = 1;//����:��Ա BaseClass::private_int���ɷ���
	}
	void UserProtectedInt()
	{
		protected_int = 1; //��ȷ 
	}
};

//protected ��ProtectedDerivedClass����������û�����Ԫ��������Ӱ��,��ProtectedDerivedClass����ĳ�Ա������Ӱ��
class ProtectedDerivedClass :protected BaseClass {
public:
	void UsePublicInt()
	{
		public_int = 1; //��ȷ BaseClass::public_int�ǹ��е�
	}
	void UserPrivateInt()
	{
		private_int = 1;//����:��Ա BaseClass::private_int���ɷ���
	}
	void UserProtectedInt()
	{
		protected_int = 1; //��ȷ 
	}
};

int main()
{
	BaseClass baseclass;
	baseclass.public_int; //��ȷ
	baseclass.protected_int; //����:��Ա BaseClass::protected_int���ɷ���
	baseclass.private_int; //����:��Ա BaseClass::private_int���ɷ���

	DerivedClass derivedclass;
	derivedclass.public_int;   //��ȷ
	derivedclass.protected_int; //����:��Ա BaseClass::protected_int���ɷ���
	derivedclass.private_int; //����:��Ա BaseClass::private_int���ɷ��� 

	ProtectedDerivedClass protectedderivedclass;
	protectedderivedclass.public_int = 1;//����:��Ա BaseClass::public_int���ɷ��� ԭ�� ProtectedDerivedClass :protected DerivedClass,��ProtectedDerivedClass���û�����public_int��protectd,�����޷�����
	protectedderivedclass.protected_int; //����:��Ա BaseClass::protected_int���ɷ���
	protectedderivedclass.private_int; //����:��Ա BaseClass::private_int���ɷ��� 
}