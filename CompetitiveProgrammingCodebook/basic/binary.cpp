while (l < r)
{
    int mid = l + r >> 1;
    if (q[mid] >= x) r = mid;
    else l = mid + 1;
}
while (l < r)
{
    int mid = l + r + 1 >> 1;
    if (q[mid] <= x) l = mid;
    else r = mid - 1;
}