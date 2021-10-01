#include <bits/stdc++.h>
using namespace std;
 
// Function to get the smallest
// sequence possible
void solve(int a[], int b[], int n)
{
 
    // Hash-table to count the
    // number of occurrences of b[i]
    unordered_map<int, int> mpp;
 
    // Store the element in sorted order
    // for using binary search
    set<int> st;
 
    // Iterate in the B array
    // and count the occurrences and
    // store in the set
    for (int i = 0; i < n; i++) {
        mpp[b[i]]++;
        st.insert(b[i]);
    }
 
    vector<int> sequence;
 
    // Iterate for N elements
    for (int i = 0; i < n; i++) {
 
        // If the element is 0
        if (a[i] == 0) {
 
            // Find the nearest number to 0
            auto it = st.lower_bound(0);
            int el = *it;
            sequence.push_back(el % n);
 
            // Decrease the count
            mpp[el]--;
 
            // Erase if no more are there
            if (!mpp[el])
                st.erase(el);
        }
 
        // If the element is other than 0
        else {
 
            // Find the difference
            int x = n - a[i];
 
            // Find the nearest number which can give us
            // 0 on modulo
            auto it = st.lower_bound(x);
 
            // If no such number occurs then
            // find the number closest to 0
            if (it == st.end())
                it = st.lower_bound(0);
 
            // Get the number
            int el = *it;
 
            // store the number
            sequence.push_back((a[i] + el) % n);
 
            // Decrease the count
            mpp[el]--;
 
            // If no more appears, then erase it from set
            if (!mpp[el])
                st.erase(el);
        }
    }
 
    for (auto it : sequence)
        cout << it << " ";
}
 
// Driver Code
int main()
{
    int a[] = { 0, 1, 2, 1 };
    int b[] = { 3, 2, 1, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    solve(a, b, n);
    return 0;
}
