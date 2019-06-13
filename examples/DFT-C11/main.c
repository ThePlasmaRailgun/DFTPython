#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define w(h) copysign(1.0, h)

typedef int D;
typedef float I;
struct _ {
    I a;
    I b;
};
typedef struct _ F;
D f(D p) {
    if (p < 1) {
        return 1;
    } else {
        return p * f(p - 1);
    }
}

I u(D s) {
    I z = 0;
    for (D k = 0; k < s; k++) {
        z += pow(-1, k) * (f(6 * k)) / ((pow(f(k), 3)) * (f(3 * k))) * (13591409 + 545140134 * k) /
             (pow(640320, (3 * k)));
    }
    return pow((z * pow(10005, 0.5) / 4270934400), -1);
}

I e(D n) {
    I j = 2;
    for (D i = 2; i < n; i++) {
        j += 1.0 / f(i);
    }
    return j;
}

I r(I h, I g) {
    if (h > 1.0 || h < -1.0) {
        return -r(1.0 / h, g) + w(h) * g / 2.0;
    }
    if (h == 1.0 || h == -1.0) {
        return g / 4.0;
    }
    I j = 0.0;
    for (D z = 0; z < 100; z++) {
        j += pow(-1.0, (I) z) * (pow(h, (2.0 * (I) z + 1.0)) / (2.0 * (I) z + 1.0));
    }
    return j;
}

F s(I n, I g, I a[]) {
    if (n < -g / 2.0 || n > g / 2.0) {
        F j;
        if (n < 0) {
            j = s(n + g, g, a);
        } else {
            j = s(n - g, g, a);
        }
        I x = j.a;
        I y = j.b;
        F v = {-x, -y};
        return v;
    }

    I x = 1.0, y = 0.0;

    for (D i = 0; i < 50; i++) {
        I d = w(n);

        I u = x, v = y;

        x = u - (d * pow(2.0, -i) * v);
        y = (d * pow(2.0, -i) * u) + v;

        n = n - (d * a[i]);
    }
    I k = 0.6072529350088814;
    F value = {x * k, y * k};
    return value;
}

I h(I a, I b) {
    I u, x;
    D v, y;
    u = frexp(a, &v);
    x = frexp(b, &y);

    I h = u * x;
    I j = v + y;

    return ldexp(h, j);
}


D t(D s) {
    D k = 0;
    while (s > 0) {
        k++;
        s >>= 1;
    }
    return k;
}

D j(D e, D h) {
    if (e < 10 || h < 10) {
        return e * h;
    }
    D y = (t(e) > t(h) ? t(e) : t(h)) / 2.0;

    D l = pow(2.0, y);

    D a = e / l;
    D b = e % l;
    D c = h / l;
    D d = h % l;

    D u = j(a, c);

    D v = j(b, d);

    D z = j(a + b, c + d) - u - v;

    return u * pow(2, (y * 2)) + (z * l) + v;
}

I m(I a, I b) {
    double x, y, u, v;
    x = modf(a, &y);
    u = modf(b, &v);

    return h(x, u) + h(y, u) + h(x, v) + j(y, v);
}

F o(F a, F b) {
    I x = a.a, y = a.b;
    I u = b.a, v = b.b;

    F r = {m(x, u) - m(y, v), m(x, v) + m(y, u)};
    return r;
}

F k(F p, I g, I b, I a[]) {
    I q = pow(b, p.a);
    F v = s(p.b, g, a);

    F r = {v.a * q, v.b * q};
    return r;
}

void dark_magic(I c[], size_t f, D l) {
    I g = u(5);
    I b = e(30);
    I a[50];

    for (D i = 0; i < 50; i++) {
        a[i] = r(pow(2.0, -i), g);
    }

    for (D i = 0; i < l; i++) {
        I s[f / 2];
        for (D j = 0; j < f; j += 2) {
            F z = {c[j], c[j + 1]};
            F x = {0.0, 2.0};
            F v = {g * j * i / f, 0.0};
            s[j / 2] = o(z, k(o(v, x), g, b, a)).a;
        }
        I out = 0;
        for (D j = 0; j < f / 2; j++) {
            out += s[j];
        }
        putchar(round(out / (f / 2)));
    }
}


D main() {
    I c[] = {1129.0,
             0.0,
             23.49715586796887,
             22.211581739879684,
             -179.7230388530905,
             -157.5036698239512,
             7.806224011347112,
             20.798766949019274,
             4.275687275221713,
             -116.59625874580514,
             -3.9410319705666126,
             -17.579175939686984,
             51.58500366911933,
             -6.977531208354918,
             51.58500366911933,
             6.977531208354918,
             -3.9410319705666126,
             17.579175939686984,
             4.275687275221713,
             116.59625874580514,
             7.806224011347112,
             -20.798766949019274,
             -179.7230388530905,
             157.5036698239512,
             23.49715586796887,
             -22.211581739879684};
    D l = 13;

    dark_magic(c, sizeof(c) / sizeof(c[0]), l);
}