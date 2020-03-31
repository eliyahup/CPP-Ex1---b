#include "PhoneticFinder.hpp"
#include <iostream>
//#include <string> 
#include <algorithm>
using namespace std;



bool sameChar(char a , char b ){
if((a=='v' && b=='w')||(a=='w' && b=='v')) 
return true;

if((a=='b' && b=='f')|| (a=='b' && b=='p')||(a=='f' && b=='b')||(a=='f' && b=='p')||(a=='p' && b=='f') || (a=='p' && b=='b')) 
return true;

if((a=='g' && b=='j')||(a=='j' && b=='g')) 
return true;

if((a=='c' && b=='k')|| (a=='c' && b=='q')||(a=='k' && b=='c')||(a=='k' && b=='q')||(a=='q' && b=='c') || (a=='q' && b=='k')) 
return true;

if((a=='s' && b=='z')||(a=='z' && b=='s')) 
return true;

if((a=='d' && b=='t')||(a=='t' && b=='d')) 
return true;

if((a=='o' && b=='u')||(a=='u' && b=='o')) 
return true;

if((a=='i' && b=='y')||(a=='y' && b=='i')) 
return true;

return false;
}

void removeSpaces(string str) 
{ 
   
    int count = 0; 
  
    for (int i = 1; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i];

    str[count] = '\0'; 
} 


namespace phonetic {
	string find(string text, string word) {
		removeSpaces(word); 
		 bool b = false;
		 string ans("");
		 string text2 = text;
		transform(text.begin(), text.end(), text.begin(), ::tolower); 
		transform(word.begin(), word.end(), word.begin(), ::tolower); 
		//cout<< word<<endl;
		//cout<< text<<endl;
		int j = 0;
		for(int i = 0;i < text.length();i++){
			for( j = 0;j+i < text.length()&&text[i+j]!= ' ';j++){
            if (word[j] == text[i+j]||sameChar(word[j],text[i+j])){
				b = true;
			ans+= text2[j+i];
			}else{
				b = false;
				while(i < text.length()&&text[i]!= ' '){
					i++;
				}
			break;
			}
			}
			   if(j==word.length()&&b == true){
				return ans;
			}
			ans = "";
		}

				//cout<< word<<endl;

        throw invalid_argument(word + " is not a full word in the sentence");

		return ans;
			
	}
}