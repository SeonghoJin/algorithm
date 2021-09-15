#include <bits/stdc++.h>

using namespace std;

int N, K;
int seg[2 << 18];

void init(int root = 1, int l = 0, int r = N)
{
    seg[root] = r - l;
    if (r - l == 1)
    {
        return;
    }
    int li = root * 2;
    int ri = root * 2 + 1;
    int m = (l + r) / 2;

    init(li, l, m);
    init(ri, m, r);
}

void die(int dead, int root = 1, int l = 0, int r = N)
{
    if (dead < l || dead >= r)
    {
        return;
    }

    if (r - l == 1)
    {
        if (dead == l)
        {
            seg[root] = 0;
        }
        return;
    }

    int mid = (l + r) / 2;
    seg[root]--;
    die(dead, root * 2, l, mid);
    die(dead, root * 2 + 1, mid, r);
}

int getLivePeople(int right, int root = 1, int l = 0, int r = N)
{
    if (r <= right)
    {
        return seg[root];
    }

    if (l >= right)
    {
        return 0;
    }

    int mid = (l + r) / 2;
    return getLivePeople(right, root * 2, l, mid) + getLivePeople(right, root * 2 + 1, mid, r);
}

int findPerson(int n, int root = 1, int l = 0, int r = N)
{
    if (r - l == 1)
    {
        return l;
    }
    int leftRoot = root * 2;
    int rightRoot = root * 2 + 1;
    int leftPeopleNumber = seg[leftRoot];
    int rightPeopleNumber = seg[rightRoot];
    int m = (l + r) / 2;

    int restPeople = n - leftPeopleNumber;
    if (restPeople > 0)
    {
        return findPerson(restPeople, rightRoot, m, r);
    }
    else
    {
        return findPerson(n, leftRoot, l, m);
    }
    return -2;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    init();

    int current = 0;
    vector<int> answer;
    for (int i = N; i != 0; i--)
    {
        int livePeopleNumber = getLivePeople(current);
        int findPersonIndex = findPerson((livePeopleNumber + K - 1) % i + 1);
        answer.push_back(findPersonIndex);
        die(findPersonIndex);
        current = findPersonIndex;
    }

    cout << "<";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] + 1 << (i == answer.size() - 1 ? ">" : ", ");
    }
}
