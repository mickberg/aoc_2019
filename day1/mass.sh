#!/bin/sh

input="input.txt"
sum=0

while IFS= read -r line
do
	inv=$(($line/3 - 2))
	sum=$(($sum + $inv))
done < "$input"

echo "$sum"

calcModuleFuel()
{
	inv=$(($1 / 3 - 2))
	calcModuleFuel $inv
	return $inv
}
