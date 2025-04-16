#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<char> s = {'h','e','l','l','o'};
    
    cout << s[0] << s[4] << s.size() <<  endl;

    return 0;
}