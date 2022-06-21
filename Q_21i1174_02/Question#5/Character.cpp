#include <iostream>
#include "Character.h"
using namespace std;
Character::Character()
{
    characters = 'l';
}
Character::Character(int x)
{

    characters = static_cast<char>(x);
}
// Character::Character(string)
// {

// }
void Character::set(char x)
{
    characters = x;
}
char Character::get() const
{
    return characters;
}
Character Character::isEqualTo(Character &t)
{
    cout << "The characters of the two objects are " << (static_cast<int>(characters) == static_cast<int>(t.get())) << endl;
};
// Compares two Character objects numerically
Character Character::isNotEqualTo(Character &t)
{
    cout << "The characters of the two objects are " << (static_cast<int>(characters) != static_cast<int>(t.get())) << endl;
};
Character Character::isGreaterThan(Character &t)
{
    cout << "The character of the object1 is " << ((static_cast<int>(characters) > static_cast<int>(t.get())) ? " greater than " : " not greater than ") << " object2 character " << endl;
};
Character Character::isLessThan(Character &t)
{
    cout << "The character of the object1 is " << ((static_cast<int>(characters) < static_cast<int>(t.get())) ? " lesser than " : " not lesser than ") << " object2 character " << endl;
};

Character Character::isGreaterThanOrEqualTo(Character &t)
{
    if (static_cast<int>(characters) > static_cast<int>(t.get()))
        cout << "The character of object 1 is greater than  the character of object 2 \n";
    else if (static_cast<int>(characters) == static_cast<int>(t.get()))
        cout << "The character of object 1 is equal to the character of object 2 \n";
        else 
            cout<<"Both of the conditions are not satisfied \n";

};
Character Character::isLessThanOrEqualTo(Character &t)
{
    if (static_cast<int>(characters) < static_cast<int>(t.get()))
        cout << "The character of object 1 is lesser than  the character of object 2 \n";
    else if (static_cast<int>(characters) == static_cast<int>(t.get()))
        cout << "The character of object 1 is equal to the character of object 2 \n";
    else 
    cout<<"Both of the conditions are not satisfied \n";
};
string Character ::stringValue()
{
     string temp(1, this->characters);
    return temp;
};
Character Character::isAlpha(const Character &t)
{
    if ((characters >= 65 && characters <= 91) || (characters >= 97 && characters <= 122))
        cout << " Character of object 1 is an alphabet \n";
    else 
    cout<<"Character of object 1 is not an alphabet \n";
    if ((t.get() >= 65 && characters <= 91) || (characters >= 97 && characters <= 122))
        cout << " Character of object 2 is an alphabet \n ";
        else
            cout<<"Character of object 1 is not an alphabet \n";

};
Character Character::isNum(const Character &t)
{
    if (characters >= 48 && characters <= 57)
        cout << " Character of object 1 is a number ";
        else
            cout<<"Character of object 1 is not an number \n";

    if (t.get() >= 48 && t.get() <= 57)
        cout << " Character of object 2 is a number ";
        else
            cout<<"Character of object 1 is not an number \n";

};
Character Character::isLower(const Character &t)
{
    if ((characters >= 97 && characters <= 122))
        cout << " Character of object 1 is a lower case alphabet \n";
        else 
            cout<<"Character of object 1 is not a lower case alphabet \n";

        
    if ((t.get() >= 97 && t.get()<= 122))
        cout << " Character of object 2 is a upper case alphabet \n ";
        else 
            cout<<"Character of object 2 is not a upper case alphabet \n";

};
Character Character::isUpper(const Character &t)
{
    if ((characters >= 65 && characters <= 91))
        cout << " Character of object 1 is an upper case alphabet \n";
        else 
            cout<<"Character of object 1 is not an upper case alphabet \n";

    if ((t.get() >= 65 && t.get() <= 91))
        cout << " Character of object 2 is an upper case alphabet \n ";
        else 
            cout<<"Character of object 2 is not an upper case alphabet \n";

};
Character Character::toUpper(Character &t)
{
    if ((characters >= 97 && characters <= 122))
    {
        characters = characters - 32;
        cout << " Character of object 1 has been converted to an upper case alphabet : "<<characters<<endl;
    }
    if ((t.get() >= 97 && t.get() <= 122))
    {
        t.set(t.get() - 32);
        cout << " Character of object 2 has been coverted to an upper case alphabet : "<<t.get()<<endl;
    }
};
Character Character::toLower(Character &t)
{
    if ((characters >= 65 && characters <= 91))
    {
        characters = characters + 32;
        cout << " Character of object 1 has been converted to a lower case alphabet : "<<characters<<endl;
    }
    if ((t.get() >= 65 && t.get()<= 91))
    {
        t.set(t.get() + 32);
        cout << " Character of object 2 has been coverted to a lower case alphabet : "<<t.get()<<endl;
    }
};
Character Character:: plus(const Character &t){
    Character temp;
    // cout<<characters + t.get()<<endl;
        temp.set(characters + t.get());
        return temp;
};
Character Character:: minus(const Character &t)
{
        Character temp;
        // cout<<characters - t.get()<<endl;
        temp.set(characters - t.get());
        return temp;

}
