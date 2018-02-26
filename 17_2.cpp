#include<bits/stdc++.h>

void shuffleArray(int cards[], int len){

    for(int i=0; i < len; ++i){
	srand (time(NULL));
	int k = rand()%len + 1;

	std::swap(cards[k], cards[i]);

    }
}

int main(){


    int card[] = {1,2,3,4,5};

    shuffleArray(card, 5);

    for (int i=0; i< 5; ++i){
	std::cout << card[i] << " ";
    }

    std::cout << std::endl;

}
