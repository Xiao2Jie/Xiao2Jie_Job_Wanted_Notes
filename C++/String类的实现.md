```C++

    class String
    {
    public:
    	//构造函数
    	String(const char* chr = NULL)
    	{
    		if(chr == NULL)
    		{
    			m_chr = new char[1];
    			*m_chr = '\0';
    		}
    		else{
    			int len = strlen(chr);
    			m_chr = new char(len+1);
    			strcpy(m_chr, chr);
    		}
    	}
    	//析构函数
    	~String()
    	{
    		delete [] m_chr;
    	}
    	
    	//拷贝构造
    	String(const String& rhs)
    	{
    		int len = rhs.m_chr();
    		m_chr = new char(len+1);
    		strcpy(m_chr, rhs.m_chr);		
    	}
    	String& operator=(const String & rhs)
    	{
    		if(&rhs == this)
    			return *this;
    		delete[] m_chr;
    		int len = strlen(rhs.m_chr);
    		m_chr = new char(len+1);
    		strcpy(m_chr, rhs.m_chr);
    		return *this;
    	}
    private:
    	char* m_chr;
    };
```