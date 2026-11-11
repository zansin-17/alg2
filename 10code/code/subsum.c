/*

    author : your name
    id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int i, j;
    int n;  // 入力される自然数の個数

    scanf("%d", &n);

    int a[n];  // 入力される自然数

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int b = 77/* complete here!! */;  // 作りたい数
    int dp[n + 1][b + 1];           // dpテーブル:
    // dp[i][j]はi番目の自然数を使って，jを作れるかどうか．作れる->1，作れない->0．

    // 初期化
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= b; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1/* complete here!! */;  // 0個の和で0は作れる

    for (i = 0; i < n; i++) {
        for (j = 0; j <= b; j++) {
            // i番目の自然を使ってjを作れるなら，i+1番目の自然数を考えたとしてもjを作れる(a[i+1]を使わなければいいので)
            dp[i + 1][j] |= dp[i][j]/* complete here!! */;

            // a[i]を使うならどうするか？
            if (j >= a[i]/* complete here!! */) {
                dp[i + 1][j] |= dp[i][j - a[i]]/* complete here!! */;
            }
        }
    }

    return 0;
}
