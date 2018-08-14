/*****************************************************************************
** File Name:        Intelligent algorithm library(IAL)
** Author:           SiQi_Wang
** Date:             2018/04/26
** Version:          1.0.1
** Description:      智能算法函数库
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           		NAME             				DESCRIPTION          *
** 2018/04/24     		SiQi_Wang                       Create               *
** --------------------------------------------------------------------------*
******************************************************************************
**                         Important Edit Update                             *
** --------------------------------------------------------------------------*
** DATE           		NAME             				DESCRIPTION          *
** 2018/04/26     		SiQi_Wang                       Create               *
** --------------------------------------------------------------------------*
** 1）新增自主设计的递归桶排序算法实现
** 2) 提高部分排序算法鲁棒性
******************************************************************************
** Copyright(c) 2018, SiQi_Wang
** All rights reserved.
** Distributed under the BSD license.
** (See accompanying file LICENSE.txt at https://LICENSE.txt)
******************************************************************************/
#pragma once
/*---------------------------------------------------------------------------*
**                              Include Files                                *
**---------------------------------------------------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
using namespace std;
/*---------------------------------------------------------------------------*
**                         Function Statement                                *
**---------------------------------------------------------------------------*/
/**--------------------------------------------------------------------------*
Name:		    Swap
Discribe:		数据交换
Parameter:      a, b (待交换数据)
**---------------------------------------------------------------------------*/
template <typename T> void Swap(T &a, T &b);

/**--------------------------------------------------------------------------*
Name:		    isDigit
Discribe:		数字判断
Parameter:      ch (字符)
Return:		    bool : true(是数字), false(不是数字)
**---------------------------------------------------------------------------*/
bool isDigit(char &ch);

/**--------------------------------------------------------------------------*
Name:		    gcd
Discribe:		最大公约数
Parameter:      num1, num2
Return:		    int (最大公约数)
**---------------------------------------------------------------------------*/
int gcd(int &num1, int &num2);

/**--------------------------------------------------------------------------*
Name:		    SwapStr
Discribe:		字符串反转 (整串&子串)
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Header:         #include <string>
				#include <cstring>
**---------------------------------------------------------------------------*/
//重载1   Input : string类字符串 【整串反转】
void SwapStr(string &str);
//重载2   Input : C字符数组指针 【整串反转】
void SwapStr(char *str);
//重载3   Input : string类字符串 【长度len子串反转】
void SwapStr(string &str, const int &len);
//重载4   Input : C字符数组指针 【长度len子串反转】
void SwapStr(char *str, const int &len);
//重载5   Input : string类字符串, 下标索引范围[start, end]， 【(str[start], str[end])子串反转】
void SwapStr(string &str, const int &start, const int &end);
//重载6   Input : C字符数组指针, 下标索引范围[start, end]， 【(str[start], str[end])子串反转】
void SwapStr(char *str, const int &start, const int &end);

/**--------------------------------------------------------------------------*
Name:		    isPalindrome
Discribe:		回文判断 (整串&子串)
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Return:		    bool : true(是回文), false(不是回文)
Header:         #include <string>
				#include <cstring>
**---------------------------------------------------------------------------*/
bool isPalindromeCore(const char *start, const char *end);
//重载1   Input : string类字符串 【整串回文判断】
bool isPalindrome(const string &str);
//重载2   Input : C字符数组指针 【整串回文判断】
bool isPalindrome(const char *str);
//重载3   Input : string类字符串 【长度len子串回文判断】
bool isPalindrome(const string &str, const int &len);
//重载4   Input : C字符数组指针 【长度len子串回文判断】
bool isPalindrome(const char *str, const int &len);
//重载5   Input : string类字符串 【(str[start], str[end])子串回文判断】
bool isPalindrome(const string &str, const int &start, const int &end);
//重载6   Input : C字符数组指针 【(str[start], str[end])子串回文判断】
bool isPalindrome(const char *str, const int &start, const int &end);

