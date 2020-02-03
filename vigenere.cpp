/*
 *	Vigenere Cypher
 *  Made by 0fabris
 *  2020 / 02
 */
#include <iostream>
#include <string>
using namespace std;

const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//pass plaintext message and key
string Vigenere_Encode(string clearmess, string key)
{
	string encmess = "";
	for(int i = 0; i < clearmess.length(); i++)
	{
		if(clearmess[i]<'A' || clearmess[i]>'Z') //Accept characters only if in chars const string
			return "";
		encmess += chars[((key[i%key.length()]-'A')+(clearmess[i]-'A'))%chars.length()];
	}
	return encmess;
}
//pass encoded message and key
string Vigenere_Decode(string encmess, string key)
{
	string clearmess = "";
	for(int i = 0,res; i < encmess.length(); i++)
	{
		res = (encmess[i]-key[i%key.length()]);
		clearmess += chars[res+((res<0)?26:0)];
	}
	return clearmess;
}

/* MAIN */
int main(){
	cout << Vigenere_Decode(Vigenere_Encode("THISISATEST","SECRET"),"SECRET");
	return 0;
}
