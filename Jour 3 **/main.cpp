#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	string bank;

	vector<long long> digitsMax;

	string maxdigitString;
	long long maxdigitValue;

	string digit;
	long long digitInt;

	ifstream entree;
    entree.open("input.txt");

    while (getline(entree, bank))
    {
    	maxdigitString = "";

    	for (int i=0; i<12; i++)
    	{
		    maxdigitString.push_back(bank[i]);
	   	}

	    maxdigitValue = stoll(maxdigitString);

	    for (int i1 = 0; i1 <= (int)bank.length() - 12; ++i1) {
	        for (int i2 = i1 + 1; i2 <= (int)bank.length() - 11; ++i2) {
	            for (int i3 = i2 + 1; i3 <= (int)bank.length() - 10; ++i3) {
	                for (int i4 = i3 + 1; i4 <= (int)bank.length() - 9; ++i4) {
	                    for (int i5 = i4 + 1; i5 <= (int)bank.length() - 8; ++i5) {
	                        for (int i6 = i5 + 1; i6 <= (int)bank.length() - 7; ++i6) {
	                            for (int i7 = i6 + 1; i7 <= (int)bank.length() - 6; ++i7) {
	                                for (int i8 = i7 + 1; i8 <= (int)bank.length() - 5; ++i8) {
	                                    for (int i9 = i8 + 1; i9 <= (int)bank.length() - 4; ++i9) {
	                                        for (int i10 = i9 + 1; i10 <= (int)bank.length() - 3; ++i10) {
	                                            for (int i11 = i10 + 1; i11 <= (int)bank.length() - 2; ++i11) {
	                                                // La dernière boucle s'arrête à la fin de la chaîne
	                                                for (int i12 = i11 + 1; i12 < (int)bank.length(); ++i12) {
	                                                    
	                                                    // Construction de la combinaison de 12 chiffres
	                                                    std::string digit = "";
	                                                    digit.push_back(bank[i1]);
	                                                    digit.push_back(bank[i2]);
	                                                    digit.push_back(bank[i3]);
	                                                    digit.push_back(bank[i4]);
	                                                    digit.push_back(bank[i5]);
	                                                    digit.push_back(bank[i6]);
	                                                    digit.push_back(bank[i7]);
	                                                    digit.push_back(bank[i8]);
	                                                    digit.push_back(bank[i9]);
	                                                    digit.push_back(bank[i10]);
	                                                    digit.push_back(bank[i11]);
	                                                    digit.push_back(bank[i12]);

	                                                    // Conversion et comparaison (utilise stoll pour les grands nombres)
	                                                    long long currentDigitValue = std::stoll(digit);

	                                                    if (currentDigitValue > maxdigitValue) {
	                                                        maxdigitValue = currentDigitValue;
	                                                        maxdigitString = digit;
	                                                    }
	                                                }
	                                            }
	                                        }
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }

	    digitsMax.push_back(maxdigitValue);
	    cout << "Une ligne finie" << endl;
	}

	entree.close();

	long long somme = 0;

	for (long long i : digitsMax)
	{
		somme += i;
	}

	cout << "-----> " << somme << endl;

	return 0;
}