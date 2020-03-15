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
			char ch;
			iss>>page>>ch;
			if (ch == '-') {
				int high;
				iss>>high>>ch;
				if (page <= high && page < pageNum) {
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

		// std::cout << "Page number: " << pageNum << " " << pages << std::endl;
		// for (int i = 0; i <= pageNum; i++) {
		// 	std::cout<<pagesToPrint[i]<<" ";
		// }
		// std::cout<<std::endl;
	}
}