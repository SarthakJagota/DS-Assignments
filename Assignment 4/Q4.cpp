#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s = "aabc";
    queue<char> q;
    int freq[26] = {0};

    for (char c : s) {
        q.push(c);
        freq[c - 'a']++;

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    return 0;
}
