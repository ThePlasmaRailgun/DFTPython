#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define w(h) copysign(1.0, h)
#define x(a, b) (a > b ? a : b)

struct _pair {
    float a;
    float b;
};
typedef struct _pair pair;

int f(int p) {
    if (p < 1) {
        return 1;
    } else {
        return p * f(p - 1);
    }
}

float u(int s) {
    float z = 0;
    for (int k = 0; k < s; k++) {
        z += pow(-1, k) * (f(6 * k)) / ((pow(f(k), 3)) * (f(3 * k))) * (13591409 + 545140134 * k) /
             (pow(640320, (3 * k)));
    }
    return pow((z * pow(10005, 0.5) / 4270934400), -1);
}

float e(int n) {
    float j = 2;
    for (int i = 2; i < n; i++) {
        j += 1.0 / f(i);
    }
    return j;
}

float r(float h, float g) {
    if (h > 1.0 || h < -1.0) {
        return -r(1.0 / h, g) + w(h) * g / 2.0;
    }
    if (h == 1.0 || h == -1.0) {
        return g / 4.0;
    }
    float j = 0.0;
    for (int z = 0; z < 100; z++) {
        j += pow(-1.0, (float) z) * (pow(h, (2.0 * (float) z + 1.0)) / (2.0 * (float) z + 1.0));
    }
    return j;
}

pair s(float n, float g, float a[]) {
    if (n < -g / 2.0 || n > g / 2.0) {
        pair xy;
        if (n < 0) {
            xy = s(n + g, g, a);
        } else {
            xy = s(n - g, g, a);
        }
        float x = xy.a;
        float y = xy.b;
        pair value = {-x, -y};
        return value;
    }

    float x = 1.0, y = 0.0;

    for (int i = 0; i < 50; i++) {
        float d = w(n);

        float u = x, v = y;

        x = u - (d * pow(2.0, -i) * v);
        y = (d * pow(2.0, -i) * u) + v;

        n = n - (d * a[i]);
    }
    float k = 0.6072529350088814;
    pair value = {x * k, y * k};
    return value;
}

float h(float a, float b) {
    float u, x;
    int v, y;
    u = frexp(a, &v);
    x = frexp(b, &y);

    float h = u * x;
    float j = v + y;

    return ldexp(h, j);
}


int t(int s) {
    int k = 0;
    while (s > 0) {
        k++;
        s >>= 1;
    }
    return k;
}

int j(int e, int h) {
    if (e < 10 || h < 10) {
        return e * h;
    }

    int y = x(t(e), t(h)) / 2.0;

    int l = pow(2.0, y);

    int a = e / l;
    int b = e % l;
    int c = h / l;
    int d = h % l;

    int u = j(a, c);

    int v = j(b, d);

    int z = j(a + b, c + d) - u - v;

    return u * pow(2, (y * 2)) + (z * l) + v;
}

float m(float a, float b) {
    double x, y, u, v;
    x = modf(a, &y);
    u = modf(b, &v);

    return h(x, u) + h(y, u) + h(x, v) + j(y, v);
}

pair o(pair a, pair b) {
    float x = a.a, y = a.b;
    float u = b.a, v = b.b;

    pair ret = {m(x, u) - m(y, v), m(x, v) + m(y, u)};
    return ret;
}

pair k(pair p, float g, float b, float a[]) {
    float q = pow(b, p.a);
    pair hz = s(p.b, g, a);

    pair ret = {hz.a * q, hz.b * q};
    return ret;
}

void dark_magic(float c[], size_t lenc, int l) {
    float g = u(5);
    float b = e(30);
    float atan[50];

    for (int i = 0; i < 50; i++) {
        atan[i] = r(pow(2.0, -i), g);
    }

    for (int n = 0; n < l; n++) {
        float sum_arr[lenc / 2];
        for (int a = 0; a < lenc; a += 2) {
            pair coefficients = {c[a], c[a + 1]};
            pair imag = {0.0, 2.0};
            pair real = {(float) g * (float) a * (float) n / (float) lenc, 0.0};
            sum_arr[a / 2] = o(coefficients, k(o(real, imag), g, b, atan)).a;
        }
        float out = 0;
        for (int i = 0; i < lenc / 2; i++) {
            out += sum_arr[i];
        }
        putchar(round(out / (lenc / 2)));
    }
}


int main() {
    float c[] = {1129.0,
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
    int l = 13;

    dark_magic(c, sizeof(c) / sizeof(c[0]), l);
}