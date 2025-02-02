#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

struct Big_number
{
	vector <int> num;
	bool isNegative = false;
	static void string_to_big_number(Big_number& number, string s_x);
	static void int_to_big_number(Big_number& number, int i_x);
	friend ostream& operator<< (ostream &out, Big_number number)
	{
		if (number.isNegative)
			out << '-';
		for (int i = number.num.size() - 1; i >= 0; i--)
		{
			int buffer = 100'000'000;
			if (i != number.num.size() - 1)
				while (buffer > number.num[i] && buffer)
				{
					out << 0;
					buffer /= 10;
				}
			if (buffer)
				out << number.num[i];
		}
		return out;
	}
	friend istream& operator>> (istream &in, Big_number& number)
	{
		string s_x;
		cin >> s_x;
		number.num.erase(number.num.begin(), number.num.end());
		number.isNegative = false;
		string_to_big_number(number, s_x);
		return in;
	}
	Big_number operator+ (Big_number b); // Big_number + Big_number
	Big_number operator- (Big_number b); // Big_number - Big_number
	Big_number operator+ (int n); // Big_number + int
	Big_number& operator+= (const Big_number& b); // Big_number += Big_number
	Big_number& operator+= (int n); // Big_number += int
	void operator= (const Big_number& b);
	void operator= (int n);
	bool operator== (const Big_number& b);
	bool operator== (int);
	bool operator> (const Big_number& b);
	bool operator< (const Big_number& b);
	Big_number operator++ (); // ++Big_number
	Big_number operator++ (int); // Big_number++
	Big_number operator- (); 
	Big_number operator* (Big_number b);
	bool operator!= (Big_number b);
	static Big_number abs(Big_number);
	static Big_number multiple(Big_number a, Big_number b);
	Big_number operator-= (const Big_number &b);
	bool operator!= (int);
	bool operator<= (Big_number);
	bool operator>= (Big_number);
};