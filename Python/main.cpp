
// Đỉnh Thắt

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// bool check(int n, int k, int u, int v, vector<vector<int>>& ke) {
//     queue<int> q;
//     vector<int> a(n + 1, 0);
//     q.push(u);
//     a[u] = 1;

//     while (!q.empty()) {
//         int x = q.front();
//         q.pop();
//         if (x == v) return false;
//         for (int i : ke[x]) {
//             if (a[i] == 0 && i != k) {
//                 q.push(i);
//                 a[i] = 1;
//             }
//         }
//     }
//     return true;
// }

// int main() {
//     int T;
//     cin >> T;

//     for (int t = 0; t < T; ++t) {
//         int n, m, u, v;
//         cin >> n >> m >> u >> v;

//         vector<vector<int>> ke(n + 1);
//         for (int i = 0; i < m; ++i) {
//             int x, y;
//             cin >> x >> y;
//             ke[x].push_back(y);
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; ++i) {
//             if (i != u && i != v) {
//                 if (check(n, i, u, v, ke)) {
//                     ans++;
//                 }
//             }
//         }
//         cout << ans << "\n";
//     }

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_length = 1; // Độ dài của dãy con lớn nhất tính đến hiện tại
    int current_length = 1; // Độ dài của dãy con liên tiếp hiện tại
    int max_average = A[0]; // Trung bình cộng lớn nhất tính đến hiện tại
    int current_sum = A[0]; // Tổng của dãy con liên tiếp hiện tại

    for (int i = 1; i < N; i++) {
        current_sum += A[i];
        current_length++;

        // Kiểm tra xem trung bình cộng hiện tại có lớn hơn trung bình cộng lớn nhất đã biết hay không
        if (A[i] * current_length > current_sum * max_length) {
            max_average = A[i];
            max_length = current_length;
        }

        // Nếu trung bình cộng bằng nhau, chọn dãy con có độ dài lớn hơn
        else if (A[i] * current_length == current_sum * max_length && current_length > max_length) {
            max_average = A[i];
            max_length = current_length;
        }
    }

    cout << max_length << endl;

    return 0;
}
