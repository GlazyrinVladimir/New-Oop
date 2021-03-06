﻿/*13.10.Абракадабра(9)
Строка s называется супрефиксом для строки t, если t начинается с s и заканчивается на s.
Например, «abra» является супрефиксом для строки «abracadabra».В частности, сама строка t
является своим супрефиксом.Супрефиксы играют важную роль в различных алгоритмах на
строках.
В этой задаче требуется решить обратную задачу поиска.Задан словарь, содержащий n слов t1,
t2, …, tn и набор из m строк - образцов s1, s2, …, sm.Необходимо для каждой строки - образца из
заданного набора найти количество слов в словаре, для которых эта строка - образец является
супрефиксом.
14
Ввод.Первая строка входного файла содержит целое число n(1 ≤ n ≤ 200 000).Последующие n
строк содержат слова t1, t2, …, tn, по одному слову в каждой строке.Каждое слово состоит из
строчных букв латинского алфавита.Длина каждого слова не превышает 50. Суммарная длина
всех слов не превышает 106
.Словарь не содержит пустых слов.Затем следует строка, содержащая
целое число m(1 ≤ m ≤ 200 000).Последующие m строк содержат строки - образцы s1, s2, …, sm, по
одной на каждой строке.Каждая строка - образец состоит из строчных букв латинского алфавита :
Длина каждой строки - образца не превышает 50. Суммарная длина всех строк - образцов не
превышает 106
.Никакая строка - образец не является пустой строкой.
Вывод.Выходной файл должен содержать m чисел, по одному на строке.Для каждой строки -
образца в порядке, в котором они заданы во входном файле, следует вывести количество слов
словаря, для которых она является супрефиксом.*/

#include "stdafx.h"
#include "Abracadabra.h"

using namespace std;

int _tmain()
{
	CSuprefixCheck suprefix;
	if (suprefix.ReadWordsAndSuprefix("test6.txt"))
	{
		suprefix.CountNumberOfSuprefixWords();
		suprefix.WriteNumberOfSuprefix();
	}
	else
	{
		cout << "error input file";
	}
	return 0;
}

