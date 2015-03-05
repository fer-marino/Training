#include "threads/mingw.thread.h"

using namespace std;

unsigned long long counter = 0;
int size = 2;

struct Move {
    int row;
    int col;
};

vector<Move> pipeline;

void path(int row, int col) {
    if(row == size && col == size) {
        counter++;
        if(counter % 5000000 == 0)
            cout << "counter " << counter << " pipeline size " << pipeline.size() << " capacity " << pipeline.capacity() << '\n';

    } else {
        if(col+1 <= size) {
            Move adding;
            adding.col = col+1;
            adding.row = row;
            pipeline.push_back(adding);
        }
        if(row+1 <= size ){
            Move adding;
            adding.col = col;
            adding.row = row+1;
            pipeline.push_back(adding);
        }
    }
}

int main() {
    for(size = 2; size < 10; size++) {
        Move adding;
        adding.col = 0;
        adding.row = 0;
        pipeline.push_back(adding);
        while (!pipeline.empty()) {
            Move t = pipeline.back();
            pipeline.pop_back();
            thread(path, t.row, t.col);
            //path(t.row, t.col);
        }

        cout << "Problem 15 solution is " << counter;
    }

    return 0;
}