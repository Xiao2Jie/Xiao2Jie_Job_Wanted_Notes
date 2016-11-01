```C++
char* strcpy(char* strDes, char* strSrc)
{
    assert(strDes != NULL && strSrc != NULL);
    char* strAddr = strDes;
    while((*strDes++ = *strSrc++) != '\0'))
         NULL;
    return strAddr;
}

```

---
```
char* strcpy(char* strDes, char* strSrc)

{

    assert(strDes != NULL && strSrc != NULL);

    char* strAddr = strDes;

    while(*strSrc != '\0')

    {

        *strDes++ = *strSrc++;
    }

    *strDes = '\0';

    return strAddr;

}


}

```