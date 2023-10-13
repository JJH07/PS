//
//  main.cpp
//  10984
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, N, tot_grade, grade;
    double tot_score, score;
    
    
    std::cout.precision(2);
    std::cin >> T;
    while(T--)
    {
        tot_grade = 0;
        tot_score = 0.0;
        std::cin >> N;
        for(int i = 0; i < N; i++)
        {
            std::cin >> grade >> score;
            tot_grade += grade;
            tot_score += grade * score;
        }
        std::cout << tot_grade << ' ' << tot_score / tot_grade << '\n';
    }
    return 0;
}
