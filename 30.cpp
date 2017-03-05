#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
using namespace std;
int find_first_word(multimap<string,int> &word_map, string word, multimap<string, int>::iterator& mit) {
    int first = -1;
    for(auto it = word_map.equal_range(word).first; it !=word_map.equal_range(word).second;++it) {
                if (it->second != -1) {
                    if(first == -1) {
                        first = it->second;
                        mit = it;
                    } else if(first > it->second) {
                        first = it->second;
                        mit = it;
                    }
                } else {
                    mit = it;
                    return -1;
                }
            }
    return first;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (s.empty() || words.empty() || words[0].empty() || s.length() < words.size() * words[0].length()) {
        return res;
    }
    multimap<string, int> word_map;
    size_t wl = words[0].length();
    for (size_t i = 0; i < wl; ++i) {
        int match = 0;
        word_map.clear();
        for(vector<string>::iterator it = words.begin(); it != words.end(); ++it)
            word_map.insert(pair<string,int>(*it, -1));
        for(int j = i; j + (words.size() -match)*wl <= s.length();j+=wl) {
            //cout <<"j="<<j<<", match="<<match<<endl;
            if(word_map.find(s.substr(j, wl)) == word_map.end()) {
                if (match > 0) {
                    for(map<string,int>::iterator it = word_map.begin(); it != word_map.end(); ++it)
                    it->second = -1;
                }
                match = 0;
                continue;
            } 
            multimap<string, int>::iterator mit;
            int first = find_first_word(word_map,s.substr(j, wl), mit); 
            if(first == -1) {
                ++match;
                mit->second = j;
                if(match == words.size()) {
                    res.push_back(j - (words.size() - 1)*wl);
                    //cout<<"j="<<j<<",match = "<<match<<",push: "<<res.back()<<endl;
                    string first_w = s.substr(res.back(), wl);
                    find_first_word(word_map,first_w,mit);
                    mit->second = -1;
                    --match;
                }
            } else {
            //cout <<"j="<<j<<", match="<<match<<",word="<<word_map[s.substr(j, wl)]<<endl;
                match = (j - first) / wl;
                for(auto it = word_map.begin(); it !=word_map.end(); ++it) {
                    if (it->second < first)
                        it->second = -1;
                }
                mit->second = j;
            }
        }
    }
    return res;
}

int main(){
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("good");
    words.push_back("best");
    vector<int> res = findSubstring("wordgoodgoodgoodbestword", words);
    for(auto i = res.begin(); i != res.end(); ++i)
        cout << *i <<endl;

    words.clear();
    words.push_back("ab");
    words.push_back("ba");
    res = findSubstring("abababab",words);
    for(auto i = res.begin(); i != res.end(); ++i)
        cout << *i <<endl;

    return 1;
}
