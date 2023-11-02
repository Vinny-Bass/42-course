#!/bin/bash

OS=$(uname -s)

echo_error() {
	local str=$1
	if [ "$OS" == "Linux" ]; then
    	echo -e "\e[31m$str\e[0m"
	else
		echo -e "\033[31m$str\033[0m"
	fi
}

echo_success() {
	local str=$1
	if [ "$OS" == "Linux" ]; then
    	echo -e "\e[32m$str\e[0m"
	else
		echo -e "\033[32m$str\033[0m"
	fi
}

for file in *.c; do
	file_name="${file%.c}"
	if ! test -f ./tests/"$file_name"_test.c; then
		echo_error "Missing tests for $file"
		continue
	fi
done

echo "Compiling lib..."
gcc -Wall -Werror -Wextra -c *.c
ar rcs libft.a *.o

if [ $? -ne 0 ]; then
	echo_error "libft is not compiling"
	continue
fi

for file in tests/*_test.c; do
	cc -Wall -Werror -Wextra -c "$file" -o "${file%.c}.o"
	if [ "$OS" == "Linux" ]; then
		cc -o "${file%.c}" "${file%.c}.o" -L. -l:libft.a
	elif [ "$OS" == "Darwin" ]; then
		cc -o "${file%.c}" "${file%.c}.o" -L. -lft
	fi

	if [ $? -ne 0 ]; then
		echo_error "$file -> not compiling"
		continue
	fi

	"./${file%.c}" > /dev/null

	if [ $? -ne 0 ]; then
		echo_error "$file -> testing failing"
	else
		echo_success "$file -> testing ok"
	fi

	rm "${file%.c}"
	rm "${file%.c}.o"
done

rm *.o
rm *.a