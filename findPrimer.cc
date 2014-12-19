#include <iostream>
#include <list>

using namespace std;


void PrintIt(int & num){
	cout<<num<<endl;
}

class findPrimer
{
public:
	findPrimer()
	{
		m_primes.push_back(2);
		m_primes.push_back(3);
		m_primes.push_back(5);
		m_primes.push_back(7);
	}

	int getFactorNo(int num)
	{
		int nCnt = 0;
		list <int>::iterator itor;
		for (itor = m_primes.begin(); itor != m_primes.end(); ++itor)
		{
			if (num%*itor == 0)
			{
				nCnt++;
			}
		}

		if (nCnt==0)
		{
			nCnt++;
			m_primes.push_back(num);
		}
		return nCnt;
	}

	int getNum(void)
	{
		int num = m_start;

		while (1)
		{
			int notFound = 0;
			for (int i = 0; i < 4; ++i)
			{
				int iCnt = getFactorNo(num+i);
				if (iCnt != 4)
				{
					notFound = 1;
					num += i;
					break;
				}
			}
			if (notFound == 0)
			{
				return num;
			}
			num++;
		}
	}

	void factorization(int num, list<int> &factor)
	{
		list <int>::iterator itor;
		for (itor = m_primes.begin(); itor != m_primes.end(); ++itor)
		{
			while (num % *itor== 0)
			{
				factor.push_back(*itor);
				num /= *itor;
				if (num == 1)
				{
					return;
				}

			}
		}
	}
	~findPrimer()
	{

	}
private:
	list<int> m_primes;
	const int static m_start = 10;
	
};

int  main(int argc, char const *argv[])
{
	findPrimer s = findPrimer();
	int num = s.getNum();
	for (int i = 0; i < 4; ++i)
	{
		list <int> result;
		s.factorization(num+i, result);
		cout<<num+i<<":"<<endl;
		for_each(result.begin(), result.end(), PrintIt);
		cout<<"+++++++++++++"<<endl;
	}
	return 0;
}