/**--------------------------------------------------------------------------*
Name:		    Permutation
Discribe:		全排列（返回整串&子串的全排列及排列总数）
Parameter:      str(字符串), len(子串长), start, end(下标索引,从0开始)
Return:		    permuPair : permuPair.array(排列), permuPair.count(排列数)
Header:         #include <string>
				#include <cstring>
				#include <vector>
**---------------------------------------------------------------------------*/
struct permuPair
{
	vector<string> array;
	int count = 0;
};
void PermutationCore(char *pStr, char *pBegin, permuPair &res);
//重载1   Input : string类字符串 【整串排列】
permuPair Permutation(const string &str);
//重载2   Input : C字符数组指针 【整串排列】
permuPair Permutation(const char *str);
//重载3   Input : string类字符串 【长度len子串全排列】
permuPair Permutation(const string &str, const int &len);
//重载4   Input : C字符数组指针 【长度len子串全排列】
permuPair Permutation(const char *str, const int &len);
//重载5   Input : string类字符串 【(str[start], str[end])子串全排列】
permuPair Permutation(const string &str, const int &start, const int &end);
//重载6   Input : C字符数组指针 【(str[start], str[end])子串全排列】
permuPair Permutation(const char *str, const int &start, const int &end);

/**--------------------------------------------------------------------------*
Name:		    Combination & CombinationN
Discribe:		全组合（返回整串&子串的全组合、字符全组合及组合总数）
Parameter:      str(字符串), len(子串长), n(组合串长), start, end(下标索引,从0开始)
Return:		    combPair : combPair.array(组合), combPair.count(组合数)
Header:         #include <string>
				#include <cstring>
				#include <vector>
**---------------------------------------------------------------------------*/
struct combPair
{
	vector<vector<char>> array;
	int count = 0;
};
void CombinationCore(char *pStr, int number, vector<char> &ans, combPair &result);
//重载1   Input : string类字符串 【整串全组合】
combPair Combination(const string &str);
//重载2   Input : C字符数组指针 【整串全组合】
combPair Combination(const char *str);
//重载3   Input : string类字符串 【前len个字符的全组合】
combPair Combination(const string &str, const int &len);
//重载4   Input : C字符数组指针 【前len个字符的全组合】
combPair Combination(const char *str, const int &len);
//重载5   Input : string类字符串 【(str[start], str[end])子串全组合】
combPair Combination(const string &str, const int &start, const int &end);
//重载6   Input : C字符数组指针 【(str[start], str[end])子串全组合】
combPair Combination(const char *str, const int &start, const int &end);

//重载1   Input : string类字符串, 组合字符数n  【整串n字符组合】
combPair CombinationN(const string &str, const int &n);
//重载2   Input : C字符数组指针, 组合字符数n  【整串n字符组合】
combPair CombinationN(const char *str, const int &n);
//重载3   Input : string类字符串, 组合字符数n 【长度len子串n字符组合】
combPair CombinationN(const string &str, const int &len, const int &n);
//重载4   Input : C字符数组指针, 组合字符数n 【长度len子串n字符组合】
combPair CombinationN(const char *str, const int &len, const int &n);
//重载5   Input : string类字符串, 组合字符数n 【(str[start], str[end])子串n字符组合】
combPair CombinationN(const string &str, const int &start, const int &end, const int &n);
//重载6   Input : C字符数组指针, 组合字符数n 【(str[start], str[end])子串n字符组合】
combPair CombinationN(const char *str, const int &start, const int &end, const int &n);

