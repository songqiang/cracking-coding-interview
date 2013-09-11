/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Given a (decimal - e.g. 3.72) number that is passed in as a string,
print the binary representation. If the number can not be
represented accurately in binary, print “ERROR”

 */

static size_t
gcd(size_t a, size_t b)
{
    if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

static string 
int2bin(const size_t n)
{
    string s = "";
    do 
    {
        size_t r = n % 2;
        n /= 2;
        s += r == 0 ? "0" : "1";
    } while (n > 0)

    return string(s.rbegin(), s.rend());
}

static string
dec2bin(const double d)
{
    string s = "";
    do 
    {
        const size_t t = static_cast<size_t>(d * 2);
        s += t == 0 ? "0" : "1";
        t *= 2;
    } while (fabs(t) >= 1e-10);

    return s;
}

static string
dec2bin(const string s)
{
    const string fs = s.substr(s.find(".") + 1);
    size_t fi = atoi(fs);
    size_t di = 1;
    for (size_t i = 0; i < fs.size(); ++i)
        di *= 10;
    const size_t gcd = gcd(fi, di);
    fi /= gcd;
    while (fi % 2 == 0) fi /= 2;
    if (fi != 1) return "ERROR";

    d = atof(s.c_str());
    const string sign(d > 0 ? "" : "-");
    d = fabs(d);
    
    const size_t i = static_cast<size_t>(d);
    const double f = d - i;

    return sign + int2bin(i) + "." + dec2bin(f);
}

