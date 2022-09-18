// TRSPO_HW1_Renskiy_KI-02_18.09.2022

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void Th1() {
	int counter = 1000;
	for (int i = 0; i < 10; i++) {
		cout << "1000-7 = " << counter << "\  FirstThread\t" << i << endl;
		counter = counter - 7;
		this_thread::sleep_for(chrono::milliseconds(500));

	}
}
void Th2() {
	int counter = 1000;
	this_thread::sleep_for(chrono::milliseconds(100));
	// ця затримка для того, щоб два методи не починали виводити повідомлення  у консоль одночасно.
	for (int i = 0; i < 10; i++) {
		cout << "1000-7 = " << counter << "\  SecondThread\t" << i <<  endl;
		counter = counter - 7;
		this_thread::sleep_for(chrono::milliseconds(1000));

	}

}
int main()
{

	cout << "Start Process" << endl;
	thread First(Th1);
	thread Second(Th2);

	Second.join();
	First.join();

	cout << "Process Finished" << endl;

	return 0;
}