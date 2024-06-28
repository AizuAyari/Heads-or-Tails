#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // 乱数のシードを設定
    srand(time(NULL));

    // 最初のリビジョンのメッセージを表示
    printf("HoT: 初期リビジョン\n");

    // ユーザーに名前を入力してもらう
    char name[100];
    printf("あなたの名前を入力してください: ");
    fgets(name, sizeof(name), stdin);

    // 名前の末尾に改行文字が含まれる場合は削除する
    if (name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }

    // ユーザーに挨拶する
    printf("%sさん、こんにちは！\n", name);

    // 3ラウンドのコイン投げを模倣する
    printf("コインを投げる...\n");
    for (int round = 1; round <= 3; ++round)
    {
        int result = rand() % 2 + 1; // 1は表、2は裏
        printf("ラウンド %d: %s\n", round, (result == 1) ? "表" : "裏");
    }

    return 0;
}
