/*****************************************************************************
** File Name:        Intelligent algorithm library(IAL)
** Author:           SiQi_Wang
** Date:             2018/05/02
** Version:          1.0.2
** Description:      智能算法函数库
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           		NAME             		DESCRIPTION                  *
** 2018/04/24     		SiQi_Wang               Create                       *
** --------------------------------------------------------------------------*
******************************************************************************
**                         Important Edit Update                             *
** --------------------------------------------------------------------------*
** DATE           		NAME             		DESCRIPTION                  *
** 2018/05/02     		SiQi_Wang               Create                       *
** --------------------------------------------------------------------------*
** 1）新增链表操作
******************************************************************************
** Copyright(c) 2018, SiQi_Wang
** All rights reserved.
** Distributed under the BSD license.
** (See accompanying file LICENSE.txt at https://LICENSE.txt)
******************************************************************************/

/*---------------------------------------------------------------------------*
**                              Include Files                                *
**---------------------------------------------------------------------------*/
#include "stdafx.h"
#include "IAL.h"
/*---------------------------------------------------------------------------*
**                         Function Definition                               *
**---------------------------------------------------------------------------*/
/**--------------------------------------------------------------------------*
Name:		    Swap
Discribe:		数据交换
Parameter:      a, b (待交换数据)
**---------------------------------------------------------------------------*/
template <typename T> void Swap(T &a, T &b) { T temp = a; a = b; b = temp; }

/**--------------------------------------------------------------------------*
Name:		    isDigit
Discribe:		数字判断
Parameter:      ch (字符)
Return:		    bool : true(是数字), false(不是数字)
**---------------------------------------------------------------------------*/
bool isDigit(char &ch) { return (ch >= '0' && ch <= '9') ? 1 : 0; }

