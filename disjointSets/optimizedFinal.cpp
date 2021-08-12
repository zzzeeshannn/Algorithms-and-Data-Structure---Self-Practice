//
// Created by Zeeshan Shaikh on 8/12/21.
//

#include <iostream>

using namespace std;

class disjointSet{
private:
    int len;
    int rank[100];
    int vertex[];


public:

    disjointSet(int num){
        int rank[num];
        vertex[num];
        for (int j = 0; j < num; j++) {
            vertex[j] = j;
            rank[j] = 0;
        }
        len = num;
    }

    // Add the union function here
    void unionFunction(int x, int y){
        // This function is used to connect the given vertices
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        int rankX = rank[rootX];
        int rankY = rank[rootY];

        if (rankX != rankY){
            if(rankX > rankY){
                vertex[y] = rootX;
            }
            else if (rankY > rankX){
                vertex[x] = rootY;
            }
            else{
                vertex[y] = rootX;
                rank[x] += 1;
            }
        }

    };

    // Add the find function here
    int findRoot(int x){
        if(x == vertex[x]){
            return x;
        }
        return vertex[x] = findRoot(vertex[x]);
    };

    // Add the connection function here
    // This function is used to find if the vertices are connected or not
    bool isConnected(int x, int y){
        // Boolean function that returns if they have the same root node
        // Since the array is already sorted, we just return the values in vertex array
        return vertex[x] == vertex[y];
    };

};

int main(){
    disjointSet d(10);

    // Connecting the nodes
    // 1-2-5-6-7 3-8-9 4

    d.unionFunction(1, 2);
    d.unionFunction(2, 5);
    d.unionFunction(5, 6);
    d.unionFunction(6, 7);
    d.unionFunction(3, 8);
    d.unionFunction(8, 9);

    // Sanity check
    for (int i = 0; i < 10; i++) {
        cout << d.findRoot(i) << endl;
    }

    cout << endl;
    cout << d.isConnected(1, 5) << endl; // Should be true
    cout << d.isConnected(4,9) << endl; // Should be false

    return 0;
}