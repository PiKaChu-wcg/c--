typedef long long LL;
struct BigInt
{
    static const int BASE = 100000000;      //基数
    static const int WIDTH = 32;             //基宽
    vector<int> s;                          //存储

    //构造函数 -- 使用LL
    BigInt(long long num = 0)
    {
        *this = num;
    }

    //赋值运算符 -- 使用LL
    BigInt operator = (long long num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        }
        while(num > 0);
        return *this;
    }
    //赋值运算符 -- 使用string
    BigInt operator = (const string& str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i++)
        {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    //比较运算符
    bool operator < (const BigInt& b) const
    {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size()-1; i >= 0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false; //相等
    }
    bool operator >  (const BigInt& b) const
    {
        return b < *this;
    }
    bool operator <= (const BigInt& b) const
    {
        return !(b < *this);
    }
    bool operator >= (const BigInt& b) const
    {
        return !(*this < b);
    }
    bool operator != (const BigInt& b) const
    {
        return b < *this || *this < b;
    }
    bool operator == (const BigInt& b) const
    {
        return !(b < *this) && !(*this < b);
    }

    //重载输入输出
    friend ostream& operator << (ostream &out, const BigInt& x)
    {
        out << x.s.back();
        for(int i = x.s.size()-2; i >= 0; i--)
        {
            char buf[20];
            sprintf(buf, "%08d", x.s[i]);
            for(int j = 0; j < strlen(buf); j++) out << buf[j];
        }
        return out;
    }
    friend istream& operator >> (istream &in, BigInt& x)
    {
        string s;
        if(!(in >> s)) return in;
        x = s;
        return in;
    }

    //加法
    BigInt operator + (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        for(int i = 0, g = 0; ; i++)
        {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size())    x += s[i];
            if(i < b.s.size())  x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }

    //加等于
    BigInt operator += (const BigInt& b)
    {
        *this = *this + b;
        return *this;
    }



//减法 -- 大减小 -- 其他的在外部处理
    BigInt operator - (const BigInt& b) const
    {
        BigInt c;
        c.s.clear();
        if((*this) == b) return c = 0;
        for(int i = 0, g = 0; ; ++i)
        {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = -g;
            g = 0;
            if(i < s.size())    x += s[i];
            if(i < b.s.size())  x -= b.s[i];
            if(x < 0) x += BASE, ++g;
            c.s.push_back(x);
        }
        for(int i = c.s.size()-1; i >= 0 && c.s[i] == 0; --i) c.s.pop_back();
        return c;
    }


    //乘法 -- 未使用FFT
    BigInt operator * (const BigInt& b) const
    {
        int s1 = s.size(), s2 = b.s.size();
        vector<LL> v(s1+s2+1,0);
        BigInt c;
        c.s.resize(s1+s2, 0);
        for(int i = 0; i < s1; ++i)        //相乘
            for(int j = 0; j < s2; ++j)
            {
                v[i+j] += (LL)s[i]*b.s[j];
            }
        for(int i = 0; i < s1+s2; ++i)      //进位
        {
            v[i+1] += v[i]/BASE;
            v[i] %= BASE;
            c.s[i] = v[i];
        }
        for(int i = c.s.size()-1; i >= 0 && c.s[i] == 0; --i) c.s.pop_back();
        return c;
    }

    //除法 -- 二分
    BigInt operator / (const BigInt& b) const
    {
        int s1 = s.size(), s2 = b.s.size();
        int len = s1-s2;
        BigInt c, x = *this, y = b;
        if(len < 0) return c = 0;

        c.s.resize(len+1, 0);
        for(int i = len; i >= 0; --i)
        {
            //先将除数对齐
            y.s.resize(s2+i,0);
            for(int j = s2+i-1; j >= 0; --j)
            {
                if(j >= i) y.s[j] = b.s[j-i];
                else y.s[j] = 0;
            }
            //再二分找商
            int L = 0, R = BASE;
            BigInt t;
            while(L < R)
            {
                int mid = (L+R)>>1;
                t = mid;
                if(t*y > x) R = mid;
                else L = mid+1;
            }
            c.s[i] = L-1;
            //更新被除数
            t = L-1;
            x = x - t*y;
        }
        for(int i = c.s.size()-1; i >= 0 && c.s[i] == 0; --i) c.s.pop_back();
        return c;
    }

    //取模
    BigInt operator % (const BigInt& b) const
    {
        return (*this) - (*this)/b * b;
    }

    //开方 -- 二分 -- 浮点数可放大1e4精确一位
    BigInt Sqrt()
    {
        BigInt L = 1, R = *this;
        while(L < R)
        {
            BigInt mid = (L+R)/2;
            if(mid*mid > *this) R = mid;
            else L = mid+1;
        }
        return L-1;
    }
};