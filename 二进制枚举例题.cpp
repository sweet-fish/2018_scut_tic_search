bool check(int i)
{
	int cnt = 0;
	while (i)
	{
		if (i & 1)
			++cnt;
		i >>= 1;
	}
	if (cnt == 2)
		return true;
	return false;
}
