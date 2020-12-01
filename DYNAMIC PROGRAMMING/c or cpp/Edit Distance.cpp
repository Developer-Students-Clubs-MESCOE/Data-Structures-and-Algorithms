#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
    using namespace std;
    int strl1 = str1.size();
    int strl2 = str2.size();
    
    int dMatrix[strl1][strl2];
    
    for(int i=0;i<strl1;i++){
        dMatrix[i][0] = i;
    }
    
    for(int j=0;j<strl2;j++){
        dMatrix[0][j] = j;
    }
    
    int insertion,deletion,match,mismatch;
    for(int i=1;i<strl1;i++){
        for(int j=1;j<strl2;j++){
            insertion = dMatrix[i][j-1] +1;
            deletion = dMatrix[i-1][j] +1;
            match = dMatrix[i-1][j-1];
            mismatch = dMatrix[i-1][j-1] +1;
            if (str1[i] == str2[j]){
                dMatrix[i][j] = min(min(insertion,deletion),match);
            }
            else{
                dMatrix[i][j] = min(min(insertion,deletion),mismatch);
            }
        }
    }
    return dMatrix[strl1 -1][strl2 -1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
