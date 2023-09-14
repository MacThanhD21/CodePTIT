/*
    Giả sử bạn là một người nghèo trong địa phương của bạn. 

    Địa phương của bạn có duy nhất một cửa hàng bán lương thực. 

    Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. 

    Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:

        N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày
        .
        S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.

        M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.

    Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại 

    trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn 

    cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là bộ 3 số N, S, M được viết trên một dòng.

    T, N, S, M thỏa mãn ràng buộc: 1≤T≤100;  1≤N, S, M ≤30.
    
Output:

    Đưa ra số ngày ít nhất bạn có thể mua lương thực 
    
    để tồn tại hoặc đưa ra -1 nếu bạn bị chết đói.
Ví dụ:

 
Input           Output

2
16 10 2         2
20 10 30        -1
*/

#include<bits/stdc++.h>

using namespace std;

/*
 -Idea : 
 + cứ 1 tuần có 1 chủ nhật không được mua thực phẩm
 => loại ngày đó bằng cách đếm số tuần vì 1 tuần có 1 ngày chủ nhật
 => số tuần = S / 7 (S là số ngày cần sống tiếp)
 
 + Tính số lượng thức ăn tối đa trong S ngày đó bằng cách 
 lấy S * số kg ăn trong 1 ngày (M)

 + Muốn biết số ngày có thể mua để sống tiếp , thì = cách duyệt qua
 số ngày còn lại trong S ngày có thể mua

 + Tính lần lượt số lượng thức ăn có thể mua trong 1,2,3,... ngày cho đến hết S1 = S - S / 7 (ngày)

 + Nếu nó > số lượng thức ăn tối đa thì đó là số ngày ít nhất cần mua

*/

void solve(){
    int N, S, M;
    cin >> N >> S >> M;
                                // N : số kg max có thể mua trong ngày
                                // S : số ngày cần sống tiếp
                                // M : số kg max ăn trong 1 ngày 
    int remainDay = S - S / 7;  // số ngày còn lại(trù chủ nhật) trong S ngày có thể mua thức ăn
    int maxValue = S * M;       // số lượng thức ăn max trong S ngày   
    long long tempValue = 0;
    
    // duyệt qua số ngày còn lại
    bool check = false;
    int minDay = 0;
    for(int i = 1; i <= remainDay; i++){
        tempValue = i * N;      // số lượng thức ăn có thể mua trong ngày 1,2.3...
        if(tempValue > maxValue){
            minDay = i;         // số ngày tối thiểu mua thưc ăn để có thể sống tiếp trong S ngày
            check = true;
            break;
        }
    }
    if(!check) cout << "-1\n";
    else cout << minDay << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}