#include <mutex>
#include <thread>
#include <iostream>

std::mutex mutexRead; // Мьютекс для читателей
std::mutex mutexWrite; // Мьютекс для писателей
std::mutex counterMutex; // Мьютекс - "заглушка"
int numberReaders; // Количество читателей

void write() {
	mutexWrite.lock();
	mutexRead.lock();
  
	// Writing something
  
	mutexWrite.unlock();
	mutexRead.unlock();
}

void read() {
	mutexWrite.lock();
	counterMutex.lock();
	int previous = numberReaders;
	numberReaders += 1;
	if (previous == 0)
		mutexRead.lock();
	counterMutex.unlock();
	mutexWrite.unlock();

	// Reading something

	counterMutex.lock();
	numberReaders -= 1;
	int current = numberReaders;
	if (current == 0)
		mutexRead.unlock();
	counterMutex.unlock();
}

/*void threadFunction(int& i) {
	std::cout << i << " number of thread" << std::endl;
}*/

/*int main() {
	int i = 5;
	std::thread thr(threadFunction, std::ref(i));
	thr.join();
	std::cout << i;
	return 0;
}*/
