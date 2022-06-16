#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */

void bonAppetit(vector<int> bill, int indexItemNotEaten, int annaCash) {
    int billTotal = 0;
    int sharedBillTotal = 0;
    int annaSplit = 0;
    int refund = 0;

    //Figure out the total cost of the bill. Loop through array and sum total.
    for (int i = 0; i < bill.size(); i++) {
        billTotal += bill[i];
    }

    //Figure out the cost of the item Anna did not eat (indexItemNotEaten)
    int costOfItemNotEaten = bill[indexItemNotEaten];

    //Divide the remaining amount by 2 to determine the amount that Anna owes
    annaSplit = ((billTotal - costOfItemNotEaten) / 2 );

    //Refund = annaCash - Even split (less item not eaten).
    refund = annaCash - annaSplit;

    //If Anna contributed the right amount, print Bon Appetit. Else print the int amount Brian owes Anna
    if (refund == 0) {
        std::cout << "Bon Appetit" << std::endl;
    }
    else {
        std::cout << refund << std::endl;
    }

}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string bill_temp_temp;
    getline(cin, bill_temp_temp);

    vector<string> bill_temp = split(rtrim(bill_temp_temp));

    vector<int> bill(n);

    for (int i = 0; i < n; i++) {
        int bill_item = stoi(bill_temp[i]);

        bill[i] = bill_item;
    }

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    bonAppetit(bill, k, b);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
