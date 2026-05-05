#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// 暴力匹配算法 (Brute Force)
int bruteForce(const string& text, const string& pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) return i;
    }
    return -1;
}

// KMP 算法 - 展现 ACM 训练成果
void getNext(const string& p, vector<int>& next) {
    int m = p.length();
    next[0] = -1;
    int k = -1, j = 0;
    while (j < m - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++; k++;
            next[j] = k;
        } else k = next[k];
    }
}

int KMP(const string& text, const string& pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> next(m);
    getNext(pattern, next);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) { i++; j++; }
        else j = next[j];
    }
    return (j == m) ? (i - j) : -1;
}

int main() {
    // 构造一个极端测试用例：大量重复字符
    string text(10000000, 'a'); 
    text += 'b';
    string pattern = "aaaaab";

    cout << "--- ZenCode Algorithm Comparison ---" << endl;

    // 测试 BF
    auto start = chrono::high_resolution_clock::now();
    bruteForce(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    cout << "Brute Force Time: " << chrono::duration<double>(end - start).count() << "s" << endl;

    // 测试 KMP
    start = chrono::high_resolution_clock::now();
    KMP(text, pattern);
    end = chrono::high_resolution_clock::now();
    cout << "KMP Algorithm Time: " << chrono::duration<double>(end - start).count() << "s" << endl;

    return 0;
}
