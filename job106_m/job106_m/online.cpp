//仔細研究了一下STL，發現還是挺好用的：
#include <iostream>

#include <string>

using namespace std;



int main()

{freopen("in.txt","r",stdin);

    string s, t, r;

        while(getline(cin, s))

        {

                cin >> t >> r;

                // add blank to both sides

                s.insert(0," "); s += " ";

                t.insert(0," "); t += " ";

                r.insert(0," "); r += " ";

                while(int(s.find(t)) >= 0)

                {

                        s.replace(int(s.find(t)), t.length(), r);

                }

                s.erase(s.begin());

                s.erase(s.end() - 1);

                cout << s << endl;

                cin.ignore();

        }

        return 0;

}