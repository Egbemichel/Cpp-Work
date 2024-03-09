#include <iostream>
#include <ctime>
using namespace std;

void newRegister();
bool validEmail(string);
bool validFirstname(string);
bool validLastname(string);
bool validPassword(string);
void verificationCode();
void login();

int main()
{
    cout << "Welcome to our website" << endl;
    newRegister();
    return 0;
}

void newRegister()
{
    string newRegister, Username, Password, Firstname, Lastname, Email;
    cout << "Would you like to Sign up?. Type no if you already have an account with us" << endl;

    cin >> newRegister;
    cin.ignore();
    if (newRegister == "Yes" || newRegister == "yes")
    {
        cout << "First name: ";
        cin >> Firstname;
        while (validFirstname(Firstname) == false)
        {
            cout << "The name you entered is not valid please try again";
            cin >> Firstname;
        }
        cout << "Valid First name" << endl;

        cout << "Lastname: ";
        cin >> Lastname;
        while (validLastname(Lastname) == false)
        {
            cout << "The last name you entered is not valid please try again";
            cin >> Lastname;
        }
        cout << "Valid Last name" << endl;

        cout << "Email: ";
        cin >> Email;
        while (validEmail(Email) == false)
        {
            cout << "The email you entered is invalid please try again";
            cin >> Email;
        }
        cout << "Valid";

        cout << " Password: ";
        cin >> Password;
        while (validPassword(Password) == false)
        {
            cout << "The password you entered is invalid please try again \n(Note: Password must contain at least one digit, one special character, one uppercase letter, one lowercase letter)";
            cin >> Password;
        }
        cout << "Valid password\n";
        verificationCode();
    }
    else if (newRegister == "No" || newRegister == "no")
    {
        string Username, Password;

        cout << "    Log in   " << endl;
        cout << "Enter your username: " << endl;
        getline(cin, Username);

        cout << " Enter your password: " << endl;
        cin >> Password;

        cout << "Login Success!";
    }
}

bool validEmail(string Email)
{
    int at = -1, dot = -1;
    int countAt = 0, countDot = 0;
    if( (Email[0] >= 'a' && Email[0] <= 'z') ||( Email[0] >= 'A' && Email[0] <= 'Z'))
    {
        for (int i=0; i < Email.length(); i++)
        {
            if (Email[i] == '@')
            {
                at = i;
                countAt++;
            }
            else if (Email[i] == '.')
            {
                dot = i;
                countDot++;
            }
        }
        if (at == -1 || dot == -1)
        
            return false;
        
        if (at > dot)
        
            return false;
        
        if (countAt > 1 || countDot > 1)
        
            return false;
        

        return !(dot >= (Email.length() - 1));
    }
    else if (Email[0] >= '0' && Email[0] <= '9')
    {
        return false;
    }
    else
    {
        return false;
    }
}

bool validFirstname(string Firstname)
{
    if (Firstname[0] >= 'A' && Firstname[0] <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validLastname(string Lastname)
{
    if (Lastname[0] >= 'A' && Lastname[0] <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}
bool validPassword(string Password)
{
    int digit = 0, uppercase = 0, lowercase = 0, specialChar = 0;
    if (Password.length() >= 8 && Password.length() <= 15)
    {
        if (Password.find(" ") == -1)
        {
            for (int i=0; i < Password.length(); i++)
            {
                if (Password[i] >= '0' && Password[i] <= '9')
                {
                    ++digit;
                }
                else if (Password[i] >= 'A' && Password[i] <= 'Z')
                {
                    ++uppercase;
                }
                else if (Password[i] >= 'a' && Password[i] <= 'z')
                {
                    ++lowercase;
                }
                else if (Password[i] == '@' || Password[i] == '#' || Password[i] == '_' || Password[i] == '-' || Password[i] == '~')
                {
                    ++specialChar;
                }
            }
            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialChar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (Password.find(" ") != -1)
        {
            return false;
        }
    }
    cout << "Your password length must be between 8-15 characters" << endl;
    return false;
}
void verificationCode()
{
    int code;

    cout << "We have sent a verification code to your Email. Please check your Email" << endl;
    cout << "Email message: Your Verification code is ";

    srand(time(0));

    for (int i=0; i <= 3; i++)
    {
        cout << rand() % 10;
    }
    cout << "\n";

    cout << "Enter the verification here: " << endl;
    cin >> code;

    cout << "Your account has been verified";
    login();
}
void login()
{
    string Username, Password;
    cin.ignore();
    cout<<"\n\n\n";
    cout << "           Login           \n";
    cout << "Username: " << endl;
    getline(cin, Username);
    cout << "Password: " << endl;
    getline(cin, Password);
    cout << "Login successful";
}
