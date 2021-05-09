#include <iostream>
using namespace std;

class Implementor
{
public:
	virtual void OperationImpl() = 0;
	virtual ~Implementor(){}
};

class ConcreteImpementor : public Implementor
{
public:
	void OperationImpl()
	{
		cout << "OperationImpl" << endl;
	}
	
};

class Abstraction
{
protected:
	Implementor *m_pImpl;
public:
	Abstraction(Implementor *pImpl) : m_pImpl(pImpl) {}
	virtual ~Abstraction(){}
	virtual void Operation() = 0;
	
};

class RedfinedAbstraction : public Abstraction
{
public:
	RedfinedAbstraction(Implementor *pImpl) : Abstraction(pImpl) {}
	void Operation()
	{
		m_pImpl->OperationImpl();
	}
	
};

int main(int argc, char const *argv[])
{
	Implementor *m_pImplObj = new ConcreteImpementor();
	Abstraction *pAbsObj = new RedfinedAbstraction(m_pImplObj);
	pAbsObj->Operation();

	delete m_pImplObj;
	m_pImplObj = NULL;
	delete pAbsObj;
	pAbsObj = NULL;

	return 0;
}

