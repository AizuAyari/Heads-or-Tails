#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// コインを投げて表か裏かをランダムに決定する関数
int flip_coin()
{
    return rand() % 2; // 0が表、1が裏を表す
}

int main()
{
    srand(time(NULL)); // 乱数の初期化

    // ユーザー名の入力を求める
    char user_name[100];
    printf("あなたは誰ですか？\n> ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = 0; // 改行を削除

    printf("こんにちは、%s!\n", user_name);

    printf("コインを投げます...\n");
    for (int round = 1; round <= 3; round++)
    {
        int result = flip_coin();
        if (result == 0)
        {
            printf("ラウンド %d: 表\n", round);
        }
        else
        {
            printf("ラウンド %d: 裏\n", round);
        }
    }

    // 5回のコイン投げ結果を集計
    int heads_count = 0, tails_count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (flip_coin() == 0)
        {
            heads_count++;
        }
        else
        {
            tails_count++;
        }
    }

    printf("表: %d、裏: %d\n", heads_count, tails_count);

    // 勝利メッセージの表示
    if (heads_count > tails_count)
    {
        printf("%s が勝ちました!\n", user_name);
    }
    else
    {
        printf("You lose.\n");
    }

    return 0;
}
