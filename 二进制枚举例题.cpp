bool check(int i)
{
	int cnt = 0;
	while (i)//逐位检查i的二进制表达
	{
		if (i & 1)
			++cnt;
		i >>= 1;
	}
	if (cnt == 2)
		return true;
	return false;
}
