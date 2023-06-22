/*2.Ќапишите функцию, котора€
Х	называетс€ PalindromFilter
Х	возвращает vector
Х	принимает vector words и int minLength и возвращает все строки из вектора words,
которые €вл€ютс€ палиндромами и имеют длину не меньше minLength
¬ходной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string& word) {
   
    int dlina = word.size();
    for (int i = 0; i < dlina / 2; i++) {

        if (word[i] != word[dlina - 1 - i]) return false;
            
    }
    return true;
}

vector<string> PalindromFilter( vector<string>& words, int minLength) {

    vector<string> palindromes;
    for (auto word : words) {
        if (word.size()<100 && word.size() >= minLength && IsPalindrom(word)) {
            palindromes.push_back(word);
        }
    }
    return palindromes;
}

int main() {

    vector<string> words;
    string slovo;
    cout << "enter words(to complete enter '1'):" << endl;
    while (true) {
        getline(cin, slovo);
        if (slovo == "1")
            break;
        if (slovo.size() > 100)
        {
            cout << "this word is too long,please enter another word" << endl;
            continue;
        }
        if (words.size() > 100)
        {
            cout << "u can't enter more than 100 words!" << endl;
            break;
        }
     
        words.push_back(slovo);
    }

    int minLength;
    cout << "enter minLength: ";
    cin >> minLength;

    vector<string> result = PalindromFilter(words, minLength);

    cout << "Palindromes with minimum length " << minLength << ":" << endl;
    for (auto word : result) {

        cout << word << endl;
    }

    return 0;
}
