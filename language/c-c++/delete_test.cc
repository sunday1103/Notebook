int _tmain(int argc, _TCHAR *argv[])
{
    int *p = new int[3]{1, 2, 3};
    int *k = new int[4]{6, 7, 8, 9};

    delete[] p;
    p = k;
    delete[] p; //此处是否会造成内存泄漏?

    return 0;
}