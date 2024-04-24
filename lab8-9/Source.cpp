#include  <iostream>
#include  <fstream>
#include  <string>
#include  <map>
#include  <algorithm>
#include <queue>

using namespace std;

struct Compare {
    bool operator() (const pair<string, int>& x, const pair<string, int>& y) {
        if (x.second == y.second) {
            return x.first > y.first; // If counts are equal, sort alphabetically
        }
        else {
            return x.second < y.second; // Sort by count
        }
    }
};
int main() {
    std::ifstream inputFile("Source1.txt");
    std::string string, words[101] = {}, empty = "";
    std::getline(inputFile, string);

    // split in words
    int i = 0, j = 0, init = 0;
    while (i < string.size()) {

        int space = string.find(' ', init),
            dot = string.find('.', init),
            comma = string.find(',', init),
            q = string.find('?', init),
            ex = string.find('!', init);
        int aux = string.size();
        if (dot > 0)
            aux = (aux < dot) ? aux : dot;
        if (space > 0)
            aux = (aux < space) ? aux : space;
        if (comma > 0)
            aux = (aux < comma) ? aux : comma;
        if (q > 0)
            aux = (aux < q) ? aux : q;
        if (ex > 0)
            aux = (aux < ex) ? aux : ex;
//aux va avea pozitia primului separator gasit

        if (aux == string.size()) {
            words[j] = string.substr(init, string.size() - init);
            std::transform(words[j].begin(), words[j].end(), words[j].begin(), ::tolower);
            j++;
            break;
        }

        int pos = aux;
        int len = pos - init;
        if (string.substr(init, len).compare("")) {
            words[j] = string.substr(init, len);
            std::transform(words[j].begin(), words[j].end(), words[j].begin(), ::tolower);
            j++;
        }
        init = pos + 1;
        i += len;

    }

    std::map<std::string, int> map;

    for (i = 0; i < j; i++) {
        int counter = 0;
        if (!map[words[i]]) {
            for (int k = 0; k < j; k++) {
                if (words[i].compare(words[k]) == 0) counter++;
            }
            map[words[i]] = counter;
        }

    }


    priority_queue<pair<std::string, int>, vector<pair<std::string, int>>, Compare> pq;

    // Insert elements into the priority queue
    for (const auto& pair : map) {
        if (pair.first.compare("") != 0)
            pq.push(pair);
    }

    // Print the elements in the priority queue
    while (!pq.empty()) {
        auto pair = pq.top();
        cout << pair.first << " => " << pair.second << endl;
        pq.pop();
    }

    inputFile.close();
    return 0;
}
