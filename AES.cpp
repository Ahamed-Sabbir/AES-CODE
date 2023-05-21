#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> plainText;
vector<vector<string>> KEY;
vector<vector<string>> S_BOX;
vector<vector<int>> MIX_COLUM_MAT;

void MIX_COLUMNS_MAT_FILL(){
  vector<int> temp(4);
  temp[0] = 2; temp[1] = 3; temp[2] = 1; temp[3] = 1;
  MIX_COLUM_MAT.push_back(temp);
  temp[0] = 1; temp[1] = 2; temp[2] = 3; temp[3] = 1;
  MIX_COLUM_MAT.push_back(temp);
  temp[0] = 1; temp[1] = 1; temp[2] = 2; temp[3] = 3;
  MIX_COLUM_MAT.push_back(temp);
  temp[0] = 3; temp[1] = 1; temp[2] = 1; temp[3] = 2;
  MIX_COLUM_MAT.push_back(temp);
}

void FILL_S_BOX(){
  vector<string> temp(16);
  temp[0] = "63"; temp[1] = "7C"; temp[2] = "77"; temp[3] = "7B"; temp[4] = "F2"; temp[5] = "6B"; temp[6] = "6F"; temp[7] = "C5"; temp[8] = "30";
  temp[9] = "01"; temp[10] = "67"; temp[11] = "2B"; temp[12] = "FE"; temp[13] = "D7"; temp[14] = "AB"; temp[15] = "76";
  S_BOX.push_back(temp);
  temp[0] = "CA"; temp[1] = "82"; temp[2] = "C9"; temp[3] = "7D"; temp[4] = "FA"; temp[5] = "59"; temp[6] = "47"; temp[7] = "F0"; temp[8] = "AD";
  temp[9] = "D4"; temp[10] = "A2"; temp[11] = "AF"; temp[12] = "9C"; temp[13] = "A4"; temp[14] = "72"; temp[15] = "C0";
  S_BOX.push_back(temp);
  temp[0] = "B7"; temp[1] = "FD"; temp[2] = "93"; temp[3] = "26"; temp[4] = "36"; temp[5] = "37"; temp[6] = "F7"; temp[7] = "CC"; temp[8] = "34";
  temp[9] = "A5"; temp[10] = "E5"; temp[11] = "F1"; temp[12] = "71"; temp[13] = "B8"; temp[14] = "31"; temp[15] = "15";
  S_BOX.push_back(temp);
  temp[0] = "04"; temp[1] = "C7"; temp[2] = "23"; temp[3] = "C3"; temp[4] = "18"; temp[5] = "96"; temp[6] = "05"; temp[7] = "9A"; temp[8] = "07";
  temp[9] = "12"; temp[10] = "80"; temp[11] = "E2"; temp[12] = "EB"; temp[13] = "27"; temp[14] = "B2"; temp[15] = "75";
  S_BOX.push_back(temp);
  temp[0] = "09"; temp[1] = "83"; temp[2] = "2C"; temp[3] = "1A"; temp[4] = "1B"; temp[5] = "6E"; temp[6] = "5A"; temp[7] = "A0"; temp[8] = "52";
  temp[9] = "3B"; temp[10] = "D6"; temp[11] = "B3"; temp[12] = "29"; temp[13] = "E3"; temp[14] = "2F"; temp[15] = "84";
  S_BOX.push_back(temp);
  temp[0] = "53"; temp[1] = "D1"; temp[2] = "00"; temp[3] = "ED"; temp[4] = "20"; temp[5] = "FC"; temp[6] = "B1"; temp[7] = "5B"; temp[8] = "6A";
  temp[9] = "CB"; temp[10] = "BE"; temp[11] = "39"; temp[12] = "4A"; temp[13] = "4C"; temp[14] = "58"; temp[15] = "CF";
  S_BOX.push_back(temp);
  temp[0] = "D0"; temp[1] = "EF"; temp[2] = "AA"; temp[3] = "FB"; temp[4] = "43"; temp[5] = "4D"; temp[6] = "33"; temp[7] = "85"; temp[8] = "45";
  temp[9] = "F9"; temp[10] = "02"; temp[11] = "7F"; temp[12] = "50"; temp[13] = "3C"; temp[14] = "9F"; temp[15] = "A8";
  S_BOX.push_back(temp);
  temp[0] = "51"; temp[1] = "A3"; temp[2] = "40"; temp[3] = "8F"; temp[4] = "92"; temp[5] = "9D"; temp[6] = "38"; temp[7] = "F5"; temp[8] = "BC";
  temp[9] = "B6"; temp[10] = "DA"; temp[11] = "21"; temp[12] = "10"; temp[13] = "FF"; temp[14] = "F3"; temp[15] = "D2";
  S_BOX.push_back(temp);
  temp[0] = "CD"; temp[1] = "0C"; temp[2] = "13"; temp[3] = "EC"; temp[4] = "5F"; temp[5] = "97"; temp[6] = "44"; temp[7] = "17"; temp[8] = "C4";
  temp[9] = "A7"; temp[10] = "7E"; temp[11] = "CD"; temp[12] = "64"; temp[13] = "5D"; temp[14] = "19"; temp[15] = "73";
  S_BOX.push_back(temp);
  temp[0] = "60"; temp[1] = "81"; temp[2] = "4F"; temp[3] = "DC"; temp[4] = "22"; temp[5] = "2A"; temp[6] = "90"; temp[7] = "88"; temp[8] = "46";
  temp[9] = "EE"; temp[10] = "B8"; temp[11] = "14"; temp[12] = "DE"; temp[13] = "5E"; temp[14] = "0B"; temp[15] = "DB";
  S_BOX.push_back(temp);
  temp[0] = "E0"; temp[1] = "32"; temp[2] = "3A"; temp[3] = "0A"; temp[4] = "49"; temp[5] = "06"; temp[6] = "24"; temp[7] = "5C"; temp[8] = "C2";
  temp[9] = "D3"; temp[10] = "AC"; temp[11] = "62"; temp[12] = "91"; temp[13] = "95"; temp[14] = "E4"; temp[15] = "79";
  S_BOX.push_back(temp);
  temp[0] = "E7"; temp[1] = "C8"; temp[2] = "37"; temp[3] = "6D"; temp[4] = "8D"; temp[5] = "D5"; temp[6] = "4E"; temp[7] = "A9"; temp[8] = "6C";
  temp[9] = "56"; temp[10] = "F4"; temp[11] = "EA"; temp[12] = "65"; temp[13] = "7A"; temp[14] = "AE"; temp[15] = "08";
  S_BOX.push_back(temp);
  temp[0] = "BA"; temp[1] = "78"; temp[2] = "25"; temp[3] = "2E"; temp[4] = "1C"; temp[5] = "A6"; temp[6] = "B4"; temp[7] = "C6"; temp[8] = "E8";
  temp[9] = "DD"; temp[10] = "74"; temp[11] = "1F"; temp[12] = "4B"; temp[13] = "BD"; temp[14] = "8B"; temp[15] = "8A";
  S_BOX.push_back(temp);
  temp[0] = "70"; temp[1] = "3E"; temp[2] = "B5"; temp[3] = "66"; temp[4] = "48"; temp[5] = "03"; temp[6] = "F6"; temp[7] = "0E"; temp[8] = "61";
  temp[9] = "35"; temp[10] = "57"; temp[11] = "B9"; temp[12] = "86"; temp[13] = "C1"; temp[14] = "1D"; temp[15] = "9E";
  S_BOX.push_back(temp);
  temp[0] = "E1"; temp[1] = "F8"; temp[2] = "98"; temp[3] = "11"; temp[4] = "69"; temp[5] = "D9"; temp[6] = "8E"; temp[7] = "94"; temp[8] = "9B";
  temp[9] = "1E"; temp[10] = "87"; temp[11] = "E9"; temp[12] = "CE"; temp[13] = "55"; temp[14] = "28"; temp[15] = "DF";
  S_BOX.push_back(temp);
  temp[0] = "8C"; temp[1] = "A1"; temp[2] = "89"; temp[3] = "0D"; temp[4] = "BF"; temp[5] = "E6"; temp[6] = "42"; temp[7] = "68"; temp[8] = "41";
  temp[9] = "99"; temp[10] = "2D"; temp[11] = "0F"; temp[12] = "B0"; temp[13] = "54"; temp[14] = "BB"; temp[15] = "16";
  S_BOX.push_back(temp);
}

