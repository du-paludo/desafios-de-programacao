#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool isFifo = true;
    bool isLifo = true;
    bool isPriority = true;
    list<int> fifoList;
    stack<int> lifoList;
    priority_queue<int> priorityList;

    int n;
    cin >> n;

    int type, age;
    list<int>::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> type >> age;
        if (type == 0) {
            fifoList.push_back(age);
            lifoList.push(age);
            priorityList.push(age);
        } else {
            if (age == *fifoList.begin()) {
                fifoList.pop_front();
            }
            if (age == lifoList.top()) {
                lifoList.pop();
            }
            if (age == priorityList.top()) {
                priorityList.pop();
            }
        }
    }

    if ((fifoList.empty() && lifoList.empty()) || (fifoList.empty() && priorityList.empty()) || (lifoList.empty() && priorityList.empty())) {
        cout << "ambiguous\n";
    } else if (fifoList.empty()) {
        cout << "fifo\n";
    } else if (lifoList.empty()) {
        cout << "lifo\n";
    } else if (priorityList.empty()) {
        cout << "priority\n";
    } else {
        cout << "unknown\n";
    }
}