#include <stdio.h>

int main() {
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        int score;
        scanf("%d", &score);
        if (score <= 1) break;

        printf("possible combinations of scoring plays:\n");

        for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
            for (int td1pt = 0; td1pt * 7 + td2pt * 8 <= score; td1pt++) {
                for (int td = 0; td * 6 + td1pt * 7 + td2pt * 8 <= score; td++) {
                    for (int fg = 0; fg * 3 + td * 6 + td1pt * 7 + td2pt * 8 <= score; fg++) {
                        int safety = (score - fg * 3 - td * 6 - td1pt * 7 - td2pt * 8) / 2;

                        if (fg * 3 + td * 6 + td1pt * 7 + td2pt * 8 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
