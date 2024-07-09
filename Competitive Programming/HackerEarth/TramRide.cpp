#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, int finish, vector<int> Ticket_cost)  {
    if(start==finish)
        return 0;  

    int i;
    long long forward_cost = 0;
    for (i = start-1; i != finish-1; i = (i + 1) % N) {
        forward_cost += Ticket_cost[i];
    }

    long long backward_cost = 0;
    for (i = start-1; i != finish-1; i = (i - 1 + N) % N) {
        backward_cost += Ticket_cost[(i - 1 + N) % N];
    }
    return min(backward_cost, forward_cost); 
}

int main() {
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++){
        cin >> Ticket_cost[i_Ticket_cost];
    }

    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}