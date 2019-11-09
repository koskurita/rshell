//#include <> everything
//
#include <string>
using namespace std;

int main(){
UserInput * mainVec = new Line();

string input = "";
while (input != "exit" || input != "Exit"){
cout << "$";
getline(cin,input);
cout << endl;
mainVec->parseUserInput(input);
}





}
