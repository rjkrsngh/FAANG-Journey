#include <iostream>
#include <map>
#include <set>

using namespace std;

template<typename K, typename V>
void remove_keys(std::map<K, V> &mp, std::set<K> &st) {
    auto it=mp.begin();
    while(it != mp.end()) {
        if(st.find(it->first) != st.end()) {
            it = mp.erase(it);
        }
        else {
            ++it;
        }
    }
}

int main() {
    std::map<int, int> mp{{0,0}, {1,1}, {2,2}, {3,3}, {4,4}};
    std::set<int> keys_to_remove{0,2};

    std::cout<<"Contents of map\n";
    for(auto it=mp.begin(); it!=mp.end(); ++it) {
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }

    remove_keys(mp, keys_to_remove);

    std::cout<<"Contents of map after removing elements from keys set\n";
    for(auto it=mp.begin(); it!=mp.end(); ++it) {
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }

    return 0;
}