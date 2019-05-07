//
//  template
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


#define _CRT_DISABLE_PERFCRIT_LOCKS
#define _ CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

/*Allocation control*/
//#define CUSTOM_VECTOR
#define CUSTOM_ALLOCATOR

/*Hidden features*/
//#define BUILTIN_TREE
//#define BINARY_IO
#define INT_128

#define DEBUG

#ifdef BUILTIN_TREE
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
#endif

#include <bits/stdc++.h>
using namespace std;

/*MACROS*/
//FUNCTIONS
#define in_range(i, l, r) for(ll i = l; i < r; i++)

#define all(v) begin(v), end(v)
#define rall(v) (v).rbegin(), (v).rend()

#define tr(it, container) for(auto it = begin(container); it != end(container); it++)
#define rtr(it, container) for(auto it = (container).rbegin(); it != (container).rend(); it++)

#define present(element, container) ((container).find(element) != end(container))

#define _T(...) __VA_ARGS__
#define forever() for(;;)

//ABBREVIATIONS
#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }
template<class T> T peek(queue<T>& q) { T top_el = q.front(); q.pop(); return top_el; }

//TYPE SAFETY
#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)

//CONSTANTS
#define INF (numeric_limits<int>::max())
#define MINF (numeric_limits<int>::min())
#define LINF (numeric_limits<long long>::max())
#define LMINF (numeric_limits<long long>::min())
#define EPS (1E-9)
#define PI ((long double)3.1415926535897932384626433832795028841971693993751)

#define reunique(container) ((container).resize(unique(all(container))-begin(container)))

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<int>> graph;

/*TEMPLATE FUNCTIONS*/
//BIT OPERATIONS
template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }

/*TEMPLATE ALGORITHMS*/
template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}
template<typename T> inline bool between(T x, T l, T r) { return l <= x && x <= r; }

/*COMBINATORS*/
template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}

//STL INPUT
void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r) cin >> arr[i]; }

//STL OUTPUT
template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r) {cout << arr[i] << " ";}; cout << "\n"; }

//VARIADIC INPUT
template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }

//VARIADIC OUTPUT
template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }

//VARIADIC TYPE DECLARATION
template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::tensor(args...); }

#ifdef INT_128
typedef __int128 bigInt;
istream& operator >>(istream& in, bigInt& n){
    in >> ws; n = 0;
    for(char ch = getchar(); isdigit(ch); ch = getchar()){
        n = n*bigInt(10) + bigInt(ch-'0');
    }
    return in;
}
ostream& operator <<(ostream& out, bigInt n){
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int representation[36];
    int pos = 0;
    while(n){
        representation[pos++] = digits[n % 10];
        n /= 10;
    }
    for(int i = pos-1; i >= 0; i--){
        out << representation[i];
    }
    return out;
}
#endif // INT_128

//DEBUG
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         cerr<<#a<<" = "<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<" = "<<(a)<<", "<<#b<<" = " <<(b)<<", "<<#c<<" = "<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<" = "<<(a)<<", "<<#b<<" ="<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#ifdef BINARY_IO
const int BUSFIZE = 2048;
static char inbuf[BUSFIZE + 16];
static char *inp = inbuf;
static char *linp = inbuf + BUSFIZE;
int read_int()
{
    if (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    bool minus = false;
    if (*inp == '-') minus = true, ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    int res = *inp++ - '0';
    if (inp == linp)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp >= '0' && *inp <= '9')
    {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp)
        {
            memset(inbuf, 0, BUSFIZE);
            cin.read(inbuf, BUSFIZE);
            inp = inbuf;
        }
    }
    return minus ? -res : res;
}
static char outbuf[BUSFIZE + 16];
static char *outp = outbuf;
static char *loutp = outbuf + BUSFIZE;
void write_int(int x, bool last = false)
{
    char *begp = outp;
    do
    {
        int t = x / 10;
        char c = x - 10 * t + '0';
        *outp++ = c;
        x = t;
    } while (x);
    char *endp = outp - 1;
    while (begp < endp)
    {
        swap(*begp, *endp);
        ++begp;
        --endp;
    }
    *outp++ = '\n';
    if (last || outp > loutp)
    {
        cout.write(outbuf, outp - outbuf);
       outp = outbuf;
    }
}
#endif

#ifdef CUSTOM_VECTOR
template <class T>
    struct custom_vector : vector<T> {
    custom_vector() : vector<T>() { }
    custom_vector( int n ) : vector<T>(n) { }
    custom_vector( int n, T x ) : vector<T>(n, x) { }
    T &operator [] ( size_t i ) {
        return vector<T>::at(i);
    }
};

