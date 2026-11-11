/*

    author : your name
    id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main(int argc, char const *argv[]) {
    int i, j;
    int n;        // 硬貨の種類
    int payment;  // 支払い金額

    // 入力と初期化
    scanf("%d", &n);
    int coin[n];  // 硬貨の
    for (i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    scanf("%d", &payment);
    // dpテーブル
    int dp[payment + 1];  // jセント支払うためにdp[j]枚の硬貨が必要

    /*
        動的計画法によって解くプログラムを書く．
    */

    // 初期化
    for (i = 0; i <= payment; i++) {
        dp[i] = /* complete here!! */;
    }

    dp[0] = /* complete here!! */;  // 0セントを払うために必要な枚数は？

    // 全ての硬貨について
    for (i = 0; i < n; i++) {
        // 支払金額がjセントのときに, coin[i]セントで払う

        for (j = /* complete here!! */; /* complete here!! */; j++) {
            // jセント払うために，coin[i]セントを使った枚数とdp[j]枚のどちらが少ないか？
            dp[j] = min(/* complete here!! */);
        }
    }

    /* dpテーブルをうまく遡ることで使用したコインの枚数を得ることができる */

    return 0;
}
