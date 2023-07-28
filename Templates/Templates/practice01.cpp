#include <iostream>
using namespace std;

template<typename T>

T largeNum(T first, T second) {
	return (first > second) ? first : second;
}

int main() {
	largeNum(1.1, 2.2);


	return 0;

}