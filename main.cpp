/*
    191
    pigLatinize
    main
    pjirele, jkilloy
*/

#include <iostream>
#include <string>

using namespace std;

bool isConsonant(char);
bool isVowel(char);
int findFirstVowel(string);
string getOriginalString();
void displayResultString(string);
string getFirstWord(string);
string eraseFirstWord(string);
string pigLatinize(string);



void main()
{
 
    string originalString, resultString = "", firstWord; //resultString is empty

    originalString = getOriginalString();

    while (!originalString.empty()) {

        firstWord = getFirstWord(originalString);

        originalString = eraseFirstWord(originalString);

        resultString += pigLatinize(firstWord);

    } //while

    displayResultString(resultString);

   
} // end main



bool isConsonant(char ch) {

    //return true if ch is a consonant, false otherwise; be smart about

     //this function; don't write 20 or comparisons

    if (ch != ' ' && !isVowel(ch))
        return true;
    else
        return false;

} // end isConsonant



bool isVowel(char ch) {

    //returns true if ch is a vowel, false otherwise

    string vowels = "aeiou";
    if (vowels.find(ch) != string::npos)
        return true;
    else
        return false;

} // end isVowel




int findFirstVowel(string s) {

    int ch;
    int i = 0;
    while (i < s.length())
    {
        ch = s[i];

        if (isVowel(ch) == true)
        {
            return i;
        }
        i++;
    } // end while

    return string::npos;

} // end findFristVowel



string getOriginalString() {

    //ask the user for the string, read it (it may include blanks

     //of course) and return it

    cout << "Enter a string" << endl;
    string str;
    getline(cin, str);
    return str;


} // getOriginalString

void displayResultString(string r) {

    cout << r << endl;

} // end displayResultString


string getFirstWord(string s) {

    //return the first word, without the blank (at the end);  if there is only 1 word

    //then return it

    string firstWord;
    int fbp;

    fbp = s.find(' ');
    firstWord = s.substr(0, fbp);
    return firstWord;


} // getFirstWord

string eraseFirstWord(string s) {

    //return the string with the first word, and the blank after it (if present),

     //removed
    int fbp;
    
    fbp = s.find(' ');
    if (fbp == string::npos) {
        s.erase(0, string::npos);
    } // end if
    else 
    {
        s.erase(0, fbp + 1);
    } // end else
    return s;


} // end eraseFirstWord

string pigLatinize(string s) {

    //returns the result of pig-latinizing one word

    if (isConsonant(s[0])) {

        int fvp = findFirstVowel(s);

        string temp = s.substr(0, fvp);

        return s.erase(0, fvp) + temp + "ay ";

    }

    else {

        return s + "ay ";

    }

} // end pigLatinize

