// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    int r;
    long int n;
    std::cin >> n;
    bool a = true;
    
    while(n > 0){
            r = n % 10;
            n = n / 10;
            if ((r != 4) && (r != 7)){
                a = false;
                break;
            }
    }
        if (a)
            std::cout << "YES";
        else
            std::cout << "NO";

    return 0;
}