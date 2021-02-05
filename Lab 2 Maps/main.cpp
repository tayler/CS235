#include <set>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

// see https://github.com/BYUCS235/sets

int main(int argc, char *argv[]) {
	vector<string> tokens;
    set <string> unique;
    string next_line;
    string filename = argv[1];
    ifstream in(filename);
    ofstream setFile(filename + "_set.txt");
    ofstream vecFile(filename + "_vector.txt");
    ofstream mapFile(filename + "_map.txt");
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
                // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    // Part 1: print all unique words in 1Nephi.txt_set.txt
    for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it) {
        setFile << *it;
        // print new line if this isn't the last item in the set
        if (next(it) != unique.end()) {
            setFile << endl;
        }
    }

    // Part 2: print the contents of the vector to a new file (1Nephi.txt_vector.txt)
    for (size_t i = 0; i < tokens.size(); i++) {
        vecFile << tokens[i];
        // print new line if this isn't the last item in the set
        if (tokens[i] != tokens.back()) {
            vecFile << endl;
        }

    }

    // Part 3: create a map with the previous word as key and the next word as value
    // I could do a lot of this in the loop above, but this keeps the steps separate
    map<string, string> wordMap;
    string previousWord = "";

    // for loop
    // for (size_t i = 0; i < tokens.size(); i++) {
    // range-based for loop
    for (auto & token : tokens) {
        // cout << "key: " << last << "; value: " << token << endl;
        wordMap[previousWord] = token;
        previousWord = token;
    }
    
    // iterate through map and add lines to file
    // see also Lab 1 TodoList.h `remove()`
    // since this is a `map`, the items in it are sorted alphabetically by key. That is why the file output is not in the order of the original text.
    auto iter = wordMap.begin();
    while (iter != wordMap.end()) {
        mapFile << iter->first << ", " << iter->second;
        if (next(iter) != wordMap.end()) {
            mapFile << endl;
        }
        iter++;
    }

    // Part 4: generate new text. e.g., "I and endure to the last day And thus it is Amen And thus it is Amen And thus it is Amen..."
    // (commenting out so I don't have to see the output every time)
//    string state = "";
//    for(int i = 0; i < 100; i++){
//        cout << wordMap[state] << " ";
//        state = wordMap[state];
//    }
//    cout << endl;

    // Part 5: change how we keep track of words in the word map. Keep track of each word seen after every word.
    map<string, vector<string>> wordMap2;
    string state2 = "";
    for (auto & token : tokens) {
        // if `state2` here is "Nephi", the items in the vector will be "having", "do", "will", "being", etc.
        // There's an entry for each word that comes after "Nephi" in the text.
        wordMap2[state2].push_back(token);
        state2 = token;
    }
    // print out the vector items for the 6th item
    // (commenting out since it was just a test)
//    auto iter2 = wordMap2.begin();
//    int count = 1;
//    while (count <= 6) {
//        if (count == 6) {
//            cout << "words in the 6th item (" << iter2->first << "):" << endl;
//            for (auto & word : iter2->second) {
//                // only entry is "ye"
//                cout << word << endl;
//            }
//            break;
//        }
//        count++;
//        iter2++;
//    }

    // new sermon by picking words known to follow other words in the text
    srand(time(nullptr)); // this line initializes the random number generated
    // so you dont get the same thing every time
//    string state3 = "";
//    for (int i = 0; i < 100; i++) {
//        int ind = rand() % wordMap2[state3].size();
//        cout << wordMap2[state3][ind] << " ";
//        state3 = wordMap2[state3][ind];
//    }
//    cout << endl;

    // Part 6: use phrases as keys instead of single words
    map<list<string>, vector<string>> wordMap3;
    list<string> state4;
    int M = 2; // M is how many words in a row it uses as the map key
    for (int i = 0; i < M; i++) {
        state4.push_back("");
    }



    for (auto & token : tokens) {
        wordMap3[state4].push_back(token);
        state4.push_back(token);
        state4.pop_front();
    }

    // generate new sermon
//    state4.clear();
//    for (int i = 0; i < M; i++) {
//        state4.push_back("");
//    }
//    for (int i = 0; i < 100; i++) {
//        int ind = rand() % wordMap3[state4].size();
//        cout << wordMap3[state4][ind]<<" ";
//        state4.push_back(wordMap3[state4][ind]);
//        state4.pop_front();
//    }

    // get a random key for wordMap3. Otherwise, it always starts with one of 4 or 5 keys
//    auto wordMap3It = wordMap3.begin();
//    std::advance(wordMap3It, rand() % wordMap3.size());
//    list<string> random_key = wordMap3It->first;
//    state4 = random_key;


    // Part 7: Do something creative - haiku
    // how many words per line
    vector<int> wordCountPerLine({3,4,3});
    // for each line in the poem
    for (int countIdx = 0; countIdx < wordCountPerLine.size(); countIdx++) {
        // print the number of lines specified in
        for (int i = 0; i < wordCountPerLine[countIdx]; i++) {
            int ind = rand() % wordMap3[state4].size();
            cout << wordMap3[state4][ind]<<" ";
            state4.push_back(wordMap3[state4][ind]);
            state4.pop_front();
        }
        cout << endl;
    }

    return 0;
}
