#!/usr/bin/env bash

wzor=$1

/usr/bin/g++ -fsanitize=undefined,address -Wall -Wextra -pedantic -Wshadow -Wfloat-equal -Wformat=2 -std=c++17 -o $wzor $wzor.cpp

for(( i=1;i<=1000;i++)) do
./$wzor < ./in/$wzor$i.in > ./out/wzor.out

if diff -qb ./in/$wzor$i.out ./out/wzor.out;
    then echo -ne "test $i           OK\r";
    else echo "test $i          KOZA W ZASWIATACH";
        break;
fi
done
