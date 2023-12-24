#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
 
void func(std::vector<std::vector<int>>& all_answers, int n, int k)
{
    std::vector<int> answer;
    for (int i = n - k; i <= n; i++)
    {
        answer.push_back(i);
    }
    for (int i = n-k-1; i >= 1; i--)
    {
        answer.push_back(i);
    }
    all_answers.push_back(answer);
}
 
int main()
{
    int num = 0, n, k;
    std::vector<std::vector<int>>answers;
    std::cin >> num;
    while (num--)
    {
        std::cin >> n >> k;
        func(answers, n, k);
    }
    for (auto x : answers)
    {
        for (int k : x)
        {
            std::cout << k << ' ';
        }
        std::cout << '\n';
    }
}