int HEXA_DECIMAL(string temp){
  int B = 16;
  if(temp.size() == 1) return (temp[0]-'0');
  int num1 = ((temp[0] <= '9' && temp[0] >= '0')?(temp[0]-'0'):((temp[0]-'A')+10));
  int num2 = ((temp[1] <= '9' && temp[1] >= '0')?(temp[1]-'0'):((temp[1]-'A')+10));
  return ((num1*16)+(num2));
}

string DECIMAL_HEXA(int temp){
  string res = "";
  if(temp == 0) res = "0";
  while(temp){
    int T = temp%16;
    res += ((T < 10)?(T+'0'):((T-10)+'A'));
    temp = temp/16;
  }
  reverse(res.begin(), res.end());
  if(res.size() == 1) return "0"+res;
  return res;
}

void KEY_EXPANSION(int R){
  vector<vector<string>> temp;
  vector<string> LAST_COL(4);
  for(int i = 1; i < 4; i++) LAST_COL[i-1] = KEY[i][3];
  LAST_COL[3] = KEY[0][3];
  for(int i = 0; i < 4; i++){
      string temp = LAST_COL[i];
      int row = ((temp[0] >= '0' && temp[0] <= '9')?(temp[0]-'0'):((temp[0]-'A')+10));
      int col = ((temp[1] >= '0' && temp[1] <= '9')?(temp[1]-'0'):((temp[1]-'A')+10));
      LAST_COL[i] = S_BOX[row][col];
      int temp1 = HEXA_DECIMAL(LAST_COL[i]);
      int temp2 = HEXA_DECIMAL(KEY[i][0]);
      int value = temp1 ^ temp2;
      if(!i) value ^= R;
      LAST_COL[i] = DECIMAL_HEXA(value);
      KEY[i][0] = LAST_COL[i];
  }
  for(int j = 1; j < 4; j++){
    for(int i = 0; i < 4; i++){
      string temp = LAST_COL[i];
      int temp1 = HEXA_DECIMAL(LAST_COL[i]);
      int temp2 = HEXA_DECIMAL(KEY[i][j]);
      LAST_COL[i] = DECIMAL_HEXA(temp1 ^ temp2);
      KEY[i][j] = LAST_COL[i];
    }
  }
}

