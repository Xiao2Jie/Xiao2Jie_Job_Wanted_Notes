```C++
deque<int> func(vector<int> vec, int nSize)
{
	deque<int> deq;
	if(vec.size()==0 || nSize<=0)
		return deq;
	for(int i = 0; i< vec.size(); ++i)
	{
		auto pos = find(deq.begin(), deq.end(), vec[i]);
		if(pos != deq.end())
		{
			deq.erase(pos);
			deq.push_back(vec[i]);
		}
		else
		{
			if(deq.size()>=nSize)
			{
				deq.pop_front();				
			}
			deq.push_back(vec[i]);
		}
	}
	return deq;
}
```