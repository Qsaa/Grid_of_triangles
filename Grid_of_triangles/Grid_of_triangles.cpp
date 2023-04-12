#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream in("barrel-nodes.xyz");
    if (!in.is_open())
    {
        cout << "File is not opened" << endl;
        return 0;
    }
    //for (string str; getline(in, str); cout << str << endl);
    
    string str;
    getline(in, str);

    getline(in, str);
    for (auto& c : str)
    {
        if (c == ',')
        {
            c = ' ';
        }
    }
    cout << str << endl;

    stringstream sstr(str);
    
    int n;
    sstr >> n;
    cout << n << endl;

    double x, y, z;
    sstr >> x >> y >> z;
    cout << x << " " << y << " " << z;

    //int n;
    //in >> n;
    //cout << n;

 

    //for (size_t i = 100; i; --i)
    //{
    //    float f;
    //    in >> f;
    //    cout << f;
    //}

    return 0;
}
