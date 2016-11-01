
```C++
//字符串转成数字
int atoi(char* pStr)
{
	assert(pStr != NULL);
	int nNumber = 0;
	bool bPositive = true;
	while(isspace(*pStr) == 0)
		++pStr;
	if(*pStr == '-')
		bPositive = false;
	if(*pStr == '-' || *pStr == '+')
		++pStr;
	while(*pStr <='9' && *pStr >= '0')
	{
		nNumber = 10*nNumber + *pStr-'0';
		++pStr;
	}
	if(!bPositive)
		nNumber = -nNumber;
	return = nNumber;
}
//整数转成字符串
void itoa(int num, char* str)
{
	int sign = num;
	int i = 0; 
	int j = 0;
	char temp[100];
	if(sign < 0)
		num = -num;
	while(num >0)
	{
		temp[i++] = num%10 +'0';
		num /= 10;
	}
	if(sign <0)
	{
		++i;
		temp[i] = '-';
	}
	++i;
	temp[i] = '\0';
	--i;
	while(i>=0)
	{
		str[j++] = temp[i--];
	}
	str[j] = '\0';
}
```
