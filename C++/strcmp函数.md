```C++
int strcmp(const char* str1. comst char* str2)
{
    assert(str1 != NULL && str2 != NULL);
    int ret = 0;
    while((ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
    {
       ++str1;
       ++str2;
    }
    if(ret>0)
        return 1;
    else if(ret<0)
        return -1;
    return 0;
}
```