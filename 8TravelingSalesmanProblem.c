#include <stdio.h>
#include <limits.h>
#define MAX 999
int n = 5;
int dist[20][20] = {
   {0, 10, 15, 20, 8},
   {10, 0, 35, 25, 12},
   {35, 15, 0, 18, 30},
   {20, 25, 18, 0, 22},
   {8, 12, 30, 22, 0}};
int DP[32][8];
int TSP(int mark, int position) {
   int completed_visit = (1 << n) - 1;
   if (mark == completed_visit) {
       return dist[position][0];
   }
   if (DP[mark][position] != -1) {
       return DP[mark][position];
   }
   int answer = MAX;
   for (int city = 0; city < n; city++) {
      if ((mark & (1 << city)) == 0) {
         int newAnswer = dist[position][city] + TSP(mark | (1 << city), city);
         answer = (answer < newAnswer) ? answer : newAnswer;
      }
   }
   return DP[mark][position] = answer;
}
int main() {
   for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
         DP[i][j] = -1;
      }
   }
   printf("Minimum Distance Travelled -> %d\n", TSP(1, 0));
   return 0;
}