#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

const int n; // n là số lượng tiến trình
semaphore S = 1;

void P(int i) { // tiến trình P(i)
    for (;;) { // lặp vô hạn
        Wait(S);
        // <Đoạn nguy hiểm>
        Signal(S);
        // <Phần còn lại của tiến trình>
    }
}

int main() {
    // Khởi tạo tiến trình chính, chạy đồng thời n tiến trình
    pthread_t threads[n];

    for (int i = 0; i < n; ++i) {
        pthread_create(&threads[i], NULL, P, (void *)(intptr_t)(i + 1));
    }

    // Chờ các tiến trình hoàn thành
    for (int i = 0; i < n; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

bool chopstick[5] = {false, false, false, false, false};
void Philosopher(int i) {
    for(;;) {
        while(test_and_set(chopstick[i]));
        while(test_and_set(chopstick[(i+1)%5]));
        <ăn cơm>
        chopstick[i] = false;
        chopstick[(i+1)%5] = false;
        <suy nghĩ>
    }
}
int main() {
    Start process(Philosopher(1));
    Start process(Philosopher(2));
    Start process(Philosopher(3));
    Start process(Philosopher(4));
    Start process(Philosopher(5));
}