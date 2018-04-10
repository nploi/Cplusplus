#include <iostream>
#include <string>

#define MAX 156

bool cnt[MAX];

using namespace std;

int main(){
   for(int i = 0; i < MAX; i++) {
	cnt[i] = 0;
   }

   char c;
   int n, count = 0;
   cin >> n;

   while (n--){
         cin >> c;
         if (!cnt[c]) {
            count ++;
	    continue;
         }
	cnt[c] = 1;
   }
   cout << count ;
   
   return 0;
}
