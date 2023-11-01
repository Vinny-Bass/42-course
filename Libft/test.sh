#!/bin/bash

for file in *.c; do
	file_name="${file%.c}"
	if ! test -f ./tests/"$file_name"_test.c; then
		echo -e "\e[31mMissing tests for $file\e[0m"
		continue
	fi
done

for file in tests/*_test.c; do
	base_file="${file#tests/}"
	base_file="${base_file%_test.c}.c"
	
	if ! test -f "$base_file"; then
		echo -e "\e[31m$base_file do not exist\e[0m"
		continue
	fi

	cc -Wall -Werror -Wextra "$file" "$base_file" -o "${file%.c}.out"

	if [ $? -ne 0 ]; then
		echo -e "\e[31m$file -> not compiling\e[0m"
		continue
	fi

	"./${file%.c}.out" > /dev/null

	if [ $? -ne 0 ]; then
		echo -e "\e[31m$file -> testing failing\e[0m"
	else
		echo -e "\e[32m$file -> testing ok\e[0m"
	fi

	rm "${file%.c}.out"
done