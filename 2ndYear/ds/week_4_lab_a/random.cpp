#include <iostream>
#include <string>
std::string reverseSubstring(const std::string &sub) {
std::string reversed = sub;
int left = 0;
int right = reversed.length() - 1;
while (left < right) {
std::swap(reversed[left], reversed[right]);
left++;
right--;
}
return reversed;
}
std::string reverseBetweenSubstrings(const std::string &input, char x, char y) {
std::string s1, s2, result;
size_t startPos = input.find(x);
size_t endPos = input.find(y, startPos + 1);
if (startPos == std::string::npos || endPos == std::string::npos) {
// Either X or Y is missing
return input;
}
s1 = input.substr(startPos + 1, endPos - startPos - 1);
size_t startPos2 = input.find(y, endPos + 1);
size_t endPos2 = input.find(x, startPos2 + 1);
if (startPos2 == std::string::npos || endPos2 == std::string::npos) {
// Either X or Y is missing
return input;
}
s2 = input.substr(startPos2 + 1, endPos2 - startPos2 - 1);
// Reverse s1 and s2 manually
s1 = reverseSubstring(s1);
s2 = reverseSubstring(s2);
result = input;
result.replace(startPos + 1, s1.length(), s1);
result.replace(startPos2 + 1, s2.length(), s2);
return result;
}
int main() {
std::string input = "ABXNNYPEROYABCDCXT";
char x = 'X';
char y = 'Y';
std::string output = reverseBetweenSubstrings(input, x, y);
std::cout << "Input: " << input << std::endl;
std::cout << "Output: " << output << std::endl;
return 0;
}
