#include<bits/stdc++.h>
using namespace std;

string Xor(string a, string b)
{
    int n = b.length();
    string result = "";
    for(int i=1; i<n; i++)
        (a[i] == b[i])? result += "0" : result += "1";
    return result;
}

string modTwoDiv(string divident, string divisor)
{
    int n = divident.length(), pick = divisor.length();
    string temp = divident.substr(0, pick);
    while (pick < n)
    {
        if (temp[0] == '1')
            temp = Xor(divisor, temp) + divident[pick];
        else
            temp = Xor(std::string(pick, '0'), temp) + divident[pick];
        pick += 1;
    }
    if (temp[0] == '1')
        temp = Xor(divisor, temp);
    else
        temp = Xor(std::string(pick, '0'), temp);
    return temp;
}

void encodeData(string data, string key)
{
    int keyLength = key.length();
    string appendedData = data + std::string(keyLength-1, '0');     //append n-1 zeros at the end of data
    string reminder = modTwoDiv(appendedData, key);
    string transmitData = data + reminder;
    cout<<"Transmitted data is : "<<transmitData<<endl;
    cout<<"\n\nEnter received frame : ";
    string recvFrame;
    cin>>recvFrame;
    (std::string(key.size()-1, '0') == modTwoDiv(recvFrame, key))? 
    cout<<"Transmitted data is error free\n" : 
    cout<<"Transmitted data has one or more error\n";
}

int main()
{
    string data, key;
    cout<<"Enter data : ";
    cin>>data;
    cout<<"Enter the key : ";
    cin>>key;
    encodeData(data, key);
    return 0;
}