long long f(int n, int m)
{
  if(m == 1||n == 0)
    return 1;
  if(m > n)
    return f(n, n)
  return f(n, m-1) + f(n - m, m);
}
