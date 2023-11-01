int	is_numeric(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus_count;
	int	result;

	i = 0;
	minus_count = 0;
	result = 0;
	while (str[i] != '\0' && !result)
	{
		if (str[i] == '-')
			minus_count++;
		if (is_numeric(str[i]))
		{
			while (str[i] != '\0' && is_numeric(str[i]))
			{
				result *= 10;
				result += str[i] - 48;
				i++;
			}
		}
		i++;
	}
	if (minus_count % 2 == 0)
		return (result);
	return (result *= -1);
}