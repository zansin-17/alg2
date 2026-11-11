/*

author : Ryoya Torikai
id     : s1300080

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;  // 額面
    int num;    // 所持枚数
    int used;   // 使用した枚数
} Coin;

int compare(const void *c1, const void *c2) { return ((Coin *)c2)->value - ((Coin *)c1)->value; }

int main(int argc, char const *argv[]) {
    int i, j;
    int n;        // 硬貨の種類
    int payment;  // 支払い金額

    // 入力と初期化
    scanf("%d", &n);
    Coin coin[n];

    for (i = 0; i < n; i++) {
        scanf("%d%d", &coin[i].value, &coin[i].num);
        coin[i].used = 0;
    }
    scanf("%d", &payment);
    qsort(coin, n, sizeof(Coin), compare);  // 貪欲法を使うために，額面の大きい順にソートしておく．
    // 入力と初期化終わり

    /*
        complete here!!
        貪欲法によるプログラムを書くこと．
    */
    for(i = 0 ; i < n ; i++){
        int max = payment / coin[i].value;
        coin[i].used = (max < coin[i].num) ? max : coin[i].num;
        payment -= coin[i].used * coin[i].value;
    }

    

    // 出力
    for (i = 0; i < n; i++) {
        printf("[%2d cent] %d used.\n", coin[i].value, coin[i].used);
    }

    return 0;
}