/**--------------------------------------------------------------------------*
Name:		    gcd
Discribe:		最大公约数
Parameter:      num1, num2
Return:		    int (最大公约数)
**---------------------------------------------------------------------------*/
int gcd(int &num1, int &num2) {
    while (num2) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

/**--------------------------------------------------------------------------*
Name:		    SwapStr
Discribe:		字符串反转 (整串&子串)
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Header:         #include <string>
				#include <cstring>
**---------------------------------------------------------------------------*/
//重载1   Input : string类字符串 【整串反转】
void SwapStr(string &str)
{
	for (int j = 0, i = str.size() - 1; j < i; --i, ++j)
		Swap(str[i], str[j]);
}
//重载2   Input : C字符数组指针 【整串反转】
void SwapStr(char *str)
{
	for (int j = 0, i = strlen(str) - 1; j < i; --i, ++j)
		Swap(str[i], str[j]);
}
//重载3   Input : string类字符串 【长度len子串反转】
void SwapStr(string &str, const int &len)
{
	for (int j = 0, i = len - 1; j < i; --i, ++j)
		Swap(str[i], str[j]);
}
//重载4   Input : C字符数组指针 【长度len子串反转】
void SwapStr(char *str, const int &len)
{
	for (int j = 0, i = len - 1; j < i; --i, ++j)
		Swap(str[i], str[j]);
}
//重载5   Input : string类字符串, 下标索引范围[start, end]， 【(str[start], str[end])子串反转】
void SwapStr(string &str, const int &start, const int &end)
{
	for (int j = start, i = end; j < i; --i, ++j)
		Swap(str[i], str[j]);
}
//重载6   Input : C字符数组指针, 下标索引范围[start, end]， 【(str[start], str[end])子串反转】
void SwapStr(char *str, const int &start, const int &end)
{
	for (int j = start, i = end; j < i; --i, ++j)
		Swap(str[i], str[j]);
}

/**--------------------------------------------------------------------------*
Name:		    isPalindrome
Discribe:		回文判断 (整串&子串)
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Return:		    bool : true(是回文), false(不是回文)
Header:         #include <string>
				#include <cstring>
**---------------------------------------------------------------------------*/
bool isPalindromeCore(const char *start, const char *end)
{
	return (start < end) ? ((*start == *end) ? isPalindromeCore(++start, --end) : false) : true;
}
//重载1   Input : string类字符串 【整串回文判断】
bool isPalindrome(const string &str)
{
	const char *pS = str.c_str(), *pE = pS + str.size() - 1;
	return isPalindromeCore(pS, pE);
}
//重载2   Input : C字符数组指针 【整串回文判断】
bool isPalindrome(const char *str)
{
	const char *pS = str, *pE = pS + strlen(str) - 1;
	return isPalindromeCore(pS, pE);
}
//重载3   Input : string类字符串 【长度len子串回文判断】
bool isPalindrome(const string &str, const int &len)
{
	const char *pS = str.c_str(), *pE = pS + len - 1;
	return isPalindromeCore(pS, pE);
}
//重载4   Input : C字符数组指针 【长度len子串回文判断】
bool isPalindrome(const char *str, const int &len)
{
	const char *pS = str, *pE = pS + len - 1;
	return isPalindromeCore(pS, pE);
}
//重载5   Input : string类字符串 【(str[start], str[end])子串回文判断】
bool isPalindrome(const string &str, const int &start, const int &end)
{
	const char *pS = str.c_str() + start, *pE = str.c_str() + end;
	return isPalindromeCore(pS, pE);
}
//重载6   Input : C字符数组指针 【(str[start], str[end])子串回文判断】
bool isPalindrome(const char *str, const int &start, const int &end)
{
	const char *pS = str + start, *pE = str + end;
	return isPalindromeCore(pS, pE);
}

/**--------------------------------------------------------------------------*
Name:		    Permutation
Discribe:		全排列（返回整串&子串的全排列及排列总数）
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Return:		    permuPair : permuPair.array(排列), permuPair.count(排列数)
Header:         #include <string>
				#include <cstring>
				#include <vector>
**---------------------------------------------------------------------------*/
/* struct permuPair
{
	vector<string> array;
	int count = 0;
}; */
void PermutationCore(char *pStr, char *pBegin, permuPair &res)
{
	if (*pBegin == '\0') { res.array.push_back(string(pStr)); res.count += 1; return; }
	for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
	{
		Swap(*pCh, *pBegin);
		PermutationCore(pStr, pBegin + 1, res);
		Swap(*pCh, *pBegin);
	}
}
//重载1   Input : string类字符串 【整串排列】
permuPair Permutation(const string &str)
{
	permuPair result; if (str.empty()) return result;
	const int len = str.size(); char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}
//重载2   Input : C字符数组指针 【整串排列】
permuPair Permutation(const char *str)
{
	permuPair result; if (str == nullptr) return result;
	const int len = strlen(str); char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}
//重载3   Input : string类字符串 【长度len子串全排列】
permuPair Permutation(const string &str, const int &len)
{
	permuPair result; if (str.empty()) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}
//重载4   Input : C字符数组指针 【长度len子串全排列】
permuPair Permutation(const char *str, const int &len)
{
	permuPair result; if (str == nullptr) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}
//重载5   Input : string类字符串 【(str[start], str[end])子串全排列】
permuPair Permutation(const string &str, const int &start, const int &end)
{
	permuPair result; if (str.empty()) return result;
	const int len = end - start + 1;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}
//重载6   Input : C字符数组指针 【(str[start], str[end])子串全排列】
permuPair Permutation(const char *str, const int &start, const int &end)
{
	permuPair result; if (str == nullptr) return result;
	const int len = end - start + 1;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	PermutationCore(Str, Str, result); delete[] Str; Str = nullptr;
	return result;
}

/**--------------------------------------------------------------------------*
Name:		    Combination & CombinationN
Discribe:		全组合（返回整串&子串的全组合、字符全组合及组合总数）
Parameter:      str(字符串), len(子串长), n(组合串长), start, end(下标索引,从0开始)
Return:		    combPair : combPair.array(组合), combPair.count(组合数)
Header:         #include <string>
				#include <cstring>
				#include <vector>
**---------------------------------------------------------------------------*/
/* struct combPair
{
	vector<vector<char>> array;
	int count = 0;
}; */
void CombinationCore(char *pStr, int number, vector<char> &ans, combPair &result)
{
	if (number == 0) { result.array.push_back(ans); result.count += 1; return; }
	if (*pStr == '\0') return;
	ans.push_back(*pStr);
	CombinationCore(pStr + 1, number - 1, ans, result);
	ans.pop_back();
	CombinationCore(pStr + 1, number, ans, result);
}
//重载1   Input : string类字符串 【整串全组合】
combPair Combination(const string &str)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	const int len = str.size(); char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}
//重载2   Input : C字符数组指针 【整串全组合】
combPair Combination(const char *str)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	const int len = strlen(str); char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}
//重载3   Input : string类字符串 【前len个字符的全组合】
combPair Combination(const string &str, const int &len)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}
//重载4   Input : C字符数组指针 【前len个字符的全组合】
combPair Combination(const char *str, const int &len)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}
//重载5   Input : string类字符串 【(str[start], str[end])子串全组合】
combPair Combination(const string &str, const int &start, const int &end)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	const int len = end - start + 1; char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}
//重载6   Input : C字符数组指针 【(str[start], str[end])子串全组合】
combPair Combination(const char *str, const int &start, const int &end)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	const int len = end - start + 1; char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	for (int i = 1; i <= len; ++i) CombinationCore(Str, i, ans, result);
	delete[] Str; Str = nullptr;
	return result;
}

//重载1   Input : string类字符串, 组合字符数n  【整串n字符组合】
combPair CombinationN(const string &str, const int &n)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	const int len = str.size(); if (n > len) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}
//重载2   Input : C字符数组指针, 组合字符数n  【整串n字符组合】
combPair CombinationN(const char *str, const int &n)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	const int len = strlen(str); if (n > len) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}
//重载3   Input : string类字符串, 组合字符数n 【长度len子串n字符组合】
combPair CombinationN(const string &str, const int &len, const int &n)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	if (n > len) return result; char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}
//重载4   Input : C字符数组指针, 组合字符数n 【长度len子串n字符组合】
combPair CombinationN(const char *str, const int &len, const int &n)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	if (n > len) return result; char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}
//重载5   Input : string类字符串, 组合字符数n 【(str[start], str[end])子串n字符组合】
combPair CombinationN(const string &str, const int &start, const int &end, const int &n)
{
	vector<char> ans; combPair result; if (str.empty()) return result;
	const int len = end - start + 1; if (n > len) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}
