/*
Nama        : Alifa Hafida Anwar
NPM         : 140810190018
Deskripsi   : Program Shift Chiper
*/
#include <iostream>
using namespace std;

string encrypt(string text, int s)
{
	string result = "";

	for (int i=0;i<text.length();i++)
	{
        if(int(text[i])>64 && int(text[i])<=90 || int(text[i])>96 && int(text[i])<123){
            if (isupper(text[i]))
                result += char(int(text[i]+s-65)%26 +65);

            // Encrypt Lowercase letters
            else
                result += char(int(text[i]+s-97)%26 +97);
        }else{
            result+=text[i];
        }
		
	}
	return result;
}
string decrypt(string text, int s)
{
	string result = "";
	for (int i=0;i<text.length();i++)
	{   
        if(int(text[i])>64 && int(text[i])<=90 || int(text[i])>96 && int(text[i])<123){
            if (isupper(text[i]))
                result += char(int(text[i]-s-65+26)%26+65);
            else
            result += char(int(text[i]-97+26-s) % 26+ 97);
        }
        else{
            result+=text[i];
        }
		
	}
	return result;
}
void pilMenu(){
    cout<<"\nPilih Menu:"<<endl;
    cout<<"1. Enkripsi"<<endl;
    cout<<"2. Deskripsi"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"\nPilih : ";
}
int main(){
    string text, Ex, Dx;
    char ans;
    int k, x;
    do{
        pilMenu();
        cin>>x;
        cin.ignore();
        switch(x){
            case 1:
            cout<< "\nMasukkan plainteks = ";
            getline(cin, text);
            cout << "\nK: ";
            cin>> k;
            Ex = encrypt(text, k);
            cout << "\n\nHasil Enkripsi: " << Ex;
            break;

            case 2:
            cout<< "\nMasukkan ciphertext = ";
            getline(cin, text);
            cout << "\nK: ";
            cin>> k;
            Dx = decrypt(Ex, k);
            cout << "\nHasil Deskripsi: " << Dx;
            break;
            
            case 3:
            return 0;

            default:
            cout<<"Menu yang anda pilih salah";
            main();
            break;
        }
        cout<<"\n\nApakah akan diulang? (Y/N) ";
        cin>> ans;
        cout<<"==============================================="<<endl;
        
    }while(ans == 'y' || ans == 'Y');
    return 0;
}
