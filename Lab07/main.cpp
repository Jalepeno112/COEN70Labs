#include "map.h"
#include <iostream>

int main () {
    Map <float,bool> m;
    m.insert(13.3, true);
    m.insert(1, false);
    m.insert(3.14, false);
    m.print();
    m.remove_key(1);
    m.print();
    cout << m.contains_key(-2) << endl;
    cout << m.contains_key(3.14) <<endl;
	return 0;
}//end main
