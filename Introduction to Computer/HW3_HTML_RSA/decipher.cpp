//HW3 decipher.cpp
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

unsigned long long int exp_mod(unsigned long long int, unsigned long long int, unsigned long long int); //function prototype

int main()
{
	//load private_key.txt
	ifstream fin_priv;
	unsigned long long int priv_N;
	unsigned long long int priv_d;

	fin_priv.open("private_key.txt", ios::in);

	fin_priv >> priv_N;
	fin_priv >> priv_d;

	fin_priv.close();

	//RSA decryption

	//load secret.txt
	ifstream fin_sec;
    string secret;
    unsigned long long int _secret;
	fin_sec.open("secret.txt", ios::in);

	//create message.txt
	ofstream fout_message;
	fout_message.open("message.txt", ios::out);

    bool test;
	do
    {
        test = getline(fin_sec, secret);
        fin_sec >> _secret;

        //To TA:
        //I tried to use the getline function by initializing "secret" string-typed,
        //but I didn't figure out how to use strtoull to convert string to unsigned long long int
        //so I can only get half of the message in plain.txt by using both getline and >> at the same time

        //decrypt message using exponentiation by squaring
        unsigned long long int message = exp_mod(priv_N, _secret, priv_d);

        //turn "message" from int into string(array)
        fout_message << (char)message;
    }
	while(test);

	fin_sec.close();
	fout_message.close();
}

unsigned long long int exp_mod(unsigned long long int N, unsigned long long int x, unsigned long long int n)
{
	x %= N;
    if (n == 0)
		return 1;
	else if (n % 2 == 0)//n is even
		return exp_mod(N, x*x%N, n/2)%N;
	else
		return x*exp_mod(N, x*x%N, (n-1)/2)%N;
}
