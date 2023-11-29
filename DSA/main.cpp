// liệt kê các cluster trống trong N cluster đầu tiên
for (i = 2; i <= N; i++){
    if (fat[i] == 0)
    printf(“% d”, i);
}
// liệt kê các cluster thuộc về file bắt đầu từ cluster thứ n
int cur = n;
while (cur < 0xFFF8){
    printf(“->% d”, cur);
    cur = fat[cur];
}