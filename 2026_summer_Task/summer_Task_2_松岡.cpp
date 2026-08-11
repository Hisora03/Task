#include <iostream>
#include <cstdlib>　　//ランダム
#include <ctime>　　　

using namespace std;  

int main()          //メイン
{
    int player;    //プレイヤーの手
    int cpu;       //敵の手
    int result;    //結果
    int i;         
    int win = 0;   //勝利数
    int lose = 0;  //敗北数
    int draw = 0;  //引き分け数

    srand((unsigned int)time(nullptr));   //乱数初期化

    cout << "じゃんけんゲームを開始します。" << endl;

    for (i = 0; i < 5; i++)  //５回勝負
    {
        cout << endl;
        cout << "-------- " << i + 1 << "回戦 --------" << endl;    //回数表示

        while (true)    //ゲームループ
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;

            cin >> player;   //プレイヤー入力

            if (player >= 0 && player <= 2)   //入力が誤ってる場合
            {
                break;
            }

            cout << "入力に誤りがあります。再入力してください。" << endl;
        }

        cpu = rand() % 3;   //CPUの手をランダムで決定

        switch (player)  //手の表記
        {
        case 0:
            cout << "PLAYER：グー" << endl;   //グー
            break;

        case 1:
            cout << "PLAYER：チョキ" << endl;  //チョキ
            break;

        case 2:
            cout << "PLAYER：パー" << endl;    //パー
            break;
        }


        switch (cpu)  //CPUの手の表示
        {
        case 0:
            cout << "CPU：グー" << endl;  //グー
            break;

        case 1:
            cout << "CPU：チョキ" << endl; //チョキ
            break;

        case 2:
            cout << "CPU：パー" << endl;  //パー
            break;
        }


        result = player - cpu;    //結果＝プレイヤーの手-CPUの手

        if (result == -1 || result == 2)  //プレイヤーが勝つ
        {
            cout << "PLAYER WIN!" << endl;
            win++;
        }
        else if (result == 0)   //引き分け
        {
            cout << "DRAW" << endl;
            draw++;
        }
        else                   //CPUが勝つ
        {
            cout << "CPU WIN!" << endl;
            lose++;
        }
    }


    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    cout << win << "勝 "     //勝敗表示
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;

    return 0;
}