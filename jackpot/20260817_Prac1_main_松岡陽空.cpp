#include <iostream>
#include <cstdlib>//ランダム
#include <ctime>//毎度繰り返す
#include "20260817_Prac1_header_松岡陽空.h"//ヘッダーを持ってくる

using namespace std;

//定数
const int PITING_MIN = 0;//球種数字の最小
const int PITING_MAX = 3;//球種数字の最大
const int PROBABILITY = 4;//確率
const int STRIKE_COUNT = 3;//ストライクカウント
const int BALL_COUNT = 4;//ボールカウント
const int OUT_COUNT = 3;//アウトカウント
const int HIT_COUNT = 4;//ヒットカウント

int main(void)//メイン
{
    int ply, emy;//プレイヤー、敵
    int prod;//確率
    int Strike = 0;//ストライク
    int Ball = 0;//ボール
    int Out = 0;//アウト
    int Hit = 0;//ヒット

    srand((unsigned int)time(NULL));//乱数初期化

    //ゲーム説明
    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    //球種の宣言と入力チェック
    while (Out < OUT_COUNT && Hit < HIT_COUNT)
    {
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート "
            << "1:カーブ "
            << "2:スライダー "
            << "3:シンカー"
            << endl;

        while (true)//入力チェック
        {
            cin >> ply;//入力

            if (PITING_MIN > ply || PITING_MAX < ply)//球種に定められた数字より下か、上の数字の場合
            {
                cout << "入力に誤りがあります。"
                    << "再度入力してください。"
                    << endl;
            }
            else
            {
                break;
            }
        }


        PitingType(ply);//プレイヤーの球種


        emy = rand() % PROBABILITY;//敵のランダム


        prod = rand() % PROBABILITY;//ランダム

        if (ply != emy)//プレイヤーと敵の数字が違う場合
        {
            if (prod == 0)//4/1でボールor4/3でストライク
            {
                cout << "ボール！" << endl;
                Ball++;//ボールカウント
            }
            else
            {
                cout << "ストライク！！" << endl;
                Strike++;//ストライクカウント
            }
        }

        else
        {
            Strike = 0;//初期化
            Ball = 0;//初期化

            if (prod == 1)//4/1の確率でアウト、4/3の確率でヒット
            {
                cout << "OUT!!!" << endl;
                Out++;//アウト
            }
            else
            {
                cout << "HIT!!" << endl;
                Hit++;//ヒット
            }
        }

        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)//ストライクカウントかボールカウントがたまり切ったらアウト、ヒット
        {
            if (Strike >= STRIKE_COUNT)
            {
                Out++;//アウトカウント
            }
            else
            {
                Hit++;//ヒットカウント
            }

            Strike = 0;
            Ball = 0;
        }

        cout << "B:" << Ball << endl;
        cout << "S:" << Strike << endl;
        cout << "O:" << Out << endl;
        cout << "Runner:" << Hit << endl;

    }


    Result(Out);//結果

    return 0;
}