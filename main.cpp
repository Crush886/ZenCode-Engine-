#include <iostream>
#include <chrono>
#include <string>

// 1. 定义链栈节点 - 体现你对数据结构的掌握
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// 2. 核心算法类：ZenStack
template <typename T>
class ZenStack {
private:
    Node<T>* topNode;
    int size;

public:
    ZenStack() : topNode(nullptr), size(0) {}

    // 入栈操作
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    // 出栈操作
    void pop() {
        if (isEmpty()) return;
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }

    bool isEmpty() { return topNode == nullptr; }
    int getSize() { return size; }
};

// 3. 性能测试函数 - 体现 ACM 备赛思维
void runBenchmark(int count) {
    ZenStack<int> stack;
    
    std::cout << "--- Performance Testing: " << count << " elements ---" << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < count; ++i) {
        stack.push(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    
    std::cout << "Pushing time: " << diff.count() << " seconds" << std::endl;
    std::cout << "Current Stack Size: " << stack.getSize() << std::endl << std::endl;
}

int main() {
    std::cout << "ZenCode Engine - Algorithm Core V1.0" << std::endl;
    std::cout << "Stable Biological Clock Sync: Success (Ready at 7:00 AM)" << std::endl; // 一个小彩蛋
    
    // 运行不同量级的测试
    runBenchmark(10000);
    runBenchmark(100000);
    
    return 0;
}
