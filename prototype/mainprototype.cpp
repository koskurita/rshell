#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h> 

using namespace std;


void Parse(string cheese){
    
    string s = "";
    vector<string> temp_vector;
    
    for(unsigned int i = 0; i < cheese.size(); i++){
        if(cheese[i] == ' '){
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
        }
        else if(cheese[i] == '&'){
            s = cheese[i];
            i++;
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(cheese[i] == '|'){
            s = cheese[i];
            i++;
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(cheese[i] == ';'){
            s = cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else{
        s+= cheese[i];
        }
    }
    temp_vector.push_back(s);
    
    
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        std::cout << temp_vector[i] << std::endl;
    }
    
    //converting it to char, does not work properly yet.
    /*
    vector<char*> ggs;
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        
        int n = temp_vector[i].length();
        char charArray[n+1];
        strcpy(charArray, temp_vector[i].c_str());
        ggs.push_back(charArray);
    }
    
    for(unsigned int i = 0; i < ggs.size(); i++){
        cout << ggs[i] << endl;
    }
    */
}





int main(){
    Parse("ls -a; cd -m|| vim READDME.hpp");
    return 0;
}


