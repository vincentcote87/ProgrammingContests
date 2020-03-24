// Contest - 2010 North American Rockey Mountain
// Problem 4886 - Page Count
// Vincent Cote - CPSC 3200
// Approach - Since any sequence will always be a number followed by a character (either - or ,)
// I grab these two right away. If I get a dash I then grab the next number to calculate the range
// In order to not count things twice I simply add pages to be printed in an array.
// To get the total count I go through the array and count how many 1's I have.
#include <iostream>
#include <sstream>

int main(void) {
	while (true) {
		int pageNum;
		std::cin >> pageNum;
		std::cin.ignore();
		if (pageNum == 0)
			return 0;
		std::string pages;
		std::getline(std::cin, pages);
		std::stringstream iss(pages);
		int pagesToPrint[1001] = {0};
		while (!iss.eof()) {
			int page;
			char ch = '#';
			iss>>page>>ch;
			if (ch == '-') {
				int high;
				iss>>high>>ch;
				if (page <= high && page <= pageNum) {
					int n;
					high < pageNum ? n = high : n = pageNum;
					for (int i = page; i <= n; i++) {
						pagesToPrint[i] = 1;
					}
				}
			} else {
				pagesToPrint[page] = 1;
			}
		}
		int result = 0;
		for (int i = 0; i <= pageNum; i++) {
			if (pagesToPrint[i] == 1)
				result++;
		}
		std::cout<<result<<std::endl;
	}
}