
//File: Encryption and Decryption program

//Purpose: It takes input and encrypt it or decrypt it by 1 of 3 ciphers the user chooses from

/* Authors : 
1: Yousef Ehab Mohamed Mohamed , Section: S24 . 
2:Ali Mahmoud Mohammed Zaki , Section : S9. 
3: George Malak Magdy Nashed , S27.
*/
//polybius square cipher was Done by : Yousef Ehab Mohamed Mohamed 

//Morse Code: was done by Ali Mahmoud Mohammed Zaki

//Atbash cipher was done by :

/*Emails :
1:yousefehabel@gmail.com
2:Ali Mahmoud :3lokaweeka2005@gmail.com 
3:georgmalak2004@gmail.com
*/
/* IDs: 1: Yousef Ehab Mohamed  : 20230486
2: Ali Mahmoud Mohammed : 20230627
3: George Malak Magdy Nashe :20231042
*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>

using namespace std;


void encryption_with_morse() {
    string the_numbers[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    string the_symbols[15] = {"-.-.--", ".-..-.", " ", "...-..-", " ", ".-...", ".----.", "-.--.", "-.--.-", " ", ".-.-.", "--..--", " -....- ", ".-.-.- ", " -..-."};
    string the_alphabetic[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    string sentence;
    string new_sentence = "";
    cin.ignore(256,'\n');  
    cout << "Write down the sentence you want to encrypt" << endl;
    getline(cin, sentence); 
    for (int z = 0; z < sentence.size(); z++) {
        if (isdigit(sentence[z])) {
            int num1 = sentence[z] - '0';
            new_sentence += the_numbers[num1] + " ";
        } else if (isalpha(sentence[z])) {
            sentence[z] = toupper(sentence[z]);
            int num2 = sentence[z] - 'A';
            new_sentence += the_alphabetic[num2] + " ";
        } else if (sentence[z] == ' ') {
            new_sentence += " ";
        } else {
            int num3 = sentence[z] - 33;
            new_sentence += the_symbols[num3] + " ";
        }
    }
    cout << "Encrypted version is: " << new_sentence << endl;
}
void decryption_with_morse() {
    string morsecode[48] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-.-.--", ".-..-.", "...-..-", ".-...", ".----.", "-.--.-", "-.--.", ".-.-.", "--..--", " -....- ", ".-.-.- ", " -..-."};
    string normal[48] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "\"", "$", "&", "'", ")", "(", "+", ",", "-", ".", " "};

    string decryption_sentence;
    string new_decryption_sentence = "" ;
    string test = "";
    cin.ignore(256,'\n');  
    cout << "Write down the sentence you want to decrypt" << endl;
    getline(cin, decryption_sentence);
    decryption_sentence += " " ;

    for (int y = 0; y < decryption_sentence.size(); y++) {
        if (decryption_sentence[y] != ' ' && decryption_sentence[y] != '/') {
            test += tolower(decryption_sentence[y]);
        } else {
            if (!test.empty()) {
                for (int m = 0; m < 48; m++) {
                    if (test == morsecode[m]) {
                        new_decryption_sentence += normal[m];
                        test = "";
                        break;
                    }
                }
            }
            if (decryption_sentence[y] ==' ' && !test.empty()) {
                new_decryption_sentence += "";
            }else{
            new_decryption_sentence +=" ";}
        }
    }
    cout << "Decryption version is: " << new_decryption_sentence << endl;
}

string polybius_square_cipher(string plain_text) {
    char polybius_Table[5][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','K'},
        {'L','M','N','O','P'},
        {'Q','R','S','T','U'},
        {'V','W','X','Y','Z'}
    };

    string cipher_text = "";

    for (char c : plain_text) {
        if (isalpha(c)) {
            if (c == 'J')
                c = 'I';
            c = toupper(c);

            int row, col;
            for (row = 0; row < 5; row++) {
                for (col = 0; col < 5; col++) {
                    if (polybius_Table[row][col] == c) {
                        cipher_text += to_string(row + 1);
                        cipher_text += to_string(col + 1);
                        break;
                    }
                }
            }
        } else if (c == ' ') {
            cipher_text += ' '; // Handling spaces
        }
    }
    return cipher_text;
}
bool is_Number(const string & s){
    for (char c : s){
        if (!isdigit(c)){
            if (c != ' '){
                return false;
            }
        }
    }
    return true;
}
string decryptPolybius(const string& cipherText) {
    char polybiusTable[5][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','K'},
        {'L','M','N','O','P'},
        {'Q','R','S','T','U'},
        {'V','W','X','Y','Z'}
    };

    string decryptedText = "";
    int i = 0;
    while (i < cipherText.length()) {
        if (cipherText[i] == ' ') {
            decryptedText += ' ';
            i++;
        } else {
            int row = cipherText[i] - '0';
            int col = cipherText[i + 1] - '0';
            decryptedText += polybiusTable[row - 1][col - 1];
            i += 2;
        }
    }
    return decryptedText;
}

//function one to encryption and decode 
string shift_by_one_atbash(const string& mess) {
    string final_message = "";
    string code_one = "zyxwvutsrqponmlkjihgfedcba";
    for (char i : mess) {
        i = tolower(i);
        if (isalpha(i)) {
            char you_message = code_one[i - 'a'];
            final_message += you_message;
        }
    }
    return final_message;
}
//second function with different method with the same approch
string shift_by_two_atbash(const string& mess) {
    string code_two = "mlkjihgfedcbazyxwvutsrqpon";
    string final_message = "";
    for (char i : mess) {
        i = tolower(i);
        if (isalpha(i)) {
            char you_message = code_two[i - 'a'];
            final_message += you_message;
        }
    }
    return final_message;
}

//main program
int main() {
    while (true) {
        cout << endl <<"ahlan ya user ya habibi :" << endl;
        cout <<endl << "what would you like to do today ?" <<endl ;
        cout << "1: Encrypt" << endl;
        cout << "2: Decrypt" << endl;
        cout << "3: Exit" << endl;
        cout << "Please choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            cout <<endl << "which cipher would you like to choose :" << endl;
            cout << "1:polybius square cipher " << endl;
            cout << "2: morse encrypt" << endl;
            cout << "3:Atbash encrypt " << endl;
            cout << "Please choose an option: ";

            int choice_menu_2;
            cin >> choice_menu_2;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }
            if(choice_menu_2 == 1){
                string plain_text;
                cout << "Enter plain text: ";
                cin.ignore(); // Clear newline character from buffer
                getline(cin, plain_text);
                cout << "Enter key to encrypt (the key must be digits from 1 to 5): ";
                int a, b, c, d, e;
                string cipher_text = polybius_square_cipher(plain_text);
                string cipher_text_withkey = "";

                while (true) {
                    bool valid_input = true;
                    cin >> a >> b >> c >> d >> e;
                    if ((a < 1 || a > 5) || (b < 1 || b > 5) || (c < 1 || c > 5) || (d < 1 || d > 5) || (e < 1 || e > 5)) {
                        cout << "Invalid input. Please enter a digit from 1 to 5." << endl;
                        valid_input = false;
                    }
                    if ((a == b) || (a == c) || (a == d) || (a == e) || (b == c) || (b == d) || (b == e) || (c == d) || (c == e) || (d == e)) {
                        cout << "Invalid input. Please enter unique digits from 1 to 5." << endl ;
                        valid_input = false;
                    }
                    if (cin.fail()) {
                        valid_input = false; 
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (!valid_input) {
                        continue; 
                    }
                    if (valid_input) {
                        break;
                    }
                }   

                for (int i = 0; i < cipher_text.size(); i++) { 
                    if (cipher_text[i] == ' ' ) 
                        cipher_text_withkey += ' ';
                    else if(cipher_text[i] == '1')
                        cipher_text_withkey += to_string(a);
                    else if (cipher_text[i] == '2' )
                        cipher_text_withkey += to_string(b);
                    else if (cipher_text[i] == '3' )
                        cipher_text_withkey += to_string(c);
                    else if (cipher_text[i] == '4' )
                        cipher_text_withkey += to_string(d);
                    else if (cipher_text[i] == '5' )
                        cipher_text_withkey += to_string(e);               
                }
                cout << "Encrypted text: " << cipher_text_withkey << endl;
            }
            else if (choice_menu_2 == 2){
                encryption_with_morse();
            }
            else if (choice_menu_2 == 3 ){
                cout << "Hello to Atabsh Cipher" << endl; //Welcome message 
                cout << "You should enter your message with shift you want 1 or 2" << endl; //note for coreect shift
                string message;
                cin.ignore(256,'\n');
                cout << "Enter your message: ";
                getline(cin, message);
                int shift;
                cout << "Please enter your shift from 1 to 2: ";
                cin >> shift;
                //check if shift is coreect choose
                while (shift < 1 || shift > 2) {
                    cout << "Please enter correct shift from 1 to 2: ";
                    cin >> shift;
                }
                //generate the message
                cin.ignore(); 
                if (shift == 1) {
                    string en_message = shift_by_one_atbash(message);
                    cout << "Your message is: " << en_message << endl;
                } else if (shift == 2) {
                    string en_message = shift_by_two_atbash(message);
                    cout << "Your message is: " << en_message << endl;
                }
            }
        } else if (choice == 2) {
            cout << endl <<"which decrypt would you like to choose " << endl;
            cout << "1:polybius square decrypt " << endl;
            cout << "2:morse decrypt" << endl;
            cout << "3:Atbash decrypt " << endl;
            cout << "Please choose an option: ";

            int decrypt_choice;
            cin >> decrypt_choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }
            if(decrypt_choice == 1){
                string cipher_Text;
                cout << "Enter the encrypted text: ";
                cin.ignore(); // Clear newline character from buffer
                getline(cin, cipher_Text);
                while (!is_Number(cipher_Text)){
                    cout << "Invalid input . Please enter numbers only to decrypt." << endl;
                    cout << "Enter the encrypted test: ";
                    getline(cin, cipher_Text);
                }
                cout << "Enter the key used for encryption: ";
                int a, b, c, d, e;
                while (true) {
                    bool valid_input = true;
                    cin >> a >> b >> c >> d >> e;
                    if ((a < 1 || a > 5) || (b < 1 || b > 5) || (c < 1 || c > 5) || (d < 1 || d > 5) || (e < 1 || e > 5)) {
                        cout << "Invalid input. Please enter a digit from 1 to 5." << endl;
                        valid_input = false;
                    }
                    if ((a == b) || (a == c) || (a == d) || (a == e) || (b == c) || (b == d) || (b == e) || (c == d) || (c == e) || (d == e)) {
                        cout << "Invalid input. Please enter unique digits from 1 to 5." << endl ;
                        valid_input = false;
                    }
                    if (cin.fail()) {
                        valid_input = false; 
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (!valid_input) {
                        continue; 
                    }
                    if (valid_input) {
                        break;
                    }
                }

                string encrypted_Text_withkey = "";
                for (int i = 0; i < cipher_Text.size(); i++) {
                    if (cipher_Text[i] == ' ') 
                        encrypted_Text_withkey += ' ';
                    else if(cipher_Text[i] == '0' + a)
                        encrypted_Text_withkey += '1';
                    else if (cipher_Text[i] == '0' + b)
                        encrypted_Text_withkey += '2';
                    else if (cipher_Text[i] == '0' + c)
                        encrypted_Text_withkey += '3';
                    else if (cipher_Text[i] == '0' + d)
                        encrypted_Text_withkey += '4';
                    else if (cipher_Text[i] == '0' + e)
                        encrypted_Text_withkey += '5';  
                }

                string decrypted_Text = decryptPolybius(encrypted_Text_withkey);
                cout << "Decrypted text: " << decrypted_Text << endl;
            }
            else if (decrypt_choice == 2){
                decryption_with_morse();
            }
            else if (decrypt_choice == 3 ){
                cout << "Hello to Atabsh Cipher" << endl; //Welcome message 
                cout << "You should enter your message with shift you want 1 or 2" << endl; //note for coreect shift
                string message;
                cin.ignore(256,'\n');
                cout << "Enter your message: ";
                getline(cin, message);
                int shift;
                cout << "Please enter your shift from 1 to 2: ";
                cin >> shift;
                //check if shift is coreect choose
                while (shift < 1 || shift > 2) {
                    cout << "Please enter correct shift from 1 to 2: ";
                    cin >> shift;
                }
                //generate the message
                cin.ignore(); 
                if (shift == 1) {
                    string en_message = shift_by_one_atbash(message);
                    cout << "Your message is: " << en_message << endl;
                } else if (shift == 2) {
                    string en_message = shift_by_two_atbash(message);
                    cout << "Your message is: " << en_message << endl;
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }
    return 0; 
}
