#include <iostream>   
#include <cstdlib>    //ランダム
#include <ctime>　　　//毎回打つたびに変える

using namespace std;

int main()　　　　　　//メイン関数
{
    int answer = -1;  //答え-１
    int question;     //正解
    int count = 0;    //カウント    

    srand((unsigned int)time(nullptr));　　//ランダム初期化

    question = rand() % 101;    //ランダム１～１００

    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    while (question != answer)　　　//正解と違ったら
    {
        count++;　　//カウント

        while (true)　　　//ループ無限
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;　　　//入力

            if (answer < 0 || answer > 100)　　　//入力チェック（０以下、１００以上の場合)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }

        if (question > answer)　　//正解が入力された数より大きい場合
        {
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)　　//小さい場合
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }

    cout << endl;
    //結果
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}