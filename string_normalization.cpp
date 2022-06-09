#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream fi ("string_normalization_inp.txt");
ofstream fo ("string_normalization_out.txt");

string str;

void removeWhitespace(){
   while (str[0] == ' ')
      str.erase(0, 1);
   while (str[str.size() - 1] == ' ')
      str.erase(str.size() - 1, 1);
   for (int i = 0; i < str.size(); i++){
      if (str[i] == ' ')
         while (str[i + 1] == ' ')
            str.erase(i + 1, 1);
   }
}

void lower(int i){
   str[i] = char(int(str[i]) + 32);
}

void upper(int i){
   str[i] = char(int(str[i]) - 32);
}

void lowerAll(){
   for (int i = 0; i < str.size(); i++)
      if (65 <= int(str[i]) && int(str[i]) <= 90)
         lower(i);
}

void upperFirstLetter(){
   upper(0);
   for (int i = 1; i < str.size(); i++)
      if (int(str[i]) == 32)
         upper(i + 1);
}

int main(){
   getline(fi, str);
   removeWhitespace();
   lowerAll();
   upperFirstLetter();
   fo << str;
   return 0;
}