//重载6   Input : C字符数组指针, 组合字符数n 【(str[start], str[end])子串n字符组合】
combPair CombinationN(const char *str, const int &start, const int &end, const int &n)
{
	vector<char> ans; combPair result; if (str == nullptr) return result;
	const int len = end - start + 1; if (n > len) return result;
	char *Str = new char[len + 1];
	for (int i = 0; i < len; ++i) Str[i] = str[i+start]; Str[len] = '\0';
	CombinationCore(Str, n, ans, result); delete[] Str; Str = nullptr;
	return result;
}

/**--------------------------------------------------------------------------*
Name:		    BubbleSort
Discribe:		冒泡排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BubbleSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	int flag = 0; //判断排序是否完成，并提前中止后续排序过程
	for (int i = 0; i != array.size() - 1; ++i)
	{
		flag = 0;
		switch (rule)
		{
		case 1: for (int j = 0; j != array.size() - 1; ++j) if (array[j] > array[j + 1]) { flag = 1; break; } break;
		case 2: for (int j = 0; j != array.size() - 1; ++j) if (array[j] < array[j + 1]) { flag = 1; break; } break;
		}
		if (flag == 0) break;
		for (int j = array.size() - 1; j > i; --j)
		{
			switch (rule)
			{
			case 1: if (array[j - 1] > array[j]) Swap(array[j - 1], array[j]); break;
			case 2: if (array[j - 1] < array[j]) Swap(array[j - 1], array[j]); break;
			}
		}
	}
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BubbleSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int flag = 0; //判断排序是否完成，并提前中止后续排序过程
	for (int i = 0; i < len - 1; ++i)
	{
		flag = 0;
		switch (rule)
		{
		case 1: for (int j = 0; j < len - 1; ++j) if (array[j] > array[j + 1]) { flag = 1; break; } break;
		case 2: for (int j = 0; j < len - 1; ++j) if (array[j] < array[j + 1]) { flag = 1; break; } break;
		}
		if (flag == 0) break;
		for (int j = len - 1; j > i; --j)
		{
			switch (rule)
			{
			case 1: if (array[j - 1] > array[j]) Swap(array[j - 1], array[j]); break;
			case 2: if (array[j - 1] < array[j]) Swap(array[j - 1], array[j]); break;
			}
		}
	}
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BubbleSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int flag = 0; //判断排序是否完成，并提前中止后续排序过程
	for (int i = 0; i < len - 1; ++i)
	{
		flag = 0;
		switch (rule)
		{
		case 1: for (int j = 0; j < len - 1; ++j) if (array[j] > array[j + 1]) { flag = 1; break; } break;
		case 2: for (int j = 0; j < len - 1; ++j) if (array[j] < array[j + 1]) { flag = 1; break; } break;
		}
		if (flag == 0) break;
		for (int j = len - 1; j > i; --j)
		{
			switch (rule)
			{
			case 1: if (array[j - 1] > array[j]) Swap(array[j - 1], array[j]); break;
			case 2: if (array[j - 1] < array[j]) Swap(array[j - 1], array[j]); break;
			}
		}
	}
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BubbleSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	int flag = 0; //判断排序是否完成，并提前中止后续排序过程
	for (int i = start; i < end; ++i)
	{
		flag = 0;
		switch (rule)
		{
		case 1: for (int j = start; j < end; ++j) if (array[j] > array[j + 1]) { flag = 1; break; } break;
		case 2: for (int j = start; j < end; ++j) if (array[j] < array[j + 1]) { flag = 1; break; } break;
		}
		if (flag == 0) break;
		for (int j = end; j > i; --j)
		{
			switch (rule)
			{
			case 1: if (array[j - 1] > array[j]) Swap(array[j - 1], array[j]); break;
			case 2: if (array[j - 1] < array[j]) Swap(array[j - 1], array[j]); break;
			}
		}
	}
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BubbleSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	int flag = 0; //判断排序是否完成，并提前中止后续排序过程
	for (int i = start; i < end; ++i)
	{
		flag = 0;
		switch (rule)
		{
		case 1: for (int j = start; j < end; ++j) if (array[j] > array[j + 1]) { flag = 1; break; } break;
		case 2: for (int j = start; j < end; ++j) if (array[j] < array[j + 1]) { flag = 1; break; } break;
		}
		if (flag == 0) break;
		for (int j = end; j > i; --j)
		{
			switch (rule)
			{
			case 1: if (array[j - 1] > array[j]) Swap(array[j - 1], array[j]); break;
			case 2: if (array[j - 1] < array[j]) Swap(array[j - 1], array[j]); break;
			}
		}
	}
}

/**--------------------------------------------------------------------------*
Name:		    SelectSort
Discribe:		选择排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void SelectSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	switch (rule)
	{
	case 1:
		for (int i = 0; i != array.size() - 1; ++i)
			for (int j = i + 1; j != array.size(); ++j)
				if (array[j] < array[i]) Swap(array[j], array[i]);
		break;
	case 2:
		for (int i = 0; i != array.size() - 1; ++i)
			for (int j = i + 1; j != array.size(); ++j)
				if (array[j] > array[i]) Swap(array[j], array[i]);
		break;
	}
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void SelectSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	switch (rule)
	{
	case 1:
		for (int i = 0; i < len - 1; ++i)
			for (int j = i + 1; j < len; ++j)
				if (array[j] < array[i]) Swap(array[j], array[i]);
		break;
	case 2:
		for (int i = 0; i < len - 1; ++i)
			for (int j = i + 1; j < len; ++j)
				if (array[j] > array[i]) Swap(array[j], array[i]);
		break;
	}
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void SelectSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	switch (rule)
	{
	case 1:
		for (int i = 0; i < len - 1; ++i)
			for (int j = i + 1; j < len; ++j)
				if (array[j] < array[i]) Swap(array[j], array[i]);
		break;
	case 2:
		for (int i = 0; i < len - 1; ++i)
			for (int j = i + 1; j < len; ++j)
				if (array[j] > array[i]) Swap(array[j], array[i]);
		break;
	}
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void SelectSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	switch (rule)
	{
	case 1:
		for (int i = start; i < end; ++i)
			for (int j = i + 1; j < end + 1; ++j)
				if (array[j] < array[i]) Swap(array[j], array[i]);
		break;
	case 2:
		for (int i = start; i < end; ++i)
			for (int j = i + 1; j < end + 1; ++j)
				if (array[j] > array[i]) Swap(array[j], array[i]);
		break;
	}
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void SelectSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	switch (rule)
	{
	case 1:
		for (int i = start; i < end; ++i)
			for (int j = i + 1; j < end + 1; ++j)
				if (array[j] < array[i]) Swap(array[j], array[i]);
		break;
	case 2:
		for (int i = start; i < end; ++i)
			for (int j = i + 1; j < end + 1; ++j)
				if (array[j] > array[i]) Swap(array[j], array[i]);
		break;
	}
}

/**--------------------------------------------------------------------------*
Name:		    InsertSort
Discribe:		插入排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void InsertSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	switch (rule)
	{
	case 1:
		for (int i = 1; i != array.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] < array[j]) Swap(array[i], array[j]);
		break;
	case 2:
		for (int i = 1; i != array.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] > array[j]) Swap(array[i], array[j]);
		break;
	}
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void InsertSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	switch (rule)
	{
	case 1:
		for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] < array[j]) Swap(array[i], array[j]);
		break;
	case 2:
		for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] > array[j]) Swap(array[i], array[j]);
		break;
	}
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void InsertSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	switch (rule)
	{
	case 1:
		for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] < array[j]) Swap(array[i], array[j]);
		break;
	case 2:
		for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j)
				if (array[i] > array[j]) Swap(array[i], array[j]);
		break;
	}
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void InsertSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	switch (rule)
	{
	case 1:
		for (int i = start + 1; i < end + 1; ++i)
			for (int j = start; j < i; ++j)
				if (array[i] < array[j]) Swap(array[i], array[j]);
		break;
	case 2:
		for (int i = start + 1; i < end + 1; ++i)
			for (int j = start; j < i; ++j)
				if (array[i] > array[j]) Swap(array[i], array[j]);
		break;
	}
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void InsertSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	switch (rule)
	{
	case 1:
		for (int i = start + 1; i < end + 1; ++i)
			for (int j = start; j < i; ++j)
				if (array[i] < array[j]) Swap(array[i], array[j]);
		break;
	case 2:
		for (int i = start + 1; i < end + 1; ++i)
			for (int j = start; j < i; ++j)
				if (array[i] > array[j]) Swap(array[i], array[j]);
		break;
	}
}

/**--------------------------------------------------------------------------*
Name:		    ShellSort
Discribe:		希尔排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void ShellSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	switch(rule)
	{
	case 1:
		for(int flag = array.size() / 2; flag > 0; flag /= 2)
			for(int i = flag; i != array.size(); ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] > array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	case 2:
		for(int flag = array.size() / 2; flag > 0; flag /= 2)
			for(int i = flag; i != array.size(); ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] < array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	}
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void ShellSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	switch(rule)
	{
	case 1:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = flag; i < len; ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] > array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	case 2:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = flag; i < len; ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] < array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	}
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void ShellSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	switch(rule)
	{
	case 1:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = flag; i < len; ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] > array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	case 2:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = flag; i < len; ++i)
				for(int j = i - flag; j >= 0; j -= flag)
					if(array[j] < array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	}
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void ShellSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	switch(rule)
	{
	case 1:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = start + flag; i < end + 1; ++i)
				for(int j = i - flag; j >= start; j -= flag)
					if(array[j] > array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	case 2:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = start + flag; i < end + 1; ++i)
				for(int j = i - flag; j >= start; j -= flag)
					if(array[j] < array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	}
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void ShellSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	switch(rule)
	{
	case 1:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = start + flag; i < end + 1; ++i)
				for(int j = i - flag; j >= start; j -= flag)
					if(array[j] > array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	case 2:
		for(int flag = len / 2; flag > 0; flag /= 2)
			for(int i = start + flag; i < end + 1; ++i)
				for(int j = i - flag; j >= start; j -= flag)
					if(array[j] < array[j+flag]) Swap(array[j], array[j+flag]);
		break;
	}
}

/**--------------------------------------------------------------------------*
Name:		    QuickSort
Discribe:		快速排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void QuickSortCore(T &array, int begin, int end, const int &rule)
{
	switch(rule)
    {
    case 1:
        if(begin < end)
        {
            int i = begin + 1, j = end;
            while(i < j) if(array[i] > array[begin]) { Swap(array[i], array[j]); --j; } else ++i;
            if(array[i] >= array[begin]) --i;
            Swap(array[i], array[begin]);
            QuickSortCore(array, begin, i, rule);
            QuickSortCore(array, j, end, rule);
        }
        break;
    case 2:
        if(begin < end)
        {
            int i = begin + 1, j = end;
            while(i < j) if(array[i] < array[begin]) { Swap(array[i], array[j]); --j; } else ++i;
            if(array[i] <= array[begin]) --i;
            Swap(array[i], array[begin]);
            QuickSortCore(array, begin, i, rule);
            QuickSortCore(array, j, end, rule);
        }
        break;
    }
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void QuickSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	QuickSortCore(array, 0, array.size()-1, rule);
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void QuickSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	QuickSortCore(array, 0, len-1, rule);
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void QuickSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	QuickSortCore(array, 0, len-1, rule);
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void QuickSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	QuickSortCore(array, start, end, rule);
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void QuickSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	QuickSortCore(array, start, end, rule);
}

/**--------------------------------------------------------------------------*
Name:		    MergeSort
Discribe:		归并排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void MergeSortCore(T &array, T &ans, int start, int end, const int &rule)
{
	if (start == end) { ans[start] = array[start]; return; }
	int len = (end - start) / 2;
	MergeSortCore(ans, array, start, start + len, rule);
	MergeSortCore(ans, array, start + len + 1, end, rule);
	int i = start + len, j = end, index = end;
	while (i >= start && j >= start + len + 1)
	{
		switch (rule)
		{
		case 1:
			if (array[i] > array[j]) ans[index--] = array[i--];
			else ans[index--] = array[j--];
			break;
		case 2:
			if (array[i] < array[j]) ans[index--] = array[i--];
			else ans[index--] = array[j--];
			break;
		}
	}
	for (; i >= start; --i) ans[index--] = array[i];
	for (; j >= start + len + 1; --j) ans[index--] = array[j];
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void MergeSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	vector<int> ans = array;
	MergeSortCore(ans, array, 0, array.size() - 1, rule);
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void MergeSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	vector<int> ans(len, 0), array2(len, 0);
	for (int i = 0; i < len; ++i) { ans[i] = array[i]; array2[i] = ans[i];}
	MergeSortCore(ans, array2, 0, len - 1, rule);
	for (int i = 0; i < len; ++i) array[i] = array2[i];
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void MergeSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int *ans = new int[len]; int* array2 = new int[len];
	for (int i = 0; i < len; ++i) { ans[i] = array[i]; array2[i] = ans[i];}
	MergeSortCore(ans, array2, 0, len - 1, rule);
	for (int i = 0; i < len; ++i) array[i] = array2[i];
	delete[] ans; ans = nullptr; delete[] array2; array2 = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void MergeSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	vector<int> ans(len, 0), array2(len, 0);
	for (int i = 0; i < len; ++i) { ans[i] = array[i + start]; array2[i] = ans[i];}
	MergeSortCore(ans, array2, 0, len - 1, rule);
	for (int i = 0; i < len; ++i) array[i + start] = array2[i];
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void MergeSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int *ans = new int[len]; int *array2 = new int[len];
	for (int i = 0; i < len; ++i) { ans[i] = array[i + start]; array2[i] = ans[i];}
	MergeSortCore(ans, array2, 0, len - 1, rule);
	for (int i = 0; i < len; ++i) array[i + start] = array2[i];
	delete[] ans; ans = nullptr; delete[] array2; array2 = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    HeapSort
Discribe:		堆排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void HeapAdjust(T &array, int i, const int& len, const int &rule)
{
	switch(rule)
    {
    case 1:
        for(int nChild; (i << 1) + 1 < len; i = nChild)
        {
            nChild = (i << 1) + 1;
            if(nChild < len - 1 && array[nChild+1] > array[nChild]) ++nChild;
            if(array[i] < array[nChild]) Swap(array[i], array[nChild]);
            else break;
        }
        break;
    case 2:
        for(int nChild; (i << 1) + 1 < len; i = nChild)
        {
            nChild = (i << 1) + 1;
            if(nChild < len - 1 && array[nChild+1] < array[nChild]) ++nChild;
            if(array[i] > array[nChild]) Swap(array[i], array[nChild]);
            else break;
        }
        break;
    }
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void HeapSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	int i = 0, len = array.size();
    for(i = len / 2 - 1; i >= 0; --i) HeapAdjust(array, i, len, rule, 0);
    for(i = len - 1; i >0; --i)
    {
        Swap(array[0], array[i]);
        HeapAdjust(array, 0, i, rule, 0);
    }
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void HeapSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int i; vector<int> ans(len, 0);
	for (int i = 0; i < len; ++i) ans[i] = array[i];
    for(i = len / 2 - 1; i >= 0; --i) HeapAdjust(ans, i, len, rule, 0);
    for(i = len - 1; i >0; --i)
    {
        Swap(ans[0], ans[i]);
        HeapAdjust(ans, 0, i, rule, 0);
    }
	for (int i = 0; i < len; ++i) array[i] = ans[i];
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void HeapSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int i; int *ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
    for(i = len / 2 - 1; i >= 0; --i) HeapAdjust(ans, i, len, rule, 0);
    for(i = len - 1; i >0; --i)
    {
        Swap(ans[0], ans[i]);
        HeapAdjust(ans, 0, i, rule, 0);
    }
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void HeapSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	int i; vector<int> ans(len, 0);
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
    for(i = len / 2 - 1; i >= 0; --i) HeapAdjust(ans, i, len, rule, 0);
    for(i = len - 1; i >0; --i)
    {
        Swap(ans[0], ans[i]);
        HeapAdjust(ans, 0, i, rule, 0);
    }
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void HeapSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int i; int *ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
    for(i = len / 2 - 1; i >= 0; --i) HeapAdjust(ans, i, len, rule, 0);
    for(i = len - 1; i >0; --i)
    {
        Swap(ans[0], ans[i]);
        HeapAdjust(ans, 0, i, rule, 0);
    }
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    RadixSort
Discribe:		基数排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <cmath>
				#include <vector>
**---------------------------------------------------------------------------*/
int FindNum(const int &i, const int &number) //LSD获取数number的各位数字(i == 1为个位,i == 2为十位)
{
	return (number / (int) pow(10,(i-1))) % 10;
}
int MaxBits(int *ans, const int &len) //获取数组最大值的位数
{
    int Bits = 0, MAX = ans[0];
    for (int i = 1; i < len; ++i) if (MAX < ans[i]) MAX = ans[i];
    while (MAX > 0) { MAX = MAX / 10; ++Bits; }
    return Bits;
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void RadixSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	const int len = array.size();
	int Bit = MaxBits(array.data(), len); int *ans = new int[len]();
    switch(rule)
    {
    case 1:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < len; ++j)
                    if(FindNum(count, array[j]) == i)
						ans[k++] = array[j];
            for(int i = 0; i < len; ++i) array[i] = ans[i];
        }
        break;
    case 2:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 9; i >= 0; --i)
				for(int j = 0; j < len; ++j)
					if(FindNum(count, array[j]) == i)
						ans[k++] = array[j];
            for(int i = 0; i < len; ++i) array[i] = ans[i];
        }
        break;
    }
	delete[] ans; ans = nullptr;
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void RadixSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int *ans1 = new int[len](); int *ans2 = new int[len]();
	for (int i = 0; i < len; ++i) ans1[i] = array[i];
	int Bit = MaxBits(ans1, len);
    switch(rule)
    {
    case 1:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < len; ++j)
                    if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    case 2:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 9; i >= 0; --i)
				for(int j = 0; j < len; ++j)
					if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    }
	for (int i = 0; i < len; ++i) array[i] = ans1[i];
	delete[] ans1; ans1 = nullptr; delete[] ans2; ans2 = nullptr;
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void RadixSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int *ans1 = new int[len](); int *ans2 = new int[len]();
	for (int i = 0; i < len; ++i) ans1[i] = array[i];
	int Bit = MaxBits(ans1, len);
    switch(rule)
    {
    case 1:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < len; ++j)
                    if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    case 2:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 9; i >= 0; --i)
				for(int j = 0; j < len; ++j)
					if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    }
	for (int i = 0; i < len; ++i) array[i] = ans1[i];
	delete[] ans1; ans1 = nullptr; delete[] ans2; ans2 = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void RadixSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	int *ans1 = new int[len](); int *ans2 = new int[len]();
	for (int i = 0; i < len; ++i) ans1[i] = array[i+start];
	int Bit = MaxBits(ans1, len);
    switch(rule)
    {
    case 1:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < len; ++j)
                    if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    case 2:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 9; i >= 0; --i)
				for(int j = 0; j < len; ++j)
					if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    }
	for (int i = 0; i < len; ++i) array[i+start] = ans1[i];
	delete[] ans1; ans1 = nullptr; delete[] ans2; ans2 = nullptr;
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void RadixSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int *ans1 = new int[len](); int *ans2 = new int[len]();
	for (int i = 0; i < len; ++i) ans1[i] = array[i+start];
	int Bit = MaxBits(ans1, len);
    switch(rule)
    {
    case 1:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < len; ++j)
                    if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    case 2:
        for(int k = 0, count = 1; count <= Bit; ++count, k = 0)
        {
            for(int i = 9; i >= 0; --i)
				for(int j = 0; j < len; ++j)
					if(FindNum(count, ans1[j]) == i)
						ans2[k++] = ans1[j];
            for(int i = 0; i < len; ++i) ans1[i] = ans2[i];
        }
        break;
    }
	for (int i = 0; i < len; ++i) array[i+start] = ans1[i];
	delete[] ans1; ans1 = nullptr; delete[] ans2; ans2 = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    CountSort
