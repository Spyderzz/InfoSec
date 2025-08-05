#include <iostream>
#include <string>
#include <vector>
using namespace std;
string encrypt(string text, int cols) {
int rows = (text.length() + cols - 1) / cols;
vector<vector<char > > grid(rows, vector<char>(cols, ' '));
int k = 0;
for(int i = 0; i < rows; i++)
for(int j = 0; j < cols; j++)
if(k < text.length()) grid[i][j] = text[k++];
string result = "";
for(int j = 0; j < cols; j++)
for(int i = 0; i < rows; i++)
if(grid[i][j] != ' ') result += grid[i][j];
return result;
}
string decrypt(string cipher, int cols) {
int fullCols = cipher.length() % cols;
int rows = cipher.length() / cols;
if (fullCols != 0) rows++;
vector<vector<char > > grid(rows, vector<char>(cols, ' '));
int k = 0;
for(int j = 0; j < cols; j++) {
int limit = (j < fullCols) ? rows : rows - 1;
for(int i = 0; i < limit; i++) {
grid[i][j] = cipher[k++];
}
}
string result = "";
for(int i = 0; i < rows; i++) {
for(int j = 0; j < cols; j++) {
if(grid[i][j] != ' ') result += grid[i][j];
}
}
return result;
}
int main() {
string text = "helloworld";
int cols = 4;
string cipher = encrypt(text, cols);
string plain = decrypt(cipher, cols);
cout << "Cipher: " << cipher << endl;
cout << "Plain: " << plain << endl;
return 0;
}
