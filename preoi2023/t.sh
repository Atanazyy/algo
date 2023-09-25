#!/bin/bash

for((i=1;i>0;i++));
do
echo $i | ./g > p.in
./b < p.in > b.out
./w < p.in > w.out
if diff -qb b.out w.out
then echo "OK\n"
else
echo "BOMBA W BOJLERZE\n"
break
fi
done
