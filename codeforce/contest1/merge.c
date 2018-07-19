int p = 0;
MergeSort(values, p, n - 1);

void MergeSort(int values[], int p, int r )
{
    int q;

    if( p >= r)
    {
        return;
    }
    else
    {
        q = ((p + r)/2);
        MergeSort(values, p, q);
        MergeSort(values, q + 1, r);
        Merge(values, p, q, r);
    }
}

void Merge(int values[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int B[n1 + 1];
    int C[n2 + 1];

    for (int k = 0, l = p; k < n1 && l <= q; k++, l++)
    {
        B[k] = values[l];
    }

    for (int k = 0, l = q + 1; k < n2 && l <= r; k++, l++)
    {
        C[k] = values[l];
    }

    B[n1] = 999999;
    C[n2] = 999999;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (B[i] <= C[j])
        {
            values[k] = B[i];
            i++;
        }

        else if (B[i] > C[j])
        {
            values[k] = C[j];
            j++;
        }
    }
}