#define vector custom_vector
#endif

struct fraction{
    ll n, d;
    fraction (): n(0), d(1) {}
    fraction (ll x): n(x), d(1) {}
    fraction (ll x, ll y) {
        ll g = gcd(x, y);
        n = x/g, d = y/g;
        if (d < 0) n *= -1, d *= -1;
    }

    fraction normalized() {
        ll g = gcd(n, d);
        return {n/g, d/g};
    }
    bool operator ==(const fraction& f) const { return n == f.n && d == f.d; }
    bool operator <(const fraction& f) const  { return n*f.d < d*f.n; }
    bool operator >(const fraction& f) const  { return n*f.d > d*f.n; }
    bool operator <=(const fraction& f) const  { return n*f.d <= d*f.n; }
    bool operator >=(const fraction& f) const  { return n*f.d >= d*f.n; }

    fraction operator +(const fraction& f) const { return fraction(n*f.d + f.n*d, d*f.d); }
    fraction operator -(const fraction& f) const { return fraction(n*f.d - f.n*d, d*f.d); }
    fraction operator *(const fraction& f) const { return fraction(n*f.n, d*f.d); }
    fraction operator /(const fraction& f) const { assert(f.n != 0); return fraction(n*f.d, d*f.n); }
};
fraction operator *(double m, const fraction& f) { return fraction(f.n*m, f.d); }
fraction operator *(const fraction& f, double m) { return fraction(f.n*m, f.d); }
fraction operator /(const fraction& f, double m) { assert(m != 0); return f*(1/m); }
istream& operator >>(istream& in, fraction& f) { in >> f.n >> f.d; return in; }
ostream& operator <<(ostream& out, const fraction& f) {
    if (f.d == 1) { out << f.n; }
    else { out << f.n << "/" << f.d; }
    return out;
}

int main(){
//        fastIO();
        freopen("in", "r", stdin);
//        freopen("out", "w", stdout);
    int m = 3, n = 8;
    vector<fraction> c(n);
    for (int i = 0; i < n; i++) { read(c[i].n); }
    auto tableau = tensor<fraction>(m+1, n+1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n+1; j++) {
            read(tableau[i][j].n);
        }
    }
//    for (int j = 1; j < n+1; j++) {
//        read(tableau[m][j].n);
//    }
    vector<int> base {6, 7, 8};
    vector<fraction> curr;
    int asaj = 8;
    for (auto &id : base) {
        curr.pb(c[id]);
        swap(c[id], c[asaj--]);
    }
    for (int j = 1; j < n+1; j++) {
        auto zj = fraction(0);
        for (int i = 0; i < m; i++) {
            zj = zj + curr[i]*tableau[i][j];
        }
        tableau[m][j] = zj-c[j];
    }
    for (int i = 0; i < m+1; i++) {
        if (i < m) cout << base[i] << ": ";
        for (int j = 0; j < n+1; j++) {
            if (i == m && j == 0) { cout << "\t"; continue; }
            cout << tableau[i][j] << "\t";
        } cout << "\n";
    }
    cout << "\n";
    for (int r, s;;) {
        auto delta = tableau[m];
        s = (min_element(begin(delta)+1, end(delta))-begin(delta));
        if (delta[s].n >= 0) break;
        vector<fraction> check(m, fraction(INF));
        for (int i = 0; i < m; i++) {
            if (tableau[i][s].n > 0) { check[i] = tableau[i][0]/tableau[i][s]; }
        }
        if (all_of(all(check), [](const fraction& f){ return f == fraction(INF); })) break;
        r = min_element(all(check))-begin(check);
        fraction pivot = tableau[r][s];
        curr[r] = tableau[m][s];
        base[r] = s;
        for (int i = 0; i < m+1; i++) {
            if (i == r) { continue; }
            fraction quot = tableau[i][s]/pivot;
            for (int j = (i == m); j < n+1; j++) {
                tableau[i][j] = tableau[i][j] - quot*tableau[r][j];
            }
        }
        for (int j = 0; j < n+1; j++) {
            tableau[r][j] = tableau[r][j]/pivot;
        }
        for (int i = 0; i < m+1; i++) {
            if (i < m) cout << base[i] << ": ";
            for (int j = 0; j < n+1; j++) {
                if (i == m && j == 0) { cout << "\t"; continue; }
                cout << tableau[i][j] << "\t";
            } cout << "\n";
        }
        cout << "\n";
    }
    print(base);
    return 0;
}

#ifdef CUSTOM_ALLOCATOR
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete ( void * ) { }
#endif // CUSTOM_ALLOCATOR
