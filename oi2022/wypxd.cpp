 #include <bits/stdc++.h>

using namespace std;

struct cie
{
    double x, d, w, m;
};

const int r = 1e5 + 9;

cie T[r];

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double n = a, D = b, W = c, M = d;
    int wyn = 1;
    cin >> a >> b >> c >> d;
    T[1].x = a; T[1].d = b; T[1].w = c; T[1].m = d;
    for(int i = 2; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        T[i].x = a; T[i].d = b; T[i].w = c; T[i].m = d;
        double t = (T[i].x - T[i].d) / (W/M - T[i].w/T[i].m);
        double l = t * T[i].w / T[i].m + T[i].x - T[i].d;
        cout << " #" << l << "# ";
        l -= (t * T[i - 1].w / T[i - 1].m + T[i - 1].x);
        double p = D;
        /*__int128_t p, l;
        l = (T[i].x - T[i].d) * M * T[i].m * (T[i].w * T[i - 1].m - T[i - 1].w * T[i].m);
        //cout << (int)l << " ";
        //l -= T[i].d * T[i].m * T[i - 1].m * (W * T[i].m - T[i].w * M);
        l += (T[i].x - T[i].d) * T[i].m * T[i - 1].m * (W * T[i].m - T[i].w * M);
        l -= T[i - 1].x * T[i].m * T[i - 1].m * (W * T[i].m - T[i].w * M);
        p = D * T[i].m * T[i - 1].m * (W * T[i].m - T[i].w * M);
        if(l == p)
            cout << i;*/
        cout << t << ", " << l << ", " << p << "\n";
        if(l >= p)
            wyn ++;
    }
    cout << wyn;
}
