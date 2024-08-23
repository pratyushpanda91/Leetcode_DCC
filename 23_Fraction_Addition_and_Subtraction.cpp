class Solution {
    typedef long long ll;

public:
    string fractionAddition(string exp) {
        if (exp == "")
            return "0/1";
        ll nu, de;
        string s = "";
        char op = '+';
        int i = 0;
        for (; i < exp.size(); i++) {
            if (i != 0 && (exp[i] == '+' || exp[i] == '-')) {
                op = exp[i];
                de = stoi(s);
                s = "";
                i++;
                break;
            } else if (i == exp.size() - 1) {

                de = stoi(s + exp[i]);
                s = "";
            } else if (exp[i] == '/') {

                nu = stoi(s);

                s = "";
            } else {
                s += exp[i];
            }
        }
        ll tn, td;
        while (i < exp.size()) {
            if (exp[i] == '+' || exp[i] == '-') {
                td = stoi(s);
                s = "";

                ll lcm = (de * td) / (__gcd(de, td));
                ll upnu = nu * (lcm / de);
                ll tnu = tn * (lcm / td);

                if (op == '+') {
                    nu = upnu + tnu;
                } else {
                    nu = upnu - tnu;
                }
                de = lcm;

                ll hcf = abs(__gcd(nu, de));
                nu /= hcf;
                de /= hcf;

                op = exp[i];
            } else if (i == exp.size() - 1) {

                td = stoi(s + exp[i]);
                s = "";

                ll lcm = (de * 1ll * td) / (__gcd(de, td));
                ll upnu = nu * (lcm / de);
                ll tnu = tn * (lcm / td);

                if (op == '+') {
                    nu = upnu + tnu;
                } else {
                    nu = upnu - tnu;
                }
                de = lcm;

                ll hcf = abs(__gcd(nu, de));

                nu /= hcf;
                de /= hcf;

            } else if (exp[i] == '/') {
                tn = stoi(s);
                s = "";
            } else {
                s += exp[i];
            }

            i++;
        }
        s = "";
        s += to_string(nu);
        s += '/';
        s += to_string(de);
        return s;
    }
};
