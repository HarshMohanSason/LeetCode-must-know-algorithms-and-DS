#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Fall back to the previous lps
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to perform KMP search
void KMPSearch(const string& pattern, const string& text) {
    int n = text.length();
    int m = pattern.length();

    // Compute the LPS array
    vector<int> lps = computeLPSArray(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
