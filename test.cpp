#include <iostream>
#include "Dragon.h"
using namespace std;
int main() {
    Payload * test = new Dragon();
    cout<<test->getPayloadDescription()<<endl;
    return 0;
}