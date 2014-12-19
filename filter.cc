#include <list>
#include <iostream>
#include <memory>

using namespace std;

void PrintIt(int & num){
	cout<<num<<endl;
}

class filter
{
public:
	filter()
	{
		memset(m_Data, 0, m_length);
	}
    
    void factorization(int num , list <int> &factor)
    {
    	int x = 2;

    	while (num != 1)
    	{
    		if (m_Data[x] == 0)
    			while (num%x == 0)
    			{
    				factor.push_back(x);
    				num /= x;
    			}
    		x++;
    	}
    	// return factor;
    }

    void initPrimes(void)
    {
    	for (int i = 2; i < m_length; ++i)
    	{
    		if (m_Data[i] == 0)
    		{
    			int mutil = 2;
    			while (i*mutil < m_length)
    			{
    				m_Data[i*mutil]++;
    				mutil ++;
    			}
    		}
    	}
    }

    int getStartNum(void)
    {
    	int x = 2;
    	while (x+3 < m_length)
    	{
    		if ((m_Data[x]   == 4) && \
    			(m_Data[x+1] == 4) && \
    			(m_Data[x+2] == 4) && \
    			(m_Data[x+3] == 4))
    		{
    			return x;
    		}
    		x++;
    	}
    	cout<<"length too low Not found"<<endl;
    	return 2;
    }

	~filter()
	{

	}
private:
	const static int m_length = 1000000;
	int  m_Data[m_length]; 
	
};


int main()
{
	filter s = filter();
	s.initPrimes();
	int num = s.getStartNum();
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