//
// Created by Zeeshan Shaikh on 8/12/21.
//

#include <iostream>

using namespace std;

class disjointSet{
private:
    int len;
    int vertex[];

public:

    disjointSet(int num){
        vertex[num];
        for (int j = 0; j < num; j++) {
            vertex[j] = j;
        }
        len = num;
    }

    // Add the union function here
    void unionFunction(int x, int y){
        // This function is used to connect the given vertices
        // Since this is quickFind, we will find the root node and save it in the array
        // instead of the parent node
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX != rootY){
            for (int i = 0; i < len; i++) {
                if(vertex[i] == rootY){
                    vertex[i] = rootX;
                }
            }
        }

    };

    // Add the find function here
    int findRoot(int x){
        return vertex[x];
    };

    // Add the conection function here
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