Discribe:		计数排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void CountSortCore(T &array, const int &len, const int &rule)
{
	int max = array[0], min = array[0];
	for (int i = 1; i < len; ++i)
	{
		max = array[i] > max ? array[i] : max;
		min = array[i] < min ? array[i] : min;
	}
	int *C = new int[max - min + 1]();
	int *B = new int[len]();
	for (int i = 0; i < len; ++i) (C[array[i]-min])++;
	for (int i = 1; i < max - min + 1; ++i) C[i] += C[i - 1];
	for (int i = len; i > 0; --i)
	{
		B[C[array[i - 1] - min] - 1] = array[i - 1];
		C[array[i - 1] - min]--;
	}
	switch (rule)
	{
	case 1: for (int i = 0; i < len; ++i) array[i] = B[i]; break;
	case 2: for (int i = 0; i < len; ++i) array[len - 1 - i] = B[i]; break;
	}
	delete[] C; C = nullptr; delete[] B; B = nullptr;
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void CountSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	CountSortCore(array, array.size(), rule);
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void CountSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	CountSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void CountSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	CountSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void CountSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	CountSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void CountSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	CountSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    BucketSort
Discribe:		桶排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void BucketSortCore(T &array, const int &len, const int &rule)
{
	int max = array[0], min = array[0];
	for (int i = 1; i < len; ++i)
	{
		max = array[i] > max ? array[i] : max;
		min = array[i] < min ? array[i] : min;
	}
	int *C = new int[max - min + 1]();
	int *B = new int[len]();
	for (int i = 0; i < len; ++i) (C[array[i]-min])++;
	for (int i = 0, k = 0; i < max - min + 1; ++i) for (int j = 1; j <= C[i]; ++j) B[k++] = i + min;
	switch (rule)
	{
	case 1: for (int i = 0; i < len; ++i) array[i] = B[i]; break;
	case 2: for (int i = 0; i < len; ++i) array[len - 1 - i] = B[i]; break;
	}
	delete[] C; C = nullptr; delete[] B; B = nullptr;
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BucketSort(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	BucketSortCore(array, array.size(), rule);
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BucketSort(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	BucketSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BucketSort(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	BucketSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BucketSort(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	BucketSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BucketSort(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	BucketSortCore(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    BucketSort2
Discribe:		桶排序2
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
int BucketSizeMap(const int &min, const int &max, const int &len) { return (max - min + 1 < len) ? max - min + 1 : len + 1; }
template <typename T> void BucketSortCore2(T &array, const int &len, const int &rule)
{
	int max = array[0], min = array[0];
	for (int i = 1; i < len; ++i)
	{
		max = array[i] > max ? array[i] : max;
		min = array[i] < min ? array[i] : min;
	}
	const int BucketSize = BucketSizeMap(min, max, len);
	vector<vector<int>> Bucket(BucketSize);
	int *B = new int[len]();
	for (int i = 0; i < len; ++i) B[i] = array[i];
	if (BucketSize == max - min + 1)
	{
		for (int i = 0; i < len; ++i) Bucket[B[i]-min].push_back(B[i]);
		for (int i = 0, k = 0; i < max - min + 1; ++i) for (int j = 0; j != Bucket[i].size(); ++j) B[k++] = i + min;
	}
	else // 初始化桶的个数BucketSize == len， 需要分配区间
	{
		const int sect = (max - min + 1) / len;
		for (int i = 0; i < len; ++i) Bucket[(B[i] - min) / sect].push_back(B[i]);
		//调用归并排序对每一个桶内元素进行排序
		for (int i = 0; i < BucketSize; ++i) MergeSort(Bucket[i], 1);
		for (int i = 0, k = 0; i < BucketSize; ++i)
			for (int j = 0; j != Bucket[i].size(); ++j)
				B[k++] = Bucket[i][j];
	}
	switch (rule)
	{
	case 1: for (int i = 0; i < len; ++i) array[i] = B[i]; break;
	case 2: for (int i = 0; i < len; ++i) array[len - 1 - i] = B[i]; break;
	}
	delete[] B; B = nullptr;
}
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BucketSort2(vector<int> &array, const int &rule)
{
	if (array.empty()) return;
	BucketSortCore2(array, array.size(), rule);
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BucketSort2(vector<int> &array, const int &len, const int &rule)
{
	if (array.empty() || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	BucketSortCore2(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BucketSort2(int *array, const int &len, const int &rule)
{
	if (array == nullptr || len == 0) return;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i];
	BucketSortCore2(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BucketSort2(vector<int> &array, const int &start, const int &end, const int &rule)
{
	if (array.empty() || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	BucketSortCore2(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BucketSort2(int *array, const int &start, const int &end, const int &rule)
{
	if (array == nullptr || start > end) return;
	const int len = end - start + 1;
	int* ans = new int[len];
	for (int i = 0; i < len; ++i) ans[i] = array[i+start];
	BucketSortCore2(ans, len, rule);
	for (int i = 0; i < len; ++i) array[i+start] = ans[i];
	delete[] ans; ans = nullptr;
}

/**--------------------------------------------------------------------------*
Name:		    generateList
Discribe:		生成一个单向链表
Parameter:      array(数组), len(链表长度), start, end(原数组区间，起始为0)
Return:		    ListNode* (链表头结点)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
/* struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
}; */
//重载1   Input : vector<int>类型数组对象  【整个数组转化成单链表】
ListNode* generateList(vector<int> &array)
{
	ListNode *head = new ListNode(0);
	ListNode *pHead = head;
	for (int i = 0; i != array.size(); ++i)
	{
		ListNode *pNode = new ListNode(array[i]);
		pHead->next = pNode;
		pHead = pHead->next;
	}
	return head->next;
}
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组生成单向链表】
ListNode* generateList(vector<int> &array, const int &len)
{
	if (array.empty() || len == 0) return nullptr;
	ListNode *head = new ListNode(0);
	ListNode *pHead = head;
	for (int i = 0; i != len; ++i)
	{
		ListNode *pNode = new ListNode(array[i]);
		pHead->next = pNode;
		pHead = pHead->next;
	}
	return head->next;
}
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组生成单向链表】
ListNode* generateList(int *array, const int &len)
{
	if (array == nullptr || len == 0) return nullptr;
	ListNode *head = new ListNode(0);
	ListNode *pHead = head;
	for (int i = 0; i != len; ++i)
	{
		ListNode *pNode = new ListNode(array[i]);
		pHead->next = pNode;
		pHead = pHead->next;
	}
	return head->next;
}
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组生成单向链表】
ListNode* generateList(vector<int> &array, const int &start, const int &end)
{
	if (array.empty() || start > end) return nullptr;
	ListNode *head = new ListNode(0);
	ListNode *pHead = head;
	for (int i = start; i <= end; ++i)
	{
		ListNode *pNode = new ListNode(array[i]);
		pHead->next = pNode;
		pHead = pHead->next;
	}
	return head->next;
}
//重载5   Input : C数组指针  【对区间[start, end]内子数组生成单向链表】
ListNode* generateList(int *array, const int &start, const int &end)
{
	if (array == nullptr || start > end) return nullptr;
	ListNode *head = new ListNode(0);
	ListNode *pHead = head;
	for (int i = start; i <= end; ++i)
	{
		ListNode *pNode = new ListNode(array[i]);
		pHead->next = pNode;
		pHead = pHead->next;
	}
	return head->next;
}

/**--------------------------------------------------------------------------*
Name:		    printList
Discribe:		打印链表
Parameter:      pHead(头结点)
**---------------------------------------------------------------------------*/
void printList(ListNode *pHead)
{
	if (pHead == nullptr) return;
	ListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->val << "\t";
		pNode = pNode->next;
	}
}

/**--------------------------------------------------------------------------*
Name:		    destroyList
Discribe:		删除链表
Parameter:      pHead(头结点)
**---------------------------------------------------------------------------*/
void destroyList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}

/**--------------------------------------------------------------------------*
Name:		    addListNode
Discribe:		添加结点到链表的指定位置
Parameter:      pHead(原链表头结点), pos(链表结点位置索引，头结点为0), pNode(链表结点), val(待添加结点值)
**---------------------------------------------------------------------------*/
//重载1   Input : 链表头结点、链表结点位置索引  【在原链表pos位置索引前添加值为val的结点】
void addListNode(ListNode **pHead, int pos, const int &val)
{
	if (pos <= 0)
	{
		ListNode *pNode = new ListNode(val);
		pNode->next = *pHead;
		*pHead = pNode;
		return;
	}
	ListNode *pNext = *pHead;
	while (pNext->next && pos-- != 0) pNext = pNext->next;
	if (pNext->next == nullptr && pos != 0) pNext->next = new ListNode(val);
	else {
		ListNode *pCur = new ListNode(val);
		pCur->next = pNext->next;
		pNext->next = pCur;
		int value = pNext->val;
		pNext->val = pCur->val;
		pCur->val = value;
	}
}
//重载2   Input : 链表头结点、链表结点  【在原链表pNode结点前添加值为val的结点】
void addListNode(ListNode **pHead, ListNode *Node, const int &val)
{
	if (*pHead == Node)
	{
		ListNode *pNode = new ListNode(val);
		pNode->next = *pHead;
		*pHead = pNode;
		return;
	}
	ListNode *pNext = *pHead;
	while (pNext->next && pNext != Node) pNext = pNext->next;
	if (pNext->next == nullptr && pNext != Node) pNext->next = new ListNode(val);
	else {
		ListNode *pCur = new ListNode(val);
		pCur->next = pNext->next;
		pNext->next = pCur;
		int value = pNext->val;
		pNext->val = pCur->val;
		pCur->val = value;
	}
}

/**--------------------------------------------------------------------------*
Name:		    removeListNode
Discribe:		删除链表指定位置下的结点
Parameter:      pHead(原链表头结点), pos(链表结点位置索引，头结点为0), pNode(链表结点)
**---------------------------------------------------------------------------*/
//重载1   Input : 链表头结点、链表结点位置索引  【删除原链表pos位置索引下的结点】
void removeListNode(ListNode **pHead, int pos)
{
	if (pos <= 0)
	{
		ListNode *pNode = *pHead;
		*pHead = (*pHead)->next;
		delete pNode; pNode = nullptr;
		return;
	}
	ListNode *pNode = *pHead;
	ListNode *pNext = pNode->next;
	while (pNext->next && --pos != 0) { pNode = pNext; pNext = pNode->next; }
	if (pNext->next == nullptr) { pNode->next = nullptr; delete pNext; pNext = nullptr; }
	else {
		pNode->next = pNext->next;
		delete pNext; pNext = nullptr;
	}
}
//重载2   Input : 链表头结点、链表结点  【删除原链表pNode结点】
void removeListNode(ListNode **pHead, ListNode *Node)
{
	if (*pHead == Node)
	{
		ListNode *pNode = *pHead;
		*pHead = (*pHead)->next;
		delete pNode; pNode = nullptr;
		return;
	}
	ListNode *pNode = *pHead;
	ListNode *pNext = pNode->next;
	while (pNext->next && pNext != Node) { pNode = pNext; pNext = pNode->next; }
	if (pNext->next == nullptr) { pNode->next = nullptr; delete pNext; pNext = nullptr; }
	else {
		pNode->next = pNext->next;
		delete pNext; pNext = nullptr;
	}
}







