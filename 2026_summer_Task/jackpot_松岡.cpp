#include <iostream>
#include<cstdlib>//ランダム
#include<ctime>//毎度毎度のループ
using namespace std;

int main(void)
{ 
	//変数宣言
    int ply;//プレイヤー
	int CPU;//敵
	int board[10];//盤面
	int turn = 1;//ターン管理
    int dice1;//サイコロ１
	int dice2;//サイコロ２
    int choice[3]; // 選択可能なマスを保存する配列
    int count = 0;// 選択可能なマスの数
	int same = 0;// 選択可能なマスが重なっていないかどうかを判定する
	int selected;// 選択したマスの番号
    int ok = 0;// 入力が有効かどうかを判定するフラグ
	int random;// CPUが選択するマスの番号
	int filled = 1;// すべてのマスが埋まったかどうかを判定するフラグ

	//乱数初期化
	srand((unsigned int)time(NULL));

    // すべてのマスを空きにする
    for (int i = 0; i < 10; i++)
    {
        board[i] = 0;
    }

    ply = 1;//プレイヤー１からスタート
    while (1)
    {
        // 盤面を表示
        cout << "現在の盤面"<<endl;

		for (int i = 1; i <= 9; i++)// 1から9までのマスを表示
        {
            cout << i << ":"<<endl;

			if (board[i] == 0)// 空きマスの場合
            {
                cout << "空き"<<endl;
            }
			else if (board[i] == 1)// プレイヤーのマスの場合
            {
                cout << "player"<<endl;
            }
            else
            {
                cout << "CPU"<<endl;
            }

            cout << "\n" << endl;

			if (i % 3 == 0)// 3の倍数のときは改行
            {
                cout << endl;
            }
        }
        // サイコロを振る
		dice1 = rand() % 6 + 1;// 1から6までのランダム
		dice2 = rand() % 6 + 1;// 1から6までのランダム

        cout << endl;

		if (turn == 1)// プレイヤーのターン
        {
            cout << "プレイヤーのターン"<<endl;
        }
        else
        {
            cout << "CPUのターン"<<endl;
        }

        cout << "サイコロの目："
            << dice1<< "\n"<< dice2<< endl;


        // 1個目のサイコロ
		if (board[dice1] == 0)// 選択可能なマスかどうかを確認
        {
			choice[count] = dice1;// 選択可能なマスを保存
            count++;//カウント
        }

        // 2個目のサイコロ
		if (board[dice2] == 0)// 選択可能なマスかどうかを確認
        {

            for (int i = 0; i < count; i++)//重複していないか
            {
				if (choice[i] == dice2)//重複していたら
                {
					same = 1;//重複していることを示す
                }
            }

			if (same == 0)// 重複していなかったら
            {
				choice[count] = dice2;// 選択可能なマスを保存

                count++;
            }
        }
        // 合計
		int sum = dice1 + dice2;// 選択可能なマスかどうかを確認

		if (sum <= 9 && board[sum] == 0)// 選択可能なマスかどうかを確認
        {

			for (int i = 0; i < count; i++)//重複していないか
            {
				if (choice[i] == sum)//重複していたら
                {
                    same = 1;
                }
            }

			if (same == 0)// 重複していなかったら
            {
				choice[count] = sum;// 選択可能なマスを保存
                count++;
            }
        }

        // 選択できるマスがない場合
        if (count == 0)
        {
            cout << "選択できるマスがありません。"<<endl;

			if (turn == 1)
            {
                cout << "CPUの勝ちです。"<<endl;
            }
            else
            {
                cout << "プレイヤーの勝ちです。"<<endl;
            }

            break;
        }
        // プレイヤーのターン
		if (turn == 1)// プレイヤーのターン
        {
            cout << "選択可能なマス：";

			for (int i = 0; i < count; i++)// 選択可能なマスを表示
            {
				cout << choice[i] << endl;
            }


			while (1)// 入力チェックループ
            {

                cout << "マスを選んでください：";
				cin >> selected;// 入力

				for (int i = 0; i < count; i++)//マスの中に入力があるかどうかを確認
                {
					if (selected == choice[i])// 入力がマスの中にあった場合
                    {
                        ok = 1;
                    }
                }

                if (ok == 1)
                {
                    break;
                }

                cout << "入力し直してください。"<<endl;
            }

			board[selected] = 1;// 選択したマスをプレイヤーのものにする
        }
        // CPUのターン
        else
        {
			random = rand() % count;// 選択可能なマスの中からランダムに選ぶ

			selected = choice[random];// 選択したマスを保存

            cout << "CPUは"<< selected<< "のマスを取りました。"<<endl;

			board[selected] = 2;// 選択したマスをCPUのものにする
        }

        // すべてのマスが埋まったか確認
		for (int i = 1; i <= 9; i++)// 1から9までのマスを確認
        {
			if (board[i] == 0)// 空きマスがあった場合
            {
                filled = 0;
            }
        }

        // すべて埋まった場合
        if (filled == 1)
        {
            cout << "すべてのマスが埋まりました。\n";

            if (turn == 1)
            {
                cout << "プレイヤーの勝ちです。\n";
            }
            else
            {
                cout << "CPUの勝ちです。\n";
            }

            break;
        }
        // ターンを交代する
        if (turn == 1)
        {
            turn = 0;
        }
        else
        {
            turn = 1;
        }
    }

    return 0;
       
}