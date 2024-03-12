#include <iostream>
#include <set>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct CompareTuple {
    bool operator()(const tuple<ull, int, ull>& lhs,
                    const tuple<ull, int, ull>& rhs) const {

        if (get<0>(lhs) != get<0>(rhs)) {
            return get<0>(lhs) < get<0>(rhs);
        }

        if (get<1>(lhs) != get<1>(rhs)) {
            return get<1>(lhs) < get<1>(rhs);
        }

        return get<2>(lhs) > get<2>(rhs);
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    ull uses;
    string format;
    int type;
    ull size;
    ull totalBytes = 0;
    multiset<tuple<ull, int, ull>, CompareTuple> files;

    for (int i = 0; i < n; i++) {
        cin >> uses >> format >> size;
        if (format == "TMP") {
            type = 0;
        } else if (format == "OGG") {
            type = 1;
        } else {
            type = 2;
        }
        files.insert(make_tuple(uses, type, size));
    }

    int count = 0;
    for (auto it = files.begin(); count < k; it++) {
        count++;
        totalBytes += get<2>(*it);
    }

    // cout << '\n';
    // for (auto it = files.begin(); it != files.end(); it++) {
    //     cout << get<0>(*it) << ' ' << get<1>(*it) << ' ' << get<2>(*it) << '\n';
    // }

    cout << totalBytes << '\n';
}