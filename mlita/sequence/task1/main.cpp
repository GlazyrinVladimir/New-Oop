/*10.12.Последовательность(6)

Имеется последовательность целых чисел x1, x2, …, xn.Найти количество троек чисел, в каждой

из которых одно из чисел равно сумме двух других.

Ввод из файла INPUT.TXT.В первой строке содержится значение n(3 ≤ n ≤ 2000).Во второй

строке заданы через пробел значения x1, x2, …, xn(1  xi  105).

Вывод в файл OUTPUT.TXT.В единственной строке выводится количество указанных троек

чисел(xi, xj, xk).
*/

#include "stdafx.h"
#include "Sequence.h"
#include <ctime>  

using namespace std;

int main()
{
	CSequence seq;

	if (seq.ReadSequence("test5.txt"))
	{
		seq.CalculationSequence();
		cout << seq.GetCount() << endl;
	}
	else
	{
		cout << "error input file";
	}
	cout << "runtime = " << clock() / 1000.0 << endl;
	return 0;
}

