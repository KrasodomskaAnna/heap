#include "Heap.h"

int main() {
    Heap heap;
    char command;
    while (std::cin >> command) {
        if (command == '+') {
            int n;
            std::cin >> n;
            std::string date, name;
            for(int i = 0; i < n; i++) {
                std::cin >> date >> name;
                Person element = Person(date, name);
                heap.put(element);
            }
        }
        if (command == '-') {
            int m;
            std::cin >> m;
            for(int i = 0; i < m; i++)
                heap.deleteLimit();
        }
        if (command == 'p')
            heap.print();
        if (command == 'r')
            heap.changeOrientation();
        if (command == 'q')
            break;
    }
    return 0;
}
