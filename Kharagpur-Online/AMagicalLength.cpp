/*
ID: tle4ever
PROG:
LANG: C++
NOTE: THIS QUES IS SAME AS CODEJAM WORLD FINALS 2009 LINK HERE : https://code.google.com/codejam/contest/dashboard?c=311101#s=p1&a=1
WE HAVE DIRECTLY USED THE CODE FROM ONE OF THE WORLD FINAL SUBMISSIONS. THIS IS A STANDARD PROBLEM. 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
const int MaxN = 1000 * 1000;
const double inf = 1e100;
const double ep = 1e-10;

#define x first
#define y second
typedef pair<double, double> Pt;

int N;
Pt p[MaxN + 10], tp[MaxN + 10];

// ref: d * d
double Dist(Pt const& a, Pt const& b, Pt const& c, double ref = inf) {
	double dx;
	double dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	double tab = dx * dx + dy * dy;
	if (tab >= ref) return inf;

	dx = a.x - c.x;
	dy = a.y - c.y;
	double tac = dx * dx + dy * dy;
	if (tac >= ref) return inf;

	dx = b.x - c.x;
	dy = b.y - c.y;
	double tbc = dx * dx + dy * dy;
	if (tbc >= ref) return inf;

	return sqrt(tab) + sqrt(tbc) + sqrt(tac);
}

inline bool CmpYX(Pt const& a, Pt const& b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int midX;
double pp;

bool LoXTest(Pt const& a) {
	return a.x <= midX + pp / 2;
}

bool HiXTest(Pt const& a) {
	return a.x >= midX - pp / 2;
}

Pt* Filter(Pt const* b, Pt const* e, Pt* r, bool (*test)(Pt const&)) {
	for (; b != e; ++b)
		if (test(*b))
			*r++ = *b;
	return r;
}

double Solve(Pt* b, Pt* e) {
	if (e - b < 7) {
		int n = e - b;
		double ans = inf;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
					ans = min(ans, Dist(b[i], b[j], b[k], ans * ans / 4));
		sort(b, e, CmpYX);
		return ans;
	}
	int mid = (e - b) / 2, _midX = b[mid].x;
	double ans = min(Solve(b, b + mid), Solve(b + mid, e));

	midX = _midX;
	pp = ans;
	Pt *b1 = tp, *e1 = Filter(b, b + mid, tp, HiXTest);
	Pt *b2 = tp + mid, *e2 = Filter(b + mid, e, tp + mid, LoXTest);
	{
		for (Pt *p = b1, *qH = b2; p != e1; ++p) {
			for (; qH < e2 && qH->y < p->y - pp; ++qH);
			for (Pt *q1 = qH; q1 < e2 && q1->y <= p->y + pp; ++q1)
				for (Pt *q2 = q1 + 1; q2 < e2 && q2->y <= p->y + pp && q2->y - q1->y <= pp / 2; ++q2)
					ans = min(ans, Dist(*p, *q1, *q2, ans * ans / 4));
		}
	}
	{
		for (Pt *p = b2, *qH = b1; p != e2; ++p) {
			for (; qH < e1 && qH->y < p->y - pp; ++qH);
			for (Pt *q1 = qH; q1 < e1 && q1->y <= p->y + pp; ++q1)
				for (Pt *q2 = q1 + 1; q2 < e1 && q2->y <= p->y + pp && q2->y - q1->y <= pp / 2; ++q2)
					ans = min(ans, Dist(*p, *q1, *q2, ans * ans / 4));
		}
	}
	Pt* r = tp;
	b1 = b, e1 = b + mid, b2 = b + mid, e2 = e;
	while (b1 < e1 && b2 < e2)
		if (CmpYX(*b1, *b2))
			*r++ = *b1++;
		else
			*r++ = *b2++;
	while (b1 != e1)
		*r++ = *b1++;
	while (b2 != e2)
		*r++ = *b2++;
	copy(tp, r, b);
	return ans;
}
string solve() 
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		cin>>p[i].x>>p[i].y;
	sort(p, p + N);
	double ans = Solve(p, p + N);
	char buf[500] = {0};
	sprintf(buf, "%.6lf", ans);
	return buf;
}
int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
    	cnt++;
    	cout<<"Case "<<cnt<<": "<<solve()<<endl;
    }
    return 0;
}
