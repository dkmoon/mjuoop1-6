#include <map>
#include <iostream>


using namespace std;


void count(bool asc) {
	string s;
	map<string, int> m;

	// EOF 가 올 때까지 단어별 입력 처리
	while (cin >> s) {
		// 소문자로 변경
		for (auto& c : s) {
			if (c >= 'A' && c <= 'Z') {
				c = c - 'A' + 'a';
			}
		}
		// 단어 빈도 계산
		++m[s];
	}

	// flag 에 따라 오름차순 정렬 혹은 내림차순 정렬
	if (asc) {
		for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
			cout << it->first << " " << it->second << endl;
		}
	}
	else {
		for (map<string, int>::const_reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
			cout << it->first << " " << it->second << endl;
		}
	}
}


int main(int argc, char* argv[]) {
	bool asc = true;

	for (int i = 0; i < argc; ++i) {
		const string arg{ argv[i] };
		if (arg == "/asc") {
			asc = true;
		}
		else if (arg == "/des") {
			asc = false;
		}
	}
	count(asc);
}