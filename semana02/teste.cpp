#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u = unsigned;
using ull = unsigned long long;

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(0);

    // Code
    
    /*
     * TMP: 0
     * OGG: 1
     * CPP: 2
     */

    u n, k;
    cin >> n >> k;

    u short type;
    ull uti, tam;
    string format;

    auto cmp = [](tuple<ull, u short, ull> a, tuple<ull, u short, ull> b) {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);

        if (get<1>(a) != get<1>(b))
            return get<1>(a) < get<1>(b);

        return get<2>(a) > get<2>(b);
    };

    multiset<tuple<ull, u short, ull>, decltype(cmp)> files(cmp);
    
    for (int i = 0; i < n; i++) {
        cin >> uti >> format >> tam;

        if (format == "TMP") type = 0;
        else if (format == "OGG") type = 1;
        else type = 2;

        files.insert(make_tuple(uti, type, tam));
    }

    ull bytes{0};
    auto it{files.begin()};

    for (u i = 0; i < k; i++) {
        bytes += get<2>(*it);
        ++it;
    }

    cout << bytes << "\n";

    //

    return 0;
}