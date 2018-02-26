#include<iostream>

void move(int h, char from, char to){

    std::cout << "Moving " << h << " from " << from  << " to " << to << "\n";

}
void moveTower(int h, char from , char aux, char to){

    if ( h == 0) return;

    moveTower( h-1, from, to, aux);
    move(h, from, to);
    moveTower( h-1, aux, from, to);
}


int main(){

    char from = 'A';
    char aux  = 'B';
    char to   = 'C';
    int h = 3;
    moveTower( h, from, aux, to);

    return 0;

}
