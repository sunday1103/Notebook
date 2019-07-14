int main()
{
    int *p = new int[3];
    int *k = new int[4];

    delete[] p;
    p = k;
    delete[] p; //此处是否会造成内存泄漏?

    return 0;
}