

#include <iostream>
using namespace std;


class Solution {
    long int temp =0;
    int check;
public:
    bool isPalindrome(int x) {
        if (x >= 0){
            check = x;
            while (x != 0){
                temp = temp*10 + x % 10;
                x /= 10;
            }
            if (temp == check)
                return true;
        }
        return false;
    }
};


int main(){
    Solution soln;
    if (soln.isPalindrome(0))
        cout << "Hello";
    return 0;
}