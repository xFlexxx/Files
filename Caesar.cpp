#include <iostream>
#include <string>

using namespace std;

int findStep(string a) {
	int Step = 0;
	int maxStep = 0;	
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ' ' and a[i] != '!' and a[i] != ',' and a[i] != '?') {
			Step++;
			if (Step > maxStep) {
				maxStep = Step;
				Step = 0;
			}
			if (a[i] == '/') {
				break;
			}
		} else {
			a[i] = a[i+1];
		}
	}
	
	return maxStep;
}

string encryption(string a, int STEP) {
    for (int i = 0; i < a.length(); i++) {
        char shifted = a[i] - STEP;
        if (islower(a[i]) and !islower(shifted) or isupper(a[i]) and !isupper(shifted)) {
            shifted += 26;
        }
        a[i] = shifted;
    }
    
    return a;
}

string decryption(string a, int STEP) {
    for (int i = 0; i < a.length(); i++) {
        char shifted = a[i] + STEP;
        if (islower(a[i]) and !islower(shifted) or isupper(a[i]) and !isupper(shifted)) {
            shifted -= 26;
        }
        a[i] = shifted;
    }
    
    return a;
}

int main() {
    string s;
    cout << "Enter the text with a slash at the end of it" << endl;
    getline(cin, s);
	const int STEP = findStep(s);
    string word = "";
    cout << endl;
    cout << "Answer: ";
    for (char c: s) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (word != ".") {
                cout << encryption(word, STEP);
            }
            cout << c;
            word = "";
        }
    }

    return 0;
}

//Happiness is like one of those palaces on an enchanted island, its gates guarded by dragons. One must fight to gain it.//