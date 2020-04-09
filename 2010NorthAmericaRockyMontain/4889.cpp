// Contest - 2010 North American Rockey Mountain
// Problem 4889 - Post Office
// Vincent Cote - CPSC 3200
// Approach - Save the inputs into an array of size 3. Sort the array from smallest to largest, position 0 should be thickness, 1 heigh
// and 2 length. For each input check the rules and return proper package 

#include <iostream>
#include <algorithm>

long double size[3];

bool isLetter() {
	if (size[0] >= 0.25 && size[0] <= 7) {
		if (size[1] >= 90 && size[1] <= 155) {
			if (size[2] >= 125 && size[2] <= 290) {
				return true;
			}
		}
	}
	return false;
}

bool isPacket() {
	if (size[0] >= 0.25 && size[0] <= 50) {
		if (size[1] >= 90 && size[1] <= 300) {
			if (size[2] >= 125 && size[2] <= 380) {
				return size[0] > 7 || size[1] > 155 || size[2] > 290;
			}
		}
	}
	return false;
}

bool isParcel() {
	if (size[0] >= 0.25) {
		if (size[1] >= 90) {
			if (size[2] >= 125) {
				if (size[0] > 50 || size[1] > 300 || size[2] > 380) {
					return  size[2] + (2 * size[0]) + (2 * size[1]) <= 2100;
				}
			}
		}
	}
	return false;
}

int main(void) {
  while (true) {
		long double a, b, c;
		std::cin>>a>>b>>c;
		if (a == 0 && b == 0 && c == 0)
			break;
		size[0] = a;
		size[1] = b;
		size[2] = c;
		std::sort(size, size + 3);
		std::string result = "not mailable";
		if (isLetter())
			result = "letter";
		else if (isPacket())
			result = "packet";
		else if (isParcel())
			result = "parcel";
		std::cout<<result<<std::endl;
    }
	return 0;
}