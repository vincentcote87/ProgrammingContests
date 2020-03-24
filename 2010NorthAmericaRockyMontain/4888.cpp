// Contest - 2010 North American Rockey Mountain
// Problem 4886 - Railroad
// Vincent Cote - CPSC 3200
// Approach -
#include <iostream>
#include <queue>

int n1, n2;
int q1[1000001] = {0};
int q2[1000001] = {0};
int seq[2000002] = {0};

bool check(std::queue<int> seq, std::queue<int> q1, std::queue<int> q2) {
	if (q1.empty() && q2.empty())
		return true;
	if (seq.empty())
		return false;
	std::queue<int> seqCopy = seq;
	std::queue<int> q1Copy = q1;
	std::queue<int> q2Copy = q2;
	int nextInSeq = seqCopy.front();
	seqCopy.pop();
	if (!q1Copy.empty() && q1Copy.front() == nextInSeq) {
		q1Copy.pop();
		check(seqCopy, q1Copy, q2Copy);
	} else if (!q2Copy.empty() && q2Copy.front() == nextInSeq) {
		q2Copy.pop();
		check(seqCopy, q1Copy, q2Copy);
	}
}

bool foo(int q1Pos, int q2Pos, int seqPos) {
	std::cout<<seqPos<<std::endl;
	if (q1Pos == (n1 - 1) && q2Pos == (n2 - 1)) {
		std::cout<<"In here"<<std::endl;
		return true;
	}
	if (seqPos == (n1 + n2 - 2))
		return false;

	if (q1Pos < (n1 - 1) && q1[q1Pos] == seq[seqPos]) {
		std::cout<<"In q1"<<std::endl;
		return foo(q1Pos + 1, q2Pos, seqPos + 1);
	}
	if (q2Pos < (n2 - 1) && q2[q2Pos] == seq[seqPos]) {
		std::cout<<"In q2"<<std::endl;
		return foo(q1Pos, q2Pos + 1, seqPos + 1);
	}
	return foo(q1Pos, q2Pos, seqPos + 1);
}

int main(void) {
	while (true) {
		std::cin>>n1>>n2;
		if (n1 == 0 && n2 == 0)
			return 0;
		// std::queue<int> q1, q2, seq;

		for (int i = 0; i < n1; i++) {
			int tmp;
			std::cin>>tmp;
			q1[i] = tmp;
			// q1.push(tmp);
		}
		for (int i = 0; i < n2; i++) {
			int tmp;
			std::cin>>tmp;
			q2[i] = tmp;
			// q2.push(tmp);
		}
		for (int i = 0; i < (n1 + n2); i++) {
			int tmp;
			std::cin>>tmp;
			seq[i] = tmp;
			// seq.push(tmp);
		}
		// for (int i = 0; i < 10; i++) {
		// 	std::cout<<seq.front()<<std::endl;
		// 	seq.pop();
		// }
		std::cout<<(foo(0, 0, 0) ? "possible" : "not possible")<<std::endl;




		// for (int i = 0; i < n1 + n2; i++) {
		// 	int nextInSeq = seq.front();
		// 	seq.pop();
		// 	std::cout<<"Next is "<<nextInSeq<<" and q1 is "<<q1.front()<<" and q2 is "<<q2.front()<<" q1 is empty "<<q1.empty()<<std::endl;
		// 	if (!q1.empty() && q1.front() == nextInSeq) {
		// 		q1.pop();
		// 	} else if (!q2.empty() && q2.front() == nextInSeq) {
		// 		q2.pop();
		// 	} else {
		// 		std::cout<<"not possible"<<std::endl;
		// 		break;
		// 	}
		// }
		// if (q1.empty() && q2.empty()) {
		// 	std::cout<<"possible"<<std::endl;
		// }
	}
}