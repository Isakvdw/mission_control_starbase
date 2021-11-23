#include "ConcreteBuilder.h"
#include "../Rocket.h"
#include "../Propulsion/Engine.h"
#include "Builder.h"
using namespace std;
int main() {
    ConcreteBuilder * CB = new ConcreteBuilder(Rocket::FALCON9, Payload::STARLINK);
    CB->setFirstStageBoosters();
    CB->setPayload(10);
    Rocket * R = CB->buildRocket();
    R->getPayload()->printPayload();
    delete CB;
    delete R;
    return 0;
}
