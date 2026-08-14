#include<iostream>
#include<cstdlib>  //ランダム
#include<ctime>
using namespace std;

int main(void)     //メイン
{
	const int CARD = 3;   //選択するカードの枚数
	const int CARD_NUMBER = 10;   //カードの数字の範囲

	int i, hit = 0;  //変数、ヒット数
	int playerCard[CARD];  //プレイヤーのカード
	int enemyCard[CARD];   //敵のカード
	int plyChoice[CARD];   //プレイヤーの選択するカード
	int emyChoice[CARD];   //敵の選択するカード

	bool trunFlag = true;  //ターンのフラグ
	bool judgementFlag = false;  //勝敗のフラグ

	srand((unsigned int)time(NULL));  //乱数初期化

	for (i = 0; i < CARD; i++)  //カードの数字がランダムで決まるループ
	{
		playerCard[i] = rand() % CARD_NUMBER;  //プレイヤーのカードの数字がランダムで決まる
		enemyCard[i] = rand() % CARD_NUMBER;   //敵のカードの数字がランダムで決まる
	}
	//ゲームの説明
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";

	for (i = 0; i < CARD; i++)  //プレイヤーのカードの数字を表示するループ
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";  //プレイヤーのカードの数字を表示
	}
	//ゲームスタート
	cout << "===================   GAME STRAT   ============================" << "\n";

	while (true)   //ゲームループ
	{

		if (trunFlag)  //プレーヤーターン
		{

			hit = 0;  //ヒット数の初期化
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";
			for (i = 0; i < CARD; i++)  //プレーヤーの入力ループ
			{
				while (true)  //入力チェックループ
				{
					cin >> plyChoice[i];  //入力したらチェック
					if (0 > plyChoice[i] || 9 < plyChoice[i])  //入力が0以下9以上の範囲外の場合	
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else
					{
						break;
					}

				}
			}


			for (i = 0; i < CARD; i++)		//ヒット数の判定ループ
			{
				if (plyChoice[i] == enemyCard[i])  //ヒット判定プレイヤーchoiceと敵のカードが同じ
				{
					cout << "Hit,";  //ヒットを表示
					hit++;  //カウント
				}
				else
				{
					cout << "Blow,";  //またはブロー
				}
			}
			cout << "\n";  //表示
			if (hit == 3)  //ヒット数３回
			{
				cout << "3Hit!!\n";  //ヒット3回の表示
				judgementFlag = true;  //勝敗のフラグをtrueへ
				break;
			}

			cout << "\n";
			trunFlag = false;    //ターンフラグをfalseへ
		}
		else
		{
			hit = 0;  //ヒット数の初期化

			cout << "ENEMY TRUN \n";  //エネミーターン表示
			for (i = 0; i < CARD; i++)  //敵の選択するカードの数字をランダムで決めるループ
			{
				emyChoice[i] = rand() % CARD_NUMBER;  //敵のカードの数字をランダムで決める

				cout << i + 1 << "番目" << emyChoice[i] << "\n";  //何回目か表示
			}

			for (i = 0; i < CARD; i++)  //ヒット数の判定ループ
			{
				if (emyChoice[i] == playerCard[i])  //ヒット判定敵choiceとプレイヤーのカードが同じ
				{
					cout << "Hit,";//ヒット表示
					hit++;   //ヒットカウント
				}
				else
				{
					cout << "Blow,";  //またはブロー
				}
			}
			cout << "\n";
			if (hit == 3)//ヒット3回
			{
				cout << "3Hit!!\n";//ヒット3回の表示
				judgementFlag = false;  //勝敗のフラグをfalseへ
				break;
			}

			cout << "\n";
			trunFlag = true;//ターンフラグをtrueへ
		}


	}

	if (judgementFlag)//勝敗のフラグがtrueの場合
	{
		cout << "PLAYER WINNER\n";//プレイヤーの勝利表示
	}
	else
	{
		cout << "ENEMY WINNER\n";//敵の勝利表示
	}

	return 0;//プログラム終了
}