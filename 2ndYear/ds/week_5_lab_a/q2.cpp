#include <bits/stdc++.h>
using namespace std;
class hi {
public:
bool checkPalindrome(string& s)
{
int n = s.size();
int i = 0, j = n - 1;
while (i < j) {
if (s[i] != s[j])
return false;
i++;
j--;
}
return true;
}
void Partition(vector<vector<string> >& res, string& s,
int idx, vector<string>& curr)
{
if (idx == s.size()) {
res.push_back(curr);
return;
}
// Stores the current substring.
string t;
for (int i = idx; i < s.size(); i++) {
t.push_back(s[i]);
if (checkPalindrome(t)) {
curr.push_back(t);
Partition(res, s, i + 1, curr);
curr.pop_back();
}
}
}
};
int main()
{
hi ob;
vector<vector<string> > res;
string s = "nitin";
int idx = 0;
vector<string> curr;
ob.Partition(res, s, idx, curr);
for (auto& v : res) {
for (auto& it : v) {
cout << it << " ";
}
cout << "\n";
}
return 0;
}