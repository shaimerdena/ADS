#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, string> old_to_new;
    map<string, string> new_to_old;

    for(int i=0; i<n; i++){
        string old_name, new_name;
        cin >> old_name >> new_name;
        if(new_to_old.find(old_name) != new_to_old.end()){
            old_to_new[new_to_old[old_name]] = new_name;
            new_to_old[new_name] = new_to_old[old_name];
            new_to_old.erase(old_name);
        }
        else{
            old_to_new[old_name] = new_name;
            new_to_old[new_name] = old_name;
        } 
    }
    cout << old_to_new.size() << endl;
    map<string, string> :: iterator it;
    for(it = old_to_new.begin(); it!= old_to_new.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}