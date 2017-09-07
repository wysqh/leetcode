#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return (m_Instance);
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }

	~Singleton(){
		cout << "deconstruction" << endl;

		delete m_Instance;
		m_Instance = nullptr;
	}
		static  Singleton *m_Instance;
		int m_Test;
};

	Singleton *Singleton ::m_Instance = new Singleton();
	less<int> functor = less<int>();

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;
	//Singleton ::DestoryInstance();

	return 0;
}