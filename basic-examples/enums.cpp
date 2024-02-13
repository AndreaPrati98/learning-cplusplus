#include <iostream>
using namespace std;
/*
    Note about enumerators from the current Google style guide: 

    Enumerators (for both scoped and unscoped enums) should be named either like constants or like macros: either kEnumName or ENUM_NAME.
    Preferably, the individual enumerators should be named like constants. 
    However, it is also acceptable to name them like macros. The enumeration name, UrlTableErrors (and AlternateUrlTableErrors), is a type, and therefore mixed case. 

    Until January 2009, the style was to name enum values like macros. This caused problems with name collisions between enum values and macros. 
    Hence, the change to prefer constant-style naming was put in place. New code should prefer constant-style naming if possible. 
    However, there is no reason to change old code to use constant-style names, unless the old names are actually causing a compile-time problem.
*/

enum class kColor { RED, BLUE, GREEN };
enum class kTraffic { RED, YELLOW, GREEN };

enum DAYS { MON, TUE, WED };
enum CAL { THU, FRI, SAT };

int main() {

    cout << (kTraffic::RED == kTraffic::RED) << endl;
    
    cout << (DAYS::MON == CAL::THU) << endl; // this is true

    // cout << (kColor::RED == kTraffic::RED) << endl; // ! error, since the two class are not comparables

    return 0;
}