#include <bits/stdc++.h>
using namespace std;
typedef struct {
    string original;
    string sub;
}st;
int compare(st a, st b) {
    return a.sub < b.sub;
}
vector<st> v;
int main() {
    string arr;
    string input;
    int n;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        getline(cin, input);
        for(int j=0; j<input.size(); j++) {
            if('A' <= input[j] && input[j] <= 'Z') {
                v.push_back({input, input.substr(j)});
                break;
            } 
        }
        // istringstream ss(input);
        // while(ss >> arr) {
        //     if('A' <= arr[0] && arr[0] <= 'Z') {
        //         v.push_back({input, arr, i});
        //         break;
        //     }
        //     else {
        //         for(int i=0; i<arr.size(); i++) {
        //             if('A' <= arr[i] && arr[i] <= 'Z') {
        //                 v.push_back({input, arr.substr(i)});
        //                 break;
        //             }
        //         }
        //     }
        // }
    }

    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++) {
        cout << v[i].original << endl;
    }
    return 0;
}