void ADD_ROUND_KEY(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      int temp1 = HEXA_DECIMAL(plainText[i][j]);
      int temp2 = HEXA_DECIMAL(KEY[i][j]);
      string temp3 = DECIMAL_HEXA(temp1^temp2);
      plainText[i][j] = temp3;
    }
  }
}

void SUBSTITUTE_BYTES(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      string temp = plainText[i][j];
      int row = ((temp[0] >= '0' && temp[0] <= '9')?(temp[0]-'0'):((temp[0]-'A')+10));
      int col = ((temp[1] >= '0' && temp[1] <= '9')?(temp[1]-'0'):((temp[1]-'A')+10));
      plainText[i][j] = S_BOX[row][col];
    }
  }
}

void SHIFT_ROWS(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < i; j++){
      string temp = plainText[i].front();
      plainText[i].erase(plainText[i].begin());
      plainText[i].push_back(temp);
    }
  }
}

vector<vector<int>> multiply(vector<vector<int> > mat1, int m){
  int n = mat1.size();
  vector<vector<int> > ans(n, vector<int>(n, 0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int current = 0;
      for(int k=0;k<m;k++){
        map<int, int> mp;
        int firstt = mat1[k][j], secondd = MIX_COLUM_MAT[i][k];
        for(int mask = 0; mask < 8; mask++){
          if((firstt>>mask)&1LL){
            for(int mask1 = 0; mask1 < 8; mask1++){
              if((secondd>>mask1)&1LL){
                if(mask+mask1 < 8) mp[(mask+mask1)]++;
                else {
                  mp[4]++;
                  mp[3]++;
                  mp[1]++;
                  mp[0]++;
                }
              }
            }
          }
        }
        int temp = 0;
        for(auto it:mp){
          if(it.second&1) temp |= (1LL<<it.first);
        }
        current ^= temp;
      }
      ans[i][j] = current;
    }
  }
  return ans;
}

void MIX_COLUMNS(){
  vector<vector<int>> temp;
  for(int i = 0; i < 4; i++){
    vector<int> temp2;
    for(int j = 0; j < 4; j++){
      temp2.push_back(HEXA_DECIMAL(plainText[i][j]));
    }
    temp.push_back(temp2);
  }
  temp = multiply(temp, 4);
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      plainText[i][j] = DECIMAL_HEXA(temp[i][j]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  FILL_S_BOX();
  MIX_COLUMNS_MAT_FILL();
  cout<<"Enter Plain Text (State Matrix 4*4)"<<endl;
  for(int i = 0; i < 4; i++){
    vector<string> temp;
    for(int j = 0; j < 4; j++){
      string x; cin >> x;
      temp.push_back(x);
    }
    plainText.push_back(temp);
  }
  cout<<"Enter KEY (Matrix 4*4)"<<endl;
  for(int i = 0; i < 4; i++){
    vector<string> temp;
    for(int j = 0; j < 4; j++){
      string x; cin >> x;
      temp.push_back(x);
    }
    KEY.push_back(temp);
  }
  int ROUND = 10;
  ADD_ROUND_KEY();
  for(int i = 0; i < ROUND; i++){
    SUBSTITUTE_BYTES();
    SHIFT_ROWS();
    if(i != ROUND-1) MIX_COLUMNS();
    KEY_EXPANSION(i+1);
    ADD_ROUND_KEY();

  }
  cout << "Encrypted: \n";
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      cout<<plainText[i][j]<<" ";
    }
    cout<<endl;
  }
}
