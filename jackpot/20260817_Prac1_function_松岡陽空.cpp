#include <iostream>
using namespace std;

#include "20260817_Prac1_header_松岡陽空.h"

void PitingType(int piting)//球種
{

	switch (piting)//球種宣言
	{
	case 0:
		cout << "ストレートを投げました" << endl;
		break;
	case 1:
		cout << "カーブを投げました" << endl;
		break;
	case 2:
		cout << "スライダーを投げました" << endl;
		break;
	case 3:
		cout << "シンカーを投げました" << endl;
		break;

	}
}


void Result(int out)//結果、勝敗
{
	if (out >= 3)//アウト3つ
	{
		cout << "PLAYER WINNER!!" << endl;
	}
	else
	{
		cout << "CPU WINNER!!" << endl;
	}
}