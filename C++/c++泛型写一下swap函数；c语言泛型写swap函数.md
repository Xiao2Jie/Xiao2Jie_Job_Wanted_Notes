```C++
//C++
template<typename T>
void myswap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}
```

---
```C++
//C
void myswap(void* a, void *b, int size)
{
  void* p = (void*)malloc(size);
  assert(p != NULL);
  memcpy(p, a, size);
  memcpy(a, b, size);
  memcpy(b, p, size);
  free(p);
}
```
