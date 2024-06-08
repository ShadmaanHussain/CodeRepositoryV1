int smar[100];
    int p, q, flag;
    p = q = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < p; j++)
        {
            if (a[i] == smar[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            smar[p] = a[i];
            p++;
        }
        else
        {
            if (a[i] == smar[q])
            {
                q++;
            }
        }
    }
    return smar[q];