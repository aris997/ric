#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hello
{
    double counter;
    char gender;
};



int main() {
    srand(time(NULL));
    printf("Hello world\n");

    struct hello m;
    m.counter = 1;
    m.gender = 'm';

    struct hello f;
    f.counter = 1.;
    f.gender = 'f';

    for (int i = 0; i < 1000000; i++){
        m.counter += (double)rand()/RAND_MAX;
        f.counter += (double)rand()/RAND_MAX;
    }
    
    char winner;

    if (m.counter > f.counter){
        winner = m.gender;
    } else if(m.counter == f.counter) {
        winner = '-';
    } else {
        winner = f.gender;
    }

    printf("%.2f %c, %.2f %c\nWinner: %c\n%.3f\n", m.counter, m.gender, f.counter, f.gender, winner, (double)rand()/RAND_MAX);

    return 0;
}