/**--------------------------------------------------------------------------*
Name:		    BubbleSort
Discribe:		冒泡排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BubbleSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BubbleSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BubbleSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BubbleSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BubbleSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    SelectSort
Discribe:		选择排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void SelectSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void SelectSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void SelectSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void SelectSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void SelectSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    InsertSort
Discribe:		插入排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void InsertSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void InsertSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void InsertSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void InsertSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void InsertSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    ShellSort
Discribe:		希尔排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void ShellSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void ShellSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void ShellSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void ShellSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void ShellSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    QuickSort
Discribe:		快速排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void QuickSortCore(T &array, int begin, int end, const int &rule);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void QuickSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void QuickSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void QuickSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void QuickSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void QuickSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    MergeSort
Discribe:		归并排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void MergeSortCore(T &array, T &ans, int start, int end, const int &rule);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void MergeSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void MergeSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void MergeSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void MergeSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void MergeSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    HeapSort
Discribe:		堆排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void HeapAdjust(T &array, int i, const int& len, const int &rule, const int& flag);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void HeapSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void HeapSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void HeapSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void HeapSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void HeapSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    RadixSort
Discribe:		基数排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <cmath>
				#include <vector>
**---------------------------------------------------------------------------*/
int FindNum(const int &i, const int &number); //LSD获取数number的各位数字(i == 1为个位,i == 2为十位)
int MaxBits(int *ans, const int &len); //获取数组最大值的位数
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void RadixSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void RadixSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void RadixSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void RadixSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void RadixSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    CountSort
Discribe:		计数排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void CountSortCore(T &array, const int &len, const int &rule);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void CountSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void CountSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void CountSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void CountSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void CountSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    BucketSort
Discribe:		桶排序
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
template <typename T> void BucketSortCore(T &array, const int &len, const int &rule);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BucketSort(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BucketSort(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BucketSort(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BucketSort(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BucketSort(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    BucketSort2
Discribe:		桶排序2
Parameter:      array(数组), len(排序长度), start, end(排序区间，起始为0), rule(排序规则 1-升序 2-降序)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
int BucketSizeMap(const int &min, const int &max, const int &len);
template <typename T> void BucketSortCore2(T &array, const int &len, const int &rule);
//重载1   Input : vector<int>类型数组对象  【整个数组排序】
void BucketSort2(vector<int> &array, const int &rule);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组进行排序】
void BucketSort2(vector<int> &array, const int &len, const int &rule);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组进行排序】
void BucketSort2(int *array, const int &len, const int &rule);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组进行排序】
void BucketSort2(vector<int> &array, const int &start, const int &end, const int &rule);
//重载5   Input : C数组指针  【对区间[start, end]内子数组进行排序】
void BucketSort2(int *array, const int &start, const int &end, const int &rule);

/**--------------------------------------------------------------------------*
Name:		    generateList
Discribe:		生成一个单向链表 
Parameter:      array(数组), len(链表长度), start, end(原数组区间，起始为0)
Return:		    ListNode* (链表头结点)
Header:         #include <vector>
**---------------------------------------------------------------------------*/
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//重载1   Input : vector<int>类型数组对象  【整个数组转化成单链表】
ListNode* generateList(vector<int> &array);
//重载2   Input : vector<int>类型数组对象  【对从0开始长度为len的的子数组生成单向链表】
ListNode* generateList(vector<int> &array, const int &len);
//重载3   Input : C数组指针  【对从0开始长度为len的的子数组生成单向链表】
ListNode* generateList(int *array, const int &len);
//重载4   Input : vector<int>类型数组对象  【对区间[start, end]内子数组生成单向链表】
ListNode* generateList(vector<int> &array, const int &start, const int &end);
//重载5   Input : C数组指针  【对区间[start, end]内子数组生成单向链表】
ListNode* generateList(int *array, const int &start, const int &end);

/**--------------------------------------------------------------------------*
Name:		    printList
Discribe:		打印链表 
Parameter:      pHead(头结点)
**---------------------------------------------------------------------------*/
void printList(ListNode *pHead);

/**--------------------------------------------------------------------------*
Name:		    destroyList
Discribe:		删除链表 
Parameter:      pHead(头结点)
**---------------------------------------------------------------------------*/
void destroyList(ListNode *pHead);

/**--------------------------------------------------------------------------*
Name:		    addListNode
Discribe:		添加结点到链表的指定位置
Parameter:      pHead(原链表头结点), pos(链表结点位置索引，头结点为0), pNode(链表结点), val(待添加结点值)
**---------------------------------------------------------------------------*/
//重载1   Input : 链表头结点、链表结点位置索引  【在原链表pos位置索引前添加值为val的结点】
void addListNode(ListNode **pHead, int pos, const int &val);
//重载2   Input : 链表头结点、链表结点  【在原链表pNode结点前添加值为val的结点】
void addListNode(ListNode **pHead, ListNode *Node, const int &val);

/**--------------------------------------------------------------------------*
Name:		    removeListNode
Discribe:		删除链表指定位置下的结点
Parameter:      pHead(原链表头结点), pos(链表结点位置索引，头结点为0), pNode(链表结点)
**---------------------------------------------------------------------------*/
//重载1   Input : 链表头结点、链表结点位置索引  【删除原链表pos位置索引下的结点】
void removeListNode(ListNode **pHead, int pos);
//重载2   Input : 链表头结点、链表结点  【删除原链表pNode结点】
void removeListNode(ListNode **pHead, ListNode *Node);

