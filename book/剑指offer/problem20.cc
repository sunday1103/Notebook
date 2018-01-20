class Solution
{
  public:
    void do_something(vector<int> &v, int a)
    {
        v.push_back(a);
        return;
    }

    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        std::vector<int> v;
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return v;
        }

        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int m0 = 0;
        int n0 = 0;
        int m1 = m0;
        int n1 = n0;
        while (m0 <= m && n0 <= n)
        {
            int flag = 0;
            while (1)
            {
                do_something(v, matrix[m1][n1]);

                // flag == 0
                if (flag == 0)
                {
                    if (n1 < n)
                    {
                        n1++;
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        if (m1 < m)
                        {
                            m1++;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                // flag == 1
                if (flag == 1)
                {
                    if (m1 < m)
                    {
                        m1++;
                        continue;
                    }
                    else
                    {
                        flag = 2;
                        if (n1 > n0)
                        {
                            n1--;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                // flag == 2
                if (flag == 2)
                {
                    if (n1 > n0)
                    {
                        n1--;
                        continue;
                    }
                    else
                    {
                        flag = 3;
                        m1--;
                        if (m1 == m0)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                // flag == 3
                if (flag == 3)
                {
                    if (m1 > m0 + 1)
                    {
                        m1--;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            m--;
            n--;
            m0++;
            n0++;
            m1 = m0;
            n1 = n0;
        }

        return v;
    }
};