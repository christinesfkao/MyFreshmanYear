//HW3 cipher.cpp
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

unsigned long long int exp_mod(unsigned long long int, unsigned long long int, unsigned long long int); //function prototype

int main()
{
	//load plain.txt
	ifstream fin_msg;
	string temp;
	string message;

	fin_msg.open("plain.txt", ios::in);

    bool test;

	do
    {
        test = getline(fin_msg, temp);
        message+=temp;
    }
	while(test);

	fin_msg.close();

	//load public_key.txt
	ifstream fin_pub;
	unsigned long long int pub_N;
	unsigned long long int pub_e;

	fin_pub.open("public_key.txt", ios::in);

	fin_pub >> pub_N;
	fin_pub >> pub_e;

	fin_pub.close();

	//RSA encryption

	int secret;
	//create secret.txt
	ofstream fout_secret;

	fout_secret.open("secret.txt", ios::out);

	for (int count = 0; count < message.length(); count += 2)
	{
	    //turn "message" from string(array) into int(every two chars)
	    secret = message[count] * 256 + message[count + 1];

	    //encrypt message using exponentiation by squaring
        unsigned long long int transmit = exp_mod(pub_N, secret, pub_e);

        fout_secret << transmit << endl;
	}

	fout_secret.close();
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
