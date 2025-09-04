#include <bits/stdc++.h>
using namespace std;

struct F
{
    int pass;
    int total;
    double avg;
    double potentiality;
    bool operator<(const F &other) const
    {
        return potentiality < other.potentiality;
    }
};

class Solution
{

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<F> pq;

        for (const auto &c : classes)
        {
            F t{c[0], c[1], 1.0 * c[0] / c[1], (1.0 * c[0] + 1) / (c[1] + 1) - (1.0 * c[0] / c[1])};
            pq.push(t);
        }

        while (extraStudents--)
        {
            F top = pq.top();
            pq.pop();

            F next = {top.pass + 1, top.total + 1, (1.0 * top.pass + 1) / (top.total + 1), (1.0 * top.pass + 2) / (top.total + 2) - (top.total + 1, (1.0 * top.pass + 1) / (top.total + 1))};
            // cout << next.pass << " " << next.total << " " << next.avg << '\n';
            pq.push(next);
        }

        double answer = 0;

        while (!pq.empty())
        {
            F top = pq.top();
            answer += top.avg;

            pq.pop();
        }

        return answer / classes.size();
    }
};