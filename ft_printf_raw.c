# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int handle_str(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int count_digits(int n)
{
	int i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void handle_positive(char *result, int n, int n_digits)
{
	result[n_digits - 1] = '\0';
	n_digits -= 2;
	while (n_digits >= 0)
	{
		result[n_digits] = (n % 10) + '0';
		n /= 10;
		n_digits--;
	}
}

void handle_negative(char *result, int n, int n_digits)
{
	n *= -1;
	result[0] = '-';
	result[n_digits] = '\0';
	n_digits--;
	while (n_digits > 0)
	{
		result[n_digits] = (n % 10) + '0';
		n /= 10;
		n_digits--;
	}
}

char *handle_zero(void)
{
	char *result;

	result = malloc(2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}


char *ft_itoa(int n)
{
	char *result;
	int	n_digits;

	n_digits = count_digits(n);
	if (n > 0)
	{
		result = malloc(n_digits + 1);
		if (!result)
			return (NULL);
		handle_positive(result, n, n_digits);
	}
	else if (n < 0)
	{
		result = malloc(n_digits);
		if (!result)
			return (NULL);
		handle_negative(result, n, n_digits);
	}
	else
		return (handle_zero());
	return (result);
}

int handle_digit(va_list *args)
{
	int digit;
	char *str;

	digit = va_arg(*args, int);
	if (digit <= INT_MIN)
		str = "-2147483648";
	else
		str = ft_itoa(digit);
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int count_digit_hex(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void build_hex_string(unsigned int n, char *str, int *index)
{
	if (n >= 16)
	{
		build_hex_string(n / 16, str, index);
		n %= 16;
	}
	if (n <= 9)
		str[(*index)++] = n + '0';
	else
		str[(*index)++] = 'a' + (n - 10);
}

int handle_digit_hex(va_list *args)
{
	unsigned int digit;
	char *hex_string;

	digit = va_arg(*args, unsigned int);
	int len = count_digit_hex(digit);
	if (digit == 0)
		len = 1;
	hex_string = malloc(len + 1);
	if (!hex_string)
		return (0);
	int index = 0;
	build_hex_string(digit, hex_string, &index);
	int i = 0;
	while (hex_string[i])
	{
		write(1, &hex_string[i], 1);
		i++;
	}
	return (i);
}

int handle_format(char flag, va_list *args)
{
	int count;

	count = 0;
	if (flag == 's')
		count += handle_str(args);
	if (flag == 'd')
		count += handle_digit(args);
	if (flag == 'x')
		count += handle_digit_hex(args);
	return (count);
}

int ft_printf(const char *str, ... )
{
	va_list	args;
	int i;
	int counter;

	if (!str || *str == '\0')
		return (0);
	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			counter++;
		}
		else
		{
			i++;
			counter += handle_format(str[i], &args);
		}
		i++;
	}
	va_end(args);
	return (counter);
}