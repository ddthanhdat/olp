#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char s[30000];
	char tam[10];
	int i;
	int n;
	int k=0;
	int len;

	cin >> n;
	cin.ignore();
	for(int p=0; p<n; p++){
		gets(s);
		cout << "Message #" << p+1 << endl;
		len=strlen(s);
		for(i=0; i<=len; i++){
			
			if(s[i]!=' ' && s[i]!='\0'){
				tam[k]=s[i];
				k++;
				
			}
			else {
				
				tam[k]='\0';
				k=0;
				if(strcmp(tam,".-")==0) cout << 'A';
				else if(strcmp(tam,".---")==0) cout << 'J';
				else if(strcmp(tam,"...")==0) cout << 'S';
				else if(strcmp(tam,".----")==0) cout << '1';
				else if(strcmp(tam,"---...")==0) cout << ':';
				else if(strcmp(tam,".-.-.-")==0) cout << '.';
				else if(strcmp(tam,"-...")==0) cout << 'B';
				else if(strcmp(tam,"-.-")==0) cout << 'K';
				else if(strcmp(tam,"-")==0) cout << 'T';
				else if(strcmp(tam,"--..--")==0) cout << ',';
				else if(strcmp(tam,"-.-.-.")==0) cout << ';';
				else if(strcmp(tam,"..---")==0) cout << '2';
				else if(strcmp(tam,"-.-.")==0) cout << 'C';
				else if(strcmp(tam,".-..")==0) cout << 'L';
				else if(strcmp(tam,"..-")==0) cout << 'U';
				else if(strcmp(tam,"...--")==0) cout << '3';
				else if(strcmp(tam,"..--..")==0) cout << '?';
				else if(strcmp(tam,"-...-")==0) cout << '=';
				else if(strcmp(tam,"-..")==0) cout << 'D';
				else if(strcmp(tam,"--")==0) cout << 'M';
				else if(strcmp(tam,"...-")==0) cout << 'V';
				else if(strcmp(tam,"....-")==0) cout << '4';
				else if(strcmp(tam,".----.")==0) cout << '\'';
				else if(strcmp(tam,".-.-.")==0) cout << '+';
				else if(strcmp(tam,".")==0) cout << 'E';
				else if(strcmp(tam,"-.")==0) cout << 'N';
				else if(strcmp(tam,".--")==0) cout << 'W';
				else if(strcmp(tam,".....")==0) cout << '5';
				else if(strcmp(tam,"-.-.--")==0) cout << '!';
				else if(strcmp(tam,"-....-")==0) cout << '-';
				else if(strcmp(tam,"..-.")==0) cout << 'F';
				else if(strcmp(tam,"---")==0) cout << 'O';
				else if(strcmp(tam,"-..-")==0) cout << 'X';
				else if(strcmp(tam,"-....")==0) cout << '6';
				else if(strcmp(tam,"-..-.")==0) cout << '/';
				else if(strcmp(tam,"..--.-")==0) cout << '_';
				else if(strcmp(tam,"--.")==0) cout << 'G';
				else if(strcmp(tam,".--.")==0) cout << 'P';
				else if(strcmp(tam,"-.--")==0) cout << 'Y';
				else if(strcmp(tam,"--...")==0) cout << '7';
				else if(strcmp(tam,"-.--.")==0) cout << "(";
				else if(strcmp(tam,".-..-.")==0) cout << '"';
				else if(strcmp(tam,"....")==0) cout << 'H';
				else if(strcmp(tam,"--.-")==0) cout << 'Q';
				else if(strcmp(tam,"--..")==0) cout << 'Z';
				else if(strcmp(tam,"---..")==0) cout << '8';
				else if(strcmp(tam,"-.--.-")==0) cout << ')';
				else if(strcmp(tam,".--.-.")==0) cout << '@';
				else if(strcmp(tam,"..")==0) cout << 'I';
				else if(strcmp(tam,".-.")==0) cout << 'R';
				else if(strcmp(tam,"-----")==0) cout << '0';
				else if(strcmp(tam,"----.")==0) cout << '9';
				else if(strcmp(tam,".-...")==0) cout << '&';
				if(s[i]==' ' && s[i+1]==' '){
					cout << " ";
					i+=1;
				}
			}
		}
		if(p != n-1)
			cout << endl;
	}
	return 0;
}
